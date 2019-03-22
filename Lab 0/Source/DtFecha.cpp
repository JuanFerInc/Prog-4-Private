#include <string>
#include "../Header/DtFecha.h"

//Constructor
DtFecha::DtFecha() {

}

DtFecha::DtFecha(int di, int me, int an){
	d = di;
	m = me;
	a = an;
}
DtFecha::DtFecha(const DtFecha& fecha) {
	this->d = fecha.d;
	this->m = fecha.m;
	this->a = fecha.a;
}
//getters
int DtFecha::getDia(){
	return d;
}

int DtFecha::getMes(){
	return m;
}

int DtFecha::getAnio(){
	return a;
}

//Otras

DtFecha DtFecha::operator=(DtFecha fechita){
	DtFecha aux;
	aux.d = fechita.d;
	aux.m = fechita.m;
	aux.a = fechita.a;
	return aux;
}
bool DtFecha::operator==(DtFecha fecha) {
	bool iguales = false;
	if ((this->d == fecha.d) && (this->m == fecha.m) && (this->a == fecha.a)) {
		iguales = true;
	}
	return iguales;
}
bool DtFecha::operator<(const DtFecha& fechita) {
	bool res = false;
	if (this->a <= fechita.a) {
		if (this->m <= fechita.m) {
			if (this->d < fechita.d) {
				res = true;
			}
		}
	}
	return res;

}

