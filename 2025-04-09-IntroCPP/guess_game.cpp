/*
Juego de adivinar un numero

Tener un numero
Preguntar al usuario el numero
Informar si lo adivino o no

*/

#include <iostream>

int main(void) {

    const int NUM = 10;
    int guessed_number;
    std::cout << "Adivina un numero entre 1 y 100:\n";
    std::cin >> guessed_number;
    
    if (guessed_number == NUM) {
        std::cout << "GANASTE!!!!\n";
    } else if (guessed_number > NUM){
        std::cout << "Te pasaste.\n";
    } else { // es menor
        std::cout << "Te falta.\n";
    }

    return 0;
}