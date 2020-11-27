/* ============================================================================
 Name        : Parcial.c
 Author      : Juan Manuel Chico
 Version     : Modelo De Parcial
 ============================================================================ */

//Bibliotecas Normalizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Bibliotecas Propias
#include "Electrodomestico.h"
#include "Reparacion.h"
#include "Marca.h"
#include "Servicio.h"
#include "Cliente.h"
#include "Informes.h"
#include "pais.h"

#include "utn.h"
//Defines.
#define TAM 1000
#define TAMCLIENTE 10

int main(void) {
	setbuf(stdout, NULL);

	int vMenu=1;
	int vSubMenu=1;
	int idElectrodomesticos=0;
	int idReparacion=0;

	eElectrodomestico Electrodomesticos[TAM];
	eMarca Marcas[5];
	eServicio Servicios[4];
	eReparacion reparaciones[1000];
	eCliente clientes[TAMCLIENTE];

	ePais paises [4]={{1,"argentina"},{2,"china"},{3,"taiwan"},{4,"EEUU"}};

	initElectrodomestico(Electrodomesticos,TAM);//realiza la inicializacion.
	initReparacion(reparaciones, TAM);//Realiza la inicilaizacion.
	harcodeoDatosServicios(Servicios, 4);//Se realiza la carga de los Servicios.
	harcodeoDatosMarcas(Marcas);//se realiza la carga de las marcas.
	//harcodeoDatosElectrodomestico(Electrodomesticos, TAM, &idElectrodomesticos);
	//harcodeoDatosReparaciones(reparaciones, TAM, &idReparacion);
	//harcodeoPaises(paises, 4);
	harcodeoClients(clientes, TAMCLIENTE);

	do {
		system("cls");
		switch (utn_GetNumber("\t<------PARCIAL 1.2 LABORATORIO------>\n"
							  "\t-------------------------------------\n"
							  "\t<-1-  ALTA ELECTRODOMESTICO -->\n"
							  "\t<-2-  MODIFICAR ELECTRODOMESTICO -->\n"
							  "\t<-3-  BAJA ELECTRODOMESTICO-->\n"
							  "\t<-4-  LISTAR ELECTRODOMESTICO-->\n"
							  "\t<-5-  LISTAR MARCAS-->\n"
							  "\t<-6-  LISTAR SERVICIOS-->\n"
							  "\t<-7-  ALTA REPARACION-->\n"
							  "\t<-8-  LISTAR REPARACIONES-->\n"
							  "\t<-9-  LISTAR CLIENTES-->\n"
							  "\t<-10- LISTAR PAISES-->\n"
							  "\t<-11- INFORMES-->\n"
							  "\t<-12- SALIR-->\n"
							  "\t<--- Opcion: ","\n Error,Reintente: ",1,11))
		{
			case 1:
				//Pido los datos de los Electrodomesticos
				getElectrodomestico(Electrodomesticos, TAM, &idElectrodomesticos,Marcas,paises);
				break;
			case 2:
				if(cantAltas(Electrodomesticos, TAM)==0){
					printf("\n\n No hay Electrodomesticos cargados.\n\n");
					system("pause");
				}else{
					printf("\n\n-----Modificacion de Electrodomestico.-----\n");
					printElectrodomestico(Electrodomesticos, TAM, Marcas, 5,paises);
					ModifyElectrodomesticos(Electrodomesticos, TAM, &idElectrodomesticos);
				}
				break;
			case 3:
				if(cantAltas(Electrodomesticos,TAM)==0){
					printf("\n\n No hay Electrodomesticos cargados.\n\n");
					system("pause");
				}else{

					printf("Baja de Electrodomestico.\n");
					printElectrodomestico(Electrodomesticos, TAM,Marcas, 5,paises);
					removeElectrodomestico(Electrodomesticos, TAM, utn_GetNumber("Ingrese Id que desea borrar: ","Error id no encontrado", 1, idElectrodomesticos));
				}
				break;
			case 4:
				if(cantAltas(Electrodomesticos, TAM)==0){
					printf("No hay Electrodomesticos cargados.");
				}else{
					printf("Electrodomesticos.\n");
					//Muestro los Electrodomesticos
					sortElectrodomestico(Electrodomesticos, TAM,0);
					printElectrodomestico(Electrodomesticos, TAM,Marcas, 5,paises);
				}
				system("pause");
				break;
			case 5:
				printf("\n\n+--------------Marcas-------------+\n");
				printMarcas(Marcas, 5);
				system("pause");
				break;
			case 6:
				printf("\n\n------------------------Servicios------------------------+\n");
				printServicios(Servicios,4);
				system("pause");
				break;
			case 7:
				if(cantAltas(Electrodomesticos, TAM)==0){
					printf("\n\n No hay Electrodomesticos cargados.\n\n");
					system("pause");
				}else{
					printf("\n\n-----Alta de reparacion.-----\n");
					//printElectrodomestico(Electrodomesticos, TAM, Marcas, 5);

					getReparacion(reparaciones,TAM,&idReparacion,Electrodomesticos,Marcas,Servicios,clientes,paises);
				}
				break;
			case 8:
				if(cantAltasRep(reparaciones,TAM)==0){
					printf("\n \t No hay reparaciones cargadas.\n\n");
				}else{
					printf("Lista de reparaciones.\n");
					printReparacion(reparaciones, TAM,Servicios,4,clientes,TAMCLIENTE);
				}
				system("pause");
				break;
			case 9:
				printClinetes(clientes, TAMCLIENTE);
				system("pause");
				break;
			case 10:
				printPaises(paises, 4);
				system("pause");
				break;
			case 11://INFORMES
				do {
					system("cls");
					switch (utn_GetNumber("\t<------PARCIAL 1.2 LABORATORIO------>\n"
										  "\t---------------INFORMES--------------\n\n"
										  "\t<-1-MOSTRAR ELECTRODOMESTICOS DEL MODELO: 2020-->\n\n"
										  "\t<-2-MOSTRAR ELECTRODOMESTICOS DE UNA MARCA SELECCIONADA-->\n\n"
										  "\t<-3-MOSTRAR REPARACIONES EFECTUADAS AL ELECTRODOMESTICO SELECCIONADO POR Nro DE SERIE N-->\n\n"
										  "\t<-4-LISTAR ELECTRODOMESTICOS NO REPARADOS-->\n\n"
										  "\t<-5-IMPORTE TOTAL DE REPARACIONES A UN ELECTRODOMESTICO-->\n\n"
										  "\t<-6-MOSTRAR EL SERVICIO MAS PEDIDO-->\n\n"
										  "\t<-7-MOSTRAR RECAUDACION DE FECHA INDICADA-->\n\n"
										  "\t<-8-MOSTRAR TODOS LOS ELECTRODOMESTICOS QUE REALIZARON GARANTIAS-->\n\n"
										  "\t<-9-TRABAJOS REALIZADOS A ELECTRODOMESTICOS DEL MODELO 2018-->\n\n"
										  "\t<-10-FACTURACION TOTAL POR LOS MANTENIMIENTOS -->\n\n"
										  "\t<-11-INFORMAR LA MARCA DE LOS ELECTRODOMESTICOS QUE EFECTUARON MAS REFACCIONES -->\n\n"
										  "\t<-12-LISTAR LOS ELECTRODOMESTICOS QUE RECIBIERON REPARACIONES EN UNA FECHA DETERMINADA -->\n\n"
										  "\t<-13-SALIR-->\n"
										  "\t<--- Opcion: ","\n Error,Reintente: ",1,13)){
						case 1:
							printElectrodomesticoByAnio(Electrodomesticos, TAM,Marcas,5);
							system("pause");
							break;
						case 2:
							printElectrodomesticoByMarca(Electrodomesticos, TAM,Marcas,5);
							system("pause");
							break;
						case 3:
							ReparacionByNroSerie(reparaciones, TAM, Servicios, 4, clientes, TAMCLIENTE, Electrodomesticos, TAM, Marcas, 5,paises);
							system("pause");
							break;
						case 4:
							printElectrodomesticoNoReparado(Electrodomesticos, TAM,Marcas,5, reparaciones,TAM,paises);
							system("pause");
							break;
						case 5:
							printImporteTotalReparacionesByElectrodomestico(Electrodomesticos, TAM, reparaciones, TAM, Servicios, 4, clientes, 3);
							system("pause");
							break;
						case 6:
							printServicioMasPedido(reparaciones, TAM, Servicios, 4);
							system("pause");
							break;
						case 7:
							recaudacionByFecha(reparaciones, TAM, Servicios, 4);
							system("pause");
							break;
						case 8:
							printReparacionSIESGarantia(reparaciones, TAM, Servicios, 4, clientes, TAMCLIENTE);
							system("pause");
							break;
						case 9:
							printReparacionByAnio(reparaciones, TAM, Servicios, 4, clientes, TAMCLIENTE, Electrodomesticos, TAM);
							system("pause");
							break;
						case 10:
							printImporteTotalReparaciones(Electrodomesticos, TAM, reparaciones, TAM, Servicios, 4, clientes, TAMCLIENTE);
							system("pause");
							break;
						case 11://INFORMAR LA MARCA DE LOS ELECTRODOMESTICOS QUE EFECTUARON MAS REFACCIONES
							printMarcaConMasRefacciones(Electrodomesticos,TAM,reparaciones,TAM,Servicios,4,clientes,3,Marcas,5);
							system("pause");
							break;
						case 12:
							printReparacionXFecha(reparaciones, TAM,Servicios,4,clientes,TAMCLIENTE);
							system("pause");
							break;
						case 13:
							vSubMenu=0;
							break;
					}
				} while (vSubMenu);
				break;
			case 12:
				vMenu=0;
				break;
		}
	} while (vMenu);

	return 0;
}
