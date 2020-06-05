#ifndef ECONFIANZA_H
#define ECONFIANZA_H

#include <Empleado.h>


class EConfianza : public Empleado
{
    public:
        EConfianza();
        EConfianza(int, string, int, float);
        void Setid();

    protected:

    private:
};

#endif // ECONFIANZA_H
