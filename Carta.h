#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
    private:
        std::string rango; //string ya que necesitamos poner el "As", "2", "J"/"K"
        std::string familia_carta; //Las familias son: diamantes, corazones, picas y trovoles
        

    public:
        //Constructor
        Carta(const std::string& r, const std::string& f); //r: rango, f: familiaCarta
        
        //Getters
        std::string getRango() const        { return rango; }
        std::string getFamiliaCarta() const { return familia_carta; }

        //Metodos
        std::string describirCarta() const; //"Traducir" el numero de las cartas y su familia a texto para mejor legibilidad
        int obtenerValorFijo() const; //Obtener el valor de las cartas como J, Q y K, el valor de esas cartas es 10
    
};

#endif //CARTA_H