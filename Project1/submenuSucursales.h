#include "vecSucursales.h"

class submenuSucursales {
public:
    static void mostrar(vecSucursales* sucursales);

private:
    static void ingresarSucursal(vecSucursales* sucursales);
    static void mostrarSucursales(vecSucursales* sucursales);
    static void reporteIMC(vecSucursales* sucursales);
};