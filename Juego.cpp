#include "Juego.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Juego::Juego(const std::string& nombre_jugador)
    : partida_activa(false) {
        jugadores.emplace_back(nombre_jugador, 1000);
        crupier.inicializarJuego();

        std::cout << "=== Bienvenido al Blackjack, " << nombre_jugador << " ===" << std::endl;
        std::cout << "Tienes 1000 fichas para empezar." << std::endl;
    }

//Verificar la baraja, si quedan menos de 10 cartas, reinicia el mazo
void Juego::verificarEstadoBaraja() {
    if (crupier.obtenerTotalCartasBaraja() < 10) {
        cout << "\n[MANTENIMIENTO] Quedan pocas cartas. Reiniciando y mezclando la baraja..." << endl;
        crupier.inicializarJuego();
    }
}

void Juego::iniciarRonda() {
    if (jugadores.empty()) return;

    Jugador& jugador = jugadores[0];

    //Limpiar mesa
    crupier.limpiarMano();
    jugador.limpiarMano();

    //Pedir apuesta
    int apuesta_monto = 0;
    cout << "\n=== NUEVA RONDA ===" << endl;
    cout << jugador.getNombreJugador() << ", tienes " << jugador.getFichas() << " fichas. ¿Cuanto deseas apostar? ";

    while(!(cin >> apuesta_monto) || apuesta_monto <= 0 || apuesta_monto > jugador.getFichas()) {
        cout << "Apuesta invalida. Introduce un monto valido (max " << jugador.getFichas() << "): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    try {
        jugador.realizarApuesta(apuesta_monto);
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return;
    }

    repartirCartasIniciales();
}

void Juego::repartirCartasIniciales() {
    Jugador& jugador = jugadores[0];

    //Repatir 2 cartas a cada uno (Jugador -> Crupier -> Jugador -> Crupier -> ...)

    //La primera carta la recibe el jugador
    jugador.tomarCarta(crupier.repartirCarta());

    //La primera carta la recibe el crupier y la mostrara.
    crupier.tomarCarta(crupier.repartirCarta());

    //Segunda carta que recibe el jugador
    jugador.tomarCarta(crupier.repartirCarta());
    
    //Segunda carta que recibe el crupier pero esta no se mostrara
    //Se mostrara con el metodo mostrarMesa()
    crupier.tomarCarta(crupier.repartirCarta());

    cout << "\n=== CARTAS REPARTIDA ===" << endl;
    jugador.mostrarMano();

    cout << "Mano del crupier: " << crupier.getMano().getCartas()[0].describirCarta() << " y una carta OCULTA." << endl;
}

void Juego::jugarTurnoJugador(Jugador& jugador) {
    cout << "\n=== TURNO DE " << jugador.getNombreJugador() << " ===" << endl;

    while (jugador.quiereCarta() && !jugador.estaPasado()) {
        Carta nueva_carta = crupier.repartirCarta();
        jugador.tomarCarta(nueva_carta);

        cout << jugador.getNombreJugador() << " pide carta: " << nueva_carta.describirCarta() << endl;

        jugador.mostrarMano();

        if (jugador.estaPasado()) {
            cout << jugador.getNombreJugador() << " Se ha pasado de 21 (" << jugador.getValorMano() << ") PIERDE la ronda." << endl;
            break;
        }
    }
}

