#include "vecClientes.h"
vecClientes::vecClientes(){
	this->can = 0;
	this->vClientes = new cliente*[tam];
	for (int i = 0; i < tam; i++) {
		vClientes[i] = nullptr;
	}
}
vecClientes::~vecClientes(){
	for(int i = 0; i < can; i++){
		delete vClientes[i];
	}
	delete[] vClientes;
}
void vecClientes::agregarCliente(cliente* cli){
	if(can < tam){
		vClientes[can] = cli;
		can++;
	}
	else{
		print("No se pueden agregar mas clientes\n");
	}
}
void vecClientes::eliminarCliente(int ced){
	for(int i = 0; i < can; i++){
		if(vClientes[i]->getCedula() == ced){
			delete vClientes[i];
			for(int j = i; j < can - 1; j++){
				vClientes[j] = vClientes[j + 1];
			}
			vClientes[can - 1] = nullptr;
			can--;
			print("Cliente eliminado\n");
			return;
		}
	}
	print("No se encontro el cliente\n");
}
cliente* vecClientes::getCliente(int ced){
	for(int i = 0; i < can; i++){
		if(vClientes[i]->getCedula() == ced){
			return vClientes[i];
		}
	}
	return nullptr;
}
int vecClientes::getCan(){
	return can;
}
string vecClientes::toString(){
	stringstream s;
	for(int i = 0; i < can; i++){
		s << vClientes[i]->toString() << endl;
	}
	return s.str();
}
string vecClientes::toStringEspecifico(int ced){
	stringstream s;
	for(int i = 0; i < can; i++){
		if(vClientes[i]->getCedula() == ced){
			s << vClientes[i]->toString() << endl;
			return s.str();
		}
	}
	return "No se encontro el cliente\n";
}
