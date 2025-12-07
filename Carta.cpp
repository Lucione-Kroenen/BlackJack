#include "Carta.h"
#include <string>
#include <stdexcept> //Libreria para manenjar errores y excepciones

Carta::Carta(const std::string& r, const std::string& f)
    : rango(r), familia_carta(f)
    {}