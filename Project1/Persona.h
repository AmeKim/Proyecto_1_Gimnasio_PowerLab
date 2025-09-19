#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Fecha.h"
using namespace std;


/*c�dula de identidad, nombre completo,  
tel�fono de contacto, correo electr�nico,
fecha de nacimiento, 

sexo, fecha de inscripci�n, entre otros m�s.*/

/*n�mero de c�dula, nombre completo,
tel�fono, correo, fecha de nacimiento,
y una o varias de las siguientes especialidades:
CrossFit, HIIT, TRX, Pesas, spinning, Cardio, Yoga,
Zumba (un instructor puede tener m�s de una especialidad). */

class Persona {
protected:
    string nombre;
    string cedula;
    int numeroT;
    string correo;
    Fecha fechaNacimiento; // Ahora usa la clase Fecha

public:
    // Constructores
    Persona(string nom, string ced, int numT, string cor, int dia, int mes, int anio);
    Persona(string nom, string ced, int numT, string cor, const Fecha& fecha);
    Persona(string nom, string ced, int numT, string cor, const string& fechaStr);

    // Destructor virtual para herencia
    virtual ~Persona();

    // Setters
    void setNombre(string nom);
    void setCedula(string ced);
    void setNumeroT(int numT);
    void setCorreo(string cor);
    void setFechaNacimiento(int dia, int mes, int anio);
    void setFechaNacimiento(const Fecha& fecha);
    void setFechaNacimiento(const string& fechaStr);

    // Getters
    string getNombre() const;
    string getCedula() const;
    int getNumeroT() const;
    string getCorreo() const;
    Fecha getFechaNacimiento() const;
    int getEdad() const; // Calcula edad autom�ticamente

    // Getters espec�ficos de fecha
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    virtual void mostrarDatos();
    virtual string toString();
};