#include "Ventas.h"
#include<iostream>
#include<exception>
#include<stdexcept>
#include<ios>
#include<typeinfo>
#include<limits>

Ventas::Ventas():Empleado()
{
    Setid();
    Setsales();
    calculateSalary();
}

void Ventas::Setid()
{
    cout<<"\nIngrese ID:\t";
    int var = validacionInt();
    try
    {

        string error = "Error, ID debe ser mayor a 5000 y menor a 7000\n";
        if(var <5000 || var >6999)
            throw error;
    }

    catch(string error)
    {
        cout << error << endl;
        return Ventas::Setid();
    }
    id = var;
}

void Ventas::Setsales()
{
    cout<<"\nIngrese las ventas hechas por el empleado\t";
    sales = Empleado::validacionFloat();
}

float Ventas::calculateSalary()
{
    int range = 0;

    if(sales>25000){range = 3;}
    if(sales <= 25000){range = 2;}
    if(sales >= 5000 && sales <= 10000){range = 1;}

    if(range>0){
        switch(range){
            case 1:salary = salary + sales*.10;break;
            case 2:salary = salary + sales*.20;break;
            case 3:salary = salary + sales*.25;break;
        }
    }
    return salary;
}

void Ventas::Imprimir()
{
    Empleado::Imprimir();
    cout << "\nVentas: " << sales <<endl;
}
