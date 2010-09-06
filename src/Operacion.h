#ifndef OPERACION_H_
#define OPERACION_H_

using namespace std;
#include <string>
#include <list>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
class Operacion {
public:
	Operacion();
	virtual list<char*>* realizarOpearacion(list<char*>* operandos)=0;
	bool esUnNumero(char* numero);
	virtual ~Operacion();
};

#endif /* OPERACION_H_ */
