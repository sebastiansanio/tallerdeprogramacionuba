/*
 * U.cpp
 *
 */

#include "U.h"

U::U() {
	// TODO Auto-generated constructor stub

}

list<string>* U::realizarOpearacion(list<char*>* operandos){
	//MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	string usuario;
	string pass;
	list<string>* respuesta = new list<string>();
		list<string>::iterator it=respuesta->begin();

	while(operandos->size()>0){
			if(strcmp(operandos->front(),"usuario")==0){
				operandos->pop_front();
				usuario=operandos->front();
				operandos->pop_front();
			}if(strcmp(operandos->front(),"password")==0){
				operandos->pop_front();
				pass=operandos->front();
				operandos->pop_front();

			}else{
				it=respuesta->begin();
				it=respuesta->insert(it,"Error");
				it++;
				it=respuesta->insert(it,"V");
				it++;
				it=respuesta->insert(it,"Falta ingresar usuario o password");
				return respuesta;
			}
		}
	bool usuValido;
	Conexion* conexion = Conexion::instancia();

	string query = "select usuario from usuarios where usuario='"+usuario+"' and password='"+pass+"'";
	res = conexion->ejecutarQuery(query.c_str());

	double valido=0;
	 if ((row = mysql_fetch_row(res)) !=NULL){
		 usuValido = true;
		 valido=0;
	 }else{
		 usuValido=false;
		 valido =1;
	 }
	 conexion->liberarConexion(res);

	if(!usuValido){
		it=respuesta->begin();
		it=respuesta->insert(it,"Error");
		it++;
		it=respuesta->insert(it,"V");
		it++;
		it=respuesta->insert(it,"Usuario invalido");
		return respuesta;
	}

	respuesta->push_back("Correcto");
	respuesta->push_back("usuario");
	respuesta->push_back(usuario);
	respuesta->push_back("password");
	respuesta->push_back(pass);
	return respuesta;

}



U::~U() {
	// TODO Auto-generated destructor stub
}
