#ifndef CRUPIER_H
#define CRUPIER_H

// #include <vector>
#include "Mano.h"
#include "Baraja.h"

class Crupier{
    private:
        Mano mano_crupier;
        Baraja baraja_de_juego;

    public:
        Carta repartirCartas() const;
        void tomarCartas();
        void contarCartas();
        void mostrarCartas() const;

};

#endif //CRUPIER_H