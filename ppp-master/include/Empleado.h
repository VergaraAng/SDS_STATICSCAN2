#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<string>
#include<iostream>

using namespace std;


class Empleado
{
    public:
        //Constructores
        Empleado();
        Empleado(int, string, int, float);

        //Get/sets
        string Getname() { return name; }
        void Setname();
        int Getid() { return id; }
        virtual void Setid()=0;
        int Getyears() { return years; }
        void Setyears();
        float Getsalary() { return salary; }
        void Setsalary() { salary = validacionFloat(); }

        //Funciones de la clase
        virtual float calculateSalary();
        virtual void Imprimir();

        //Funciones para validaciones
        static int validacionInt();
        static float validacionFloat();
        static string LeerCadena(string dato);


        friend std::ostream& operator<<(std::ostream&,  Empleado&);

    protected:
        int id;
        int years;
        float salary;
        string name; //nombre completo
    private:


};



#endif // EMPLEADO_H
