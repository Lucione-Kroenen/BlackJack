#ifndef BARAJA_H
#define BARAJA_H

#include <vector>
#include <string>
#include "Carta.h"


//La clase Baraja es el contenedor de la la clase Carta.
class Baraja {
    private:
        std::vector<Carta> cartas; //Por este medio tendremos en un vector las 52 cartas.

    public:
        //Constructor
        Baraja();

        //Getters
        const std::vector<Carta>& getCartas() const { return cartas; }
        
        //Metodos    
        int obtenerTotalCartas() const; //Ira quitando las cartas de la baraja para que no se repitan.
        void mezclarCartas(); //Originalmente tenia un int pero se cambio a un void ya que solamente vamos a cambiar de orden los elementos.
        Carta repartirCarta(); //Llamamos a clase ya que de ahi se le daran los atributos a la carta
        void inicializarBaraja(); 
};

#endif //BARAJA_H