/*
 * Informes.c
 *      Author: Juan Manuel Chico
 */

#include "Informes.h"
#include "Reparacion.h"
#include "Marca.h"

void reparacionByClientes (eReparacion* listRepacaion,int tamReparacion,eServicio* listServicio,int tamServicio,eCliente* listClientes,int tamClientes){
	for (int i=0; i<tamClientes;++i){
	printf("\n Cliente: %s, %s \n",listClientes[i].apellido,listClientes[i].nombre);

		if(conterReparacionByClientes(listRepacaion, tamReparacion, (listClientes[i].id))>0){
			printreparacionByClientes(listRepacaion, tamReparacion, listServicio, tamServicio, listClientes, tamClientes, (listClientes[i].id));
		}else{
			printf("No contiene reparaciones.\n");
		}
	}
}

void printReparacionCliente (eReparacion* listRepacaion,int tamReparacion,eServicio* listServicio,int tamServicio,eCliente* listClientes,int tamClientes){
	printClinetes(listClientes, tamClientes);
	int auxIdCliente=utn_GetNumber("Ingrese Id del Cliente ","Error,Reintente:",1,3);
		if(conterReparacionByClientes(listRepacaion, tamReparacion, auxIdCliente)>0){
			printreparacionByClientes(listRepacaion, tamReparacion, listServicio, tamServicio, listClientes, tamClientes, auxIdCliente);
		}else{
			printf("No contiene reparaciones.\n");
		}
	}


void printreparacionByClientes (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients,int idCliente){
	char descript[26];
	char nombre[51];
	char apellido[51];
	printf("+-------------------------------------------------------------------------------------------------+\n");
	printf("|%8s  %13s  %15s  %15s  %15s  %15s      |\n","ID","SERIE "," NOMBRE "," APELLIDO ","SERVICIO"," FECHA ");
	printf("+-------------------------------------------------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1 && list[i].idClients == idCliente){

				ServicioDescripcionByID(listServicio, tamServicio,(list[i].idServicio), descript);
				nombreByIdCliente(listClients, tamClients,(list[i].idClients), nombre, apellido);

				printf("|%-8d|  %10d  |  %15s  |  %15s  |  %10s  |  %8d/%d/%d | \n",list[i].id,list[i].serie,nombre,apellido, descript, list[i].fecha.dia,list[i].fecha.mes,  list[i].fecha.anno);
				printf("+-------------------------------------------------------------------------------------------------+\n");
			}
		}
	}
}
int conterReparacionByClientes (eReparacion* listRepacaion,int tamReparacion,int idCliente){
	int reply=0;
	for (int i = 0; i < tamReparacion; ++i){
		if(listRepacaion[i].idClients==idCliente){
			reply++;
		}
	}
	return reply;
}

void ReparacionByNroSerie (eReparacion* listRepacaion,int tamReparacion,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes,
						   eElectrodomestico* listElectrodomesticos,int tamElectrodomesticos,eMarca* listMarca,int tamMarca,ePais* listPais){
	int vSerie;
	int serie;
	char descript[26];
	char nombre[51];
	char apellido[51];
	printElectrodomestico(listElectrodomesticos, tamElectrodomesticos, listMarca, tamMarca,listPais);
	do {
		serie=utn_GetNumber("Ingresar numero de serie(Nro:XXXXX):","Error, Reintente",9999,9999999);
		for (int i = 0; i < 1000; ++i){
			if(listElectrodomesticos[i].serie == serie){
				vSerie=0;
				break;
			}else{vSerie=1;}
		}
	} while (vSerie);
	printf("+-------------------------------------------------------------------------------------------------+\n");
	printf("|%8s  %13s  %15s  %15s  %15s  %15s      |\n","ID","SERIE "," NOMBRE "," APELLIDO ","SERVICIO"," FECHA ");
	printf("+-------------------------------------------------------------------------------------------------+\n");
	for (int i=0; i<tamReparacion;++i){
		if(listRepacaion[i].serie == serie && listRepacaion[i].isEmpty==1){
			ServicioDescripcionByID(listServicio, tamServicio,(listRepacaion[i].idServicio), descript);
			nombreByIdCliente(listClientes, tamClientes,(listRepacaion[i].idClients), nombre, apellido);
			printf("|%-8d|  %10d  |  %15s  |  %15s  |  %10s  |  %8d/%d/%d | \n",listRepacaion[i].id,listRepacaion[i].serie,nombre,apellido, descript, listRepacaion[i].fecha.dia,listRepacaion[i].fecha.mes,listRepacaion[i].fecha.anno);
			printf("+-------------------------------------------------------------------------------------------------+\n");
		}
	}
}

