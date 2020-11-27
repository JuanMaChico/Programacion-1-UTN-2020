/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Juan Manuel Chico
 Version     : 0.0.0
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define LEN 100

int main(void) {
	setbuf(stdout,NULL);
	int vMenu=1;
	int lastId=0;
	float totalSueldos;
	float promedioSueldos;
	int arribadelPromedio;
	Employee Empleados[LEN];
	initEmployees(Empleados, LEN);
	//HardCoding de valores
	harcodeoDatos(Empleados, lastId,&lastId);

	do {system("cls");
		switch (utn_GetNumber("--Trabajo Practico N2-- \n\n"
							  "-1- Nuevo Empleado\n"
							  "-2- Modificar Empleado\n"
							  "-3- Eliminar Empleado\n"
							  "-4- Informar Empleados \n"
							  "-5- Salir\n"
							  "Opcion: "
							 ,"Erro,Opcion no valida.\n",1,5))
		{
			case 1:
				getEmployee(Empleados, LEN,&lastId);
				system("pause");
				break;
			case 2:
				if(arrayEmpty(Empleados,LEN)!=0){
					printEmployees(Empleados, LEN);
					if(ModifyEmployee(Empleados, LEN)){
						printf("Modificado Correctamente.\n");
					}else{
						printf("Uups. Algo salio mal Reintente.");
					}
					system("pause");
				}else{
					printf("\nNo es posible modificar por que no hay empleados.\n");
					system("pause");
				}
				break;
			case 3:
				if(arrayEmpty(Empleados,LEN)!=0){
					printEmployees(Empleados, LEN);
					if(removeEmployee(Empleados, LEN, utn_GetNumber("Ingrese el ID del emprelado a eliminar: ","ID Fuera de rango.",1,searchId(Empleados,LEN)))){
						printf("\nUups. Algo salio mal Reintente.\n");
					}else{
						printf("\nEliminado Correctamente.\n");
						system("pause");
					}
				}else{
					printf("\nNo es posible modificar por que no hay empleados.\n");
					system("pause");
				}
				break;
			case 4:
				if(arrayEmpty(Empleados,LEN)!=0){
					switch (utn_GetNumber("-1- Lista de Empleados.\n"
										  "-2- Total y Promedio, Empleados por encima del promedio.\n"
										  "-3- Volver al menu anterior.\n"
										  "--Opcion: "
										  ,"Error, Opcion no valida.",1,3))
					{
						case 1:// Listado de los empleados ordenados alfab�ticamente por Apellido y Sector
							sortEmployees(Empleados, LEN, 0);
							printEmployees(Empleados, LEN);
							system("pause");
							break;
						case 2://Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
							promedioSueldos=averageSalary(Empleados, LEN, &totalSueldos,&arribadelPromedio);
							printAverageInfo(&promedioSueldos, &totalSueldos, &arribadelPromedio);
							break;
						case 3:
							//Se ejecuta el Break en este case para volver al menu anterior!
							break;
					}
				}else{
					printf("\nNo es posible mostrar por que no hay empleados.\n");
					system("pause");
				}
				break;
			case 5:
				vMenu=0;
				break;
		}
	} while (vMenu);

	return 0;
}
