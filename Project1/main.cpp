#include "PowerLab.h"

int main() {
    PowerLab* sistema = new PowerLab();
    sistema->ejecutar();
    delete sistema;
    return 0;
}