void Juego::ejecutarLoopPrincipal() {
    partida_activa = true;

    while (partida_activa && !jugadores.empty()) {
        Jugador& jugador = jugadores[0];

        if (jugador.getFichas() <= 0) {
            cout << "\n Te quedaste sin fichas. Fin del juego." << endl;
            partida_activa = false;
            break;
        }

        verificarEstadoBaraja();

        iniciarRonda();

        if (jugador.getApuesta().getMonto() == 0) {
            continue;
        }

        if (jugador.tieneBlackjack()) {
            cout << "\nBLACKJACK INSTANTANEO" << endl;
            if (crupier.tieneBlackjack()) {
                cout << "El crupier tambien tiene blackjack. EMPATE" << endl;
                crupier.mostrarCartas();
                jugador.resolverEmpate();
            } else {
                cout << "El crupier NO tiene blackjack !GANASTE con blackjack" << endl;
                crupier.mostrarCartas();
                jugador.resolverBlackjack();
            }

            mostrarApuestasYSaldo();

            if (!preguntarSiContinuar()) {
                partida_activa = false;
                break;
            }

            continue;
        }

        jugarTurnoJugador(jugador);

        if (jugador.estaPasado()) {
            mostrarResultados();
            jugador.resolverPerdida();
            mostrarApuestasYSaldo();
            
            if (!preguntarSiContinuar()) {
                partida_activa = false;
                break;
            }

            continue;
        }

        jugarTurnoCrupier();

        mostrarResultados();

        resolverRonda();

        mostrarApuestasYSaldo();

        if (!preguntarSiContinuar()) {
            partida_activa = false;
            break;
        }
    }

    //Mensaje de despedida.
    cout << "\n=== FIN DEL JUEGO ===" << endl;
    if (!jugadores.empty()) {
        Jugador& jugador = jugadores [0];
        cout << jugador.getNombreJugador() << ", terminaste con " << jugador.getFichas() << " fichas." << endl;
        
        if (jugador.getFichas() > 1000) {
            cout << "FELICIDADES GANASTE " << (jugador.getFichas() - 1000) << " fichas." << endl;   
        } else if (jugador.getFichas() < 1000) {
            cout << "Perdiste " << (1000 - jugador.getFichas()) << " fichas." << endl;
        } else {
            cout << "Terminaste con el mismo saldo inicial." << endl;
        }
    }

    cout << "Gracias por jugar." << endl;
}

bool Juego::preguntarSiContinuar() {
    char respuesta;
    cout << "\nQuieres jugar otra ronda? (s/n): ";

    while (true) {
        if (cin >> respuesta) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (respuesta == 's' || respuesta == 'S') {
                return true;
            } else if (respuesta == 'n' || respuesta == 'N') {
                return false;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Respuesta invalida. Ingresa 's para continuar o 'n' para salir: ";
    }
}

void Juego::jugarTurnoCrupier() {
    cout << "\n=== TURNO DEL CRUPIER ===" << endl;
    crupier.mostrarCartas();
    crupier.jugarTurnoCrupier();
    crupier.mostrarCartas();
}

void Juego::resolverRonda() {
    Jugador& jugador = jugadores[0];

    //Si el jugador se paso, pierde
    if (jugador.estaPasado()) {
        jugador.resolverPerdida();
        return;
    }

    //Si el crupier pierde, el jugador gana
    if (crupier.estaPasado()) {
        if(jugador.tieneBlackjack()) {
            jugador.resolverBlackjack();
        } else {
            jugador.resolverVictoria();
        }
        return;
    }

    int valor_jugador = jugador.getValorMano();
    int valor_crupier = crupier.getValorMano();

    if (valor_jugador > valor_crupier) {
        if (jugador.tieneBlackjack() && !crupier.tieneBlackjack()) {
            jugador.resolverBlackjack();
        } else {
            jugador.resolverVictoria();
        }
    } else if (valor_jugador < valor_crupier) {
        jugador.resolverPerdida();
    } else {
        jugador.resolverEmpate();
    }
}

void Juego::limpiarRonda() {
    crupier.limpiarMano();
    for (Jugador& jugador : jugadores) {
        jugador.limpiarMano();
    }
}

void Juego::mostrarResultados() const {
    cout << "\n=== RESULTADO FINAL ===" << endl;
    const Jugador& jugador = jugadores[0];
    jugador.mostrarMano();
    crupier.mostrarCartas();
}

void Juego::mostrarApuestasYSaldo() const {
    const Jugador& jugador = jugadores[0];
    cout << "\nSaldo actual: " << jugador.getFichas() << " fichas" << endl;
}
