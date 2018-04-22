#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_BUF   256

void main(int argc, char **argv) {
  DIR *dirp;
  struct dirent *dp;
  char buf[MAX_BUF];

  /* imrpime el directorio actual */
  getcwd(buf, MAX_BUF);
  printf("Directorio actual: %s\n", buf);

  /*abre el directorio pasado como argumento */
  dirp = opendir(argv[1]);

  if (dirp == NULL)  {
     fprintf(stderr,"No puedo abrir %s\n", argv[1]);
  } 
  else {
       /* lee entrada a entrada */
      while ( (dp = readdir(dirp)) != NULL)
 	       printf("%s\n", dp->d_name);
	       closedir(dirp);  
      }
  
  exit(0);
}

