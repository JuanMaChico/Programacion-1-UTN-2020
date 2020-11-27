/*
 * calculos.h
 *
 *      Author: juan Manuel Chico
 *
 */
#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * \brief Solicita dos numeros enteros y los suma.
 * \param Numero entero para sumar.
 * \param Numero entero para sumar.
 * \return El valor de la suma de los numero enteros ingresados.
 */
float suma (float num1, float num2);

/**
 * \brief Solicita dos numeros enteros y los resta.
 * \param Numero entero para restar.
 * \param Numero entero para restar.
 * \return El valor de la resta de los numero enteros ingresados.
 */
float resta (float num1, float num2);

/**
 * \brief Solicita dos numeros enteros y los multiplicarlos.
 * \param Numero entero para multiplicar.
 * \param Numero entero para multiplicar.
 * \return El valor de la multiplicacion de los numero enteros ingresados.
 */
float multiplicacion (float num1, float num2);

/**
 * \brief Solicita dos numeros enteros y los divide.
 * \param Numero entero para vidivir.
 * \param Numero entero para dividir.
 * \return El valor de la divicion de los numero enteros ingresados.
 */
float division (float num1, float num2);

/**
 * \brief Solicita dos numeros enteros y los divide.
 * \param Numero entero para vidivir.
 * \param Numero entero para dividir.
 * \return El valor de la divicion de los numero enteros ingresados.
 */
int factorial (float num1);

/**
 * \brief Recibe un numero Float para validar si este es entero.
 * \param Numero Float del cual necesitamos saber si es entero.
 * \return Devuelve 0 si el numero posee decimales y 1 si no posee decimales.
 */
int EsEntero (float num1);


#endif /* CALCULOS_H_ */
