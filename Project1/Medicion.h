#pragma once
#include <string>
#include "fecha.h"
#include "cliente.h"
#include "instructor.h"

using namespace std;

class Medicion {
private:
    // Referencias al cliente e instructor
    cliente* clienteRef;
    instructor* instructorRef;

    fecha* fechaMedicion;
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
    Medicion(cliente*, instructor*, fecha*, double peso, double estatura, double pGrasa, double pMusculo, int edadMet, double grasaVisc, double cintura, double cadera, double pecho, double muslo);
    ~Medicion();

    // Gets para obtener informaci�n del cliente e instructor
    string getNombreCliente() const;
    string getIdCliente() const;
    string getNombreInstructor() const;
    char getSexoCliente() const;

    // Gets para datos de medici�n ingresados
    fecha* getFechaMedicion() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    int getEdadMetabolica() const;
    double getPorcentajeGrasaVisceral() const;

    // Gets para medidas corporales
    double getCintura() const;
    double getCadera() const;
    double getPecho() const;
    double getMuslo() const;

    // Gets para datos calculados
    double getIMC() const;
    string getClasificacion() const;
    bool esAltoRiesgo() const;
    int getVasosAgua() const;
    double getProteina() const;

    // Gets para referencias
    cliente* getCliente() const;
    instructor* getInstructor() const;

    // Sets para datos de medici�n (recalculan autom�ticamente)
    void setFechaMedicion(fecha* fecha);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double pGrasa);
    void setPorcentajeMusculo(double pMusculo);
    void setEdadMetabolica(int edad);
    void setPorcentajeGrasaVisceral(double grasaVisc);

    // Sets para medidas corporales
    void setCintura(double cintura);
    void setCadera(double cadera);
    void setPecho(double pecho);
    void setMuslo(double muslo);

    // M�todo para actualizar todos los c�lculos
    void actualizarCalculos();
};