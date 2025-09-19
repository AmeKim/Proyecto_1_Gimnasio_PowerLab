#include <sstream>
#include "Sucursal.h"
#include "utiles.h"
using namespace std;

class vecSucursales {
private:
    Sucursal** vSucursales;
    int can;
    int tam = 30; // Máximo 30 sucursales según el proyecto
public:
    vecSucursales();
    ~vecSucursales();
    void agregarSucursal(Sucursal* sucursal);
    void eliminarSucursal(int codigo);
    Sucursal* buscarSucursal(int codigo);
    int getCan() const;
    string toString() const;
    string toStringEspecifica(int codigo) const;
    void mostrarTodas() const;
    bool existeCodigo(int codigo) const;
    Sucursal* getSucursalPorIndice(int idx);
};