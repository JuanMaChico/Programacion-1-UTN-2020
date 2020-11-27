/*
 ===========================================+
 Name        : 2do-Parcial-Laboratorio-2.c  |
 Author      : Juan Manuel Chico            |
 Version     : 1.0.0						|
 Description : 2do Parcial Laboratorio 1	|
 ===========================================+
 */

/*
 * el 5 no hace pausa
 * opcion dos no borra el menu
 * el 3 borra
 * el 4 dice descuento realizado
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Articulos.h"
#include "utn.h"
#include "Controller.h"


int main()
{
	setbuf(stdout,NULL);
	int vMenu=1;
	int vSubMenu=1;
	int contadorID=0;
	char nameArchivo[51];
	int flagDescuento=0;
	int flagArchivoCargado=0;

	LinkedList* listArticulos = ll_newLinkedList();
	eRubro listaRubros[4]={{1,"CUIDADO DE ROPA           "},{2,"LIMPIEZA Y DESINFECCION   "},{3,"CUIDADO PERSONAL E HIGIENE"},{4,"CUIDADO DEL AUTOMOTOR     "}};


	do {
		system("cls");
		switch (utn_GetNumber("------------------------------Parcial 2 Parte 1------------------------------ \n\n"
							  "-1- Cargar archivo .csv (modo texto) \n"
							  "-2- Ordenar A-Z. \n"
							  "-3- Listar Articulos. \n"
							  "-4- Aplicar Descuento \n"
							  "-5- Guardar. \n"
							  "-6- Informes \n"
							  "-7- Salir \n"
							  "--------------------------------------------------------------------------------\n\n"
							  "Opcion: "
							 ,"Erro,Opcion no valida.\n",1,7))
		{
			case 1:
                system("cls");
                printf("Ingrese Nombre del archivo(data.csv): ");
                fflush(stdin);
                scanf("%[^\n]",nameArchivo);
                if(strcmp(nameArchivo,"data.csv")==0){
					controller_loadFromText(nameArchivo,listArticulos,&contadorID);
					flagArchivoCargado=1;
                }else{
                	printf("Se espera el Archivo data.csv...\n REINTENTE \n");
                	system("pause");
                }
				break;
			case 2:
				if(flagArchivoCargado==1){
					controller_sortArticulo(listArticulos,listaRubros);
				}else{
					printf("No hay datos para ordenar...\n");
					system("pause");
				}
				break;
			case 3:
                controller_ListArticulo(listArticulos,listaRubros);
                system("pause");
				break;
			case 4:
				if(flagArchivoCargado == 0){
					printf("Primero debe cargar un archivo...\n");
					system("pause");
				}else{
					flagDescuento=1;
					controller_MapearArticulo(listArticulos,listaRubros);
				}
				break;
			case 5:
				if(flagDescuento==1){
					controller_saveAsText("mapeado.csv", listArticulos);
				}else{
					printf("No hay descuento para guardar...\n");
					system("pause");
				}
				break;
			case 6:
				if(flagArchivoCargado==1){
					do {
						system("cls");
						switch (utn_GetNumber("------------------------------    Informes    ------------------------------ \n\n"
											  "-1- Cantidad de Articulos cuyo precio sea mayor a $100. \n"
											  "-2- Cantidad de Articulos del Rubro 1-CUIDADO DE ROPA \n"
											  "-3- Salir \n"
											  "------------------------------------------------------------------------------\n\n"
											  "Opcion: "
											 ,"Erro,Opcion no valida.\n",1,3))
						{
							case 1:
								controller_conterPorPrecio(listArticulos);
								system("pause");
								break;
							case 2:
								controller_conterPorRubro(listArticulos);
								system("pause");
								break;
							case 3:
								vSubMenu=0;
								break;
						}
					} while (vSubMenu);
				}else{
					printf("No hay datos para mostrar...\n");
					system("pause");
				}
				break;
			case 7:
				vMenu=0;
				break;
		}
	} while (vMenu);
    return 0;
}
