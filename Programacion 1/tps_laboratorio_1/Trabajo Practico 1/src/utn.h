/*
 * utn.h
 *      Author: Juan Manuel Chico
 *
 */
#ifndef UTN_H_
#define UTN_H_

/** author juanm
 * \brief  Recibe un valor float y lo devuelve por Return
 *  \param Texto indicativo para el Usuario
 *  \return devulve el valor ingresado por el usuario y
 *  por flag devuelve si se cargo correctamente un numero o dio error.
 */

int getFloat(float* operando, char []);

/** author juanm
 * \brief  Recibe un valor entero y lo devuelve por Return
 *  \param Texto indicativo para el Usuario
 *  \return devulve el valor ingresado por el usuario.
 */
int getInt(char []);


#endif /* UTN_H_ */
