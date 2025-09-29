#include "vecSucursales.h"
#include "utiles.h"

#include "BateriaEjercicios.h"

using namespace std;

class submenuInstructores {
public:
    static void mostrar(vecSucursales* sucursales, BateriaEjercicios* bateria);

private:
    static void incluirInstructor(vecSucursales* sucursales);
    static void listaInstructoresPorSucursal(vecSucursales* sucursales);
    static void detalleInstructor(vecSucursales* sucursales);
    static void instructoresPorEspecialidad(vecSucursales* sucursales);
    static void clientesPorInstructor(vecSucursales* sucursales);
    static void generarMedicion(vecSucursales* sucursales);
    static void historialMediciones(vecSucursales* sucursales);
    static void ingresarEjercicio(BateriaEjercicios* bateria);
    static void generarRutina(vecSucursales* sucursales, BateriaEjercicios* bateria);
    static void visualizarRutina(vecSucursales* sucursales);
};