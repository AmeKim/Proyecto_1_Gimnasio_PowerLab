#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Sucursal {
private:
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

public:
    // Constructores
    Sucursal();
    Sucursal(string codigo, string provincia, string canton, string correo, string telefono);
    ~Sucursal();

    // Getters
    string getCodigo() const;
    string getProvincia() const;
    string getCanton() const;
    string getCorreo() const;
    string getTelefono() const;

    // Setters
    void setCodigo(string codigo);
    void setProvincia(string provincia);
    void setCanton(string canton);
    void setCorreo(string correo);
    void setTelefono(string telefono);

    // Métodos
    string toString() const;
    void mostrar() const;
};