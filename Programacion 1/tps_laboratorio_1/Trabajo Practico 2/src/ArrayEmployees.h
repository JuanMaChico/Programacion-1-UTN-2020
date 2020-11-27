/*
 * ArrayEmployees.h
 *
 *  Created on: 23 sep. 2020
 *       Author      : Juan Manuel Chico
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

/**
 * \brief	Estructura de Empleados.
 */
typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

void harcodeoDatos(Employee list[],int len,int* lastID);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all*position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/**
 * \brief recibe la lista de Employees y busca un lugar disponible.
 *  \param recibe la lista
 *  \param recibe el tamanio
 *  \return En caso de encontrar lugar retorna el indice de la lista que se encuentra disponible
 *  		 0 en caso de No encontrar lugar
 *  		 y -1 en caso de error en algun parametro.
 */
int searchSlot(Employee* list, int len);

/**\brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * \brief	Pide los datos necesarios para la carga de un Empleado.
 *  \param	Lista de Empleados.
 *  \param	Tamanio de la lista.
 *  \return	Devuelve -1 en caso de no haber lugar para este nuevo empleado,
 *  		o Cero en caso de poder realizar el pedido por que hay lugar disponible.
 */
int getEmployee(Employee* list,int len,int* lastID);

/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int
 */
int printEmployees(Employee* list, int length);

/**
 * \brief	Realiza la modificacion un elemento del array de Empleados.
 *  \param	Recibe la lista de Empleados.
 *  \param	Recibe el tamanio de esa lista.
 *  \return	Retorna 0 en caso de no poder Imprimir en pantalla, o 1 si imprimio correctamente.
 */
int ModifyEmployee(Employee* list,int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/**
 * \brief	Calcula el promedio del sueldo de la nomina de empleados, y tambien el total de todos los sueldos.
 *  \param	recibe la lista de empleados.
 *  \param	recibe la cantidad de elementos de esa lista.
 *  \param	Direccion de memoria donde se va a guardar el total de sueldos.
 *  \param	Direccion de memoria donde se va a guardar la cantidad de empleados que superen el promedio.
 *  \return	retorna el promedio de todos los sueldos de la nomina.
 */
float averageSalary(Employee* list,int len,float* total,int* cantEmp);

/**
 * \brief	Recorre un array corroborando si esta se encuentra llena o no.
 *  \param	recibe la lista de la cual se desea saber si esta llena.
 *  \param	recibe el largo de la lista.
 *  \return	Retorna 0 en caso de que esta se encuentra completa o la cantidad de espacios disponibles osea > a cero.
 */
int arrayEmpty(Employee* list,int len);

/**
 * \brief	Recorre la lista de Empleados buscando el ID mas grande.
 *  \param	lista a recorrer.
 *  \param	Tamanio de la lista.
 *  \return Retorna el ID mas grande ocupado hasta el momento, o -1 en caso de no haber.
 */
int searchId(Employee* list, int len);

/**
 * \brief	recibe informacion de la nomina y la muestra formateada por pantalla.
 *  \param	recibe la direccion de memoria del promedio de los sueldos.
 *  \param	recibe la direccion de memoria del la suma total de los sueldos.
 *  \param	Recibe la direccion de memoria de la cantidad de empleados por encima del promerio.
 *  \return	no retorna nada, simplemente muestra por pantalla la informacion.
 */
void printAverageInfo(float* promedio,float* total,int* cantEncimaDelPromedio);



#endif /* ARRAYEMPLOYEES_H_ */
