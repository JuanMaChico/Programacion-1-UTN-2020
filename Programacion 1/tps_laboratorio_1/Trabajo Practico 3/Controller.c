#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int* lastID){

    FILE* f;
    int retorno=-1;
    f = fopen (path, "r");
    if(ll_len(pArrayListEmployee) == 0){
		if(f == NULL){
			printf("Error al abrir el archivo de texto, Corrobore si existe. \n\n");
			system("pause");
		}else{
			retorno = 0;
			 printf("Archivo abierto correctamente.\n\n");
			 retorno= parser_EmployeeFromText(f , pArrayListEmployee,lastID);
			 system("pause");
		}
    }else{
    	printf("El archivo ya fue cargado!.\n\n");
    	system("pause");
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* f;
    int retorno=-1;
    f= fopen(path, "rb");
    if(ll_len(pArrayListEmployee) == 0){
		if(f==NULL)
		{
			retorno=0;
			printf("Error al abrir el archivo de Binary, Corrobore si existe.\n");

		}
		else{
			retorno=1;
			retorno= parser_EmployeeFromBinary(f , pArrayListEmployee);
			printf("Archivo de texto abierto\n");

		}
    }else{
    	printf("El archivo ya fue cargado!.\n\n");
    	system("pause");
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param puntero contador ID.
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* contadorID){
    Employee* empleadoNuevo;
	int retorno = -1;
    int id;
    int sueldo;
    int horasTrabajadas;

    char idS[100];
    char nombre[100];
    char sueldoS[100];
    char horasTrabajadasS[100];

    if(ll_len(pArrayListEmployee) != 0){
		utn_GetName(nombre, "Ingrese Nombre: ",100);
		horasTrabajadas=utn_GetNumber("Ingrese Horas Trabajadas: ","Error, Reintente",1,9999999);
		sueldo=utn_GetNumber("Ingrese Sueldo: ","Error, Reintente",1,999999);

		sprintf(sueldoS,"%d",sueldo);
		sprintf(horasTrabajadasS,"%d",horasTrabajadas);
		(*contadorID)++;
		id=*contadorID;
		sprintf(idS,"%d",id);

		empleadoNuevo = employee_newParametros(idS,nombre,horasTrabajadasS,sueldoS);
		ll_add(pArrayListEmployee, empleadoNuevo);
		retorno=0;

		printf("\n\ndatos cargados correctamente!\n");
    }else{
    	printf("\n\nNo es posible dar de alta Nuevos empleados...\n");
    }
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int id;
    int opcion=0;
    char nombre[100];
    int sueldo;
    int horasTrabajadas;
    if(ll_len(pArrayListEmployee)!=0){
		printf("\n Ingrese el ID del empleado a modificar: ");
		scanf("%d",&id);
		empleado = ll_get(pArrayListEmployee, (id-1));
		do
		{
			printf("\t MODIFICACIONES \n");
			printf("1- Nombre\n");
			printf("2- Cantidad de horas trabajadas\n");
			printf("3- Sueldo\n");
			printf("4- Salir\n");
			printf("- Opcion: ");
			scanf("%d", &opcion);
			   switch(opcion){
					case 1:
						 utn_GetName(nombre, "Ingrese Nombre: ", 100);
						 employee_setNombre(empleado,nombre);
						 printf("\nNombre cambiado con exito\n");
						 system("pause");
						break;
					case 2:
						horasTrabajadas=utn_GetNumber("Ingrese Horas Trabajadas: ", "Error reintente",1,999999);
						employee_setHorasTrabajadas(empleado,horasTrabajadas);
						printf("\nHoras trabajadas cambiado con exito\n");
						system("pause");
						break;
					case 3:
						sueldo=utn_GetNumber("Ingrese Sueldo: ","Error, Reintente",1,999999);
						employee_setSueldo(empleado,sueldo);
						printf("\nSueldo cambiado con exito\n");
						system("pause");
						break;
					case 4:
						opcion=4;
						break;
				}
		}while(opcion!=4);
    }else{
    	printf("\n\nNo es modificar empleados...\nCargue un archivo previamente.\n\n");
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int empleadoEliminar;
    int len;
    int opcion;
    int retorno=-1;
    Employee* empleado;
    len = ll_len(pArrayListEmployee);

    if(ll_len(pArrayListEmployee)!=0){
		printf("Ingrese el ID que desea eliminar\n");
		scanf("%d", &empleadoEliminar);

		for(int i=0;i<len;i++)
		{
			empleado= ll_get(pArrayListEmployee, i);
			if(empleado->id == empleadoEliminar)
			{
				printf("Esta seguro de que desea eliminar ?\n1-Si\n2-No\n");
				scanf("%d",&opcion );
				if(opcion ==1)
				{
					empleado=ll_pop(pArrayListEmployee,i);
					printf("\nEMPLEADO ELIMINADO");
					retorno=0;
					break;
				}
				else
				{
					printf("\n No se pudo eliminar el empleado\n");
					break;
				}
			}
		}
    }else{
    	printf("\n\nNo es borrar empleados...\nCargue un archivo previamente.\n\n");
    }
    system("pause");
    return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int retorno=-1;
    int i,len;
    len=ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL && len>0)
    {
    	printf("+-----------------------------------------------------------------------+\n");
    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
    	printf("+-----------------------------------------------------------------------+\n");
        for(i=0;i<len;i++)
        {
            employee_printEmployee(pArrayListEmployee,i);
            printf("+-----------------------------------------------------------------------+\n");
            retorno=0;
        }
    }else{
    	printf("No hay datos a mostrar.\n");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
	int vMenu=1;
	int len;
	len = ll_len(pArrayListEmployee);
	if (pArrayListEmployee!=NULL && len>0){
		do{
			system("cls");
			switch (utn_GetNumber("\t-- Criterios de Ordenamiento --\n"
									"\t-1-Lista original--\n"
									"\t-2-ID de menor a mayor--\n"
									"\t-3-ID de mayor a menor--\n"
									"\t-4-Horas de trabajo de menor a mayor--\n"
									"\t-5-Horas de trabajo de mayor a menor--\n"
									"\t-6-Sueldo de menor a mayor--\n"
									"\t-7-Sueldo de mayor a menor--\n"
									"\t-8-Nombre de la A-Z--\n"
									"\t-9-Nombre de la Z-A--\n"
									"\t-10-Salir--\n"
									"\t\t Opcion: ","\t\nError, Reintente \n",1,10))
			{
				case 1://ORIGINAL
				controller_ListEmployee(pArrayListEmployee);
				break;

				case 2://mM
				printf("\tID MENOR A MAYOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,1);
				break;

				case 3://Mm
				printf("\tID MAYOR A MENOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,0);
				break;

				case 4://mM
				printf("\tHORAS TRABAJADAS MENOR A MAYOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,1);
				break;

				case 5://Mm
				printf("\tHORAS TRABAJADAS MAYOR A MENOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,0);
				break;

				case 6:
				printf("\tSUELDOS MENOR A MAYOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,1);
				break;

				case 7:
				printf("\tSUELDOS MAYOR A MENOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,0);
				break;

				case 8:
				printf("\tNOMBRES MENOR A MAYOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,1);
				break;

				case 9:
				printf("\tNOMBRES MAYOR A MENOR\n\n");
				ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,0);
				break;

				case 10:
				vMenu=0;
				break;
				controller_ListEmployee(pArrayListEmployee);
			}
	}while(vMenu);
	} else {
		printf(" \nNo hay datos a Mostrar \n");
		system("pause");
	}
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* empleadoAux;
    int retorno=-1;
    int i,len,id, sueldo, horasTrabajadas;
    char nombre[100];

    f= fopen(path, "w");
    if(f != NULL && ll_len(pArrayListEmployee)>0)
    {
        len=ll_len(pArrayListEmployee);
        fprintf(f,"id,nombre,horasTrabajadas,Sueldo\n");
        for(i=0; i<len; i++)
        {
            empleadoAux= ll_get(pArrayListEmployee, i);
            employee_getId(empleadoAux,&id);
            employee_getSueldo(empleadoAux, &sueldo);
            employee_getHorasTrabajadas(empleadoAux, &horasTrabajadas);
            employee_getNombre(empleadoAux,nombre);

            fprintf(f,"%d,%s,%d,%d\n",id , nombre, horasTrabajadas, sueldo);
        }
        printf(" \nArchivo guardado\n\n");
        retorno=0;
    }
    else
    {
        printf(" \nNo se pudo guardar el archivo\n");
        retorno=0;
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    int retorno=-1;
    int len;
    FILE* f;
    Employee* empleado;
    f=fopen(path, "wb");

    if(f != NULL && ll_len(pArrayListEmployee))
    {
        len= ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            empleado=ll_get(pArrayListEmployee, i);
            fwrite(empleado,sizeof(Employee),1,f);
        }
        printf(" \nArchivo binario guardado con exito\n");
        system("pause");
        retorno=1;
    }
    else
    {
        printf(" \nNo se pudo guardar el archivo\n");
        system("pause");
    }
    fclose(f);
    return retorno;
}

