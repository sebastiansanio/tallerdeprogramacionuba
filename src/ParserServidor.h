#ifndef PARSERSERVIDOR_H_
#define PARSERSERVIDOR_H_

using namespace std;
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Grafo.h"

typedef struct {
	string pathEscenario;
	list<string>* jugadores;
	list<string>* cartas;

}informacionConfiguracion;

typedef struct {
	char* server;
	char* user;
	char* password;
	char* database;
}informacionConexion;

class ParserServidor {
	private:
		char* armarXmlDeErrores(list<string>* base,string idOperacion);
		char* armarXmlDeResultado(list<string>* base,string idOperacion);
		ifstream* archivo;
		ofstream* archivoerrores;
		string* pathArchivo;
		bool fallido;
		bool tieneArchivo;
		bool tieneArchivoErrores;
		bool seCreoPath;
		Grafo* grafoTags;
	public:
		ParserServidor();
		ParserServidor(const char* archivoXml);
		string getOperacionId(char xml[]);
		list<char*>* getOperandos(char xml[]);
		string getNombreJugador(char xml[]);
		char* getXml(list<string>* base,string idOperacion);
		bool huboErrorAlAbrirArchivo();
		bool comprobarSintaxis();
		bool comprobarTag(string* cadenaArchivo,string* cadenaNodo);
		void registrarError(string idOperacion, list<string>* mensajesError);
		informacionConfiguracion* getInformacionConfig();
		informacionConexion* getInformacionConexion();
		void construirGrafo();
		virtual ~ParserServidor();
};

#endif /* PARSERSERVIDOR_H_ */
