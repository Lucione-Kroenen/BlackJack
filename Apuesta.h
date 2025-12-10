#ifndef APUESTA_H
#define APUESTA_H

class Apuesta{
    private:
        int monto;

    public:
        int obtenerMonto() const;
        float ganancias(float multiplicador) const;
        void resultadoApuesta();
};

#endif //APUESTA_H