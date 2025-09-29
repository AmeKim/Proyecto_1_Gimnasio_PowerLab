#include "vecSucursales.h"
#include "BateriaEjercicios.h"

using namespace std;

class PowerLab {
private:
    vecSucursales* sucursales;
    BateriaEjercicios* bateria;

    void cargarDatosIniciales();

public:
    PowerLab();
    ~PowerLab();

    void ejecutar();
    void mostrarMenuPrincipal();
};