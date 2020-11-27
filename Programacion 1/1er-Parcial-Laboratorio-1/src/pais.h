/*
 * pais.h
 *
 *  Created on: 19 nov. 2020
 *      Author: juanm
 */

#ifndef PAIS_H_
#define PAIS_H_

typedef struct{
	int idPais;
	char nombrePais[20];
}ePais;

void harcodeoPaises (ePais* listPais,int tam);

void printPaises (ePais* listPais,int tam);

void PaisByID (ePais* listPais,int tam,int id,char nombrePaises[]);










#endif /* PAIS_H_ */
