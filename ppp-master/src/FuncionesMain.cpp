#include <iostream>
#include "FuncionesMain.h"
#include "Empleado.h"
#include <fstream>
#include <vector>
using namespace std;


void MostrarMenuPrincipal(){
     cout<<"\n*****************************************************\n";
     cout<<"                    MENU PRINCIPAL                     \n";
     cout<<"*****************************************************\n\n";
     cout<<"\t1) Ver informaci�n de todos los empleados\n";
     cout<<"\t2) Ver informaci�n de los empleados por departamento\n";
     cout<<"\t3) Calcular n�mina\n";
     cout<<"\t4) Salir\n\n";
     cout<<"*****************************************************\n";
}

void MostrarTipoEmpleados(){
     cout<<"\n*****************************************************\n";
     cout<<"                      OPCIONES                       \n";
     cout<<"*****************************************************\n\n";
     cout<<"\t1) Empleados de Ventas\n";
     cout<<"\t2) Empleados T�cnicos y Administrativos\n";
     cout<<"\t3) Personal de confianza\n";
     cout<<"\t4) Salir\n\n";
     cout<<"*****************************************************\n";
}

int ValidarOpcionMenu(int lim){
    cout << "\nIngrese opcion del menu\t";
    int opc= Empleado::validacionInt();

   try
    {
        if(opc==0||opc>lim){throw invalid_argument("La opci�n del menu no es v�lida.");}

    }
    catch(invalid_argument& ia)
	{
        cout << ia.what()<<"\n";
        return ValidarOpcionMenu(lim);
	}
	catch(exception& e)
	{
        cout << "Hubo un error\n Intente de nuevo: \n";
        return ValidarOpcionMenu(lim);
    }
    catch(...){
        cout << "Se debe de cerrar la aplicaci�n";
    }

    return opc;
}

