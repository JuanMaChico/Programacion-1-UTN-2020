/**************************************************************************************************

Alumno: Juan Manuel Chico
Divicion: 1.E
Actividad: Trabajo Practico Nro 3

**************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/**************************************************************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
**************************************************************************************************/
int main()
{
	setbuf(stdout,NULL);
	int vMenu=1;
	int contadorID=0;
	LinkedList* listaEmpleados = ll_newLinkedList();
	do {
		system("cls");
		switch (utn_GetNumber("------------------------------Trabajo Practico N3------------------------------ \n\n"
							  "-1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n"
							  "-2- Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n"
							  "-3- Alta de empleado \n"
							  "-4- Modificar datos de empleado \n"
							  "-5- Baja de empleado \n"
							  "-6- Listar empleados \n"
							  "-7- Ordenar empleados \n"
							  "-8- Guardar los datos de los empleados en el archivo data.csv (modo texto).    \n"
							  "-9- Guardar los datos de los empleados en el archivo data.csv (modo binario).  \n"
							  "-10- Salir \n"
							  "--------------------------------------------------------------------------------\n\n"
							  "Opcion: "
							 ,"Erro,Opcion no valida.\n",1,10))
		{
			case 1:
				controller_loadFromText("data.csv",listaEmpleados,&contadorID);
				break;
			case 2:
				controller_loadFromBinary("data.bin",listaEmpleados);
				system("pause");
				break;
			case 3:
				controller_addEmployee(listaEmpleados,&contadorID);
				system("pause");
				break;
			case 4:
				controller_editEmployee(listaEmpleados);
				system("pause");
				break;
			case 5:
				controller_removeEmployee(listaEmpleados);
				break;
			case 6:
				controller_ListEmployee(listaEmpleados);
				system("pause");
				break;
			case 7:
				controller_sortEmployee(listaEmpleados);
				break;
			case 8:
				controller_saveAsText("data.csv" , listaEmpleados);
				break;
			case 9:
				controller_saveAsBinary("data.bin" , listaEmpleados);
				break;
			case 10:
				vMenu=0;
				break;
		}
	} while (vMenu);
    return 0;
}

