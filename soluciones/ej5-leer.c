#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "registro.h"

const char NOMBRE_FICHERO[40]="registros.dat";

void leer(int file);
void abrirLectura(const char *nombre, int *df);

int main ( int argc, char *argv[] ) 
{
	int file;
	tipoRegistro registro ;
	abrirLectura(NOMBRE_FICHERO, &file) ;
    
   	leer(file);

	close(file);
}

void leer(int file){
	int bytes_leidos;
	tipoRegistro registro;
	printf("tamaño registro %ld\n",sizeof(registro));

	bytes_leidos = read (file, &registro, sizeof(registro));
	while ( bytes_leidos !=0 ){
	        printf  ("registro leido -> codigo:%d - nombre:%s\n",
			 registro.codigo, 
			 registro.nombre);
	        bytes_leidos = read (file, &registro, sizeof(registro));
       	}
}

void abrirLectura(const char *nombre, int *df){
	*df = open (nombre, O_RDONLY) ;
	if (*df == -1) {
    	fprintf (stderr, "No se ha podido abrir el fichero %s\n",nombre);
	    exit (-1) ;
        }
    
}
