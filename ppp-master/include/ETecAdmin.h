#ifndef ETECADMIN_H
#define ETECADMIN_H

#include <Empleado.h>


class ETecAdmin : public Empleado
{
    public:
        ETecAdmin();
        ETecAdmin(int, string, int, float, bool);
        void Setid();
        bool Getbonus() { return bonus; }
        void Setbonus();
        float calculateSalary();
        void Imprimir();

    protected:

    private:
        bool bonus;
};

#endif // ETECADMIN_H
