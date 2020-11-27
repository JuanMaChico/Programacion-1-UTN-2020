/*
 * pais.c
 *      Author: Juan Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pais.h"
#include "utn.h"


void harcodeoPaises (ePais* listPais,int tam){
	int id[5]={1,2,3,4};
	char nombresPaises[4][51]={"Argentina","China","Taiwan","EEUU"};
	for (int i = 0; i < 5; ++i){
		listPais[i].idPais=id[i];
		strcpy(listPais[i].nombrePais,nombresPaises[i]);
	}
}


void printPaises (ePais* listPais,int tam){
	printf("+---------------------------------+\n");
	printf("|%10s  %20s | \n","ID","DESCRIPCION");
	printf("+---------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			printf("|%10d|  %20s|   \n", listPais[i].idPais, listPais[i].nombrePais);
		}
	}
	printf("+---------------------------------+\n");
}

void PaisByID (ePais* listPais,int tam,int id,char nombrePaises[]){

	for (int i = 0; i < 4; ++i){
		if(listPais[i].idPais==id){
			strcpy(nombrePaises,listPais[i].nombrePais);
		}
	}
}
