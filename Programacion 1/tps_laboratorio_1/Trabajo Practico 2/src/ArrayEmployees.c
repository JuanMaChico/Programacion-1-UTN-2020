/*
 * ArrayEmployees.c
 *
 *  Created on: 23 sep. 2020
 *       Author      : Juan Manuel Chico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define VACIO 0
#define OCUPADO 1


void harcodeoDatos(Employee list[],int len,int* lastID){
	*lastID=5;
	int id[5]={1,2,3,4,5};
	char name[][51]={"Juan","Sasha","Facundo","German","Octavio"};
	char lastName[][51]={"Chico","Lospalluto","Chico","Scarafilo","Villegas"};
	float salary[5]={34000.00,35000.00,34000.00,45000.00,65000.00};
	int sector[5]={1,1,1,3,3};
	int isEmpty[5]={1,1,1,1,1};
	for (int i = 0; i < 5; ++i){
		list[i].id=id[i];
		strcpy(list[i].name,name[i]);
		strcpy(list[i].lastName,lastName[i]);
		list[i].salary=salary[i];
		list[i].sector=sector[i];
		list[i].isEmpty=isEmpty[i];
	}
}


int initEmployees(Employee* list, int len)
{
	int reply=0;
	if(len>0){
		for (int i = 0; i < len; ++i){
			list[i].isEmpty=0;
		}
	}else{
		reply=-1;
	}
	return reply;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int place =	searchSlot(list, len);
	if(place>=0){
		list[place].id=id;
		strcpy(list[place].name,name);
		strcpy(list[place].lastName,lastName);
		list[place].salary=salary;
		list[place].sector=sector;
		list[place].isEmpty=OCUPADO;
	}
	return 0;
}
int searchSlot(Employee* list, int len){
	int reply=-2;
	if(len>0){
		for (int i = 0; i < len; ++i){
			if(list[i].isEmpty==VACIO){
				reply=i;
				break;
			}else{reply=-1;}
		}
	}
	return reply;
}
int searchId(Employee* list, int len){
	int reply=-1;
	for (int i = 0; i < len; ++i){
		if(list[i].isEmpty==OCUPADO){
			if(list[i].id > reply){
				reply=list[i].id;
			}
		}
	}
	return reply;
}

int arrayEmpty(Employee* list,int len){
	int reply=0;
	for (int i = 0; i < len; ++i){
		if(list[i].isEmpty == 1){
			reply++;
		}
	}
	return reply;
}


int getEmployee(Employee* list,int len,int* lastID){
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int reply=0;
	int id;
	if(searchSlot(list, len)<=-1){
		printf("No hay lugares Disponibles para nuevos empleados.\n");
		reply=-1;
	}else{
		/*
		id=(searchId(list, len));
		id=id+1;
		*/
		id=*lastID+1;
		utn_GetName(name, "Ingrese Nombre del empleado: ",51);
		formatName(name, 51);
		utn_GetName(lastName, "Ingrese Apellido del empleado: ",51);
		formatName(lastName, 51);
		salary=utn_GetNumberFloat("Ingrese Salario del empleado: ","Error, No valido: ",1,999999);
		sector=utn_GetNumber("Ingrese Sector al que pertenece el empleado: ","Sector no valido: ",1,10);
		addEmployee(list, len, id, name, lastName, salary, sector);
		*lastID = id;
		reply=0;
	}
	if(reply == 0){
		printf("La carga se realizo con exito. \n");
	}
	return reply;
}
void formatName(char name[],int tam){
	char auxName[51];

	strcpy(auxName,name);
	for (int i = 0; i < 51; ++i){
		auxName[i] = tolower(auxName[i]);
	}
	auxName[0] = toupper(auxName[0]);
	strcpy(name,auxName);
};

