# Ejercicios de ficheros

## Ejercicio 01

Realizar	un	programa	que	reciba	un	nombre	de	directorio	y		muestre	por	pantalla	los	
nombres	de	ficheros	y	directorios	que	contiene,	su	modo,	si	tienen	o	no	permiso	de	
lectura	para	el	propietario,	si	son	directorios	y,	para	los	ficheros	modificados	en	los	
últimos	10	días,	su	fecha	de	acceso	

## Ejercicio 05

a)	Escribir un programa que escriba en un fichero “registros.dat”  una colección N de registros que incluyan un código y un nombre de cliente, ordenados por código.  Si el fichero no existe, el programa debe crearlo.  

b)	Escribir un programa que lea los registros del archivo anterior y los muestre ordenados por pantalla.


## Ejercicio 06


a)	Escribir un programa que escriba en un fichero “registros.dat”  una colección N de registros que incluyan un código y un nombre de cliente, ordenados por código.  El programa debe pedir código y nombre de cliente, saltar a la posición correspondiente del fichero y escribirlo. Si el fichero no existe, el programa debe crearlo.  

b)	Escribir un programa que pida el código de un cliente, lo lea del fichero y lo muestre ordenados por pantalla.    Si el cliente no existe, deberá escribir un registro vacío. 


## Ejercicio 07


a)	Escribir un programa que use la llamada write para escribir un mensaje por la salida estándar y otro por la de error estándar. 

b)	Escribir un posible mandato para ver la salida en 2 archivos distintos para stdout y stderr.

## Ejercicio 08

Escribir un programa en C para mostrar el uso de la llamada al sistema “dup”.  El programa debe redirigir la salida de errores a un archivo “f.dat” y la duplica sobre la salida estándar usando dup y dup2.  Para ver el efecto debe imprimir algo en cada paso. 

## Ejercicio 09

Escribir un programa en C  que cree un directorio nuevo “Dirnuevo” en el directorio actual con permisos de lectura y escritura para el usuario dueño.  A continuación debe ejecutar una llamada para leer el path del directorio actual y mostrar todos los directorios (rutas absolutas) que hay desde el directorio actual hasta el directorio raiz


## Ejercicio 10

Escribir un programa en C  que reciba un nombre de directorio y  muestre por pantalla los nombres de ficheros y directorios que contiene, su modo, si tienen o no permiso de lectura para el propietario, si son directorios y, para los ficheros modificados en los últimos 10 días muestra su fecha de acceso.


## Ejercicio 11

Escriba un programa en C que permita comprobar el funcionamiento de la llamada “umask”.  Para ello, debe aplicar la máscara del archivo al tipo “rwxrwx---“ y crear un archivo.   Después debe cambiar la máscara a “rw-r---w-“ y crear otro fichero aplicando dicha máscara.  Compruebe el resultado usando “ls –l”.

## Ejercicio 12

Escribir un programa modifica la fecha de acceso de “fich_existente” colocándola 2 horas respecto a la fecha actual y modifica la fecha de modificación colocándola 3 horas antes que la que tenía
Se puede comprobar con un ls -l antes y después de la ejecución del programa.  “fich_existente” debe crearse antes.

