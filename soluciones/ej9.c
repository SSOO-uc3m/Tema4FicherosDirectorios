#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


void crearDirectorio(char *nombre);
void listarDirectorio();

int main(){
  char nombreDir [80];

  printf ("Introduce un nombre para el directorio \n");
  scanf("%s",nombreDir);

  crearDirectorio(nombreDir);

  printf ("Listando rutas del directorio %s al raíz / \n",nombreDir);
  listarDirectorio();
 

}

void listarDirectorio(){
	char nombreDir [80];
	strcpy (nombreDir,"");
  	getcwd(nombreDir,80);
  	printf ("Nombre del directorio actual=%s\n", nombreDir);
  	while ( strcmp(nombreDir,"/")!=0){
   	 	chdir ("..");
    		getcwd(nombreDir,80);
   	 	printf ("Nombre del directorio actual=%s\n", nombreDir);
	}
}

void crearDirectorio(char *nombre){
	mkdir (nombre, S_IWUSR|S_IRUSR);
 	if (errno != 0 )
       	 fprintf (stderr, "No se ha podido crear el directorio %s\n",nombre);
}
