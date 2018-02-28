#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "registro.h"

const int TAM_REGISTRO = 36;
const int TAM_NOMBRE = 30;
const char nombreFich[30]="registros.dat";

void abrirEscritura(const char *nombre, int *file);
void modificarUsuario(tipoRegistro *reg, int *file);
void leerUsuario(tipoRegistro *reg);
/*
Programa que pide un código/posición de persona y escribe los datos en laposición del fichero que corresponden
*/
int main () {
	int f;
	tipoRegistro reg;       
     
       	abrirEscritura(nombreFich, &f);
	
	leerUsuario(&reg);  

	modificarUsuario(&reg,&f);

	//resto -1 porque la persona de código n está en la posición n-1
   
	close(f);
}

 /*  Tratamos de abrir el fichero.  Si no existe se crea  */
void abrirEscritura(const char *nombre, int *file){
 	mode_t mode = S_IRUSR | S_IWUSR;
	*file = open (nombreFich, O_WRONLY|O_CREAT, mode) ;
	
	if ( *file < 0) {	  
	      printf ("Error en la creacion :1\n");
	      exit (-1);
	  }

}

void modificarUsuario(tipoRegistro *reg, int *file){
	int numbyteescritos;
	//resto -1 porque la persona de código n está en la posición n-1
	lseek (*file, (reg->codigo-1) * TAM_REGISTRO, SEEK_SET); 
	numbyteescritos=write (*file, reg, TAM_REGISTRO );
        if (numbyteescritos < 0)
		printf  ("Error al escribir registro codigo:%d\n",reg->codigo);
        else
		printf  ("registro escrito %d bytes,  codigo:%d: nombre:%s:\n",
			numbyteescritos,reg->codigo, reg->nombre);

}

void leerUsuario(tipoRegistro *reg){
	char nombre[TAM_NOMBRE];
	do{
		printf( "Dar codigo del usuario:");
 		scanf ("%d", &reg->codigo);
	}while(reg->codigo<=0);

  	printf( "Dar nombre del usuario:");
 	scanf ("%s", nombre);
	strcpy(reg->nombre,nombre);
}

