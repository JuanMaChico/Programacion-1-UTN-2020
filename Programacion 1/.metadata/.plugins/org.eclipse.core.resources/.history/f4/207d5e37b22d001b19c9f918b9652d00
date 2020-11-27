/*
 * utn.c
 * 	Biblioteca de Funciones UTN.
 *      Author: Juan Manuel Chico
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
//
// Pide un entero al usuario
//
int utn_GetNumber (char texto[],char textoError[], int min, int max){
	int datoIngresado;
	int validacion=1;
	do{
		//system("cls");
		printf("\n%s", texto);
		fflush(stdin);
		if(scanf("%d", &datoIngresado)){
			if(ValidaMinMax(datoIngresado, min,max)){
				validacion=0;
			}else{printf("%s\n",textoError);system("pause");};
		}else{printf("%s\n",textoError);system("pause");};
	}while(validacion);
	return datoIngresado;
}
int ValidaMinMax(int dato, int min, int max){
    int valido = 1;
    if(dato<min || dato>max)
    {
        valido = 0;
    }
    return valido;
}
//
// Pide numero flotante al Usuarip
//
float utn_GetNumberFloat (char texto[],char textoError[], float min, float max){
	float datoIngresado;
	int validacion=1;
	do{
		printf("\n%s", texto);
		fflush(stdin);
		if(scanf("%f", &datoIngresado)){
			if(ValidaMinMax(datoIngresado, min,max)){
				validacion=0;
			}else{printf("%s",textoError);};
		}else{printf("%s",textoError);};
	}while(validacion);
	return datoIngresado;
}
int ValidaMinMaxFloat(float dato, float min, float max)
{
    int valido = 1;
    if(dato<min || dato>max)
    {
        valido = 0;
    }
    return valido;
}
//
// Pide un string al usuario(cadena de chars)
//
void utn_GetName(char name[],char text[],int tam){
	int validacion;
	do {
		printf("%s",text);
		fflush(stdin);
		scanf("%[^\n]",name);
		if(isName(name,tam) != 1){
			validacion=0;
		}else{validacion=1;}

	} while(validacion);
}
int isName (char*cadena, int limite) {
	int retorno = 0;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if((cadena[i] < 'a' || cadena[i] > 'z')
				&& (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i]=='\0')){
			retorno = 1;
			break;
		}}
	return retorno;
}
//
// Formatea un nombre colocando la primera letra en Mayuscula y bajando el resto
//
void formatName(char name[],int tam){
	char auxName[51];

	strcpy(auxName,name);
	for (int i = 0; i < 51; ++i){
		auxName[i] = tolower(auxName[i]);
	}
	auxName[0] = toupper(auxName[0]);
	strcpy(name,auxName);
}
//
// Pide al usuario CUIT
//
void utn_GetCuit(char textIngreso[],char dato[]){
	int validacion;
	int tam = 11;
	do {
		printf("%s",textIngreso);
		fflush(stdin);
		scanf("%[^\n]",dato);
		if(isCuit(dato,tam)==1){
			validacion=0;
		}else{validacion=1;}
	} while(validacion);
}
int isCuit(char dato[],int tam){
	int reply=1;
	if(strlen(dato) == 11){
		for (int i = 0; i < tam; ++i){
			if(isdigit(dato[i])==0){
				reply=-1;
				printf("Error, Cuit no valido, posee caracteres no admitidos.\n");
				break;
			}
		}
	}else{
		reply=-2;
		printf("Error, Cuit no valido! ");
	}
	return reply;
}
//
// Pide al usuario un DNI.
//
void utn_GetDNI(char textIngreso[],char dato[]){
	int validacion;
	int tam = 8;
	do {
		printf("%s",textIngreso);
		fflush(stdin);
		scanf("%[^\n]",dato);
		if(isDNI(dato,tam)==1){
			validacion=0;
		}else{validacion=1;}
	} while(validacion);
}
int isDNI(char dato[],int tam){
	int reply=1;
	if(strlen(dato) == 8){
		for (int i = 0; i < tam; ++i){
			if(isdigit(dato[i])==0){
				reply=-1;
				printf("Error, DNI no valido, posee caracteres no admitidos.\n");
				break;
			}
		}
	}else{
		reply=-2;
		printf("Error, DNI no valido! ");
	}
	return reply;
}
//
// Limpia la consola de mensajes anteriores.
//
void utn_limpiarPantalla(){
    system("cls");
    //system("clear");
}
//
// Pausa el sistema.
//
void utn_pausa(){
	system("pause");
}

