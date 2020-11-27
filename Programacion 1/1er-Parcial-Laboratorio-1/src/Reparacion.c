/*
 * Reparacion.c
 *      Author: Juan Manuel Chico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Reparacion.h"
#include "Electrodomestico.h"
#include "Marca.h"

#define VACIO 0
#define OCUPADO 1


void initReparacion (eReparacion* list,int tam){
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			list[i].isEmpty=0;
		}
	}
}

int searchSlotReparacion(eReparacion* list, int tam){
	int reply=-2;
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==VACIO){
				reply=i;
				break;
			}else{reply=-1;}
		}
	}
	return reply;
}

void harcodeoDatosReparaciones (eReparacion* list,int tam,int* idReparacion){
	*idReparacion=10;

	int id[10]={1,2,3,4,5,6,7,8,9,10};
	int idCliente[10]={1,4,4,3,8,4,1,2,7,5};
	int serie[10]={12345,70070,12345,70070,12345,40040,12345,40040,30030,12345};
	int idServicio[10]={20001,20000,20002,20000,20003,20002,20001,20003,20003,20000};
	eFecha fecha[10]={{20,1,2018},{10,7,2019},{12,5,2020},{24,6,2019},{17,11,2018},{19,12,2019},{20,5,2013},{26,10,2017},{20,8,2013},{20,5,2013}};
	int isEmpty[10]={1,1,1,1,1,1,1,1,1,1};

	for (int i = 0; i < 10; ++i){
		list[i].id=id[i];
		list[i].idClients=idCliente[i];
		list[i].serie=serie[i];
		list[i].idServicio=idServicio[i];
		list[i].fecha=fecha[i];
		list[i].isEmpty=isEmpty[i];
	}
}

void printReparacion (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients){
	char descript[26];
	char nombre[51];
	char apellido[51];

	printf("+-------------------------------------------------------------------------------------------------+\n");
	printf("|%8s  %13s  %15s  %15s  %15s  %15s      |\n","ID","SERIE "," NOMBRE "," APELLIDO ","SERVICIO"," FECHA ");
	printf("+-------------------------------------------------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1){
				ServicioDescripcionByID(listServicio, tamServicio,(list[i].idServicio), descript);
				nombreByIdCliente(listClients, tamClients,(list[i].idClients), nombre, apellido);

				printf("|%-8d|  %10d  |  %15s  |  %15s  |  %10s  |  %8d/%d/%d | \n",list[i].id,list[i].serie,nombre,apellido, descript, list[i].fecha.dia,list[i].fecha.mes,  list[i].fecha.anno);
				printf("+-------------------------------------------------------------------------------------------------+\n");
			}
		}
	}
}

void getReparacion (eReparacion* list,int tam,int* idReparacion,eElectrodomestico* listElectro,eMarca* listMarcas,eServicio* listservicios, eCliente* listClients,ePais* listPaises){

	int id;
	int idClientes;
	int serie;
	int idServicio;
	eFecha fecha;
	int vSerie=1;

	if(searchSlotReparacion(list, tam)<=-1){
		printf("No hay lugares Disponibles.\n");
	}else{
		printElectrodomestico(listElectro, tam,listMarcas, 5, listPaises);
		do {
			serie=utn_GetNumber("Ingresar numero de serie(Nro:XXXXX):","Error, Reintente",9999,9999999);
			for (int i = 0; i < 1000; ++i){
				if(listElectro[i].serie == serie){
					vSerie=0;
					break;
				}else{vSerie=1;}
			}
		} while (vSerie);

		printClinetes(listClients, 10);

		idClientes=utn_GetNumber("Ingresar id del cliente: ","Error, Reintente: ",1,10);

		id=*idReparacion+1;
		printServicios(listservicios,4);
		idServicio=utn_GetNumber("Ingrese Servicio: ","Error, Servicio no contemplad0.\nReintente:",20000,20003);
		getFechaReparacion(&fecha);

		addReparacion(list, tam, id, serie, idServicio,fecha,idClientes);
		*idReparacion = id;
	}
}

int addReparacion (eReparacion* list, int tam, int id,int serie,int idServicio,eFecha fecha,int idCliente){
	int place =	searchSlotReparacion(list, tam);
	if(place>=0){

		list[place].id=id;
		list[place].idClients=idCliente;
		list[place].serie=serie;
		list[place].idServicio=idServicio;
		list[place].fecha.dia=fecha.dia;
		list[place].fecha.mes=fecha.mes;
		list[place].fecha.anno=fecha.anno;
		list[place].isEmpty=OCUPADO;
	}
	return 0;
}

void getFechaReparacion (eFecha* fecha){
	int dia;
	int mes;
	int anno;
	int vFecha=1;
	do {
		dia=utn_GetNumber("Ingrese Dia: ","Error dia no valido, Reintente: ",1,31);
		mes=utn_GetNumber("Ingrese Mes: ","Error mes no valido, Reintente: ",1,12);
		anno=utn_GetNumber("Ingrese Anno: ","Error anno no valido, Reintente: ",1980,2020);

		switch (mes){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(dia>=1 || dia<=31){
					vFecha=0;
				};
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(dia>=1 || dia<=30){
					vFecha=0;
				};
				break;
			case 2:
				// si el año es bisiesto o no
				if ( ((anno%4==0) && (anno%100!=0)) || (anno%400==0) ) {
					if(dia>=1 || dia<=28){
						vFecha=0;
					};
				} else {
					if(dia>=1 || dia<=29){
						vFecha=0;
					};
				}
				break;
		}
	}while(vFecha);

	fecha->dia=dia;
	fecha->mes=mes;
	fecha->anno=anno;
}

int cantAltasRep (eReparacion* list, int tam){
	int reply=0;
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==OCUPADO){
				reply++;
				break;
			}else{reply=0;}
		}
	}
	return reply;
}


