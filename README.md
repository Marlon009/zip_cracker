# zip_cracker
                                                                                           
                                                           A8sof6W nCop                             
                                                         UMKeJ8Z zrqA                               
                          aSc7AS                       AzZK8sAAA2AFwTRU                             
                             IKHLEDOfT                 KAPBIQRjpYZJny                               
                     zgKc8cZq64  AiZE9JCSdJ   ummgp271HaqDiZ3FExSZa8 QK                             
                       n7KpCXgMDQBekgZFCAglJvMBEDcBA5KCDpu TKT0Uc3llMZ                              
                        WflZHAROaFLBAVMZH5hKUUAPgQaDWFDVclt8zaA62xqi                                
                         GXS4Ek07AA9GKECAATJABACFPVjGAHLNYWYw TAj3Gk                                
                            IT3DCNJPEkXFFUK85UASFJWVLEDDCiWRVZr LQKWz                               
                             G0o54lNAAAxBFKCCAE8AscA4dAHKCFltW1jvz5EGG                              
                              cqQT7BAHA2dZYk8TCHIX8YAXYOEoKAU5Hjhbxx                                
                                 IU9lQ1rrhAM7JDYFZcLpCO3EN6OOB4p1Iquw zq7                            
                                    AAAcF4qXMGABACDC7HAGANCDBBHQoyysKA5                            
                                 mAHUAAAADAAICbYChgosrEXLDlAGE6MHv zzAm                             
                               tjpyppz2q shjnhgp6ccAPiApmARA0OcRoowxt2                              
                            TonevuzxyvAE8NvzyiztezzzTXyRyvmqVACqjArWeg                              
                          qZAtcwt7mAYeWgzxywtxyzqowWMszV5 IlEAAAAOyQrR                              
                         9U3rnxzzAUbL3rwxxwyvayeXdaZ6JLPEMPE   UBLvxjkz                             
                         Ao7f3tUFMvqUowruyxvolABA6ABAYGD        AAxufn2                             
                        REDorzqAAW3 xzzyzuZwqcmCA               A5FynuRr                            
                       1FpnuqzxSx zzxt0kWwsr7q                   ICtWuGa                            
                       0EKlxzzyxzzzxna1QuxfVp                    AYyxz3y                            
                       BAfmrz xywgdYWsuwyIC5PAAs                 HP8zz0  aw                         
                       EAIQcgmpPS0DxxuooTAOOAHAMAZ                AAx9zxOobMzX                      
                       UOGGXGFfJWzzkeVAz9oxtrxw3nzu2AADEAvA        AozvBAzDGVB                      
                     beTDEAAAAAA9GVi7ijWOFvuuZbCsyEvSIDDM03PAD7H4BAGAfstxAC0wZBxk                   
                 YzM60Om5AAAFHAQxAADtO7JpDu5TAGbAAAe6ru14qrsyrtiQGBvwRpikiv8ptc53d0Dic              
                5mXqZTf8ebbQJHk80G4A4XbhAShHpAetAU6ulfprp ysvrh8 z vzzpirvubvjycy                   
                                       sz                                                           
     AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA     
     AAAA A AA AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA     
     AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA   
Zip_cracker é uma ferramenta simples de brute-force para arquivos zip usando um dicionário de palavras.

Funcionalidades:

    Quebrar senhas de arquivos ZIP protegidos.
    Utiliza um dicionário de senhas para tentar encontrar a correta.
    Exibe uma arte ASCII ao iniciar o programa.

Pré-requisitos:

Antes de começar, você precisará instalar as seguintes dependências:
Dependências

    GCC/G++ (compilador C++)
    libzip (biblioteca para manipulação de arquivos ZIP)

Como instalar as dependências:
----------------
Ubuntu/Debian:

bash

sudo apt update
sudo apt install g++ libzip-dev
----------------
Fedora:

bash

sudo dnf install gcc-c++ libzip-devel
----------------
macOS (via Homebrew):

bash

brew install gcc libzip
----------------
Windows:

Para Windows, você pode instalar a libzip via MSYS2 ou vcpkg. Aqui está um exemplo usando vcpkg:

    Instale o vcpkg:

    bash

git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat

Instale o libzip:

bash

    ./vcpkg install libzip

    Adicione o caminho do vcpkg à variável de ambiente PATH ou inclua o caminho ao compilar.
----------------


Execute o programa com o seguinte comando:

bash

./zip_cracker <arquivo.zip> <dicionario.txt>

    <arquivo.zip>: O caminho para o arquivo ZIP protegido por senha.
    <dicionario.txt>: O caminho para o arquivo de dicionário que contém possíveis senhas, uma por linha.
----------------
Exemplo de uso:

bash

./zip_cracker arquivo_protegido.zip dicionario.txt

Se a senha for encontrada no dicionário, o programa exibirá:

css

[+] Password found: <senha>

Caso contrário, será exibida a mensagem:

css

[-] Password not found in the dictionary.

Contribuições

Sinta-se à vontade para abrir issues ou enviar pull requests para melhorias ou correções.

Este projeto é licenciado sob a MIT.
Notas

    A biblioteca libzip não está inclusa no projeto. Siga as instruções acima para instalá-la no seu sistema antes de compilar o programa.

    
