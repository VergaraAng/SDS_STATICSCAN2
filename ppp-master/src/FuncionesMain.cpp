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
     cout<<"\t1) Ver información de todos los empleados\n";
     cout<<"\t2) Ver información de los empleados por departamento\n";
     cout<<"\t3) Calcular nómina\n";
     cout<<"\t4) Salir\n\n";
     cout<<"*****************************************************\n";
}

void MostrarTipoEmpleados(){
     cout<<"\n*****************************************************\n";
     cout<<"                      OPCIONES                       \n";
     cout<<"*****************************************************\n\n";
     cout<<"\t1) Empleados de Ventas\n";
     cout<<"\t2) Empleados Técnicos y Administrativos\n";
     cout<<"\t3) Personal de confianza\n";
     cout<<"\t4) Salir\n\n";
     cout<<"*****************************************************\n";
}

int ValidarOpcionMenu(int lim){
    cout << "\nIngrese opcion del menu\t";
    int opc= Empleado::validacionInt();

   try
    {
        if(opc==0||opc>lim){throw invalid_argument("La opción del menu no es válida.");}

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
        cout << "Se debe de cerrar la aplicación";
    }

    return opc;
}

