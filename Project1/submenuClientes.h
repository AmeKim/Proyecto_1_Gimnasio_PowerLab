#include "vecSucursales.h"

class submenuClientes {
public:
    static void mostrar(vecSucursales* sucursales);

private:
    static void incluirCliente(vecSucursales* sucursales);
    static void asignarInstructor(vecSucursales* sucursales);
    static void listaClientesPorSucursal(vecSucursales* sucursales);
    static void detalleCliente(vecSucursales* sucursales);
};