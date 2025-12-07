#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Baraja.h"
#include "Jugador.h"
#include "Crupier.h"

class Juego {
    private:
        Baraja baraja;
        Crupier crupier;
        std::vector<Jugador> jugadores;
    
    public:
        void inicializarJuego(); //Crea los jugadores, mezclar y repartir
        void resolverRonda(); //Determinnar el ganador, pagar y cobrar a los jugadores
        void iniciarRonda();
        void mostrarResultados() const;

};

#endif //JUEGO_H