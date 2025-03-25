#include <iostream>

void Es2(char carattere);
void Es3(char carattere, int numero);

int main(){
    std::cout << "Es 2-----> \n\n";
    Es2('*');

    std::cout << "Es 3-----> \n\n";
    Es3('*', 5);

    return 0;
}

void Es2(char carattere){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= i; j++){
            std::cout << carattere;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void Es3(char carattere, int numero){
    for(int i = 1; i <= numero; i++){
        for(int j = 1; j <= i; j++){
            std::cout << carattere;
        }
        std::cout << "\n";
    }

    for(int i = numero; i > 0; i--){
        for(int j = i; j > 0; j--){
            std::cout << carattere;
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

