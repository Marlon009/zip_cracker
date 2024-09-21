#include <iostream>
#include <fstream>
#include <zip.h>
#include <cstring>

using namespace std;

void ascii() {
    cout<< R"(                                                                                                   
                                                                                                    
                                                                                                    
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
                                                                                                 
                                      zip_cracker                                                  
                                                                                                 
                                   My GitHub: Marlon009                                            
                                   
                    How to use: ./zip_cracker <archive.zip> <dictionary.txt>   
                                                                        
                                                                            
                                                                             )" << endl;
}

bool tryPassword(const char* filename, const char* password) {
    int err = 0;
    zip_t* z = zip_open(filename, ZIP_RDONLY, &err);

    if (!z) {
        cerr << "Error opening ZIP file!" << endl;
        return false;
    }

    zip_file_t* zfile = zip_fopen_encrypted(z, zip_get_name(z, 0, 0), 0, password);

    if (zfile != NULL){
        zip_fclose(zfile);
        zip_close(z);
        return true;
    }


    zip_close(z);
    return false;


}

void crackZip(const char* zipFilename, const char* dictionaryFile){

     ifstream dict(dictionaryFile);
     string password;


     if (!dict.is_open()) {
        cerr << "Could not open dictionary file!" << endl;
        return;
     }

     while (getline(dict, password)) {

        if (tryPassword(zipFilename, password.c_str())){

        cout << "[+] password found" << password << endl;
        return;
        }
     }

     cout << "[-] Password not found in the dictionary." << endl;
}


int main(int argc, char* argv[]){

    cout << "How to use: ./zip_cracker <archive.zip> <dictionary.txt> ";

    ascii();
    if(argc != 3){
        cerr << "Usage: " << argv[0] << " <zipfile> <dictionary>" << endl;
        return 1;
    }

    crackZip(argv[1], argv[2]);
    return 0;
}