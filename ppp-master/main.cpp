#include <iostream>
#include <vector>
#include <fstream>
#include <locale.h>
#include <Empleado.h>
#include <Ventas.h>
#include <ETecAdmin.h>
#include <EConfianza.h>
#include "FuncionesMain.h"
#include <cmath>


using namespace std;

typedef vector< vector<int> > Matrix;

void calcuNom(Matrix& m,float s){

	int salaryTemp = rint(s);

    //!Calculamos la cantidad de billetes de la matriz
        int M=m.size();
        //int N=m[0].size();
        for(int i=0; i<M; i++){
             if(salaryTemp>=m[i][0]){
                m[i][1] = salaryTemp/m[i][0];  //Obtenemos la cantidad de billetes de la denominacion en el espacio i
                salaryTemp =salaryTemp%m[i][0];
            }
        }
	}


void ImprimirNominaArchivo(Matrix& m, long nominaF, Empleado* e[], int tam){
     int M=m.size();
     ofstream of("NominaSemanal.txt");
        of<<"\n*********************************************\n";
        of<<"                   Nomina                       \n";
        of<<"*********************************************\n";
         of<<"\nResumen empleados  :\n";
        //of<<"\nSu saldo inicial : $"<<(double)saldoInicial/100<<endl;
         for(int i = 0; i < tam; i++){
                of  <<  *(e[i]);
            }
        of<<"\nNomina de la empresa : $"<<nominaF<<endl;
        of<<"\nBilletes a entregar:\n\n";
        for(int i=0; i<M; i++){
            // en el array denominacion :   0-5 billetes  6-10 monedas
            //Se valida si es billete o moneda o centavo , en singular o plural para imprimir con formato
             switch(m[i][1]){
                case 0:break;
                //singular
                case 1:
                     if(i>5){ of <<"\t"<<m[i][1]<<" moneda   de $"<<m[i][0]<<endl;}
                     else{of <<"\t"<<m[i][1]<<" billete  de $"<<m[i][0]<<endl;}
                     break;
                default:
                     //plural
                    if(i>5){of <<"\t"<<m[i][1]<<" monedas  de $"<<m[i][0]<<endl;}
                    else{of <<"\t"<<m[i][1]<<" billetes de $"<<m[i][0]<<endl;}
                    break;
             }
        }

}


int main(){

     Matrix m =  {
    {1000,0},{500,0},
    {200,0},{100,0},
    {50,0},{20,0},
    {10,0},{5,0},
    {2,0},{100,0}
    };

    setlocale(LC_ALL, "Spanish");

    //! Se piden numero de empleados
    cout << "Ingrese el numero de empleados\t";
    int tam= Empleado::validacionInt();

    //!Se crea el arreglo
    Empleado *empls[tam];

    //!Se llena el arreglo
    for(int i = 0; i < tam; i++){
            cout<< "\n\nIndique el tipo de empleado a registrar";
            cout<< "\n\t1- Empleado de ventas \n\t2- Empleado Tecnico y Adm.\n\t3- Empleado de Confianza";
            int opc= ValidarOpcionMenu(3);

            switch(opc){
                case 1:empls[i] = new Ventas();break;
                case 2:empls[i] = new ETecAdmin();break;
                case 3:empls[i] = new EConfianza();break;
        }
    }

    //!Se muestra menu principal
    bool reg = false;
    long nominaF=0;


    do{
        MostrarMenuPrincipal();
        reg = true;
        switch(ValidarOpcionMenu(4)){
        case 1:
            for(int i = 0; i < tam; i++){
            empls[i]->Imprimir();
            }
            break;
        case 2:
            int filter;
            MostrarTipoEmpleados();
            filter= ValidarOpcionMenu(4);
            if(filter==4){break;}
            for(int i = 0; i < tam; i++){
                int range = 0;

                if(empls[i]->Getid()>=9000){range = 3;}
                if(empls[i]->Getid()>=7000 && empls[i]->Getid()<=8999){range = 2;}
                if(empls[i]->Getid()>=5000 && empls[i]->Getid()<=6999){range = 1;}

                if(range==filter){
                     empls[i]->Imprimir();
                }
            }
            break;
        case 3:

            for(int i = 0; i < tam; i++){
                calcuNom(m,empls[i]->Getsalary());
                nominaF+=empls[i]->Getsalary();
            }
            ImprimirNominaArchivo(m,nominaF,empls,tam);
            break;
        case 4:
            reg=false;
        }


    }while(reg);

     delete []empls;

}
