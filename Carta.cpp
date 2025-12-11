#include "Carta.h"
#include <string>
#include <stdexcept> //Libreria para manenjar errores y excepciones

Carta::Carta(const std::string& r, const std::string& f)
    : rango(r), familia_carta(f)
    {}

int Carta::obtenerValorFijo() const {
    //Cartas J, Q, K = 10
    if (rango == "J" || rango == "Q" || rango == "K") {
        return 10;
    } 

    //Carta As (1 u 11)
    else if (rango == "As") {
        return 11;
    } 
    
    //Cartas 2 al 10
    else {
        //try-catch para manejar el error si std::stoi falla
        try {
            //Convertir el string en entero usando std::stoi (string to integer)
            return std::stoi(rango);
        }
        catch (const std::exception& e){
            //Si se genera una falla, obtendremos un 0
            return 0;
        }
    }
}

std::string Carta::describirCarta() const {
    std::string simbolo;
    
    if (familia_carta == "Corazones") {
        simbolo = "♥";
    } 
    else if (familia_carta == "Diamantes") {
        simbolo = "♦";
    } 
    else if (familia_carta == "Picas") {
        simbolo = "♠";
    } 
    else if (familia_carta == "Treboles") {
        simbolo = "♣";
    }
    else {
        //Fallback: si la familia no se reconoce, usar el texto
        return rango + " de " + familia_carta;
    }
    
    return rango + simbolo;
}