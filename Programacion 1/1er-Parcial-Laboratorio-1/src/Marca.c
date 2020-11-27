/*
 * Marca.c
 *     Author: Juan Manuel Chico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Marca.h"


void harcodeoDatosMarcas (eMarca* list){
	int id[5]={1000,1001,1002,1003,1004};
	char descripcion[5][21]={"Wirpool","Sony","Liliana","Gafa","Philips"};
	for (int i = 0; i < 5; ++i){
		list[i].id=id[i];
		strcpy(list[i].descripcion,descripcion[i]);
	}
}
void printMarcas (eMarca* list, int tam){
	printf("+---------------------------------+\n");
	printf("|%10s  %20s | \n","ID","DESCRIPCION");
	printf("+---------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			printf("|%10d|  %20s| \n", list[i].id, list[i].descripcion);
		}
	}
	printf("+---------------------------------+\n");
}

void MarcaDescripcionByID (eMarca* listMarca,int tamMarca,int id,char descripcion[]){
	for (int i = 0; i < tamMarca; ++i){
		if(listMarca[i].id==id){
			strcpy(descripcion,listMarca[i].descripcion);
		}
	}
}
