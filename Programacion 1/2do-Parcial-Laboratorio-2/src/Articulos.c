/*
 ===========================================+
 Name        : 2do-Parcial-Laboratorio-2.c  |
 Author      : Juan Manuel Chico            |
 Version     : Articulos.c					|
 Description : 2do Parcial Laboratorio 1	|
 ===========================================+
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Articulos.h"
#include "LinkedList.h"

eArticulo* articulo_new()
{
    return (eArticulo*) malloc(sizeof (eArticulo));
}

eArticulo* articulo_newParametros(char* idStr,char* articuloStr, char* medidaStr,char* precioStr,char*rubroIdStr)
{
	eArticulo* aux;
    aux = articulo_new();

    if(aux !=  NULL)
    {

    	articulo_setIdS(aux , idStr);

    	articulo_setNombre(aux, articuloStr);

    	articulo_setprecioS(aux, precioStr);

    	articulo_setMedidaS(aux, medidaStr);

    	articulo_setrubroIdS(aux, rubroIdStr);
    }
    return aux;
}

int articulo_setId(eArticulo* this,int id)
{
    int Retorno =-1;
    if(this != NULL && id>0)
    {
        this->id =id;
        Retorno = 0;
    }
    return Retorno;
}

int articulo_setIdS(eArticulo* this,char* id)
{
    int Retorno=-1;
    int idAux;
    if(this!=NULL && id!=NULL)
    {
        if(isValidNumber(id)==0)
        {
            idAux = atoi(id);
            if(articulo_setId(this,idAux)==0)
            {
            	Retorno=0;
            }
        }
    }
    return Retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=0;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int articulo_setNombre(eArticulo* this,char* nombre)
{
    int Retorno =-1;

    if(this != NULL)
    {
         strcpy (this->articulo, nombre);
    }
    return Retorno;
}

int articulo_setprecio(eArticulo* this,float precio)
{
    int Retorno =-1;

    if(this != NULL && precio>0)
    {
        this->precio = precio;
        Retorno = 0;
    }
    return Retorno;
}

int articulo_setprecioS(eArticulo* this,char* precioS)
{
    int Retorno=-1;
    float precioAux;
    if(this!=NULL && precioS!=NULL)
    {
        if(isValidNumber(precioS)==0)
        {
            precioAux = atof(precioS);
            if(articulo_setprecio(this,precioAux)==0)
            {
            	Retorno=0;
            }
        }
    }

    return Retorno;
}

int articulo_setMedidaS(eArticulo* this,char* medidaStr)
{
    int Retorno =-1;

    if(this != NULL)
    {
         strcpy(this->medida, medidaStr);
    }
    return Retorno;
}

int articulo_setrubroIdS(eArticulo* this,char* idrubro)
{
    int Retorno=-1;
    int idAux;
    if(this!=NULL && idrubro!=NULL)
    {
        if(isValidNumber(idrubro)==0)
        {
            idAux = atoi(idrubro);
            if(articulo_setrubroId(this,idAux)==0)
            {
            	Retorno=0;
            }
        }
    }
    return Retorno;
}

int articulo_setrubroId(eArticulo* this,int idrubro)
{
    int Retorno =-1;
    if(this != NULL && idrubro>0)
    {
        this->rubroId =idrubro;
        Retorno = 0;
    }
    return Retorno;
}

int articulo_getId(eArticulo* this,int* id)
{
    int Retorno=-1;

    if(this != NULL && id != NULL)
    {
        *id= this->id;
        Retorno=0;
    }
    return Retorno;
}

int articulo_getArticulo(eArticulo* this,char* nombre)
{
    int Retorno =-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->articulo);

        Retorno =1;
    }
    return Retorno;
}

int articulo_getMedida(eArticulo* this,char* medida)
{
    int Retorno =-1;

    if(this != NULL && medida != NULL)
    {
        strcpy(medida, this->medida);
        Retorno =1;
    }
    return Retorno;
}

int articulo_getPrecio(eArticulo* this,float* precio)
{
    int Retorno =-1;
    if(this != NULL && precio>0)
    {
    	*precio=this->precio;
        Retorno = 0;
    }
    return Retorno;
}

int articulo_getRubroId(eArticulo* this,int* idrubro)
{
    int Retorno=-1;

    if(this != NULL && idrubro != NULL)
    {
        *idrubro= this->rubroId;
        Retorno=0;
    }
    return Retorno;
}



int Articulo_printArticulo(LinkedList* pArrayListArticulo, int index,eRubro* listaRubro){
    eArticulo* articuloAux;
	int id;
	char articulo[100];
	float precio;
	char medida[100];
	int rubroId;
	char rubroAux[100];
    int Retorno=-1;
    if(pArrayListArticulo!=NULL && index>=0 && index<ll_len(pArrayListArticulo))
    {
        articuloAux=(eArticulo*)ll_get(pArrayListArticulo,index);
        articulo_getId(articuloAux,&id);
        articulo_getArticulo(articuloAux,articulo);
        articulo_getMedida(articuloAux,medida);
        articulo_getPrecio(articuloAux,&precio);
        articulo_getRubroId(articuloAux,&rubroId);

        buscaRubroPorID(rubroId,listaRubro,rubroAux);

        printf("|%5d|   %35s   |  %10.2f  |   %10s    |   %19s   |\n",id,articulo,precio,medida,rubroAux);
        Retorno=0;
    }
    return Retorno;
}
void buscaRubroPorID(int idRubro,eRubro* listaRubro,char rubroS[]){

	for (int i = 0; i < 5; ++i){
		if(idRubro == listaRubro[i].id){
			strcpy(rubroS,listaRubro[i].rubro);
		}
	}
}



int articulo_OrdenaCadenaNombre(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    eArticulo* articuloA;
    eArticulo* articuloB;
    articuloA = (eArticulo*)elementoA;
    articuloB = (eArticulo*)elementoB;

    if(strcmp(articuloA->articulo, articuloB->articulo)<0)
    {
        Retorno =1 ;
    }
    if(strcmp(articuloA->articulo, articuloB->articulo)>0)
    {
        Retorno = -1;
    }
    return Retorno;
}

int articulos_countPrecio(void* articulo){
	int retorno;
	float auxPrecio;
	eArticulo* auxArticulo = (eArticulo*) articulo;
	if(auxArticulo!=NULL){
		articulo_getPrecio(auxArticulo, &auxPrecio);
		if(auxPrecio > 100){
			retorno=1;
		}else{
			retorno=0;
		}
	}
	return retorno;
}

int articulos_countXrubro (void* articulo){
	int retorno;
	int auxIdRubro;
	eArticulo* auxArticulo = (eArticulo*) articulo;
	if(auxArticulo != NULL){
		articulo_getRubroId(auxArticulo, &auxIdRubro);
		if(auxIdRubro == 1){
			retorno =1;
		}else{
			retorno=0;
		}
	}
	return retorno;
}

void harcodeoRubros(eRubro* listaRubro,int len) {
	int id[]={1,2,3,4};
	char nombre[5][100]={"CUIDADO DE ROPA           ","LIMPIEZA Y DESINFECCION   ","CUIDADO PERSONAL E HIGIENE","CUIDADO DEL AUTOMOTOR     ","\0"};
	for (int i = 0; i < len; ++i){
		listaRubro[i].id=id[i];
		strcpy(listaRubro[i].rubro,nombre[i]);
	}
}



