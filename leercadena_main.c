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
  char comando[BUFSIZ];
  char **vector;
  int i;
  char prueba[] = "quit";
  pid_t pid;

  while(1) {
          printf("> ");
          leer_de_teclado(BUFSIZ,comando);
          pid = fork();
          if (pid < 0) {
                  printf("No pude crear un proceso\n");
                  return 2;
          } else if (pid == 0) {
		if((strcmp(comando,prueba))==0){
			exit(0);}
		
                vector = de_cadena_a_vector(comando);
              

             execvp(vector[0],vector);


          } else {
                  wait(NULL);
	        if((strcmp(comando,prueba))==0){
			exit(0);}
		            }
}
  return 0;
}

