/*
 * utn.c
 *      Author: Juan Manuel Chico
 *
 */
#include <stdio.h>
#include <stdlib.h>


int getFloat(float* operando, char texto []){

	float respuesta;
	float bufferGet;

	printf("%s", texto);
	fflush(stdin);
	if(scanf("%f", &bufferGet) == 1){
		*operando=bufferGet;
		respuesta=1;
	}else{
		respuesta=0;
		printf("Error.");
		system("pause");
	}

	return respuesta;
}

int getInt(char texto []){

	int numeroIngresado;
	printf("%s", texto);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}


