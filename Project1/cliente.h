#include <iostream>
#include <string>
#include <sstream>
#include "reporteM.h"
#include "Rutina.h"
using namespace std;

class cliente {
private:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    string fechaNacimiento;
    string sexo;
    string fechaInscripcion;
    string cedulaInstructor;
    reporteM** mediciones;
    int canMediciones;
    int maxMediciones;
    Rutina* rutinaActual;

public:
    cliente();
    cliente(const string& nombre, const string& cedula, const string& telefono,
        const string& correo, const string& fechaNacimiento,
        const string& sexo, const string& fechaInscripcion);
    ~cliente();

    // Getters
    string getNombre() const;
    string getCedula() const;
    string getTelefono() const;
    string getCorreo() const;
    string getFechaNacimiento() const;
    string getSexo() const;
    string getFechaInscripcion() const;
    string getCedulaInstructor() const;
    int getCanMediciones() const;
    Rutina* getRutinaActual() const;

    // Setters
    void setNombre(const string& nombre);
    void setCedula(const string& cedula);
    void setTelefono(const string& telefono);
    void setCorreo(const string& correo);
    void setFechaNacimiento(const string& fechaNacimiento);
    void setSexo(const string& sexo);
    void setFechaInscripcion(const string& fechaInscripcion);
    void setCedulaInstructor(const string& cedula);

    // Métodos para mediciones
    bool agregarMedicion(reporteM* medicion);
    reporteM* getMedicion(int indice) const;
    string historialMediciones() const;
    void mostrarHistorialMediciones() const;

    // Métodos para rutina
    void asignarRutina(Rutina* rutina);
    void eliminarRutina();

    // Métodos de utilidad
    void mostrar() const;
    string toString() const;
    string toStringCompleto() const;
};