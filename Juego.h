#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
#include "Jugador.h"
#include "Crupier.h"

class Juego {
    private:
        Crupier crupier;
        bool partida_activa;
        std::vector<Jugador> jugadores;
        bool preguntarSiContinuar();
        void verificarEstadoBaraja(); //Para mezclar o inicializar si hay pocas cartas.
    
    public:
        Juego(const std::string& nombre_jugador);

        void ejecutarLoopPrincipal(); //Loop contiene rondas

        void iniciarRonda(); //Crea los jugadores, mezclar y repartir
        void repartirCartasIniciales();
        void jugarTurnoJugador(Jugador& jugador);
        void jugarTurnoCrupier();
        void resolverRonda(); //Determinnar el ganador, pagar y cobrar a los jugadores
        void limpiarRonda();

        void mostrarResultados() const;
        void mostrarApuestasYSaldo() const;

};

#endif //JUEGO_H