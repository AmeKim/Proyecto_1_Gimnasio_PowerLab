#include <iostream>
#include <string>
#include <sstream>
#include "PowerLab.h"
using namespace std;

int main() {
	PowerLab* pl = new PowerLab;
	pl->iniciar();
	delete pl;
}