int printEmployees(Employee* list, int length){
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  %10s %10s| \n","ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
	printf("+-----------------------------------------------------------------------------+\n");
	if(length>0){
		for (int i = 0; i < length; ++i){
			if(list[i].isEmpty==1){
				printf("|%10d|  %20s|  %20s|  %10.2f| %6d| \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
	printf("+-----------------------------------------------------------------------------+\n");
	return 0;
}


int ModifyEmployee(Employee* list,int len){
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int reply=0;
	int id = utn_GetNumber("Ingrese El ID del empleado: ","Error id fuera de rango", 1, len+1);
	int aux = findEmployeeById(list, len, id);
	if(aux>=0){
		printf("Se modificara el empleado: \n");
		printf("+------------------------------------------------------------------------------+\n");
		printf("|%10s  %20s  %20s  %10s %10s| \n","ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
		printf("+------------------------------------------------------------------------------+\n");
		printf("|%10d|  %20s|  %20s|  %10.2f| %6d| \n",list[aux].id,list[aux].name,list[aux].lastName,list[aux].salary,list[aux].sector);
		printf("+------------------------------------------------------------------------------+\n");
		for (int i = 0; i <len; ++i){
			if(list[i].id==id){
				switch (utn_GetNumber("Que campo desea modificar?\n"
									  "-1- Nombre\n"
									  "-2- Apellido\n"
									  "-3- Salario\n"
									  "-4- Sector\n"
									  "Ingrese Opcion: ","\nError,Reintente:",1,4)){
					case 1:
						utn_GetName(name, "Ingrese Nombre: ",51);
						strcpy(list[i].name,name);
						break;
					case 2:
						utn_GetName(lastName, "Ingrese Apellido: ",51);
						strcpy(list[i].lastName,lastName);
						break;
					case 3:
						salary=utn_GetNumberFloat("Ingrese Salario: ","Error, No valido: ",1,999999);
						list[i].salary=salary;
						break;
					case 4:
						sector=utn_GetNumber("Ingrese Sector: ","Sector no valido: ",1,10);
						list[i].sector=sector;
						break;
				}
				reply=1;
			}
		}
	}
	return reply;
}
int findEmployeeById(Employee* list, int len,int id){
	int reply=-1;
	if(len>0){
		for (int i = 0; i <len; ++i){
			if(list[i].id==id && list[i].isEmpty==1){
				//reply=id;
				reply=i;
			}
		}
	}
	return reply;
}

int removeEmployee(Employee* list, int len, int id){
	int reply=-1;
	int position = findEmployeeById(list, len, id);
	if(position != -1){
		if(list[position].isEmpty == OCUPADO){
			list[position].isEmpty=VACIO;
			reply=0;
		}
	}
	return reply;
}

int sortEmployees(Employee* list, int len, int order){
	int flagSwap;
	int counter=0;
	int reply=-1;
	Employee aux;
	if(list != NULL && len >= 0){
		do {
			flagSwap=0;
			for (int i = 0; i < len-1; ++i) {
				if(order == 0){
					if(strcmp(list[i].lastName,list[i+1].lastName)>0){
						flagSwap=1;
						aux=list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
					}else{
						if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i].sector > list[i+1].sector){
							flagSwap=1;
							aux=list[i];
							list[i]=list[i+1];
							list[i+1]=aux;
						}
					}
				}else if(order == 1){
					if(strcmp(list[i+1].lastName,list[i].lastName)>0){
						flagSwap=1;
						aux=list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
					}else{
						if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i+1].sector > list[i].sector){
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

float averageSalary(Employee* list,int len,float* total,int* cantEmp){
	float reply=-1;
	float accum=0;
	int conter=0;
	int cantidadEmpleados=0;
	if(list != NULL && len >= 0){
		for (int i = 0; i < len; ++i){
			if(list[i].isEmpty == 1){
				accum+=list[i].salary;
				conter++;
			}
		}
		*total = accum;
		reply = ((float)accum/(float)conter);
		for (int i = 0; i < len; ++i){
			if(list[i].salary > reply && list[i].isEmpty == 1){
				cantidadEmpleados++;
			}
		}
		*cantEmp = cantidadEmpleados;
	}
	return reply;
}

void printAverageInfo(float* promedio,float* total,int* cantEncimaDelPromedio){
	printf("DATOS DE SUELDOS TOTAL Y PROMEDIO DE LA NOMINA DE EMPLEADOS: \n");
	printf("+------------------------------------------------------------------------------------+\n");
	printf("|%1s      | %-25s  | %20s | \n"," PROMEDIO "," TOTAL "," EMPLEADOS POR ARRIBA DEL PROMEDIO  ");
	printf("+------------------------------------------------------------------------------------+\n");
	printf("| %-15.2f|  %-26.2f|  %21d               |\n",*promedio,*total,*cantEncimaDelPromedio);
	printf("+------------------------------------------------------------------------------------+\n");
	system("pause");
}


