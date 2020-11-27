/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Juan Manuel Chico
 Version     : Trabajo Practico - 1
 Description : Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
				1. Ingresar 1er operando (A=x)
				2. Ingresar 2do operando (B=y)
				3. Calcular todas las operaciones
					a) Calcular la suma (A+B)
					b) Calcular la resta (A-B)
					c) Calcular la division (A/B)
					d) Calcular la multiplicacion (A*B)
					e) Calcular el factorial (A!)
				4. Informar resultados
				a) “El resultado de A+B es: r”
				b) “El resultado de A-B es: r”
				c) “El resultado de A/B es: r” o “No es posible dividir por cero”
				d) “El resultado de A*B es: r”
				e) “El factorial de A es: r1 y El factorial de B es: r2”
				5. Salir
				• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
				que contenga las funciones para realizar las cinco operaciones.
				• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
				(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
				• Deberán contemplarse los casos de error (división por cero, etc)
				• Documentar todas las funciones
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	//Interaccion con el menu
	int opcionesMenu=0;
	//Ingreso de datos
	float operando1=0;
	float operando2=0;
	//Validaciones
	int flagOperando1=0;
	int flagOperando2=0;
	//Validacion del menu
	int vMenu=0;
	int flagOperaciones=0;
	//Resultados
	float resultadoSuma=0;
	float resultadoResta=0;
	float resultadoMultiplicacion=0;
	float resultadoDivision=0;
	//resultados
	int resultadoFactorial1=0;
	int resultadoFactorial2=0;

	do {
		system("cls");

		printf ("\t Trabajo practico N1 \n");
		if(flagOperando1 == 0){
			printf("\t -1- Ingresar 1er operando --\n");
		}else{
			printf("\t -1- Ingresar 1er operando: A= %.2f --\n",operando1);
		}
		if(flagOperando2 == 0){
			printf("\t -2- Ingresar 2do operando --\n");
		}else{
			printf("\t -2- Ingresar 2do operando: B= %.2f --\n",operando2);
		}
		printf("\t -3- Calcular todas las operaciones --\n");
		printf("\t -4- Informar resultados --\n");
		printf("\t -5- Salir --\n");


		switch (opcionesMenu = getInt("\n\n -Ingresar Opcion: ")) {
			case 1:
				flagOperando1 = getFloat(&operando1,"\n\t -Ingrese Numero 1: ");

				break;
			case 2:
				flagOperando2 = getFloat(&operando2,"\n\t -Ingrese Numero 2: ");

				break;
			case 3:
				if(flagOperando1 == 1 && flagOperando2 == 1){
					resultadoSuma=suma(operando1,operando2);
					resultadoResta=resta(operando1,operando2);
					resultadoMultiplicacion=multiplicacion(operando1,operando2);
					resultadoDivision=division(operando1,operando2);
					resultadoFactorial1=factorial(operando1);
					resultadoFactorial2=factorial(operando2);
					flagOperaciones = 1;
					printf("\n\tOperacion Exitosa.\n");
				}else{
					printf("\nDebe ingresar ambos Operandos. \n");
				}
				system("pause");
				break;
			case 4:
				if(flagOperaciones == 0 && flagOperando1 == 0 && flagOperando2 == 0){
					printf("\n Error, No puede mostrar sin antes calcular..\n");
				}else{
					printf("\n El resultado de la suma es: %.2f \n",resultadoSuma);
					printf("\n El resultado de la resta es: %.2f \n",resultadoResta);
					printf("\n El resultado de la multiplicacion es: %.2f \n",resultadoMultiplicacion);
					if(operando2 == 0){
						printf("\nNo es posible dividir por 0.\n");
					}else{
						printf("\n El resultado de la division es: %.2f \n",resultadoDivision);
					}
					if(resultadoFactorial1 == 0){
						printf("\n Error. No es posible realizar Factoreo de este numero: %.2f\n",operando1);
					}else{
						printf("\n El resultado de la factorizacion del operador 1 es: %d \n",resultadoFactorial1);
					}
					if(resultadoFactorial2 == 0){
						printf("\n Error. No es posible realizar Factoreo de este numero: %.2f\n",operando2);
					}else{
						printf("\n El resultado de la factorizacion del operador 2 es: %d \n",resultadoFactorial2);
					}
				}
				system("\npause");
				break;
			case 5:
				vMenu =1;
				break;
			default:
				printf("\t\n No ha ingresado un valor valido. Intente de nuevo!\n");
				system("pause");
				vMenu = 0;
				break;
			}
	} while (vMenu == 0);

	system("pause");
	return 0;
}

