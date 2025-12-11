#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Mano.h"
#include "Apuesta.h"

class Jugador {
    private:
        std::string nombre_jugador;
        int fichas;
        Mano mano;
        Apuesta apuesta_actual;

    public:
        //constructor
        Jugador(const std::string& nj, int saldo_inicial);
        
        //getters
        std::string getNombreJugador() const { return nombre_jugador; }
        int getFichas() const                { return fichas; }
        const Apuesta& getApuesta() const    { return apuesta_actual; }
        const Mano& getMano() const          { return mano; }
        
        int getValorMano() const             { return mano.obtenerValorTotal(); }
        bool estaPasado() const              { return mano.estaPasado(); }
        bool tieneBlackjack() const          { return mano.esBlackjack(); }

        //metodos
        void tomarCarta(const Carta& carta);
        void limpiarMano();
        void mostrarMano() const;
        bool quiereCarta() const;

        void realizarApuesta(int monto);
        void resolverVictoria();
        void resolverBlackjack();
        void resolverEmpate();
        void resolverPerdida();
};

#endif //JUGADOR_H