#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
 
using namespace std;


class DtDireccion {
private:
	string nombreCalle, numero, calleAdyacente;

public:
	DtDireccion() = default;
	DtDireccion(const DtDireccion &direccion);
	DtDireccion(string numero, string calle, string calleAdyacente);
//geters
	string getNombreCalle();
	string getNumero();
	string getCalleAdyacente();
};


#endif