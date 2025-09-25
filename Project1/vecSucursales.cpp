#include "vecSucursales.h"
#include "utiles.h"

vecSucursales::vecSucursales(int capacidadInicial) {
    if (capacidadInicial < 1) capacidadInicial = 10;
    tam = capacidadInicial;
    cant = 0;
    datos = new Sucursal * [tam];
    for (int i = 0; i < tam; ++i) datos[i] = nullptr;
}

vecSucursales::~vecSucursales() {
    for (int i = 0; i < cant; ++i) if (datos[i]) delete datos[i];
    delete[] datos;
}

void vecSucursales::expandir() {
    int nuevo = tam * 2;
    Sucursal** aux = new Sucursal * [nuevo];
    for (int i = 0; i < nuevo; ++i) aux[i] = nullptr;
    for (int i = 0; i < cant; ++i) aux[i] = datos[i];
    delete[] datos;
    datos = aux;
    tam = nuevo;
}

bool vecSucursales::insertar(Sucursal* s) {
    if (!s) return false;
    if (buscarPorCodigo(s->getCodigo()) != nullptr) return false;
    if (cant >= tam) expandir();
    datos[cant++] = s;
    return true;
}

Sucursal* vecSucursales::buscarPorCodigo(const string& codigo) const {
    for (int i = 0; i < cant; ++i) if (datos[i] && datos[i]->getCodigo() == codigo) return datos[i];
    return nullptr;
}

int vecSucursales::indicePorCodigo(const string& codigo) const {
    for (int i = 0; i < cant; ++i) if (datos[i] && datos[i]->getCodigo() == codigo) return i;
    return -1;
}

Sucursal* vecSucursales::obtener(string cod) const {
    for (int i = 0 ; i< cant; i++){
		if (datos[i]->getCodigo() == cod)
			return datos[i];
    }
	return nullptr;
}

int vecSucursales::cantidad() const { return cant; }

void vecSucursales::listarTodos() const {
    if (cant == 0) { print("No hay sucursales registradas\n"); return; }
    for (int i = 0; i < cant; ++i) {
        if (datos[i]) {
            stringstream s;
            s << datos[i]->getCodigo() << " " << datos[i]->getProvincia() << " - " << datos[i]->getCanton() << "\n";
            print(s.str());
        }
    }
}

bool vecSucursales::eliminarPorCodigo(const string& codigo) {
    int idx = indicePorCodigo(codigo);
    if (idx == -1) return false;
    if (datos[idx]) delete datos[idx];
    for (int i = idx; i < cant - 1; ++i) datos[i] = datos[i + 1];
    datos[cant - 1] = nullptr;
    --cant;
    return true;
}



string vecSucursales::listarInstructoresPorSucursal(string codigo) {
    Sucursal* suc = buscarPorCodigo(codigo);
    if (!suc) return "Error: No existe una sucursal con ese codigo.\n";
    vecInstructores* vInstructores = suc->getVecInstructores();
 
    if (!vInstructores || vInstructores->getcantidad() == 0) return "No hay instructores registrados en esta sucursal.\n";
    stringstream s;
    s << "Instructores en la sucursal " << codigo << ":\n";
    for (int i = 0; i < vInstructores->getcantidad(); ++i) {
        Instructor* inst = vInstructores->obtener();
        if (inst) {
            s << inst->toString() << "\n";
        }
	}
    return s.str();
}