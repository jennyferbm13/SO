/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"
#include <stdlib.h> 
int main(int argc, char *argv[]) {
//se declaran las variables iniciales
  char comando[BUFSIZ];
  char **vector;
  int i;
  char prueba[] = "quit";
  pid_t pid;
//Se repite hasta que el proceso no pueda ser creado o se ingrese un comando 
//prestablecido para detenerlo
  while(1) {
          printf("> ");
	  //lee un comando del usuario y crea un proceso hijo para que lo ejecute
          leer_de_teclado(BUFSIZ,comando);
          pid = fork();
	  //Si no se puede crear el hijo, imprime un mensaje y termina el programa
          if (pid < 0) {
                  printf("No pude crear un proceso\n");
                  return 2;
	//El hijo intena ejecutar el comando ingreado por el usuario. Si el comando es el 
        //prestablecido termina el proceso
          } else if (pid == 0) {
		if((strcmp(comando,prueba))==0){
			exit(0);}
		
                vector = de_cadena_a_vector(comando);
              

             execvp(vector[0],vector);

		//El padre espera a que la ejecucion del hijo termine. Si el comando es el
                //prestablecido, termina el programa
          } else {
                  wait(NULL);
	        if((strcmp(comando,prueba))==0){
			exit(0);}
		            }
}
  return 0;
}

