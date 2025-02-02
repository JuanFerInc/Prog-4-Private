#include "../Header/Local.h"
#include "../Header/DtProducto.h"
#include "../Header/DtMenu.h"
#include "../Header/Venta.h"
#include "../Header/Mesa.h"
#include "../Header/VentaComida.h"
#include "../Header/Mozo.h"
#include "../Header/DtComida.h"
#include "../Header/Comida.h"
#include "../Header/DtComidaVendida.h"
#include "../Header/CtrlProducto.h"

Local::Local(map<int, Mesa*> mesas, string nroVenta, Mozo *mozo):Venta(nroVenta) {
	this->setsito = mesas;
	this->linkMozo = mozo;
}




bool Local::hayComidaEnVenta(string codigo) {
	set<VentaComida*>::iterator i;
	bool hay = false;
	
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->ventaContieneComida(codigo)) {
			hay = true;			
		}
	}

	
	return hay;
}

void Local::aumentarCantidad(string codigo, int cantidad) {
	set<VentaComida*>::iterator i;
	CtrlProducto *v = CtrlProducto::getInstance();
	Comida *c = v->pedirComida(codigo);
	this->subtotal = this->subtotal + c->getPrecio()*cantidad;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		(*i)->incrementarCantidad(codigo, cantidad);

	}
}

void Local::agregarComida(Comida* c, int cantidad) {
	VentaComida* res = new VentaComida(c, cantidad);
	comidaContenida.insert(res);
	this->subtotal = this->subtotal + c->getPrecio()*cantidad;
}

set<DtComida> Local::productosEnVenta() {
	set<VentaComida*>::iterator i;
	set<DtComida> res;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		DtComida* c = (*i)->pedirDatatypeAComida();
		DtProducto* pepe = dynamic_cast<DtProducto*> (c);
		if (pepe != NULL) {
			DtProducto dtestatico = (*pepe);
			res.insert(dtestatico);
		}
		else {
			DtMenu* pep = dynamic_cast<DtMenu*> (c);
			DtMenu dtestatico = (*pep);
			res.insert(dtestatico);
		}
		delete c;

	}
	return res;
}
bool Local::cantEsMayor(string codigo, int cantidad) {
	set<VentaComida*>::iterator i;
	bool mayor = false;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->esMayor(codigo, cantidad)) {
			mayor = true;
		}
	}
	return mayor;
}

void Local::decrementarCantidad(string codigo, int cantidad) {
	set<VentaComida*>::iterator i;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		(*i)->bajarCantidad(codigo,cantidad);
	}
}
void Local::desvincularMesaDeMiEnVentaActual() {
	map<int, Mesa*>::iterator iter;
	for (iter = this->setsito.begin(); iter != this->setsito.end(); iter++) {
		(*iter).second->desvincularmeDelLocal();
	}
	
}
void Local::eliminarComida(string codigo) {
	set<VentaComida*>::iterator i;
	set<VentaComida*>::iterator iterAEliminar;
	VentaComida* r = NULL;


	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->esComidaAEliminar(codigo) != NULL) {
			iterAEliminar = i;
			this->subtotal = this->subtotal - (*i)->darPrecio();
			r = (*i)->esComidaAEliminar(codigo);

		}
	}

	comidaContenida.erase(iterAEliminar);
	if (r != NULL) {
		delete r;
	}
}

set<DtComidaVendida> Local::darComidas() {
	set<VentaComida*>::iterator i;
	set<DtComidaVendida> res;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		DtComidaVendida *data = (*i)->darDtComidayCantidad();
		DtComidaVendida data2 = *data;
		res.insert(data2);
		delete data;
	}
	return res;
}
void Local::desvincular(VentaComida vp) {
	set<VentaComida*>::iterator i;
	string codigo = vp.darCodigoDeComida();
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->tieneMismo(codigo)) {
			comidaContenida.erase(i);
		}
	}
}

bool Local::noEstaFacturada() {
	return (!this->facturado);
}

DtMozo Local::getDtMozo() {
	return this->linkMozo->getDtMozo();

}