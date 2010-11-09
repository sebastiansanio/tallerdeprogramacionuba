#ifndef PROCESADOR_H_
#define PROCESADOR_H_

#define PORT 54340
#define MAXBYTES 60000
#define MAXBYTESRECIBIDOS 60000
#define MAXIMODEJUGADORES 6
#define MAXIMODECARTAS 5
#define PATHARCHIVOCONF "config.ini"

using namespace std;
#include <string>
#include "Operacion.h"
#include "ParserServidor.h"
#include "S.h"
#include "D.h"
#include "R.h"
#include "M.h"
#include "J.h"
#include "C.h"
#include "U.h"
#include <map>
#include <list>
#include <ctype.h>
#include "Carta.h"
#include "Jugador.h"
#include "Conexion.h"

class Procesador {
protected:
	Procesador(int i);
private:
	static pthread_mutex_t mutex;
	ParserServidor* parser;
	static Procesador* instanciaUnica;
	list<Carta*>* cartas;
	list<Jugador*>* jugadores; //Los jugadores que se van agregando
	long int bote; //Poso que se va acumulando
	long int apuestaMayorEnRonda; //sirve para cuando pasan los turnos de todos cuanto se va apostando
	string path; //La que se tiene que mandar cuando se lo pida
	informacionConfiguracion* infoconfig;
	string nombreJugadorJugando;
	bool estaJugando;
public:
	static Procesador* instancia();
	bool empezarPartida(char* xml);//Devuelve true si la operacion en una F cosa que empieza a jugar
	list<string>* seConectoJugador(char* xml);
	string getPathArchivo();
	bool agregarJugador(Jugador* jugadorNuevo);
	bool quitarJugador(Jugador* jugador);
	bool agregarCarta(Carta* cartaNueva);
	bool enviarArchivo(char*xml); //FALTA VER LO DE SI ES UNA IMAGEN DE UN JUGADOR
	bool recibirArchivo(char*xml);
	char* getRespuesta(char* xml);
	void terminoMiTurno();
	void setMesa();
	bool seEstaJugando(){return this->estaJugando;}
	virtual ~Procesador();
};

#endif /* PROCESADOR_H_ */