void printElectrodomesticoByAnio (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca){
	char descript[21];
	int AuxModelo;
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  %20s | \n","ID","SERIE","MARCA","MODELO");
	printf("+-----------------------------------------------------------------------------+\n");
	if(tam>0){
		//AuxModelo = utn_GetNumber("Ingrese Modelo (formato Nros: xxxx):","Error, reintente",1980,2020);
		AuxModelo = 2020;
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1 && list[i].modelo == AuxModelo){
				MarcaDescripcionByID(listMarca, tamMarca,(list[i].idMarca), descript);
				printf("+-----------------------------------------------------------------------------+\n");
				printf("|%10d|  %20d|  %20s|   %17d| \n", list[i].id, list[i].serie, descript, list[i].modelo);
				printf("+-----------------------------------------------------------------------------+\n");
			}
		}
	}
}
void printElectrodomesticoByMarca (eElectrodomestico* list, int tam,eMarca* listMarca,int tamMarca){
	char descript[21];
	int AuxMarca;
	if(tam>0){
		printf("\n\n+--------------Marcas-------------+\n");
		printMarcas(listMarca, 5);
		AuxMarca = utn_GetNumber("Ingrese Marca (formato Nros: xxxxx):","Error, reintente",1000,1004);
		printf("+-----------------------------------------------------------------------------+\n");
		printf("|%10s  %20s  %20s  %20s | \n","ID","SERIE","MARCA","MODELO");
		printf("+-----------------------------------------------------------------------------+\n");
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1 && list[i].idMarca == AuxMarca){
				MarcaDescripcionByID(listMarca, tamMarca,(list[i].idMarca), descript);
				printf("+-----------------------------------------------------------------------------+\n");
				printf("|%10d|  %20d|  %20s|   %17d| \n", list[i].id, list[i].serie, descript, list[i].modelo);
				printf("+-----------------------------------------------------------------------------+\n");
			}
		}
	}
}

int conterReparacion(eReparacion* listRepacaion,int tamReparacion){
	int reply=0;
	for (int i = 0; i < tamReparacion; ++i){
		if(listRepacaion[i].isEmpty==1){
			reply++;
		}
	}
	return reply;
}

// Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado

void printImporteTotalReparacionesByElectrodomestico (eElectrodomestico* listElectrodomesticos, int tamElectrodomesticos,eReparacion* listReparaciones,
													  int tamReparaciones,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes){
	float montoTotal=0;
	int auxSerial;

	printReparacion(listReparaciones, tamReparaciones, listServicio, tamServicio, listClientes, tamClientes);
	auxSerial = utn_GetNumber("Ingrese Nro de Serie del electrodomestico: ","Error,Reintente...",9999,999999);

	for (int i = 0; i < tamReparaciones; ++i){
		if(listReparaciones[i].isEmpty == 1 && listReparaciones[i].serie == auxSerial){
			for (int j = 0; j < tamServicio; ++j){
				if(listServicio[j].id == listReparaciones[i].idServicio){
					montoTotal += listServicio[j].precio;
				}
			}
		}
	}
	printf("El electrodomestico serie: %d cuenta con un total por reparaciones de: %.2f\n",auxSerial,montoTotal);
}

void printServicioMasPedido (eReparacion* listReparaciones,int tamReparaciones,eServicio* listServicio,int tamServicio){
	int auxIdServicio;
	int contadorGarantia=0;
	int contadorMantenimiento=0;
	int contadorRepuestos=0;
	int contadorRefacciones=0;
	for (int i = 0; i < tamReparaciones; ++i){
		if(listReparaciones[i].isEmpty==1){
			auxIdServicio = (listReparaciones[i].idServicio);

			switch (auxIdServicio) {
				case 20000:
					contadorGarantia++;
					break;
				case 20001:
					contadorMantenimiento++;
					break;
				case 20002:
					contadorRepuestos++;
					break;
				case 20003:
					contadorRefacciones++;
					break;
			}
		}
	}
	if(contadorGarantia == contadorMantenimiento && contadorGarantia == contadorRepuestos  && contadorGarantia == contadorRefacciones){
		printf("\nTodos los servicios han sido demandados por igual\n");
	}else if(contadorMantenimiento >= contadorGarantia && contadorMantenimiento >= contadorRepuestos  && contadorMantenimiento >= contadorRefacciones){
		printf("\nEl servicio mas usado es actualmente: Mantenimientos\n");
	}else if(contadorRepuestos >= contadorGarantia && contadorRepuestos >= contadorMantenimiento  && contadorRepuestos >= contadorRefacciones){
		printf("\nEl servicio mas usado es actualmente: Repuestos\n");
	}else if(contadorRefacciones >= contadorGarantia && contadorRefacciones >= contadorMantenimiento  && contadorRefacciones >= contadorRepuestos){
		printf("\nEl servicio mas usado es actualmente: Refacciones\n");
	}else if (contadorGarantia >= contadorMantenimiento && contadorGarantia >= contadorRepuestos  && contadorGarantia >= contadorRefacciones){
		printf("\nEl servicio mas usado es actualmente: Garantias\n");
	}
}

