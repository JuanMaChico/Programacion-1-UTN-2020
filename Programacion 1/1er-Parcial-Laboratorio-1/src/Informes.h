/*
 * Informes.h
 *      Author: Juan Manuel Chico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Electrodomestico.h"
#include "Reparacion.h"
#include "Marca.h"
#include "Servicio.h"
#include "Cliente.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/*
 * \brief Muestra por pantalla un cuadro donde expone las reparaciones cargadas para cada uno de los clientes
 *  \param Lista de reparaciones
 *  \param tamanio de la lista de reparaciones
 *  \param lista de servicios
 *  \param tamanio de la lista de servicios
 *  \param lista de clientes
 *  \param tamanio de la lista de clientes
 *  \return	no retorna nada.
 */
void reparacionByClientes (eReparacion* listRepacaion,int tamReparacion,eServicio* listServicio,int tamServicio,eCliente* listClientes,int tamClientes);

/*
 * \brief imprime en pantalla todas las reparaciones cargadas
 *  \param lista de tipo reparacion
 *  \param tamanio de lista reparacion
 *  \param lista de tipo servicio
 *  \param tamanio de lista servicio
 *  \param lista de tipo cliente
 *  \param tamanio de lista cliente
 *  \return no retorna nada.
 */
void printreparacionByClientes (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients,int idCliente);

/*
 * \brief cuenta si hay reparaciones para un cliente en espesifico
 *  \param lista de tipo reparacion
 *  \param tamanio de la lista reparacion
 *  \param id del cliente que se desea saber si tiene reparaciones
 *  \return retorna la cantidad de reparaciones que tiene el cliente, 0 en caso de no tener ninguna
 */
int conterReparacionByClientes (eReparacion* listRepacaion,int tamReparacion,int idCliente);

/*
 * \brief Imprime por pantalla la lista correspondiente al cliente indicado unicamente
 *  \param lista de tipo reparacion
 *  \param tamanio de lista reparacion
 *  \param lista de tipo servicio
 *  \param tamanio de lista servicio
 *  \param lista de tipo cliente
 *  \param tamanio de lista clientes
 *  \return no retorna nada.
 */
void printReparacionCliente (eReparacion* listRepacaion,int tamReparacion,eServicio* listServicio,int tamServicio,eCliente* listClientes,int tamClientes);

/*
 * \brief Muesta por pantalla un cuadro con las reparaciones correspondientes a un numero de serie en espesifico
 *  \param lista de tipo reparacion
 *  \param tamanio de lista reparacion
 *  \param lista de tipo servicio
 *  \param tamanio de lista servicio
 *  \param lista de tipo cliente
 *  \param tamanio de lista clientes
 *  \param lista de tipo electrodomestico
 *  \param tamanio de lista electrodomestico
 *  \param lista de tipo marca
 *  \param tamanio de lista marca
 *  \return no reporta
 */

void ReparacionByNroSerie (eReparacion* listRepacaion,int tamReparacion,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes,
						   eElectrodomestico* listElectrodomesticos,int tamElectrodomesticos,eMarca* listMarca,int tamMarca,ePais* listPais);


/*
 * \brief recibe la lista de electrodomesticos y muestra solo los del modelo indicado por el usuario
 *  \param lista de tipo electrodomestico
 *  \param tamanio de la lista de electrodomestico
 *  \param lista de tipo marca
 *  \param tamanio de la lista marca
 *  \return no retorna nada solo muestra por pantalla
 */
void printElectrodomesticoByAnio (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca);

/*
 * \brief muesta por pantalla la lista de electrodomesticos correspondientes a la marca indicada por el usuario
 *  \param lista de tipo electrodomestico
 *  \param tamanio de la lista de electrodomestico
 *  \param lista de tipo amrca
 *  \param tamnio de la lista marca
 *  \return no retorna solo muestra poir pantalla
 */
void printElectrodomesticoByMarca (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca);

/*
 * \brief muestra por pantalla los electrodomesticos que nunca fueron reparados
 *  \param lsiota de tipo electrodomestico
 *  \param tamanio de la lsita de electrodomestico
 *  \param lista de tipo marca
 *  \param tamanio de la lsita de tipo marca
 *  \param lista de tipo reparaciones
 *  \param tamanio de la lista de reparaciones
 *  \return no retorna solo mesta por pantalla
 */
void printElectrodomesticoNoReparado (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca,eReparacion* listRepacaion,int tamReparacion,ePais*listPaises);

/*
 * \brief cuenta la cantidad de reparaciones totales
 *  \param lista de reparaciones
 *  \param tamanio de la lista de reparaciones
 *  \return retorna la cantidad o cero si no las hay.
 */
int conterReparacion(eReparacion* listRepacaion,int tamReparacion);

/*
 * \brief muestra por pantallla el monto total que gasto ese electrodomestico indicado
 *  \param lista de tipo electrodomestico
 *  \param tamanio de la lista de electrodomestico
 *  \param lista de tipo reparacion
 *  \param tamanio de la lista de reparaciones
 *  \param lista de tipo servicios
 *  \param tamanio de la lista servicios
 *  \param lista de tipo clientes
 *  \param tamanio de la lista clientes
 *  \return no retorna solo imprime por pantalla
 */
void printImporteTotalReparacionesByElectrodomestico (eElectrodomestico* listElectrodomesticos, int tamElectrodomesticos,eReparacion* listReparaciones,
													  int tamReparaciones,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes);

/*
 * \brief imprime por pantalla el servicio mas solicitado
 *  \param lista de tipo reparaciones
 *  \param	tamanio de la lista reparaciones
 *  \param lista de tipo servicios
 *  \param tamanio de la lista de servicios
 *  \return	no retorna solo imprime por pantalla
 */

void printServicioMasPedido (eReparacion* listReparaciones,int tamReparaciones,eServicio* listServicio,int tamServicio);

/*
 * \brief muesta por pantalla la recaudacion total por fecha indicada
 *  \param lista de tipo reparaciones
 *  \param tamanio de la lista de reparaciones
 *  \param lista de servicios
 *  \param tamanio de la lista de servicios
 *  \return no retorna solo imprime por pantalla
 */
void recaudacionByFecha (eReparacion* listReparaciones,int tamReparaciones,eServicio* listServicio,int tamServicio);

/*
 * \brief imprime por pantalla reparaciones del concepto garantias
 *  \param	 lista de reparaciones
 *  \param tamanio de la lista de reparaciones
 *  \param lista de tipo servicios
 *  \param tamanio de la lista servicios
 *  \param	lista de tipo clientes
 *  \param tamanio de la lista clientes
 *  \return	 no retorna solo imprime por pantalla
 */

void printReparacionSIESGarantia (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients);

/*
 * \brief
 *  \param
 *  \param
 *  \return
 */
void printReparacionByAnio (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients,eElectrodomestico* listElectrodomestico, int tamElectrodomestico);
/*
 * \brief
 *  \param
 *  \param
 *  \return
 */

void printImporteTotalReparaciones (eElectrodomestico* listElectrodomesticos, int tamElectrodomesticos,eReparacion* listReparaciones,
													  int tamReparaciones,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes);
/*
 * \brief
 *  \param
 *  \param
 *  \return
 */
void printMarcaConMasRefacciones (eElectrodomestico* listElectrodomesticos, int tamElectrodomesticos,eReparacion* listReparaciones,
		  	  	  	  	  	  	  int tamReparaciones,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes,
								  eMarca* listMarcas,int tamMarcas);
/*
 * \brief
 *  \param
 *  \param
 *  \return
 */
void printReparacionXFecha (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients);





#endif /* INFORMES_H_ */
