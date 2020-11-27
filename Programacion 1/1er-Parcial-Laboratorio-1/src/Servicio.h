/*
 * Servicio.h
 *      Author: Juan Manuel Chico
 *
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id;
	char descripcion[26];
	float precio;
}eServicio;

/**
 * \brief Realiza carga autimatica de datos
 *  \param lista que se desea cargar
 *  \param tamanio de la lista
 *  \return no retorna
 */
void harcodeoDatosServicios (eServicio* list,int tam);

/**
 * \brief imprime en forma de cuadro los datos de una lista struct
 *  \param structura que se desea imprimir en pantalla
 *  \param tamanio de la lista a imprimir
 *  \return no retorna
 */

void printServicios (eServicio* list, int tam);

/**
 * \brief busca la descripcion de un servicio
 *  \param lista que se desea recorrer
 *  \param tamanio de la lista
 *  \param id que se va a buscar
 *  \param posicion donde se va a guardar el dato
 *  \return no retorna
 */

void ServicioDescripcionByID (eServicio* list,int tamServicio,int id,char descripcion[]);









#endif /* SERVICIO_H_ */
