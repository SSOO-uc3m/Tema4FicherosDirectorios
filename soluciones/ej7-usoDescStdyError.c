/*
Ejercicio simple de utilización de la salida estandar y la de errores.
Ejecutarlo como main >salida 2>errores
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {   
   

  write (STDOUT_FILENO, "Escrito en salida estandar \n", 
    strlen ("Escrito en salida estandar \n")); 
  write (STDERR_FILENO, "Escrito en salida errores \n", 
    strlen ("Escrito en salida errores \n")); 
}
