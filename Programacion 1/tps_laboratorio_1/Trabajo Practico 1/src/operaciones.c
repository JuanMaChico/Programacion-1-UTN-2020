
#include "operaciones.h"

float suma(float num1, float num2) {

	float numero1 = num1;
	float numero2 = num2;
	float total;

	total = (numero1 + numero2);

	return total;
}

float resta(float num1, float num2) {

	float numero1 = num1;
	float numero2 = num2;
	float total;

	total = (numero1 - numero2);

	return total;
}

float multiplicacion(float num1, float num2) {

	float numero1 = num1;
	float numero2 = num2;
	float total;

	total = (numero1 * numero2);

	return total;
}

float division(float num1, float num2) {

	float numero1 = num1;
	float numero2 = num2;

	float total;
	if (num2 == 0) {
		total = 0;
	} else {
		total = (numero1 / numero2);
	}
	return total;
}

int factorial(float num1) {
	int resultado = num1;

	if (EsEntero(num1) == 1 && num1 > 0) {
		for (int i = resultado; i > 1; --i) {
			resultado = ((i - 1) * resultado);
		}
	} else {
		resultado = 0;
	}
	return resultado;
}

int EsEntero(float num1) {

	int resultado = 0;
	if ((num1 - (int) num1) == 0) {
		resultado = 1;
	}
	return resultado;
}

