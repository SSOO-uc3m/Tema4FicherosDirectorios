#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


const int MAX_NUMERO = 100;
const char NOMBRE_FICH[30]="numeros.dat" ;

void escribir(int file);
void abrirEscritura(const char *nombre, int *file);
void leer(int file);
void abrirLectura(const char *nombre, int *file);

int main ( int argc, char *argv[] ) 
{
	int file ;
	int i ;


	

	/* Escribir n´meros */
	//abrirEscritura(NOMBRE_FICH,&file);
   // escribir(file);

    //close(file);

	/* Leer números */
	
	abrirLectura(NOMBRE_FICH,&file);
	leer(file);
    
	/* Cerrar fichero */
	close(file);
}

void escribir(int file){
    int i;
    for (i=1; i< MAX_NUMERO; i++) {
	  write (file, &i, sizeof (int) );
    }
    
}

void  leer(int file){
    int bytes_leidos;
	int numero;
	
    bytes_leidos = read (file, &numero, sizeof(int));
	while ( bytes_leidos !=0 ){
	        printf  ("%d\n",numero);
	        bytes_leidos = read (file, &numero, sizeof(int));
       	}
}

void abrirLectura(const char *nombre, int *file){
	*file = open (nombre, O_RDONLY) ;
	if (*file == -1) {
    	fprintf (stderr, "No se ha podido abrir el fichero %s\n",nombre);
	    exit (-1) ;
        }
    
}

void abrirEscritura(const char *nombre, int *file){
    /* Abrir fichero */
    *file = open (nombre,O_APPEND|O_WRONLY) ;
	if (-1 != *file) {
	  printf ("El fichero %s ya existe, anyado al final\n",nombre);
	}

	if (-1 == *file) {
	  printf ("El fichero %s no existe\n",nombre);
	  printf ("Se va a crear el fichero\n");
          *file=open (nombre, O_CREAT| O_WRONLY, S_IWUSR|S_IRUSR) ;
	 if (-1 == *file) {
	      printf ("Error en la creacion del fichero %s :1\n",nombre);
	      exit (-1);
	  }
	}
}

