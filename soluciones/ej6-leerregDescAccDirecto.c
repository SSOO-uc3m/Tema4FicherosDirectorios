#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "registro.h"

const int TAM_REGISTRO = 36;

const char nombreFich[30]="registros.dat";

void abrirLectura(const char *nombre, int *file);
int buscarUsuario(int *file, int cod, tipoRegistro *reg);
/*
Programa que pide un código/posición de persona y muestra los datos que se encuentran en esa posición  en el fichero 
*/
int main () {
	int f;
	int cod;
	
	tipoRegistro reg;

	abrirLectura(nombreFich, &f);	
	
  	printf( "Dar codigo del usuario:");
 	scanf ("%d", &cod);
	
	if(buscarUsuario(&f,cod, &reg)>0)	
		printf  ("registro leido,  codigo:%d: nombre:%s:\n",reg.codigo, reg.nombre);
	else
		printf  ("codigo:%d no encontrado\n",cod);

	 
	close(f);
        		
}

int buscarUsuario(int *file, int cod, tipoRegistro *reg){
	int numbyteleidos;
	//resto -1 porque la persona de código n está en la posición n-1
	lseek (*file, (cod-1) * TAM_REGISTRO, SEEK_SET); 
	numbyteleidos=read (*file, reg, TAM_REGISTRO);
	printf  ("registro leido %d bytes,  codigo:%d: nombre:%s:\n",
		numbyteleidos,reg->codigo, reg->nombre);
	if (cod!=reg->codigo)
		return -1;
	else  
		return cod;	
}

void abrirLectura(const char *nombre, int *file){
 	*file=open (nombreFich, O_RDONLY);

	if ( *file < 0) {	  
	       fprintf (stderr, "No se ha podido abrir el fichero\n");
	      exit (-1);
	  }

}


