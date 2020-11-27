/*
 ===========================================+
 Name        : 2do-Parcial-Laboratorio-2.c  |
 Author      : Juan Manuel Chico            |
 Version     : parser.h						|
 Description : 2do Parcial Laboratorio 1	|
 ===========================================+
 */
#ifndef PARSER_H_
#define PARSER_H_

/*
 * \brief  recibe un archivo con el fin de cargarlo en una linkedlist
 *  \param puntero a FILE
 *  \param puntero a lista inteligente
 *  \param puntero a int lastID donde se guardara el ultimo ID generado por la lsita inteligente
 *  \return retorna cantidad de elementos aregados.
 */
int parser_ArticuloFromText(FILE* pFile , LinkedList* pArrayListArticulo,int* lastID);

#endif /* PARSER_H_ */
