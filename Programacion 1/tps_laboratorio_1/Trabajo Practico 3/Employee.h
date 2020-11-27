
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* lista);

int employee_setIdS(Employee* this,char* id);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadasS(Employee* this,char* horasTrabajadas);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldoS(Employee* this,char* sueldo);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_printEmployee(LinkedList* pArrayListEmployee, int index);

int employee_OrdenaEnteroID(void* elementoA, void* elementoB);
int employee_OrdenaEnteroHoras(void* elementoA, void* elementoB);
int employee_OrdenaEnteroSueldo(void* elementoA, void* elementoB);
int employee_OrdenaCadenaNombre(void* elementoA, void* elementoB);

int isValidNumber(char* stringRecibido);

#endif // employee_H_INCLUDED
