#pragma once
#include <iostream>
#include <string>


/*c�dula de identidad, nombre completo,  
tel�fono de contacto, correo electr�nico,
fecha de nacimiento, 

sexo, fecha de inscripci�n, entre otros m�s.*/

/*n�mero de c�dula, nombre completo,
tel�fono, correo, fecha de nacimiento,
y una o varias de las siguientes especialidades:
CrossFit, HIIT, TRX, Pesas, spinning, Cardio, Yoga,
Zumba (un instructor puede tener m�s de una especialidad). */
using namespace std;

class Persona {
private:
	string nombre;
	string cedula;
	int numeroT;
	string correo;
	int fechaN[3];// dia, mes, a�o
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