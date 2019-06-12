#include "../Header/Delivery.h"
#include "../Header/Empleado.h"
#include "../Header/DtDelivery.h"
#include "../Header/TipoTransporte.h"

DtDelivery* Delivery::darDtDelivery() {
	return new DtDelivery(this->getNombre(), this->getNroEmpleado(), this->tipoDeTransporte );
}

Delivery::Delivery(string nombre, int nroEmpleado, TipoTransporte vehiculo):Empleado(nombre, nroEmpleado) {
	this->tipoDeTransporte = vehiculo;
}
Delivery::~Delivery(){

}