#include <iostream>
#include <string>

using namespace std;

//Non serve che abbia lo stesso nome del file
class Bici{
private:

    string marca;
    string modello;
    int prezzo;


public:

    //Costruttore
    Bici(string marca, string modello, int prezzo){
        this->marca = marca;
        this->modello = modello;
        this->prezzo = prezzo;
    }

    //Getters
    string getMarca(){return marca;}
    string getModello(){return modello;}
    int getPrezzo(){return prezzo;}

    //Setters
    void setPrezzo(int prezzo){this->prezzo = prezzo;}

    //Metodo
    void stampaBici(){
        cout << "Marca: " << marca << " Modello: " << modello << " Prezzo: " << prezzo;
    }

};

void stampaArrayBici(Bici biciclette[], int prezzo){
    for(Bici bicicletta : biciclette[]){
        if(bicicletta.getPrezzo() < prezzo){
            bicicletta.stampaBici();
        }
    }
}

bool trovaBici(Bici bici, Bici biciclette[]){
    bool isIn = false;
    for(Bici bicicletta : biciclette[]){
        if(bici.getMarca() == bicicletta.getMarca()  &&  bici.getModello() == bici.getModello() && bici.getPrezzo() == bici.getPrezzo()){
            isIn = true;
            break;
        }
    }
    return isIn;
}


int main(){
    Bici a = Bici("a", "a", 1000);
    
    Bici biciclette[] = {
        Bici("a", "a", "1000"),
        Bici("h", "d", "54"),
        Bici("a", "h", "13120"),

    }
}