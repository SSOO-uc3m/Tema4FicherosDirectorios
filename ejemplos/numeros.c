#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


const int MAX_NUMERO = 100;
const char NOMBRE_FICH[30]="numeros.dat" ;

void escribir(int df);
void abrirEscritura(const char *nombre, int *df);
void leer(int df);
void abrirLectura(const char *nombre, int *df);

int main ( int argc, char *argv[] ) 
{
	int df ; // descriptor del fichero
	int i ;

	/* Escribir numeros */
	abrirEscritura(NOMBRE_FICH,&df);
        escribir(df);

        close(df);

	/* Leer numeros */

	abrirLectura(NOMBRE_FICH,&df);
	leer(df);

	/* Cerrar fichero */
	close(df);
}

void escribir(int df){
    int i;
    for (i=1; i< MAX_NUMERO; i++) {
	  write (df, &i, sizeof (int) );
    }

}

void  leer(int df){
    int bytes_leidos;
    int numero;

    bytes_leidos = read (df, &numero, sizeof(int));
	while ( bytes_leidos !=0 ){
	        printf  ("%d\n",numero);
	        bytes_leidos = read (df, &numero, sizeof(int));
       	}
}

void abrirLectura(const char *nombre, int *df){
	*df = open (nombre, O_RDONLY) ;
	if (*df == -1) {
    	fprintf (stderr, "No se ha podido abrir el fichero %s\n",nombre);
	    exit (-1) ;
        }

}

void abrirEscritura(const char *nombre, int *df){
    /* Abrir fichero para escritura anadiendo contenido al final*/
    *df = open (nombre,O_APPEND|O_WRONLY) ;
	if (-1 != *df) {
	  printf ("El fichero %s ya existe, anyado al final\n",nombre);
	}

	if (-1 == *df) {
	  printf ("El fichero %s no existe\n",nombre);
	  printf ("Se va a crear el fichero\n");
          // abrir el fichero para escritura, si no existe lo crea
	  // S_IWUSR 00200 usuario tiene permiso para escribir (w)
          // S_IRUSR  00400 usuario tiene permiso para leer (r)
          *df=open (nombre, O_CREAT| O_WRONLY, S_IWUSR|S_IRUSR) ;
	 if (-1 == *df) {
	      printf ("Error en la creacion del fichero %s :1\n",nombre);
	      exit (-1);
	  }
	}
}

