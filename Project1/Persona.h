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
    string telefono;
    string correo;
    Fecha* fechaNacimiento;

public:
    // Constructores
    Persona(string nombre, string cedula, string telefono, string correo, int dia, int mes, int anio);
    Persona(string nombre, string cedula, string telefono, string correo, const Fecha& fecha);
    Persona(string nombre, string cedula, string telefono, string correo, const string& fechaStr);
    Persona();
    virtual ~Persona();

    // Getters
    string getNombre() const;
    string getCedula() const;
    string getTelefono() const;
    string getCorreo() const;
    Fecha* getFechaNacimiento() const;
    int getEdad() const;

    // Setters
    void setNombre(string nombre);
    void setCedula(string cedula);
    void setTelefono(string telefono);
    void setCorreo(string correo);
    void setFechaNacimiento(const Fecha& fecha);
    void setFechaNacimiento(int dia, int mes, int anio);
    void setFechaNacimiento(const string& fechaStr);

    // M�todos virtuales
    virtual string toString();
};