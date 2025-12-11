#include "Apuesta.h"

Apuesta::Apuesta()
    : monto(0), esta_activa(false) {}

void Apuesta::realizar(int monto_apostado) {
    if (monto_apostado <= 0) {
        throw std::invalid_argument("El monto para apostar debe ser mayor a 0.");
    }

    monto = monto_apostado;
    esta_activa = true;
}

void Apuesta::cancelar() {
    monto = 0;
    esta_activa = false;
}

int Apuesta::calcularGananciaVictoria() const {
    if (!esta_activa) {
        throw std::runtime_error("No hay apuesta activa.");
    }
    
    return monto * 2;
}

int Apuesta::calcularGananciaBlackjack() const {
    if (!esta_activa){
        throw std::runtime_error("No hay apuesta activa.");
    }

    return static_cast<int>(monto * 2.5f); //(Apuesta + 1.5x ganacia)
}

int Apuesta::calcularEmpate() const {
    if (!esta_activa) {
        throw std::runtime_error("No hay apuesta activa.");
    }
    return monto;
}

int Apuesta::calcularPerdida() const {
    return 0;
}

bool Apuesta::esMontoValido(int monto, int fichas_disponibles) {
    return (monto > 0) && (monto <= fichas_disponibles);
}