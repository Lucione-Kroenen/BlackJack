#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Mano.h"

class Jugador {
    private:
        std::string nombre_jugador;
        int apuesta;
        std::vector<Mano> mano;

    public:
        //constructor
        Jugador(const std::string& nj, const int& a, const std::vector<Mano>& m);
        
        //getters
        std::string getNombreJugador() const { return nombre_jugador; }
        int getApuesta() const               { return apuesta; }
        std::vector<Mano> getMano() const    { return mano; }

        //metodos
        void tomarCarta();
        void montoApostar();
        int totalCartas();
};

#endif //JUGADOR_H