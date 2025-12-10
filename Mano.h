#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"
#include <iostream>

class Mano{
    private:
        std::vector<Carta> cartas;

    public:
        //Constructor
        Mano();

        //Getters
        const std::vector<Carta>& getCartas() const { return cartas; }

        //Metodo
        void agregarCarta(const Carta& carta);
        int obtenerValorTotal() const; //Metodo para el valor total que tiene la mano/mazo del jugador.
        bool estaPasado() const; //Verificacion si el jugador se ha pasado de 21.
        bool esBlackJack() const; //Metodo para verificar si el jugador tiene un As y 10 o J,Q,K.
        void limpiarMano(); //Metodo para borrar las cartas e iniciar una ronda.
};

#endif //MANO_H