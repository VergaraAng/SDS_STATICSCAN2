#define _GLIBCXX_USE_CXX11_ABI 0
#include "Empleado.h"
#include<iostream>
#include<exception>
#include<stdexcept>
#include<ios>
#include<typeinfo>
#include<limits>
#include<regex>
#include<cmath>



Empleado::Empleado()
{
    cout << "\nIngrese su nombre completo:\n";
    (*this).Setname();
    cout << "\nIngrese los a�os de antiguedad del trabajador:\t ";
    (*this).Setyears();
    cout << "\nIngrese el salario base de el empleado:\t ";
    (*this).Setsalary();
}

float Empleado::calculateSalary()
{
    return salary;
}

void Empleado::Imprimir()
{
    cout << "\nID del empleado: " << id;
    cout << "\nNombre del empleado: " << name;
    cout << "\nAnios de experiencia del empleado: " << years;
    cout << "\nSalario del empleado: " << Empleado::calculateSalary();
}

int Empleado::validacionInt()
{
    int var;
    cin.exceptions(ios::failbit | ios::badbit);
    try
    {
//        cout<<"Ingrese dato\n";
        cin >> var;
        string error = "Error, dato no puede ser negativo\n";
        if(var < 0)
            throw error;
    }

    catch(ios_base::failure& e)
    {
        cout <<e.what()<<" Dato no valido, ingrese de nuevo\n";
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        return Empleado::validacionInt();
    }

    catch(string error)
    {
        cout << error << endl;
        return Empleado::validacionInt();
    }
    return var; //! este es igual a set id y al set years
}

string Empleado::LeerCadena(string dato)
{

    //! Se valida el string para nombre, apellido paterno y materno
    //! No puede ser mayor a 255 caracteres ni contener caracteres que no sean letras

    string cadena;
    string errorChar="Error: dato ingresado incorrecto";
    string errorTam="Error: solo se aceptan hasta 255 caract�res";

    if(dato!="e")
    {
        cout << "\nIngrese  "+dato+":\t";
    }
    cin >> cadena;
    cin.ignore(256,'\n');
    string subject(cadena);
    try
    {
        regex rgx("[^A-Za-z]");
        smatch match;
        if (cadena.size()>255)
        {
            throw errorTam;
        }
        if (regex_search(subject, match, rgx))
        {
            throw errorChar;
        }
    }
    catch (regex_error& e)
    {
        // Syntax error in the regular expression
    }
    catch (string e)
    {
        cout << e << endl;
        return LeerCadena(dato);
    }
    catch(...)
    {
        cout << "Error inesperado";
        return LeerCadena(dato);
    }

    return cadena;
}

float Empleado::validacionFloat()
{
    float var;
    cin.exceptions(ios::failbit | ios::badbit);
    try
    {
        cin >> var;
        string error = "Error, dato no puede ser negativo\n";
        if(var < 0)
            throw error;
    }

    catch(ios_base::failure& e)
    {
        cout <<" Dato no valido, ingrese de nuevo\n";
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        return Empleado::validacionInt();
    }

    catch(string error)
    {
        cout << error << endl;
        return Empleado::validacionInt();
    }
    return var;
}

void Empleado::Setname()
{
    string n, ap,am;
    n=Empleado::LeerCadena("nombre");
    ap=Empleado::LeerCadena("apellido paterno");
    am=Empleado::LeerCadena("apellido materno");
    name = n+" "+ap+" "+am;
}

void Empleado::Setyears()
{
    years=Empleado::validacionInt();
}

ostream& operator<<(ostream& out, Empleado &e){
    out << "\nID: " << e.Getid();
    out << "\nNombre completo: " << e.Getname();
    out << "\nSueldo semanal: "<< rint(e.Getsalary())<< "\n";
    return out;
}