void recaudacionByFecha (eReparacion* listReparaciones,int tamReparaciones,eServicio* listServicio,int tamServicio){
	eFecha fechaAux;
	float recaudacionDia=0;
	getFechaReparacion(&fechaAux);
	for (int i = 0; i < tamReparaciones; ++i){
		if(listReparaciones[i].isEmpty==1){
			if(fechaAux.dia == listReparaciones[i].fecha.dia && fechaAux.anno == listReparaciones[i].fecha.anno && fechaAux.mes == listReparaciones[i].fecha.mes){
				for (int r = 0; r < 4; ++r){
					if(listReparaciones[i].idServicio == listServicio[r].id){
						recaudacionDia += listServicio[r].precio;
					}
				}
			}
		}
	}
	printf("El Dia %d/%d%d se recaudo: $ %.2f",fechaAux.dia,fechaAux.mes,fechaAux.anno,recaudacionDia);
}

void printElectrodomesticoNoReparado (eElectrodomestico* listElectrodomestico, int tamElectrodomestico,eMarca* listMarca,int tamMarca,eReparacion* listRepacaion,int tamReparacion,ePais*listPaises){
	char descript[21];
	int vReparado=0;
	if(tamElectrodomestico>0){
		if(conterReparacion(listRepacaion, tamReparacion)>0){
			printf("+-----------------------------------------------------------------------------+\n");
			printf("|%10s  %20s  %20s  %20s | \n","ID","SERIE","MARCA","MODELO");
			printf("+-----------------------------------------------------------------------------+\n");
			for (int i = 0; i < tamElectrodomestico; ++i){
				if(listElectrodomestico[i].isEmpty==1){
					for (int r = 0; r < tamReparacion; ++r){
						if(listRepacaion[r].isEmpty){
							if(listElectrodomestico[i].serie == listRepacaion[r].serie){
								vReparado=1;
								break;
							}
						}
					}
					if(vReparado==0){
						MarcaDescripcionByID(listMarca, tamMarca,(listElectrodomestico[i].idMarca), descript);
						printf("+-----------------------------------------------------------------------------+\n");
						printf("|%10d|  %20d|  %20s|   %17d| \n", listElectrodomestico[i].id, listElectrodomestico[i].serie, descript, listElectrodomestico[i].modelo);
						printf("+-----------------------------------------------------------------------------+\n");
					}
				}
				vReparado=0;
			}

		}else{
			printf("+-----------------------ELECTRODOMESTICOS NO REPARADOS-----------------------+\n");
			printElectrodomestico(listElectrodomestico, tamElectrodomestico, listMarca, tamMarca,listPaises);
		}
	}
}
void printReparacionSIESGarantia (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients){
	char descript[26];
	char nombre[51];
	char apellido[51];

	printf("+-------------------------------------------------------------------------------------------------+\n");
	printf("|%8s  %13s  %15s  %15s  %15s  %15s      |\n","ID","SERIE "," NOMBRE "," APELLIDO ","SERVICIO"," FECHA ");
	printf("+-------------------------------------------------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1 && list[i].idServicio == 20000){
				ServicioDescripcionByID(listServicio, tamServicio,(list[i].idServicio), descript);
				nombreByIdCliente(listClients, tamClients,(list[i].idClients), nombre, apellido);

				printf("|%-8d|  %10d  |  %15s  |  %15s  |  %10s  |  %8d/%d/%d | \n",list[i].id,list[i].serie,nombre,apellido, descript, list[i].fecha.dia,list[i].fecha.mes,  list[i].fecha.anno);
				printf("+-------------------------------------------------------------------------------------------------+\n");
			}
		}
	}
}
void printReparacionByAnio (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients,eElectrodomestico* listElectrodomestico, int tamElectrodomestico){
	char descript[26];
	char nombre[51];
	char apellido[51];

	printf("+-------------------------------------------------------------------------------------------------+\n");
	printf("|%8s  %13s  %15s  %15s  %15s  %15s      |\n","ID","SERIE "," NOMBRE "," APELLIDO ","SERVICIO"," FECHA ");
	printf("+-------------------------------------------------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(listElectrodomestico[i].isEmpty==1 && listElectrodomestico[i].modelo == 2018){
				for (int r = 0; r < tam; ++r){
					if(listElectrodomestico[i].serie == list[r].serie && list[r].isEmpty==1){

						ServicioDescripcionByID(listServicio, tamServicio,(list[i].idServicio), descript);
						nombreByIdCliente(listClients, tamClients,(list[i].idClients), nombre, apellido);
						printf("|%-8d|  %10d  |  %15s  |  %15s  |  %10s  |  %8d/%d/%d | \n",list[i].id,list[i].serie,nombre,apellido, descript, list[i].fecha.dia,list[i].fecha.mes,  list[i].fecha.anno);
						printf("+-------------------------------------------------------------------------------------------------+\n");

						//break;
					}
				}
			}

		}
	}
}

