#include "Mano.h"

Mano::Mano() {}

int Mano::obtenerValorTotal() const {
    int valor_total = 0;
    int contador_ases = 0;

    for (const Carta& carta: cartas) {

        int valor = carta.obtenerValorFijo();
        if (valor == 11) {
            contador_ases ++;
        }
        valor_total += valor;
    }

    while (valor_total > 21 && contador_ases > 0){
        valor_total -= 10;
        contador_ases --;
    }
    
    return valor_total;
}

bool Mano::estaPasado() const {
    return obtenerValorTotal() > 21;
}

bool Mano::esBlackjack() const {
    return (obtenerValorTotal() == 21) && (cartas.size() == 2);
}

void Mano::agregarCarta(const Carta& carta) {
    cartas.push_back(carta);
}

void Mano::limpiarMano() {
    cartas.clear();
}