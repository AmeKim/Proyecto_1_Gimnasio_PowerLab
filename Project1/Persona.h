#pragma once
#include <iostream>
#include <string>


/*cédula de identidad, nombre completo,  
teléfono de contacto, correo electrónico,
fecha de nacimiento, 

sexo, fecha de inscripción, entre otros más.*/

/*número de cédula, nombre completo,
teléfono, correo, fecha de nacimiento,
y una o varias de las siguientes especialidades:
CrossFit, HIIT, TRX, Pesas, spinning, Cardio, Yoga,
Zumba (un instructor puede tener más de una especialidad). */
using namespace std;

class Persona {
private:
	string nombre;
	string cedula;
	int numeroT;
	string correo;
	int fechaN[3];// dia, mes, año
public:
	Persona(string ="", string ="", int =0, string ="", int =0, int =0, int =0);
	void setNombre(string nom);
	string getNombre();
	void setCedula(string ced);
	string getCedula();
	void setNumeroT(int numT);
	int getNumeroT();
	void setCorreo(string cor);
	string getCorreo();
	void setFechaN(int dia, int mes, int annio);
	int getDia();
	int getMes();
	int getAnnio();
	void mostrarDatos();
	~Persona();
};