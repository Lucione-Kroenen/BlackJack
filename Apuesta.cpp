#include "Apuesta.h"


Apuesta::Apuesta(int monto_inicial)
    : monto(monto_inicial){}

int Apuesta::obtenerMonto() const {
    return monto;
}


float Apuesta::ganancias(float multiplicador) const {

    if (multiplicador < 0.0f) {

        return -static_cast<float> (monto);
    }

    else {
        return static_cast<float>(monto) * multiplicador;
    
    }

}

void Apuesta::resultadoApuesta () {

}
