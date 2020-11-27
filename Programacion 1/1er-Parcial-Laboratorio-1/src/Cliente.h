/*
 * Cliente.h
 *      Author: Juan Manuel Chico
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int id;
	char nombre[51];
	char apellido[51];
}eCliente;


/*
 * \brief Carga de manera automatica los clientes.
 * \param Lista de tipo clientes
 * \param tamanio de la lista de clientes
 * \return no retorna.
 */
void harcodeoClients (eCliente* listClients,int tam);

/*
 * \brief imprime por pantalla cuadro con la informacion cargada en la esctrucutra cliente
 *  \param lista de clientes
 *  \param tamanio de la lista
 *  \return no retorna.
 */
void printClinetes (eCliente* listClients,int tam);

/*
 * \brief busca el nombre y apellido de un cliente y lo devuelve por copia.
 *  \param  lista de clientes
 *  \param  tamanio de la lista
 *  \param id del cliente que se desea optener los datos
 *  \param direccion donde se guardara el nombre
 *  \param direccion donde se guardara el apellido
 *  \return  no retorna.
 */
void nombreByIdCliente (eCliente* listClients,int tam,int idCliente,char nombre[],char apellido[]);










#endif /* CLIENTE_H_ */
