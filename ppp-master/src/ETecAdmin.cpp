#define _GLIBCXX_USE_CXX11_ABI 0
#include "ETecAdmin.h"
#include <iostream>

ETecAdmin::ETecAdmin():Empleado()
{
    Setbonus();
    Setid();
    calculateSalary();
}

inline const char * const BoolToString(bool b)
{
  return b ? "Si" : "No";
}

void ETecAdmin::Setid()
{
    cout<<"\nIngrese ID: ";
    int var =Empleado::validacionInt();

    try
    {
        string error = "Error, ID debe ser mayor a 7000 y menor a 9000\n";
        if(var <7000 || var >8999){throw error;}
    }
    catch(string error)
    {
        cout << error << endl;
        return ETecAdmin::Setid();
    }
    id = var;
}

float ETecAdmin::calculateSalary()  //!este depende de si van los 6 dias a trabajar y llegan temprano..
{
    int range= 0;

    if(years<5){range=4;}
    if(years>=5 && years<10){range=3;}
    if(years>=10 && years<=20){range=2;}
    if(years>20){range= 1;}

    float tsalary = salary*6; //!es el salario de una semana;

    if(range>0){
        switch(range)
        {
            case 1:salary=tsalary +(tsalary*.25);break;
            case 2:salary=tsalary +(tsalary*.20);break;
            case 3:salary=tsalary +(tsalary*.10);break;
            case 4:salary=tsalary +(tsalary*.05);break;
        }
    }

    return salary;
}

void ETecAdmin::Imprimir()
{
   Empleado::Imprimir();
   cout << "\nBono puntualidad y asistencia: " << BoolToString(Getbonus())<<endl;
}

void ETecAdmin::Setbonus()
{
    bonus =false;
    string b = Empleado::LeerCadena("el empleado tiene asistencia completa? (Si/No)");
    if(b=="Si"||b=="si"||b=="s"||b=="S")
    {
        bonus =true;
    }
}

