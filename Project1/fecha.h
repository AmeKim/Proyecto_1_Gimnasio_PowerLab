#pragma once
#include <iostream>
#include <string>
#include <sstream>
class fecha{
	private:
	int dia;
	int mes;
	int annio;
public:
		fecha(int = 0, int = 0, int = 0);
		~fecha();
		void setDia(int dia);
		int getDia();
		void setMes(int mes);
		int getMes();
		void setAnnio(int annio);
		int getAnnio();
		string toString();
};

