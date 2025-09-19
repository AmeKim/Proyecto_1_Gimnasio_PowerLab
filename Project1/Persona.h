#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Fecha.h"
using namespace std;


/*cédula de identidad, nombre completo,  
teléfono de contacto, correo electrónico,
fecha de nacimiento, 

sexo, fecha de inscripción, entre otros más.*/

/*número de cédula, nombre completo,
teléfono, correo, fecha de nacimiento,
y una o varias de las siguientes especialidades:
CrossFit, HIIT, TRX, Pesas, spinning, Cardio, Yoga,
Zumba (un instructor puede tener más de una especialidad). */

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
    int getEdad() const; // Calcula edad automáticamente

    // Getters específicos de fecha
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    virtual void mostrarDatos();
    virtual string toString();
};