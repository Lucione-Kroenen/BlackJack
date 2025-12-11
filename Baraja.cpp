#include "Baraja.h"
#include <algorithm>
#include <random>

Baraja::Baraja() {
    inicializarBaraja();
    mezclarCartas();
}


void Baraja::inicializarBaraja() {
    std::vector<std::string> rangos = {"2","3","4","5","6","7","8","9","10","J","Q","K","As"};
    std::vector<std::string> familia_carta = {"Corazones","Picas","Diamantes","Treboles"};
    
    cartas.clear();
    
    for (const std::string& palo : familia_carta){
        for (const std::string& rango : rangos){
            cartas.push_back(Carta(rango, palo));
        }
    }
}

void Baraja::mezclarCartas() {
    //Generador aleatorio usando la hora como semilla(para que sea diferente cada vez)
    //si usamos otro valor diferente a 0 porque sino, generearia algun patron y el jugador podria saber el orden
    std::random_device rd;
    std::default_random_engine generador_aleatorio(rd());
    std::shuffle(cartas.begin(), cartas.end(), generador_aleatorio);
}

Carta Baraja::repartirCarta() {
    if (cartas.empty()) {
        throw std::runtime_error("No se pueden repartir mas cartas, baraja vacia.");
    }
    
    //Obtener la carta superior del mazo (vease como una pila de cartas).
    Carta carta_repartida = cartas.back();
    
    //Eliminar una carta del mazo, remueve el ultimo elemento.
    cartas.pop_back();
    
    //Regresar la carta para el jugador o el cruepier.
    return carta_repartida;
}

int Baraja::obtenerTotalCartas() const {
    return cartas.size(); 
}
