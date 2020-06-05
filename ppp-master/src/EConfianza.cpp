#include "EConfianza.h"
#include<iostream>

EConfianza::EConfianza()
{
    Setid();
}


void EConfianza::Setid()
{
    cout<<"\nIngrese ID: ";
    int var =Empleado::validacionInt();
    try
    {
        string error = "Error, ID debe ser mayor a 9000\n";
        if(var <9000)
            throw error;
    }

    catch(string error)
    {
        cout << error << endl;
        return Setid();
    }
    id = var;
}

