#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "registro.h"


const char NOMBRE_FICHERO[40] = "registros.dat" ;
const int TAM_NOMBRE = 30;
const int TAM_REGISTRO = 36;

void escribir(int file, tipoRegistro *registro);
void imprimirPosicion(int file);
void abrirEscritura(const char *nombre, int *file);


int main ( int argc, char *argv[] ) 
{
	int fichero,i ;	
	tipoRegistro registro ;
	printf("tamano registro %ld\n",sizeof(registro));
	char sNombre[TAM_NOMBRE] ;

	/* Abrir fichero */
    	abrirEscritura(NOMBRE_FICHERO, &fichero) ; 

	/* Escribir registros */
	for(i=1;i<10;i++){
		
		registro.codigo = i;
		sprintf(sNombre, "nombre %d", i);
		
		strcpy (registro.nombre, sNombre);
		escribir(fichero, &registro);
	}

	/* Imprimir la posición */
	imprimirPosicion(fichero);

	/* Cerrar fichero */
	close(fichero);
}

void escribir(int file, tipoRegistro *registro ){
      printf ("Escribiendo registro %d:%s \n ", registro->codigo,registro->nombre );
      write (file, registro, TAM_REGISTRO);
    }
    

void  imprimirPosicion(int file){
    int posicion = lseek(file,0,SEEK_CUR) ;
    printf ("Estoy en la posicion %d del fichero\n", posicion );
}

void abrirEscritura(const char *nombre, int *file){
	*file = open (nombre,O_APPEND|O_WRONLY) ;

	if (-1 != *file) {
	  printf ("El fichero ya existe, anyado al final\n");
	}

	if (-1 == *file) {
	  printf ("El fichero no existe\n");
	  printf ("Se va a crear el fichero\n");
          *file=open (nombre, O_CREAT| O_WRONLY, S_IWUSR|S_IRUSR);

	 if (-1 == *file) {
	      printf ("Error en la creacion :1\n");
	      exit (-1);
	  }

	}


    
}
