#include "Servidor.h"

void* interactuar(void* structThreads){
	paraThreadsRecibidos* threads=(paraThreadsRecibidos*)structThreads;
	ServidorCliente* servCliente=new ServidorCliente(threads);
	cout<<"Se conecto Cliente: "<<threads->valorAcept<<endl;
	servCliente->interactuarConCliente();
	void* arg;
	cout<<"Se finalizó la coneccion con Cliente: "<<threads->valorAcept<<endl;
	close(threads->valorAcept);
	pthread_exit(arg);
	delete threads;
	delete servCliente;
	return arg;
}

Servidor::Servidor() {
	//creamos el socket
	this->descriptorSocket=socket(AF_INET,SOCK_STREAM,0);
	if(this->descriptorSocket==-1){
		cout<<"Mal creado socket del servidor"<<endl;
		exit(0);
	}

	//para llamar al bind()
	this->estructurDeDirecciones.sin_family=AF_INET;//para lo de family QUE SEA LOCAL
	this->estructurDeDirecciones.sin_port=htons(PORT);
	this->estructurDeDirecciones.sin_addr.s_addr=inet_addr("127.0.0.1");//INADDR_ANY coloca nuestra direccion IP automaticamente

	for(int i=0;i<8;i++){
			this->estructurDeDirecciones.sin_zero[i]=0;}

	socklen_t length=sizeof(sockaddr);

	int valorBind=bind(this->descriptorSocket,(struct sockaddr*)&(this->estructurDeDirecciones),length);
	if(valorBind==-1){
		cout<<"Fallo en Bind del servidor"<<endl;
		exit(0);
	}
}
void Servidor::escuchar(){
	//para el listen
	int valorListen=listen(descriptorSocket,10);
	if(valorListen==-1){
		cout<<"Mal listen del servidor"<<endl;
		exit(0);
	}else{
//		pthread_mutex_init(&this->mutex, NULL);
		Procesador * procesador=Procesador::instancia();
		cout<<"Escuchando..."<<endl;
	}
}
void Servidor::aceptar(){
	//Para el accept
	while(true){
		socklen_t length=sizeof(sockaddr);
		valorAccept=accept(descriptorSocket,(struct sockaddr*)&clienteAdress,&length);
		if(valorAccept==-1){
			cout<<"Mal accept del servidor"<<endl;
		}else{
			paraThreadsRecibidos* threads=new paraThreadsRecibidos;
			threads->clientAdress=clienteAdress;
			threads->valorAcept=valorAccept;
			threads->descriptorSocket=this->descriptorSocket;
			threads->mutex=this->mutex;
			pthread_t thread;
			int creado=pthread_create(&thread,NULL,interactuar,(void*)threads);
			if(creado!=0) cout<<"mal creado el thread"<<endl;}
	}
}

Servidor::~Servidor() {
	close(descriptorSocket);}
