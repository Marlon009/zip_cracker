#include <iostream>
#include <fstream>
#include <zip.h>
#include <cstring>
#include <iomanip>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

#define VERSION "2.0"
#define AUTHOR "Marlon009"

//namespace fs = std::filesystem;

void show_ascii() {
    std::cout << R"(
 

    ███████╗██╗██████╗      ██████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗ 
    ╚══███╔╝██║██╔══██╗    ██╔════╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗
      ███╔╝ ██║██████╔╝    ██║     ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝
     ███╔╝  ██║██╔═══╝     ██║     ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗
    ███████╗██║██║         ╚██████╗██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║
    ╚══════╝╚═╝╚═╝          ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ V)" VERSION R"(
                                                                              
    -------------------------------------------------------------------------------------
                                 By: github.com/)" AUTHOR R"(
    -------------------------------------------------------------------------------------
    )" << std::endl;
}

struct CrackConfig {
    std::string zip_file;
    std::string dict_file;
    bool use_mutation = false;
    int mutation_level = 1;
};

class Stats {
public:
    void start() {
        start_time = std::chrono::steady_clock::now();
    }
    
    void update(size_t tested) {
        auto now = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start_time);
        passwords_tested = tested;
    }
    
    void print() const {
        const auto seconds = elapsed.count();
        const auto rate = (seconds > 0) ? (passwords_tested / seconds) : 0;
        const char* spinner = "|/-\\";
        
        std::cout << "\r[+] Progresso: "
                  << std::setw(8) << passwords_tested << " senhas | "
                  << "Tempo: " << std::setw(4) << seconds << "s | "
                  << std::setw(6) << rate << " p/s | "
                  << "Descompactando... " << spinner[spinner_pos]
                  << std::flush;
    }

    void advance_spinner() {
        spinner_pos = (spinner_pos + 1) % 4;
    }

private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::seconds elapsed{0};
    size_t passwords_tested{0};
    int spinner_pos = 0;
};

std::string open_file_dialog() {
    std::string path;
#ifdef _WIN32
    OPENFILENAME ofn;
    char szFile[260] = {0};
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Arquivos ZIP\0*.zip\0Todos os Arquivos\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        path = ofn.lpstrFile;
    }
#else
    std::string cmd = "zenity --file-selection --title=\"Selecione um arquivo\" 2>/dev/null";
    char buffer[512];
    if (FILE* f = popen(cmd.c_str(), "r")) {
        if (fgets(buffer, sizeof(buffer), f)) {
            path = buffer;
            path.erase(path.find_last_not_of("\n\r") + 1);
        }
        pclose(f);
    }
#endif
    return path;
}

void show_menu(CrackConfig& config) {
    int choice;
    do {
        system("cls || clear");
        show_ascii();
        std::cout << "\nMenu Principal:\n"
                  << "1. Selecionar arquivo ZIP [" 
                  << (config.zip_file.empty() ? "Nenhum" : config.zip_file) << "]\n"
                  << "2. Selecionar dicionário [" 
                  << (config.dict_file.empty() ? "Nenhum" : config.dict_file) << "]\n"
                  << "3. Configurar mutação de senhas\n"
                  << "4. Iniciar Ataque\n"
                  << "5. Sair\n"
                  << "Escolha: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                config.zip_file = open_file_dialog();
                if(!config.zip_file.empty()) {
                    std::cout << "\nArquivo selecionado: " 
                              << config.zip_file << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                break;
            case 2:
                config.dict_file = open_file_dialog();
                if(!config.dict_file.empty()) {
                    std::cout << "\nDicionário selecionado: " 
                              << config.dict_file << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                break;
            case 3: {
                std::cout << "Nível de mutação (1-3): ";
                std::cin >> config.mutation_level;
                config.use_mutation = config.mutation_level > 0;
                break;
            }
            case 4:
                if(!config.zip_file.empty() && !config.dict_file.empty()) {
                    return;
                }
                std::cout << "Selecione arquivo e dicionário primeiro!\n";
                break;
        }
    } while(choice != 5);
    exit(0);
}

void mutate_password(std::string& password, int level) {
    if(level >= 1) {
        password += "123";
    }
    if(level >= 2) {
        std::replace(password.begin(), password.end(), 'e', '3');
    }
    if(level >= 3) {
        for(auto& c : password) {
            if(rand() % 2) c = toupper(c);
        }
    }
}

void crack_zip(const CrackConfig& config) {
     std::cout << "\nIniciando descriptografia...\n";
    std::cout << "Arquivo: " << config.zip_file << "\n";
    std::cout << "Dicionário: " << config.dict_file << "\n";
    std::cout << "----------------------------------------\n";

    Stats stats;
    stats.start();

    zip_t* archive = zip_open(config.zip_file.c_str(), ZIP_RDONLY, nullptr);
    if(!archive) {
        std::cerr << "\n[!] Erro ao abrir arquivo ZIP!" << std::endl;
        return;
    }

    std::ifstream dict(config.dict_file);
    if(!dict) {
        std::cerr << "\n[!] Erro ao abrir dicionário!" << std::endl;
        zip_close(archive);
        return;
    }

    std::string password;
    size_t count = 0;
    bool found = false;

    while(std::getline(dict, password) && !found) {
        if(config.use_mutation) {
            mutate_password(password, config.mutation_level);
        }

        zip_file_t* file = zip_fopen_index_encrypted(archive, 0, 0, password.c_str());
        if(file) {
            char buffer[128];
            if(zip_fread(file, buffer, sizeof(buffer)) >= 0) {
                found = true;
                std::cout << "\n\n[+] Senha encontrada: " << password << std::endl;
            }
            zip_fclose(file);
        }

        if(++count % 500 == 0) {
            stats.update(count);
            stats.advance_spinner();
            stats.print();
        }
    }

    zip_close(archive);
    
    if(!found) {
        std::cout << "\n\n[-] Senha não encontrada no dicionário." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    CrackConfig config;

    if(argc == 1) {
        show_menu(config);
    } else if(argc == 3) {
        config.zip_file = argv[1];
        config.dict_file = argv[2];
    } else {
        std::cerr << "Uso: " << argv[0] << " [<arquivo.zip> <dicionario.txt>]\n";
        return 1;
    }

    crack_zip(config);
    return 0;
}