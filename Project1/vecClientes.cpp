#include "vecClientes.h"

cliente* vecClientes::getCliente(string ced) const {
    for (int i = 0; i < can; i++) {
        if (vClientes[i]->getCedula() == ced) {
            return vClientes[i];
        }
    }
    return nullptr;
}

int vecClientes::getCan() const { 
    return can;
}