void printImporteTotalReparaciones (eElectrodomestico* listElectrodomesticos, int tamElectrodomesticos,eReparacion* listReparaciones,
													  int tamReparaciones,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes){
	float montoTotal=0;

	for (int i = 0; i < tamReparaciones; ++i){

		if(listReparaciones[i].isEmpty == 1 && listReparaciones[i].idServicio == 20001){

			for (int j = 0; j < tamServicio; ++j){

				if(listServicio[j].id == listReparaciones[i].idServicio){

					montoTotal += listServicio[j].precio;
				}
			}
		}
	}
	printf("La facturacion total por reparaciones es: %.2f\n",montoTotal);
}

//INFORMAR LA MARCA DE LOS ELECTRODOMESTICOS QUE EFECTUARON MAS REFACCIONES cod 20003
void printMarcaConMasRefacciones (eElectrodomestico* listElectrodomesticos, int tamElectrodomesticos,eReparacion* listReparaciones,
		  	  	  	  	  	  	  int tamReparaciones,eServicio* listServicio,int tamServicio, eCliente* listClientes,int tamClientes,
								  eMarca* listMarcas,int tamMarcas){

	int Wirpool=0;
	int Sony=0;
	int Liliana=0;
	int Gafa=0;
	int Philips=0;

	for (int i = 0; i < tamReparaciones; ++i){
		if(listReparaciones[i].isEmpty == 1){
			for (int x = 0; x < tamElectrodomesticos; ++x){
				if(listElectrodomesticos[x].isEmpty == 1 && listReparaciones[i].serie == listElectrodomesticos[x].serie){
					if(listReparaciones[i].idServicio == 20003){
						switch (listElectrodomesticos[x].idMarca){
							case 1000:
								Wirpool++;
								break;
							case 1001:
								Sony++;
								break;
							case 1002:
								Liliana++;
								break;
							case 1003:
								Gafa++;
								break;
							case 1004:
								Philips++;
								break;
						}
					}
				}
			}
		}
	}
	if(Wirpool > Sony && Wirpool > Liliana && Wirpool > Gafa && Wirpool > Philips){
		printf("\n La Marca con mas Refacciones realizadas es: Wirpool\n");
	}
	if(Sony > Wirpool && Sony > Liliana && Sony > Gafa && Sony > Philips){
		printf("\n La Marca con mas Refacciones realizadas es: Sony\n");
	}
	if(Liliana > Wirpool && Liliana > Sony && Liliana > Gafa && Liliana > Philips){
		printf("\n La Marca con mas Refacciones realizadas es: Liliana\n");
	}
	if(Gafa > Wirpool && Gafa > Sony && Gafa > Liliana && Gafa > Philips){
		printf("\n La Marca con mas Refacciones realizadas es: Gafa\n");
	}
	if(Philips > Wirpool && Philips > Sony && Philips > Liliana && Philips > Gafa){
		printf("\n La Marca con mas Refacciones realizadas es: Philips\n");
	}
}

//LISTAR LOS ELECTRODOMESTICOS QUE RECIBIERON REPARACIONES EN UNA FECHA DETERMINADA
void printReparacionXFecha (eReparacion* list, int tam,eServicio* listServicio,int tamServicio,eCliente* listClients,int tamClients){
	char descript[26];
	char nombre[51];
	char apellido[51];
	eFecha auxFecha;

	getFechaReparacion(&auxFecha);

	printf("+-------------------------------------------------------------------------------------------------+\n");
	printf("|%8s  %13s  %15s  %15s  %15s  %15s      |\n","ID","SERIE "," NOMBRE "," APELLIDO ","SERVICIO"," FECHA ");
	printf("+-------------------------------------------------------------------------------------------------+\n");
	if(tam>0){
		for (int i = 0; i < tam; ++i){
			if(list[i].isEmpty==1 && auxFecha.dia == list[i].fecha.dia && auxFecha.mes == list[i].fecha.mes && auxFecha.anno == list[i].fecha.anno){
				ServicioDescripcionByID(listServicio, tamServicio,(list[i].idServicio), descript);
				nombreByIdCliente(listClients, tamClients,(list[i].idClients), nombre, apellido);

				printf("|%-8d|  %10d  |  %15s  |  %15s  |  %10s  |  %8d/%d/%d | \n",list[i].id,list[i].serie,nombre,apellido, descript, list[i].fecha.dia,list[i].fecha.mes,  list[i].fecha.anno);
				printf("+-------------------------------------------------------------------------------------------------+\n");
			}
		}
	}
}








