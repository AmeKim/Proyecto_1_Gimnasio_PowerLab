#pragma once
#include "fecha.h"
#include "cliente.h"
#include "instructor.h"
#include <string>
using namespace std;

class Medicion {
private:
    // Referencias al cliente e instructor
    cliente* clienteRef;
    instructor* instructorRef;

    Fecha* fechaMedicion;
    double peso;
    double estatura;
    double porcentajeGrasa;
    double porcentajeMusculo;
    int edadMetabolica;
    double porcentajeGrasaVisceral;

    // Medidas
    double cintura;
    double cadera;
    double pecho;
    double muslo;

    // Datos calculados autom�ticamente
    double imc;
    string clasificacion;
    bool altoRiesgo;
    int vasosAgua;
    double proteina;

    // M�todos privados
    void calcularIMC();
    void determinarClasificacion();
    void calcularVasosAgua();
    void calcularProteina();

public:
    Medicion();
    Medicion(cliente* cliente, instructor* instructor, const Fecha& fecha, double peso, double estatura,
        double pGrasa, double pMusculo, int edadMet, double grasaVisc,
        double cintura, double cadera, double pecho, double muslo);
    ~Medicion();

    // Getters para obtener informaci�n del cliente e instructor
    string getNombreCliente() const;
    string getIdCliente() const;
    string getNombreInstructor() const;
    char getSexoCliente() const;

    // Getters para datos de medici�n ingresados
    Fecha* getFechaMedicion() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    int getEdadMetabolica() const;
    double getPorcentajeGrasaVisceral() const;

    // Getters para medidas corporales
    double getCintura() const;
    double getCadera() const;
    double getPecho() const;
    double getMuslo() const;

    // Getters para datos calculados
    double getIMC() const;
    string getClasificacion() const;
    bool esAltoRiesgo() const;
    int getVasosAgua() const;
    double getProteina() const;

    // Getters para referencias
    cliente* getCliente() const;
    instructor* getInstructor() const;

    // Setters para datos de medici�n (recalculan autom�ticamente)
    void setFechaMedicion(const Fecha& fecha);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double pGrasa);
    void setPorcentajeMusculo(double pMusculo);
    void setEdadMetabolica(int edad);
    void setPorcentajeGrasaVisceral(double grasaVisc);

    // Setters para medidas corporales
    void setCintura(double cintura);
    void setCadera(double cadera);
    void setPecho(double pecho);
    void setMuslo(double muslo);

    // M�todo para actualizar todos los c�lculos
    void actualizarCalculos();
};