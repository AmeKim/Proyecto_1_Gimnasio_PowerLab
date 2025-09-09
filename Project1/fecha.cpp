#include "fecha.h"
#include <iostream>
using namespace std;

fecha::fecha(int dia, int mes, int annio)
{
	this->dia = dia;
	this->mes = mes;
	this->annio = annio;
}
fecha::~fecha(){}
void fecha::setDia(int dia)
{
	this->dia = dia;
}
int fecha::getDia()
{
	return dia;
}
void fecha::setMes(int mes)
{
	this->mes = mes;
}
int fecha::getMes()
{
	return mes;
}
void fecha::setAnnio(int annio)
{
	this->annio = annio;
}
int fecha::getAnnio()
{
	return annio;
}
string fecha::toString(){
	stringstream s;
	s << dia << "/" << mes << "/" << annio << endl;
	return s.str();
}

