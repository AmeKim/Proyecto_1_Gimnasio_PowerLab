#include "vecSucursales.h"
#include "utiles.h"

using namespace std;

class submenuClaseGrup {
public:
    static void mostrar(vecSucursales* sucursales);

private:
    static void crearClaseGrupal(vecSucursales* sucursales);
    static void mostrarClasesGrupales(vecSucursales* sucursales);
    static void matricularCliente(vecSucursales* sucursales);
    static void clasesMatriculadas(vecSucursales* sucursales);
};