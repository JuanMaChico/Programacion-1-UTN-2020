/*
 * utn.c
 * 	Biblioteca de Funciones UTN.
 *      Author: Juan Manuel Chico
 */
#ifndef UTN_H_
#define UTN_H_


/*\
 *\Brief Pide un entero por pantalla, valida que se encuentre dentro de un rango.
 *\param Texto que corresponde al pedido(Ej: "Ingrese Edad: ").
 *\param Texto que corresponde al error(Ej: "La edad ingresada no existe. Intente nuevamente: ").
 *\return Retorna el valor correspondiente al pedido.
 */
int utn_GetNumber (char texto[],char textoError[], int min, int max);

/*\
 *\Brief Valida el numero ingresado en TomaEntero(); que se encuentre entre el min y max.
 *\param Numero entero Ingresado por el Usuario.
 *\param Numero entero minimo permitido.
 *\param Numero entero maximo permitido.
 *\return 1 falso o 0 verdadero.
 */
int ValidaMinMax(int dato, int min, int max);

/*\
 *\Brief Pide un flotante por pantalla, valida que se encuentre dentro de un rango.
 *\param Texto que corresponde al pedido(Ej: "Ingrese Suledo: ").
 *\param Texto que corresponde al error(Ej: "El sueldo ingresada no corresponde. Intente nuevamente: ").
 *\return Retorna el valor correspondiente al pedido.
 */
float utn_GetNumberFloat(char texto[],char textoError[], float min, float max);

/*\
 *\Brief Valida el numero ingresado en TomaFlotante(); que se encuentre entre el min y max.
 *\param Numero flotante Ingresado por el Usuario.
 *\param Numero flotante minimo permitido.
 *\param Numero flotante maximo permitido.
 *\return 1 falso o 0 verdadero.
 */
int ValidaMinMaxFloat(float dato, float min, float max);

/**
 * \brief Pide el ingreso de un dato string (cadena de char).
 *  \param	direccion donde guardara el array de char.
 *  \param	Texto que interactuara con el usuario.
 *  \param	tamanio del array
 *  \return	no retorna nada.
 */

void utn_GetName(char name[],char text[],int tam);


/**
 * \brief	valida lo ingresado en utn_GetName que efectivamente sean caracteres alfabeticos correspondientes a un nombre en castellano.
 *  \param	direccion de memoria del array donde se guardo el nombre.
 *  \param	cantidad limite de caracteres que pueden usarse sin desbordar el array name.
 *  \return	retorna 0 en caso de error o 1 en caso contrario.
 */
int isName (char*cadena, int limite);

/*\
 *\Brief Recorre un array y inicializa todas las posiciones en 0, liberando el espacion de posible basura.
 *\param Recibe el array que se desea inicializar
 *\param Numero entero correspondiente al tamanio del array.
 *\return no retorna nada.
 */


void utn_InitArrayInt(int array[], int tam);

/*\
 *\Brief Carga la primera posicion disponible de un array de enteros.
 *\param Recibe el array que se desea cargar.
 *\param Numero entero correspondiente al tamanio del array
 *\param Numero entero que se desea cargar en el array
 *\returnRetorna 1 en caso de carga exitosa o 0 en el caso contrario.
 */
int CargaSecuencialArrayInt(int array[],int tam,int dato);

/*\
 *\Brief Carga un dato en un array en la posicion indicada por el usuario.
 *\param Numero correspondiente al tamanio del array
 *\param Numero correspondiente al dato que se quiere cargar en el array
 *\param Numero correspondiente a la posicion en la que se desa cargar el array
 *\return Retorna 1 en caso de que la carga este correcta o cero en caso contrario.
 */
int CargaAleatoriaArrayInt(int array[],int tam,int dato,int posicion);


/*\
 *\Brief Recibe un array de enteros y lo muestra por pantalla mostrando su ID o posicion en el array
 *\param Array que se desea mostrar.
 *\param Texto correspondiente al dato que se va a mostrar
 *\return retorna 1 si existen datos para mostrar, o cero en caso contrario.
 */
int MostrarArrayInt(int array[],char text[],int tam);


/*\
 *\Brief Ordena un array de mayor a menor por burbujeo
 *\param Recibe el array que se desea ordenar.
 *\param Recibe el tamanio del array a ordenar/
 *\return Retorna la cantidad de iteraciones que fueron necesarias para acomodar el array
 *\return o -1 en caso de no poder ordenarlo por algun error en el proseso de ordenado.
 */
int ordenarArrayInt(int* array,int tam);


/**
 * \brief Realiza el formateo de un string colocando la primera letra en mayuscula
 *  \param	recibe la cadena a formatear
 *  \param	recibe el tamanio de la cadena a formatear
 *  \return	no retorna nada!
 */
void formatName(char name[],int tam);

int nroMayor (char id,int* lastID);

















#endif /* UTN_H_ */
