#include "../Header/DtDelivery.h"
#include "../Header/TipoTransporte.h"
#include "../Header/DtEmpleado.h"
#include <string>


//Venta a Domicilio
DtDelivery::DtDelivery(string nombre, int nroEmpleado, TipoTransporte tipo):DtEmpleado(nombre, nroEmpleado) {
	this->transporte = tipo;
}

DtDelivery::DtDelivery(const DtDelivery& a):DtEmpleado(a.getNombre(), a.getNroEmpleado()) {
	this->transporte = a.getTransporte();

}

TipoTransporte DtDelivery::getTransporte() const {
	return this->transporte;
}

void DtDelivery::print(std::ostream& out) {
	using namespace std;
	out << "numero de empleado: " << this->getNroEmpleado() << endl;
	out << "nombre: " << this->getNombre() << endl;
	out << "tipo de transporte: " << this->transporte << endl;
}
bool DtDelivery::operator<(const DtDelivery& d)const {
	if (nombre.compare(d.nombre) <= 0) {
		return true;
	}else {
		return false;
	}
}