/*
 * Servicio.c
 *      Author: Juan Manuel Chico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Servicio.h"

void harcodeoDatosServicios (eServicio* list,int tam){

	int id[]={20000,20001,20002,20003};
	char descripcion[][26]={"Garantia","Mantento..","Repuestos","Refaccion"};
	float precio[]={250.00,500.00,400.00,600.00};

	for (int i = 0; i < tam; ++i){
		list[i].id=id[i];
		strcpy(list[i].descripcion,descripcion[i]);
		list[i].precio=precio[i];
	}
}

void printServicios (eServicio* list, int tam){
	printf("+--------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  | \n","ID","DESCRIPCION","PRECIO");
	printf("+--------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			printf("|%10d|  %20s|  %20.2f|   \n", list[i].id, list[i].descripcion, list[i].precio);
		}
	}
	printf("+--------------------------------------------------------+\n");
}

void ServicioDescripcionByID (eServicio* listServicios,int tamServicio,int id,char descripcion[]){

	for (int i = 0; i < tamServicio; ++i){
		if(listServicios[i].id==id){
			strcpy(descripcion,listServicios[i].descripcion);
		}
	}
}
