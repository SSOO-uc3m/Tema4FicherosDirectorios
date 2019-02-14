#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "registro.h"

const int TAM_REGISTRO = 36;
const int TAM_NOMBRE = 32;
const char NOMBRE_FICH[30]="registros.dat";

void abrirEscritura(const char *nombre, int *df);
void guardarRegistro(tipoRegistro *reg, int *df);
void leerRegistro(tipoRegistro *reg);
/*
Programa que pide un codigo/posicion de persona y escribe los datos en la posicion del fichero que corresponden
*/
int main () {
	int descriptorFichero;
	tipoRegistro registro;       
     
       	abrirEscritura(NOMBRE_FICH, &descriptorFichero);
	
	leerRegistro(&registro);  

	guardarRegistro(&registro,&descriptorFichero);

	//resto -1 porque la persona de codigo n esta en la posicion n-1
	
   
	close(descriptorFichero);
}

 /*  Tratamos de abrir el fichero.  Si no existe se crea  */
void abrirEscritura(const char *nombreFichero, int *df){
 	mode_t mode = S_IRUSR | S_IWUSR;
	*df = open (nombreFichero, O_WRONLY|O_CREAT, mode) ;
	
	if ( *df < 0) {	  
	      printf ("Error en la creacion del fichero %s\n",nombreFichero);
	      exit (-1);
	  }

}

void guardarRegistro(tipoRegistro *registro, int *df){
	int numBytesEscritos;
	// resto -1 porque la persona de codigo n esta en la posicion n-1
	lseek (*df, (registro->codigo-1) * TAM_REGISTRO, SEEK_SET); 
	numBytesEscritos=write (*df, registro, TAM_REGISTRO );
        if (numBytesEscritos < 0)
		printf  ("Error al escribir registro codigo:%d\n",registro->codigo);
        else
		printf  ("registro escrito %d bytes,  codigo:%d: nombre:%s:\n",
			numBytesEscritos,registro->codigo, registro->nombre);

}

void leerRegistro(tipoRegistro *registro){
	char nombre[TAM_NOMBRE];
	do{
		printf( "Introduzca el codigo del usuario: ");
 		scanf ("%d", &registro->codigo);
	}while(registro->codigo<=0);

  	printf("Introduzca el nombre del usuario: ");
 	scanf ("%s", nombre);
	strcpy(registro->nombre,nombre);
}
