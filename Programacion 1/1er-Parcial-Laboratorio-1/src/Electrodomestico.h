/*
 * prestamo.h
 *
 *      Author: Juan Manuel Chico
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#include "Marca.h"
#include "pais.h"

typedef struct{
	int id;
	int serie;
	int idMarca;
	int modelo;
	int idPaisdeOrigen;
	int isEmpty;
}eElectrodomestico;

/**
 * \brief Recibe un array de tipo Struc y lo inicializa colocando isEmpty = 0.
 *  \param Array de tipo struct con isEmpty
 *  \param Espacios del array
 *  \return No retorna datos.
 */
void initElectrodomestico (eElectrodomestico* list,int tam);

/**
 * \brief Recibe una estructura  y carga datos.
 *  \param tamanio de la lista de tipo structura
 *  \param puntero donde se guarda el ultimo ID harcodeado
 *  \return no retorna
 */
void harcodeoDatosElectrodomestico (eElectrodomestico* list,int tam,int* lastIDPrestamos);

/**
 * \brief Imprimo en forma de cuadro los datos cargados en el array de tipo struct
 *  \param recibe la lista que se va a imprimir
 *  \param tamanio e la lista que se va a imprimir
 *  \return no retorna
 */

void printElectrodomestico (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca,ePais* listPais);

/**
 * \brief pide los datos para una strtuctura en forma de array pidiendo los datos necesarios
 *  \param tamanio de la lista
 *  \param puntero donde se almancenan el ultimo id generado
 *  \return no retorna
 */
void getElectrodomestico (eElectrodomestico* list,int tam,int* idElectrodomesticos,eMarca* listMarcas,ePais* listPais);

/**
 * \brief carga los datos solicitados al usuario en la funciuon getElectrodomestico
 *  \param array de la structura
 *  \param tamanio de la estructura
 *  \param datos correspondientes a la estructura para ser cargada
 *  \return retorna si pudo o no realizar la carga
 */

int addElectrodomestico(eElectrodomestico* list, int tam, int id,int serie,int idMarca,int modelo,int idpais);

/**
 * \brief Busca Electrodomestico por ID
 *  \param array de tipo struct
 *  \param entero del tamanio de la lista
 * 	\param id que se desea buscar
 *  \return retorna la posicion donde se encuentra ese ID
 */
int findElectrodomesticosById(eElectrodomestico* list, int tam,int id);

/**
 * \brief busca y modifica los datos de una struct
 *  \param struct array que se desar modificar
 *  \param tamanio del array
 *  \param puntero con el ultimo id generado
 *  \return retoran verdadero o falso
 */
int ModifyElectrodomesticos (eElectrodomestico* list, int tam,int* idElectrodomesticos);

/**
 * \brief realiza la baja logica de un elemento del array
 *  \param estructura que se desea recorrer
 *  \param tamanio de la lista
 *  \param id correspondiente al elemento que se desea recorrer
 *  \return retorna verdadero o falso
 */

int removeElectrodomestico (eElectrodomestico* list, int len, int id);


/**
 * \brief busca espacio en un array de tipo struct
 *  \param array de struct
 *  \param tamanio
 *  \return retorna verdadero o falso
 */

int searchSlot(eElectrodomestico* list, int tam);

/**
 * \brief busca que existan lugares ocupados
 *  \param lista a recorrer
 *  \param tamanio
 *  \return retorna position ocupada
 */
int cantAltas (eElectrodomestico* list, int tam);

/*
 * \brief ordena la lista de electrodomesticos por modelo y numero de serie
 *  \param	lista de electrodomesticos a ordenar
 *  \param	tamanio de la lista a ordenar
 *  \param orden con el que se desea ordenar 1 acendente 0 decendente
 *  \return	retorna la cantidad de vueltas necesarias para ordenarlo
 */

int sortElectrodomestico (eElectrodomestico* list, int len, int order);


#endif /* ELECTRODOMESTICO_H_ */
