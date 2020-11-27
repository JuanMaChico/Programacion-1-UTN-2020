/*
 * Cliente.c
 *      Author: Juan Manuel Chicos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Cliente.h"

void harcodeoClients (eCliente* listClients,int tam){
	int id[10]={1,2,3,4,5,6,7,8,9,10};
	char nombre[10][51]={"Maria","Juan","Dario","Candela","Marina","Carolina","Nicolas","Cristina","Daniel","Lydia"};
	char apellido[10][51]={"Perez","Martinez","Gomez","Cuda","Arias","Yokoyama","Gushiken","Ramos","Tamashiro","Morales"};
	for (int i = 0; i < tam; ++i){

		listClients[i].id=id[i];
		strcpy(listClients[i].nombre,nombre[i]);
		strcpy(listClients[i].apellido,apellido[i]);
	}
}


void printClinetes (eCliente* listClients,int tam){
	char auxNombre[51];
	char auxApellido[51];
	printf("+--------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  | \n","ID","NOMBRE","APELLIDO");
	printf("+--------------------------------------------------------+\n");
	printf("%d",tam);
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			nombreByIdCliente(listClients, tam,(listClients[i].id) , auxNombre, auxApellido);
			printf("+--------------------------------------------------------+\n");
			printf("|%10d|  %20s|  %20s|\n", listClients[i].id, auxNombre, auxApellido);
			printf("+--------------------------------------------------------+\n");
		}
	}
}

void nombreByIdCliente (eCliente* listClients,int tam,int idCliente,char nombre[],char apellido[]){

	for (int i = 0; i < tam; ++i){

		if(listClients[i].id==idCliente){

			strcpy(nombre,listClients[i].nombre);

			strcpy(apellido,listClients[i].apellido);
		}
	}
}


