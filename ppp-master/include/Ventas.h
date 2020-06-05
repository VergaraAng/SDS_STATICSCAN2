#ifndef VENTAS_H
#define VENTAS_H
#include <string>
#include <Empleado.h>


class Ventas : public Empleado
{
    public:
        Ventas();
        Ventas(int, string, int, float, int);
        void Setid();
        int Getsales() { return sales; }
        void Setsales();
        float calculateSalary();
        void Imprimir();
    protected:

    private:
        float sales;
};

#endif // VENTAS_H
