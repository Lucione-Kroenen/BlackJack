#ifndef CRUPIER_H
#define CRUPIER_H

#include "Mano.h"
#include "Baraja.h"

class Crupier{
    private:
        Mano mano_crupier;
        Baraja baraja_de_juego;

    public:
        //Constructor
        Crupier();

        //Metodos de gestion Baraja
        void inicializarJuego();
        Carta repartirCarta();

        //Metodos de juego
        void tomarCarta(const Carta& carta);
        void jugarTurnoCrupier();
        void limpiarMano();
        
        int obtenerTotalCartasMano() const;
        int obtenerTotalCartasBaraja() const;
        bool estaPasado() const;
        bool tieneBlackjack() const;

        //Metodos de Visualización
        void mostrarCartas() const;

        //Getters
        int getValorMano() const;
        const Mano& getMano() const { return mano_crupier; }
};

#endif //CRUPIER_H