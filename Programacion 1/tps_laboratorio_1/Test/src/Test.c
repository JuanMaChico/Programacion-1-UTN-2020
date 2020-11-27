

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nroMayor (int id,int* lastID);


int main(void) {
	setbuf(stdout,NULL);
	int contadorID=0;



	for (int i = 0; i < 10; ++i) {
		nroMayor(i,&contadorID);

		printf("%d \n",contadorID);
	}

	printf("last id: %d \n",contadorID);



	return 0;
}

int nroMayor (int id,int* lastID){
	int retorno=0;

	if( id > *lastID ){

		*lastID=id;
		retorno++;
	}

	return retorno;
}
