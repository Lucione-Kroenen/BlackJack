#include "Juego.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre;

    cout << "========================================" << endl;
    cout << "        BIENVENIDO AL BLACKJACK         " << endl;
    cout << "========================================" << endl;
    cout << "\nIngresa tu nombre: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        nombre = "Jugador";
    }

    cout << "\nHola, " << nombre << endl;
    cout << "\nPresiona ENTER para comenzar...";
    cin.get();

    try {
        Juego juego(nombre);
        juego.ejecutarLoopPrincipal();
    }
    catch (const exception&e) {
        cerr << "\nERROR CRITICO " << e.what() << endl;
        return 1;
    }

    return 0;
}