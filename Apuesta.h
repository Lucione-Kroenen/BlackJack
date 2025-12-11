#ifndef APUESTA_H
#define APUESTA_H

#include <stdexcept>
class Apuesta{
    private:
        int monto;
        bool esta_activa;

    public:
        //Constructor
        Apuesta();
        
        void realizar(int monto_apostado);
        void cancelar();

        int calcularGananciaBlackjack() const;
        int calcularGananciaVictoria() const;
        int calcularEmpate() const;
        int calcularPerdida() const;

        static bool esMontoValido(int monto, int fichas_disponibles);

        //Getters
        int getMonto()       const { return monto; }
        bool getEstaActiva() const { return esta_activa; }
};

#endif //APUESTA_H