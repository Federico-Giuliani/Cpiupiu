#include <iostream>
#include <filesystem>
#include <string>


namespace fsys = std::filesystem;

void eliminaCartella(std::string path);
void eliminaDentroCartella(std::string path);
void rinominaCartella(std::string path, std::string nome);
void rinominaDentroCartella(std::string path, std::string nome);

int main(){

    //VARIABILI
    bool isGoing = true;
    std::string pathCartella;
    std::string end;
    std::string ren;
    int scelta;
    
    while(isGoing){
        std::cout << "Inserisci il path della cartella";
        std::cin >> pathCartella;

        while(true){
            std::cout << "Scegliere azione \n";
            std::cout << "1 -Elimina cartella \n";
            std::cout << "2 -Elimina tutto il contenuto della cartella (no cartella) \n";
            std::cout << "3 -Rinomina cartella\n";
            std::cout << "4 -Rinomina tutto il contenuto della cartella (no cartella) \n";
            std::cin >> scelta;
            
            //Scelte
            switch(scelta){
                case 1:
                    eliminaCartella(pathCartella);
                    break;

                case 2:
                    eliminaDentroCartella(pathCartella);
                    break;

                case 3:
                    std::cout << "Come vuoi rinominare la cartella?";
                    std::cin >> ren;
                    rinominaCartella(pathCartella, ren);
                    break;

                case 4:
                    std::cout << "Come vuoi rinominare i files?";
                    std::cin >> ren;
                    rinominaDentroCartella(pathCartella, ren);
                    break;
                    
                default:
                    std::cout << "Opzione non valida o non aggiunta";
                    break;
            }
            
            std::cout << "\n Concludere l'esecuzione? [Y/N]";
            std::cin >> end;

            if(end == "N"){}
            else{//Se non risponde N interrompe l'esecuzione
                isGoing == false;
            }
        }



    }
}

//! Metodo----------

/**
 * *METODO 1
 * Metodo per l'eliminazione di una cartella (se possibile)
 * @param path path della cartella
 */
void eliminaCartella(std::string path){
    if(fsys::exists(path)){
        try{
            fsys::remove(path);
            std::cout << "Cartella: " << path << " || Eliminata con successo";
        }
        catch (const fsys::filesystem_error& e){
            std::cout << "Cartella: " << path << " || Problema con l'eliminazione";
        }
    }
    else{
        std::cout << "Cartella: " << path << " || Non esiste";
    }
}

/**
 * *METODO 2
 * Metodo per l'eliminazione dentro una cartella (se possibile)
 * @param path Path della cartella
 */
void eliminaDentroCartella(std::string path){
    if(fsys::exists(path)){
        for(const auto file : fsys::directory_iterator(path)){
            try{
                fsys::remove(file.path());
                std::cout << "File: " << file.path() << " || Eliminato con successo";
            }
            catch (const fsys::filesystem_error& e){
                std::cout << "File: " << file.path() << " || Problema con l'eliminazione";
            }
        }
    }
    else{
        std::cout << "Cartella: " << path << " || Non esiste";
    }
}

/**
 * *METODO 3
 * Metodo per rinominare una cartella (se possibile)
 * @param path Path della cartella
 * @param nome Nome con cui rinominare
 */
void rinominaCartella(std::string path, std::string nome){
    if(fsys::exists(path)){
        try{
            fsys::rename(path, nome);
            std::cout << "Cartella: " << path << " || Rinominata con successo";
        }
        catch (const fsys::filesystem_error& e){
            std::cout << "Cartella: " << path << " || Problema con la rinominazione";
        }
    }
    else{
        std::cout << "Cartella: " << path << " || Non esiste";
    }
}

/**
 * *METODO 4
 * Metodo per rinominare dentro una cartella (se possibile)
 * @param path Path della cartella
 * @param nome Nome con cui rinominare
 */
void rinominaDentroCartella(std::string path, std::string nome){
    if(fsys::exists(path)){
        for(const auto file : fsys::directory_iterator(path)){
            try{
                fsys::rename(file.path(), nome);
                std::cout << "File: " << file.path() << " || Rinominato con successo";
            }
            catch (const fsys::filesystem_error& e){
                std::cout << "File: " << file.path() << " || Problema con la rinominazione";
            }
        }
    }
    else{
        std::cout << "Cartella: " << path << " || Non esiste";
    }
}
