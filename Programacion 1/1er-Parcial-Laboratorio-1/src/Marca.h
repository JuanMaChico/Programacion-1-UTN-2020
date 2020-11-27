/*
 * Marca.h
 *      Author: Juan Manuel Chico
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id;
	char descripcion[21];
}eMarca;



/**
 * \brief carga de manera automatica los datos correspondiente a Marca en la lista de tipo marca
 *  \param lista de tipo Marca
 *  \return no retorna
 */
void harcodeoDatosMarcas (eMarca* list);

/*
 * \brief  Imprime un cuadro de los datos cargados en la estructura Marca
 *  \param	lista de tipo marca
 *  \param	tamanio de la lista
 *  \return	 no retorna nada.
 */
void printMarcas (eMarca* list, int tam);

/*
 * \brief busca la descripcion y la devuelve por copia
 *  \param	lista de tipo marca
 *  \param	tamanio de lista marca
 *  \param id de la marca que se desea saber la descripcion
 *  \param puntero donde se desea copiar la descripcion encontrada
 *  \return	no retorna nada.
 */
void MarcaDescripcionByID (eMarca* listMarca,int tamMarca,int id,char descripcion[]);











#endif /* MARCA_H_ */
