#ifndef SERVIDOR_H_
#define SERVIDOR_H_
#define PORT 5434
#define MAXBYTES 3000000
using namespace std;
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

struct paraThreadsRecibidos{
	sockaddr_in clientAdress;
	int valorAcept;
};

class Servidor{
private:
	int descriptorSocket,valorAccept;
	sockaddr_in estructurDeDirecciones,clienteAdress;
public:
	Servidor();
	void escuchar();
	void aceptar();
//	static void recibi(paraThreadsRecibidos obj);
	virtual ~Servidor();
};

#endif /* SERVIDOR_H_ */
