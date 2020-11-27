/*
 ===========================================+
 Name        : 2do-Parcial-Laboratorio-2.c  |
 Author      : Juan Manuel Chico            |
 Version     : parser.c						|
 Description : 2do Parcial Laboratorio 1	|
 ===========================================+
 */
#include <stdio.h>
#include <stdlib.h>

#include "Articulos.h"
#include "LinkedList.h"

int parser_ArticuloFromText(FILE* pFile , LinkedList* pArrayListArticulo,int* lastID){

    int retorno= 0;
    eArticulo *pElement;

	char id[100];
	char articulo[100];
	char precio[100];
	char medida[100];
	char rubroId[100];

    int auxLastId=-1;

    if(pFile!=NULL && pArrayListArticulo!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,id,id,id,id);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubroId);

            pElement = articulo_newParametros(id,articulo,medida,precio,rubroId);

            if(pElement != NULL)
            {
                if(ll_add(pArrayListArticulo,pElement)==0){
                	if(atoi(id)>auxLastId){
                		auxLastId=atoi(id);
                	}
                    retorno++;
                }
            }
        }
    }
    if(retorno>0){
    	*lastID= auxLastId;
    }
    return retorno;
}
