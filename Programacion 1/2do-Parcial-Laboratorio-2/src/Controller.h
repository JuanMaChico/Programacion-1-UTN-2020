/*
 ===========================================+
 Name        : 2do-Parcial-Laboratorio-2.c  |
 Author      : Juan Manuel Chico            |
 Version     : controller.h					|
 Description : 2do Parcial Laboratorio 1	|
 ===========================================+
 */

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si no se pudo abrir archivo 1 si esta todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArticulo,int* lastID);

/*
 * \brief toma la el puntero a lista y llama a la funcion que imprime por pantalla los datos cargados
 *  \param	puntero a la lista
 *  \return	retorna 1 si pudo imprimir o 0 en caso de no poder realizar la imprecion
 */
int controller_ListArticulo(LinkedList* pArrayListArticulo,eRubro* listaRubro);

/*
 * \brief ordena los elementos de la lista de la A a la Z
 *  \param	puntero a la lista
 *  \return	retorna 1 en caso de no poder imprimir o 0 en caso de poder realizar la imprecion si error
 */
int controller_sortArticulo(LinkedList* pArrayListEmployee,eRubro*listaRubro);

/*
 * \brief recibe el nombre del archivo con el que se desea guardar y guarda los cambios
 *  \param	nombre del archivo a guardar
 *  \param	puntero a la lista
 *  \return	retorna 1 en caso de contener error o 0 en caso de no tener error
 */
int controller_saveAsText(char* path , LinkedList* pArrayListArticulos);


/*
 * \brief calcula el desuento correspondiente para el elemento
 *  \param	puntero al elemento
 *  \return	retorna el 1 en caso de poder realizar el descuento o 0 en caso de no poder hacerlo
 */
int calculaDescuento (void* pElemento);

/*
 * \brief realiza la carga de todos los datos mapeados con el descuento
 *  \param	puntero a la lista
 *  \return	retorna o en caso de poder ser mapeado y 1 en caso de no poder cargar el archivo
 */
int controller_MapearArticulo(LinkedList* pArrayListEmployee,eRubro*listaRubro);

/*
 * \brief realiza el conteo de los elementos que cumplen con el filtro de precio
 *  \param	puntero a la lista
 *  \return	retorna 1 en caso de poder realizar el conteo
 */
int controller_conterPorPrecio (LinkedList* pArrayListEmployee);


/*
 * \brief realiza el conteo de los elementos que cumplen con el filtro de rubro
 *  \param	puntero a la lista
 *  \return	retorna 1 en caso de poder realizar el conteo
 */
int controller_conterPorRubro(LinkedList* pArrayListEmployee);


