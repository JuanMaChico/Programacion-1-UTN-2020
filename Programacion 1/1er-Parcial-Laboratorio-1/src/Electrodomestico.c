/*
 * prestamo.c
 *      Author: Juan Manuel Chico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Electrodomestico.h"
#include "Marca.h"
#include "Servicio.h"
#include "utn.h"
#include "pais.h"
#define VACIO 0
#define OCUPADO 1

void initElectrodomestico (eElectrodomestico* list,int tam){
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			list[i].isEmpty=0;
		}
	}
}

void harcodeoDatosElectrodomestico (eElectrodomestico* list,int tam,int* idElectrodomesticos){

	*idElectrodomesticos=10;
	int id[11]={1,2,3,4,5,6,7,8,9,10};
	int serie[11]={12345,70070,79797,89898,45454,40040,23232,12121,30030,90909};
	int idMarca[11]={1002,1000,1003,1001,1004,1002,1004,1000,1002,1000};
	int modelo[11]={2019,2020,2018,2020,2019,2018,2020,2019,2018,2020};
	int idPais[11]={1,1,2,3,4,2,3,2,2,3};
	int isEmpty[11]={1,1,1,1,1,1,1,1,1,1};
	for (int i = 0; i <= 10; ++i){

		list[i].id=id[i];
		list[i].serie=serie[i];
		list[i].idMarca=idMarca[i];
		list[i].modelo=modelo[i];
		list[i].idPaisdeOrigen=idPais[i];
		list[i].isEmpty=isEmpty[i];
	}
}

void printElectrodomestico (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca,ePais* listPais){
	char descript[21];
	char nombrePais[51];
	printf("+----------------------------------------------------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  %20s  %20s  | \n","ID","SERIE","MARCA","PAIS","MODELO");
	printf("+----------------------------------------------------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1){

				MarcaDescripcionByID(listMarca, tamMarca,(list[i].idMarca), descript);

				PaisByID (listPais,4,(list[i].idPaisdeOrigen), nombrePais);

				printf("+----------------------------------------------------------------------------------------------------+\n");
				printf("|%10d|  %20d|  %20s|  %20s|   %17d| \n", list[i].id, list[i].serie, descript, nombrePais,list[i].modelo);
				printf("+----------------------------------------------------------------------------------------------------+\n");
			}
		}
	}
}

int searchSlot(eElectrodomestico* list, int tam){
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
int cantAltas (eElectrodomestico* list, int tam){
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







void getElectrodomestico (eElectrodomestico* list,int tam,int* idElectrodomesticos,eMarca* listMarca,ePais* listPais){
	int id;
	int serie;
	int idMarca;
	int modelo;
	int idPais;

	int vSerie=1;
	if(searchSlot(list, tam)<=-1){
		printf("No hay lugares Disponibles para nuevos Electrodomesticos.\n");
	}else{
		id=*idElectrodomesticos+1;
		do {
			system("cls");
			printf("ALTA DE NUEVOS ELECTRODOMESTICOS\n");
			printf("--------------------------------\n\n");
			if(cantAltas(list, tam) > 0){
				printf("\t -Listado de Electrodomesticos Existentes.\n");
				printElectrodomestico(list, tam,listMarca, 5,listPais);
			}
			serie=utn_GetNumber("Ingresar numero de serie(Nro:XXXXX): ","Error, Reintente",9999,99999);
			for (int i = 0; i < 1000; ++i){
				if(list[i].serie == serie && list[i].isEmpty == 1){
					vSerie=1;
					printf("Ya existe... Reintente.\n");
					system("pause");
					break;
				}else{vSerie=0;}
			}
		} while (vSerie);
		printMarcas(listMarca, 5);
		idMarca=utn_GetNumber("Ingrese Marca: ","Error, Marca no contemplada.\nReintente.",1000,1004);
		modelo=utn_GetNumber("Ingresar Modelo: ","Error, Modelo no valido,Reintente:",2000,2020);
		printPaises(listPais, 4);
		idPais=utn_GetNumber("Ingrese ID Pais de Origen: ","Error, Id fuera de rango",1,4);

		addElectrodomestico(list, tam, id, serie, idMarca, modelo,idPais);
		*idElectrodomesticos = id;
	}
}






int addElectrodomestico(eElectrodomestico* list, int tam, int id,int serie,int idMarca,int modelo,int idpais){
	int reply=0;
	int place =	searchSlot(list, tam);
	if(place >= 0){
		list[place].id=id;
		list[place].serie=serie;
		list[place].idMarca=idMarca;
		list[place].modelo=modelo;
		list[place].idPaisdeOrigen=idpais;
		list[place].isEmpty=OCUPADO;
		place=1;
		printf("\t -La Carga fue Exitosa. \n\n");
		system("pause");
	}
	return reply;
}


int ModifyElectrodomesticos (eElectrodomestico* list,int tam,int* idElectrodomesticos){

	int serie;
	int modelo;
	int reply=0;
	int vSerie=1;
	int id = utn_GetNumber("Ingrese El ID del Electrodomestico: ","Error id fuera de rango", 1, (*idElectrodomesticos));
	int aux = findElectrodomesticosById(list, tam, id);
	if(aux>=0){
		printf(" Modificar Datos Existentes \n");
		//printf(" ---------------------------\n\n");
		printf("+---------------------------------------------------------------------+\n");
		printf("|%10s  %20s  %20s  %10s    |\n","ID","SERIE","ID MARCA","MODELO");
		printf("+---------------------------------------------------------------------+\n");
		printf("|%10d|  %20d|  %20d|  %10d| \n",list[aux].id,list[aux].serie,list[aux].idMarca,list[aux].modelo);
		printf("+---------------------------------------------------------------------+\n");
		fflush(stdin);
		for (int i = 0; i < *idElectrodomesticos; ++i){
			fflush(stdin);
			if(list[i].id==id && list[i].isEmpty == 1){
				fflush(stdin);
				system("pause");
				switch (utn_GetNumber("Que campo desea modificar?\n"
									  "-1- serie\n"
									  "-2- modelo\n"
									  "-3- Salir\n"
									  "Ingrese Opcion: ","\nError,Reintente:",1,3)){
					case 1:
						do{
							serie=utn_GetNumber("Ingresar numero de serie: ","Error, Reintente: ",9999,99999);
							for (int x = 0; x < 1000; ++x){
								if(list[x].serie == serie && list[x].isEmpty == 1){
									vSerie=1;
									printf("Ya existe... Reintente.\n");
									system("pause");
									break;
								}else{
									list[i].serie=serie;
									vSerie=0;
									}
							}
					} while (vSerie);
						break;
					case 2:
						modelo=utn_GetNumber("Ingresar Modelo: ","Error, Modelo no valido,Reintente:",2000,2020);
						list[i].modelo=modelo;
						break;
					case 3:
						//salir
						break;
				}
				reply=1;
			}
		}
	}
	return reply;
}


int removeElectrodomestico (eElectrodomestico* list, int len, int id){
	int reply=-1;
	int position = findElectrodomesticosById(list, len, id);
	if(position != -1){
		if(list[position].isEmpty == OCUPADO){
			list[position].isEmpty=VACIO;
			reply=0;
		}
	}
	return reply;
}

int findElectrodomesticosById(eElectrodomestico* list, int tam,int id){
	int reply=-1;
	if(tam>0){
		for (int i = 0; i <tam; ++i){
			if(list[i].id==id && list[i].isEmpty==1){
				reply=i;
			}
		}
	}
	return reply;
}

int sortElectrodomestico (eElectrodomestico* list, int len, int order){
	int flagSwap;
	int counter=0;
	int reply=-1;
	eElectrodomestico aux;
	if(list != NULL && len >= 0){
		do {
			flagSwap=0;
			for (int i = 0; i < len-1; ++i) {
				if(order == 0){
					if(list[i].modelo > list[i+1].modelo){
						flagSwap=1;
						aux=list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
					}else{
						if(list[i].modelo == list[i+1].modelo && list[i].serie > list[i+1].serie){
							flagSwap=1;
							aux=list[i];
							list[i]=list[i+1];
							list[i+1]=aux;
						}
					}
				}else if(order == 1){
					if(list[i+1].modelo > list[i].modelo){
						flagSwap=1;
						aux=list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
					}else{
						if(list[i].modelo == list[i+1].modelo && list[i+1].serie > list[i].serie){
							flagSwap=1;
							aux=list[i];
							list[i]=list[i+1];
							list[i+1]=aux;
						}
					}
				}
				counter++;
			}
		} while (flagSwap);
		reply = counter;
	}
	return reply;
}



