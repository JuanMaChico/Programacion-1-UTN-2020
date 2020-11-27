/*
 * Reparacion.h
 * Author: Juan Manuel Chico
 */

#ifndef REPARACION_H_
#define REPARACION_H_
#include "utn.h"
#include "Servicio.h"
#include "Cliente.h"
#include "Electrodomestico.h"

typedef struct{
	int dia;
	int mes;
	int anno;
}eFecha;

typedef struct{
	int id;//AutoIncrementals
	int idClients;
	int serie;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eReparacion;


/**
 * \brief inicializa una array de struct colocando el campo isEmpty en cero
 *  \param lista que se desea recorrer
 *  \param tamanio de la lista
 *  \return no retorna nada.
 */
void initReparacion (eReparacion* list,int tam);

/**
 * \brief realiza la carga Harcodeada de algunos valores para poder realizar testeos del programa
 *  \param lista de tipo reparaciones
 *  \param tamanio de la lista reparaciones
 *  \param puntero int donde se almacena el ultimo id generado.
 *  \return
 */
void harcodeoDatosReparaciones (eReparacion* list,int tam,int* idReparacion);

/**
 * \brief imprime en pantalla cuadro con la informacion correspondiente a las reparaciones cargadas.
 *  \param lista de tipo reparaciones
 *  \param tamanio de la lista reparaciones
 *  \param lista de tipo servicios
 *  \param tamanio de la lista servicios
 *  \param lista de tipo cliente
 *  \param tamanio de la lista clientes
 *  \return no restorna nada.
 */
void printReparacion (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients);

/*
 * \brief Busca un lugar disponible para ser usado en la lista de Reparaciones
 *  \param	lista de reparaciones
 *  \param	tamanio de la lista
 *  \return	retorna la posicion libre en caso de existir y en caso de no haber retorna -1.
 */
int searchSlotReparacion(eReparacion* list, int tam);


/**
 * \brief pide al usuario que ingrese una fecha y valida que esta sea correcta
 *  \param estructura fecha
 *  \return no retorna nada.
 */
void getFechaReparacion (eFecha* fecha);


/**
 * \brief carga el array de tipo repacacion con los datos ingresados por el usuario.
 *  \param array de tipo reparacion
 *  \param tamanio de la lista reparacion
 *  \param id de la reparacion
 *  \param numero de serie del producto asociado a la reparacion
 *  \param id correspondiente al servicio a realizar
 *  \param dato de tipo eFecha correspondiente a la fecha de ingreso del servicio
 *  \param id del cliente al que corresponde el electrodomestico a reparar
 *  \return retorna 0 en caso de estar correcto
 */
int addReparacion (eReparacion* list, int tam, int id,int serie,int idServicio,eFecha fecha,int idCliente);


/**
 * \brief ccuenta la cantidad de reparaciones existenetes
 *  \param lista de tipo reparacion
 *  \param tamanio de la lista de reparaciones
 *  \return retorna la cantidad de reparaciones
 */
int cantAltasRep (eReparacion* list, int tam);


/**
 * \brief pide los datos que posteriormente van a ser cargados con la funcion addReparacion en la lista de reparacion
 *  \param lista de tipo reparacion
 *  \param tamanio de la lista reparacion
 *  \param puntero id reparaicon donde se encuentra el ultimo id AI de reparacion
 *  \param lista de electrodomesticos
 *  \param lista de marcas
 *  \param lista de servicios
 *  \param lista de cliente
 *  \return no retorna nada.
 */

void getReparacion (eReparacion* list,int tam,int* idReparacion,eElectrodomestico* listElectro,eMarca* listMarcas,eServicio* listservicios, eCliente* listClients,ePais*listPaises);


#endif /* REPARACION_H_ */
