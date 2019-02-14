#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "registro.h"


const char NOMBRE_FICHERO[40] = "registros.dat" ;
const int TAM_NOMBRE = 32;
const int TAM_REGISTRO = 36; // 32 char + 4 int
const int NUM_REGISTROS = 10;

void escribir(int file, tipoRegistro *registro);
void imprimirPosicion(int file);
void abrirEscritura(const char *nombre, int *df);


int main ( int argc, char *argv[] )
{
	int dfichero,i ;
	tipoRegistro registro ;
	printf("tamano registro %ld\n",sizeof(registro));
	char sNombre[TAM_NOMBRE] ;

	/* Abrir fichero */
    	abrirEscritura(NOMBRE_FICHERO, &dfichero) ; 

	/* Escribir registros */
	for(i=1;i<NUM_REGISTROS;i++){

		registro.codigo = i;
		sprintf(sNombre, "nombre %d", i);
		strcpy (registro.nombre, sNombre);
		escribir(dfichero, &registro);
	}

	/* Imprimir la posicion */
	imprimirPosicion(dfichero);

	/* Cerrar fichero */
	printf("Cierro el fichero para guardar los cambios\n");
	close(dfichero);
}

void escribir(int file, tipoRegistro *registro ){
      printf ("Escribiendo registro %d:%s \n ", registro->codigo,registro->nombre );
      write (file, registro, TAM_REGISTRO);
    }
    

void  imprimirPosicion(int file){
    int posicion = lseek(file,0,SEEK_CUR) ;
    printf ("Estoy en la posicion %d del fichero\n", posicion );
}

void abrirEscritura(const char *nombre, int *df){
	*df = open (nombre,O_APPEND|O_WRONLY) ;

	if (-1 != *df) {
	  printf ("El fichero %s ya existe, anyado al final\n",NOMBRE_FICHERO);
	}

	if (-1 == *df) {
	  printf ("El fichero %s no existe\n",NOMBRE_FICHERO);
	  printf ("Se va a crear el fichero\n");
          *df=open (nombre, O_CREAT| O_WRONLY, S_IWUSR|S_IRUSR);

	 if (-1 == *df) {
	      printf ("Error en la creacion :\n");
	      exit (-1);
	  }

	}


    
}
