#include "Crupier.h"
#include <iostream>

Crupier::Crupier() {}

void Crupier::inicializarJuego() {
    baraja_de_juego.inicializarBaraja();
    baraja_de_juego.mezclarCartas();
}

Carta Crupier::repartirCarta() {
    return baraja_de_juego.repartirCarta();
}

void Crupier::tomarCarta(const Carta& carta) {
    mano_crupier.agregarCarta(carta);
}

int Crupier::getValorMano() const {
    return mano_crupier.obtenerValorTotal();
}

void Crupier::jugarTurnoCrupier() {
    while (getValorMano() < 17 ) {
        Carta nueva_carta = repartirCarta();
        tomarCarta(nueva_carta);
    }
}

int Crupier::obtenerTotalCartasMano() const {
    return mano_crupier.getCartas().size();
}

void Crupier::mostrarCartas() const {
    const std::vector<Carta>& mano = mano_crupier.getCartas();

    std::cout << "=== Cartas del Crupier (" << getValorMano() << ") ===" << std::endl;

    for (const Carta& carta : mano) {
        std::cout << " === " << carta.describirCarta() << std::endl;
    }

    std::cout << "====================================" << std::endl;
}

void Crupier::limpiarMano() {
    mano_crupier.limpiarMano();
}

int Crupier::obtenerTotalCartasBaraja() const {
    return baraja_de_juego.obtenerTotalCartas();
}

bool Crupier::estaPasado() const {
    return mano_crupier.estaPasado();
}

bool Crupier::tieneBlackjack() const {
    return mano_crupier.esBlackjack();
}