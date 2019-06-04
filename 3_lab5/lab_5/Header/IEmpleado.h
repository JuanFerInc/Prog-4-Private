#ifndef IEMPLEADOS
#define IEMPLEADOS_H

#include <iostream>
#include <set>

using namespace std;

class IEmpleado{
    public:
		virtual set<int>* mesasDeMozo(int nroEmpleado) = 0; 
};

#endif


