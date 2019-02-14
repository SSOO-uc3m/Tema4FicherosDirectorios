#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "registro.h"

const int TAM_REGISTRO = 36;

const char nombreFich[30]="registros.dat";

void abrirLectura(const char *nombre, int *df);
int buscarRegistro(int *df, int cod, tipoRegistro *reg);
/*
Programa que pide un código/posición de persona y muestra los datos que se encuentran en esa posición  en el fichero 
*/
int main () {
	int df;
	int codigo;
	
	tipoRegistro registro;

	abrirLectura(nombreFich, &df);	
	
  	printf( "Dar codigo del usuario:");
 	scanf ("%d", &codigo);
	
	if(buscarRegistro(&df,codigo, &registro)>0)	
		printf  ("registro leido,  codigo:%d: nombre:%s:\n",registro.codigo, registro.nombre);
	else
		printf  ("codigo:%d no encontrado\n",codigo);

	 
	close(df);
        		
}

int buscarRegistro(int *df, int codigo, tipoRegistro *registro){
	int numBytesLeidos;
	//resto -1 porque la persona de código n está en la posición n-1
	lseek (*df, (codigo-1) * TAM_REGISTRO, SEEK_SET); 
	numBytesLeidos=read (*df, registro, TAM_REGISTRO);
	printf  ("registro leido %d bytes,  codigo:%d: nombre:%s:\n",
		numBytesLeidos,registro->codigo, registro->nombre);
	if (codigo!=registro->codigo)
		return -1;
	else  
		return codigo;	
}

void abrirLectura(const char *nombre, int *df){
 	*df=open (nombreFich, O_RDONLY);

	if ( *df < 0) {	  
	       fprintf (stderr, "No se ha podido abrir el fichero\n");
	      exit (-1);
	  }

}


