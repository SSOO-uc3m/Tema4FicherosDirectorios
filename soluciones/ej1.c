#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	<dirent.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<sys/types.h>
/*
 * Este programa recibe un mombre de directorio y muestra por pantalla los nombres de
 * ficheros y directorios que contiene,	su modo, si tienen o no	permiso	de lectura para	el	* propietario,	si son directorios y, para los ficheros	modificados en los últimos 10 días
 * muestra su fecha de acceso
 *	*/
int main (int argc, char **argv) {
	
	char nombreDirectorio[100], nombreFichero[100];
	struct stat atributo;
	DIR * directorio;
	struct dirent *fDirectorio;
	time_t fecha;

	printf ("Nombre directorio\n");
	fgets (nombreDirectorio, sizeof (nombreDirectorio),	stdin);
	//scanf("%s",nombreDirectorio);
	/* hay que quitar el \n	del nombre del directorio*/
	nombreDirectorio[strlen(nombreDirectorio)-1]='\0';

	fecha=time(&fecha);

	if ((directorio=opendir(nombreDirectorio))==NULL)	{
		printf ("No existe ese directorio \n");
		return	-1;
	}
	else {
		while (( fDirectorio = readdir(directorio)) != NULL) {
			//if ( (strcmp(fDirectorio->d_name, ".")==0 ) && 
			//     (strcmp(fDirectorio->d_name, "..")==0)) {
			        
		        // El nombre del ficjero será nombreDirectorio + / +fDirectorio->d_name	
			strcpy (nombreFichero, nombreDirectorio);
			strcat (nombreFichero, "/");
			strcat (nombreFichero, fDirectorio->d_name);
				
			if(stat	(nombreFichero, &atributo)>=0){
				if (S_ISDIR(atributo.st_mode))				
					printf ("directorio :%s:", nombreFichero);	
				else if (S_ISREG(atributo.st_mode))
					printf ("fichero :%s:", nombreFichero);	

				printf	("modo :%#o:",	atributo.st_mode);
				if ((atributo.st_mode & 0400) != 0)
					printf	("permiso R para propietario\n");
				else printf ("No permiso R para propietario\n");
				if (S_ISREG(atributo.st_mode)){
					/* ficheros modificados	en los ultimos 10 dias */
					if ( (fecha - 10*24*60*60) <atributo.st_mtime) {
						printf ("FICHERO:%s: fecha acceso %s, en sgdos %lu\n", 
							fDirectorio->d_name, ctime (&atributo.st_mtime), atributo.st_mtime);	
		 			}
				}
			}		
		} //fin while
		closedir (directorio);
	}
	return 0;
}/*	main*/
