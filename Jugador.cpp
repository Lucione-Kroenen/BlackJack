#include "Jugador.h"
#include <iostream>
#include <limits>

Jugador::Jugador(const std::string& nj, int saldo_inicial) : nombre_jugador(nj), fichas(saldo_inicial), apuestaActual(0) {}

std::string Jugador::obtenerNombre() const {
    return nombre_jugador;
}

int Jugador::obtenerFichas() const {
    return fichas;
}

int Jugador::obtenerApuestaActual() const {
    return apuesta_actual;
}

void Jugador::limpiarMano() {
    mano.limpiarMano();
}

void Jugador::resetApuesta(){
    apuesta_actual = 0; 
}

void Jugador::tomarCarta(const Carta& carta) {
    mano.agregarCarta(carta);
}

void Jugador::mostrarMano() const {
    std::cout << "\n--- Mano de " << nombre_jugador << " ---" << std::endl;    
    for (const carta& carta : mano.obtenerCartas()) {
    std::cout << "  - " << carta.describirCarta() << std::endl;    
    }
    std::cout << "Total: " << mano.obtenerValorTotal() << std::endl;
}

bool Jugador::quiereCarta() const {
    char opcion;
    std::cout << nombre_jugador << ", ¿quieres otra carta? (s/n): ";
    if (!(std::cin >> opcion)) {

    // Limpiar buffer de entrada en caso de entrada inválida
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return false;
}

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

return (opcion == 's' || opcion == 'S');

}