#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <SolarSockets/SolarSockets++.h>
#include <string>


class Servidor : public ssPPServer{
public:
	Servidor();
	virtual ~Servidor();
};

#endif /* SERVIDOR_H_ */
