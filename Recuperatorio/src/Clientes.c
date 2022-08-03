/*
 * Clientes.c
 *
 *  Created on: 3 ago. 2022
 *      Author: Gian
 */

#include "Clientes.h"


int main_Menu(){
		int option;

		printf("\n\t>-MENU PRINCIPAL-<\t\n");
		printf("-----------------------------------------\n");
		printf("Opcion 1 ALTA DE CLIENTE \n");
		printf("Opcion 2 MODIFICAR CLIENTE: \n");
		printf("Opcion 3 BAJA CLIENTE \n");
		printf("Opcion 4 ALTA DE PRESTAMO\n");
		printf("Opcion 5 SALDAR PRESTAMO \n");
		printf("Opcion 6 REANUDAR PRESTAMO \n");
		printf("Opcion 7 IMPRIMIR CLIENTES \n");
		printf("Opcion 8 IMPRIMIR PRESTAMOS \n");
		printf("Opcion 9 INFORMAR CLIENTES \n");
		printf("Opcion 10 INFORMAR PRESTAMOS \n");

		scanf("%d", &option);

		return option;
}

int subMenu_Modify(){
	printf("----------------------------MENU MODIFICAR------------------------------\n");
		int option;

		printf("\n Opcion 1 Modificar Nombre \n");
		printf("\n Opcion 2 Modificar Apellido \n");
		printf("\n Opcion 3 Modificar CUIL \n");
		printf("\n Opcion 4 Mostrar Lista de Clientes \n");
		printf("\n Opcion 5 Salir \n");

		scanf("%d", &option);

		return option;
}

int inicializarClientes(Cliente* clientes, int tamC){
	int retorno=-1;

	if(clientes!=NULL && tamC>0){
		for(int i=0; i<tamC; i++){
			clientes[i].isEmpty=1;
		}
		retorno=0;
	}

	return retorno;
}

int inicializarPrestamos(Prestamo* prestamos, int tamP){
	int retorno=-1;

	if(prestamos!=NULL && tamP>0){
		for(int i=0; i<tamP; i++){
			prestamos[i].isEmpty=1;
		}
		retorno=0;
	}

	return retorno;
}



int findEmptyCliente(Cliente* clientes, int tamCl, int* index){
	int retorno=-1;

	if(clientes!=NULL && index!=NULL && tamCl>0){
		for(int i=0; i<tamCl; i++){
			if(clientes[i].isEmpty==1){
				*index=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}


int altaDeCliente(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP, int* idCliente){
	int retorno=-1;

	int index=-1;

	printf("\n\t>-ALTA DE CLIENTE-<\t\n");
	printf("-----------------------------------------\n");

	if(clientes!=NULL && prestamos!=NULL && tamCl>0 && tamP>0 && idCliente!=NULL){
		findEmptyCliente(clientes, tamCl, &index);
		if(index!=-1){
			getStringSoloLetras("Ingrese el nombre del cliente \n", "Error, ingrese solo letras \n", clientes[index].nombre, 20, 2);
			getStringSoloLetras("Ingrese el apellido del cliente \n", "Error, ingrese solo letras \n", clientes[index].apellido, 20, 2);
			getStringTelefonoCuit("Ingrese el CUIL del Cliente", "Error. Intente nuevamente \n", clientes[index].cuil, 25, 2);

			(*idCliente)++;
			clientes[index].idCliente=*idCliente;
			clientes[index].isEmpty=0;
			 printf("          *** Nuevo Cliente Creado ***\n\n");
			 printf("ID Cliente  	 Nombre        Apellido    	  CUIL    \n");
			 printf("-----------------------------------------------------\n");
			mostrarUnCliente(clientes[index], clientes, tamCl);
			retorno=0;
		}


	}

	return retorno;
}



int mostrarClientes(Cliente* clientes, int tamCl){
	int retorno=-1;

	if(clientes!=NULL && tamCl>0){
 printf("          *** Listado de Clientes ***\n\n");
 printf("ID Cliente  	 Nombre        Apellido    	  CUIL    \n");
 printf("-----------------------------------------------------\n");
		for(int i=0; i<tamCl; i++){
			if(clientes[i].isEmpty==0){
				mostrarUnCliente(clientes[i], clientes, tamCl);
			}
		}
	}


	return retorno;
}

void mostrarUnCliente(Cliente unCliente, Cliente* clientes, int tamCl){

// Mostrar el nombre del duenio

	printf("%-9d        %-8s      %-13s      %-12s    \n", unCliente.idCliente
																				 , unCliente.nombre
																				 , unCliente.apellido
																				 , unCliente.cuil);

}

int findCliente_ById(Cliente* clientes, int tamCl, int auxId, int* index){
	int retorno=-1;

	if(clientes!=NULL && tamCl>0 && auxId>=0 && index!=NULL){
		for(int i=0; i<tamCl; i++){
			if(auxId == clientes[i].idCliente){
				retorno=0;
				*index=i;
				break;
			}
		}
	}

	return retorno;
}


int modificarCliente(Cliente* clientes, int tamCl){
	int retorno=-1;
	int auxId;
	int opcion;
	int index=-1;
	if(clientes!=NULL && tamCl>0){
		printf("\n\t>-MODIFICACION DE CLIENTE-<\t\n");
		printf("-----------------------------------------\n");
		mostrarClientes(clientes, tamCl);
		auxId=getValidInt("Ingrese el id de Cliente a Modificar \n", "Error, ingrese solo numeros \n ", 0, tamCl);
		findCliente_ById(clientes, tamCl, auxId, &index);
		if(index!=-1){
			do{

				opcion=subMenu_Modify();
				switch(opcion){
				case 1:
					puts("Usted a elegido la opcion 1: Modificar Nombre \n");
					getStringSoloLetras("Ingrese el nombre del cliente \n", "Error, ingrese solo letras \n", clientes[index].nombre, 20, 2);
					break;
				case 2:
					puts("Usted a elegido la opcion 2: Modificar Apellido \n");
					getStringSoloLetras("Ingrese el apellido del cliente \n", "Error, ingrese solo letras \n", clientes[index].apellido, 20, 2);
					break;
				case 3:
					puts("Usted a elegido la opcion 3: Modificar CUIL \n");
					getStringTelefonoCuit("Ingrese el CUIL del Cliente", "Error. Intente nuevamente \n", clientes[index].cuil, 25, 2);
					break;
				case 4:
					puts("Usted a elegido la opcion 4: Mostrar Listado de Clientes\n");
					mostrarClientes(clientes, tamCl);
					break;
				case 5:
					puts("Menu Principal \n");
					retorno=0;
					break;
				}
			}while(opcion!=5);
		}else{
			puts("Cliente Invalido \n");
		}
	}

	return retorno;
}

int eliminarCliente(Cliente* clientes, int tamCl){
	int retorno=-1;
	int auxId;
	int index=-1;
	char respuesta[4];
	strcpy(respuesta, "no");
	if(clientes!=NULL && tamCl>0){
		printf("\n\t>-ELIMINACION DE CLIENTE-<\t\n");
		printf("-----------------------------------------\n");
		mostrarClientes(clientes, tamCl);
		auxId=getValidInt("Ingrese el id de Cliente a Eliminar \n", "Error, ingrese solo numeros \n ", 0, tamCl);
		findCliente_ById(clientes, tamCl, auxId, &index);
		if(index!=-1){
			mostrarUnCliente(clientes[index], clientes, tamCl);
			printf("Esta seguro de eliminar el Cliente? \n	");
			scanf("%s",respuesta);
			if (!(stricmp(respuesta, "si"))) {
				clientes[index].isEmpty = 0;
				puts("Baja Realizada \n");
				retorno=0;
			} else {
				puts("Baja anulada \n");
			}
		}else{
			puts("Cliente Invalido \n");
		}
	}

	return retorno;

}


int findEmptyPrestamo(Prestamo* prestamos, int tamP, int* index){
	int retorno=-1;

	if(prestamos!=NULL && index!=NULL && tamP>0){
		for(int i=0; i<tamP; i++){
			if(prestamos[i].isEmpty==1){
				*index=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int AltaDePrestamo(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP, int *idPrestamo){
	int retorno=-1;
	int auxId;
	int index=-1;
	int indexP=-1;
	if(clientes!=NULL && tamCl>0 && prestamos!=NULL && tamP>0 && idPrestamo!=NULL){
		printf("\n\t>-ALTA DE PRESTAMO-<\t\n");
		printf("-----------------------------------------\n");
		mostrarClientes(clientes, tamCl);
		auxId=getValidInt("Ingrese el id de Cliente para asignar el Prestamo \n", "Error, ingrese solo numeros \n ", 0, tamP);
		if(!findCliente_ById(clientes, tamCl, auxId, &index)){
			puts("Cliente Valido");
			findEmptyPrestamo(prestamos, tamP, &indexP);
			if(indexP!=-1){
				prestamos[indexP].idCliente=auxId;
				chargeSalary(&prestamos[indexP].importe, "Ingrese el importe del Prestamo \n", "Error. Ingrese solo numeros \n");
				prestamos[indexP].cuotas=getValidInt("Ingrese la cantidad de cuotas 1 - 48\n", "Error. Ingrese solo cantidad de cuotas 1 - 48" , 1, 48);

				(*idPrestamo)++;
				prestamos[indexP].idPrestamo=*idPrestamo;
				prestamos[index].isPaid=0;
				prestamos[index].isEmpty=0;
				 printf("          *** Nuevo Prestamo Creado ***\n\n");
				 printf("ID Cliente  	 ID Prestamo   Importe   Cuotas   Estado  \n");
				 printf("-----------------------------------------------------\n");
				mostrarUnPrestamo(prestamos[index], prestamos, tamP);
				retorno=0;

			}


		}



	}


	return retorno;
}


int getEstadoPrestamo(Prestamo* prestamos, int idPrestamo, int tamP, char* estadoP){
	int retorno=-1;

		if(prestamos!=NULL && estadoP!=NULL && tamP>0 && idPrestamo>0){
			for(int i=0; i<tamP; i++){
				if(prestamos[i].isPaid==0 && prestamos[i].idPrestamo==idPrestamo){
					strcpy(estadoP, "Activo");
					retorno=0;
					break;
				}else{
					strcpy(estadoP, "Saldado");
					retorno=0;
					break;
				}
			}
		}

		return retorno;
}


int mostrarPrestamos(Prestamo* prestamos, int tamP){
	int retorno=-1;

	if(prestamos!=NULL && tamP>0){
 printf("          *** Listado de Prestamos***\n\n");
 printf("ID Cliente  	 ID Cliente     CUOTAS    Importe    	  Estado    \n");
 printf("-----------------------------------------------------\n");
		for(int i=0; i<tamP; i++){
			if(!prestamos[i].isEmpty){
				mostrarUnPrestamo(prestamos[i], prestamos, tamP);
				retorno=0;
			}
		}
	}


	return retorno;
}

void mostrarUnPrestamo(Prestamo unPrestamo,Prestamo* prestamos, int tamP){
char auxEstado[20];

getEstadoPrestamo(prestamos, unPrestamo.idPrestamo, tamP, auxEstado);

	printf("%-9d        %-8d      %5.2f    %-9d   %-12s    \n",unPrestamo.idCliente
														 , unPrestamo.idPrestamo
														 , unPrestamo.importe
														 , unPrestamo.cuotas
														 , auxEstado);

}


int saldarPrestamo(Cliente* clientes, Prestamo* prestamos, int tamP, int tamCl){
	int retorno=-1;
	int auxIdPrestamo;
	int indexP=-1;
	int indexC=-1;
	char respuesta[4];
	strcpy(respuesta, "no");
	if(clientes!=NULL && tamCl>0 && prestamos!=NULL && tamP>0 ){
		mostrarPrestamos(prestamos, tamP);
		auxIdPrestamo=getValidInt("Ingrese el id de Prestamo a Saldar \n", "Error. Ingrese solo numeros", 0, tamP);
		findPrestamo_ById(prestamos, tamP, auxIdPrestamo, &indexP);
		if(indexP!=-1){
			if(prestamos[indexP].isPaid==1){
				puts("El prestamo ya se encuentra saldado\n");
				retorno=0;
			}else{

				findCliente_ById(clientes, tamCl, prestamos[indexP].idCliente,
						&indexC);
				if (indexC != -1) {
					printf(
							"          *** Datos del Cliente Encontrado ***\n\n");
					printf(
							"ID Cliente  	 Nombre        Apellido    	  CUIL    \n");
					printf(
							"-----------------------------------------------------\n");
					mostrarUnCliente(clientes[indexC], clientes, tamCl);
					printf(
							"Esta seguro de cambiar el Estado del prestamo a 'Saldado'? \n	");
					scanf("%s", respuesta);
					if (!(stricmp(respuesta, "si"))) {
						prestamos[indexP].isPaid = 1;
						puts("Estado cambiado \n");
						retorno = 0;
					} else {
						puts("Cambio de estado Anulado\n");
					}
				}
			}
		}else{
			puts("Prestamo inexistente\n");
		}

	}

return retorno;
}


int reanudarPrestamo(Cliente* clientes, Prestamo* prestamos, int tamP, int tamCl){
	int retorno=-1;
		int auxIdPrestamo;
		int indexP=-1;
		int indexC=-1;
		char respuesta[4];
		strcpy(respuesta, "no");
		if(clientes!=NULL && tamCl>0 && prestamos!=NULL && tamP>0 ){
			mostrarPrestamos(prestamos, tamP);
			auxIdPrestamo=getValidInt("Ingrese el id de Prestamo a Reanudar \n", "Error. Ingrese solo numeros", 0, tamP);
			findPrestamo_ById(prestamos, tamP, auxIdPrestamo, &indexP);
			if(indexP!=-1){
				if(prestamos[indexP].isPaid==0){
					puts("El prestamo ya se encuentra activo\n");
					retorno=0;
				}else{

					findCliente_ById(clientes, tamCl, prestamos[indexP].idCliente,
							&indexC);
					if (indexC != -1) {
						printf(
								"          *** Datos del Cliente Encontrado ***\n\n");
						printf(
								"ID Cliente  	 Nombre        Apellido    	  CUIL    \n");
						printf(
								"-----------------------------------------------------\n");
						mostrarUnCliente(clientes[indexC], clientes, tamCl);
						printf(
								"Esta seguro de cambiar el Estado del prestamo a 'Activo'? \n	");
						scanf("%s", respuesta);
						if (!(stricmp(respuesta, "si"))) {
							prestamos[indexP].isPaid = 1;
							puts("Estado cambiado \n");
							retorno = 0;
						} else {
							puts("Cambio de estado Anulado\n");
						}
					}
				}
			}else{
				puts("Prestamo inexistente\n");
			}

		}

	return retorno;
}
int findPrestamo_ById(Prestamo*  prestamos, int tamP, int auxId, int* index){
	int retorno=-1;

	if(prestamos!=NULL && tamP>0 && auxId>=0 && index!=NULL){
		for(int i=0; i<tamP; i++){
			if(auxId == prestamos[i].idPrestamo){
				retorno=0;
				*index=i;
				break;
			}
		}
	}

	return retorno;
}


int mostrarClientesCompleto(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP){
	int retorno=-1;

	if(clientes!=NULL && tamCl>0 && prestamos!=NULL && tamP>0 ){
		 printf("          *** Listado de Clientes ***\n\n");
		 printf("ID Cliente  	 Nombre        Apellido    	  CUIL    Prestamos Activos\n");
		 printf("-----------------------------------------------------------------------\n");
		 for(int i=0;i<tamCl;i++){
			 if(clientes[i].isEmpty==0){
				 mostrarUnClienteCompleto(prestamos, tamP, clientes[i], clientes, tamCl);
			 }
		 }


	}


	return retorno;
}

void mostrarUnClienteCompleto(Prestamo *prestamos, int tamP, Cliente unCliente,
		Cliente *clientes, int tamCl) {

// Mostrar el nombre del duenio
	int cantidad = -1;
	contarPrestamosActivos(prestamos, tamP, unCliente.idCliente, &cantidad);
	if (cantidad != -1) {
		printf("%-9d        %-8s      %-13s      %-12s    %-9d\n",
				unCliente.idCliente, unCliente.nombre, unCliente.apellido,
				unCliente.cuil, cantidad);

	}

}

int contarPrestamosActivos(Prestamo* prestamos, int tamP, int idCliente, int* cantidad){
	int retorno=-1;
	int contador=0;
	if(prestamos!=NULL && tamP>0){
		for(int i=0; i<tamP; i++){
			if(prestamos[i].idCliente == idCliente){
				if(prestamos[i].isPaid==0){
					contador++;
				}
			}
		}
		*cantidad=contador;
		retorno=0;
	}

	return retorno;
}


int mostrarPrestamosCompleto(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP){
	int retorno=-1;

	if(clientes!=NULL && tamCl>0 && prestamos!=NULL && tamP>0 ){
		 printf("          *** Listado de Prestamos***\n\n");
		 printf("ID Cliente  	 ID Prestamo    CUOTAS    Importe    	  Estado    CUIL  \n");
		 printf("--------------------------------------------------------------------\n");
		 for(int i=0;i<tamP;i++){
			 if(prestamos[i].isEmpty==0){
				 mostrarUnPrestamoCompleto(prestamos, tamP, prestamos[i], clientes, tamCl);
			 }
		 }


	}


	return retorno;
}

void mostrarUnPrestamoCompleto(Prestamo *prestamos, int tamP, Prestamo unPrestamo,
		Cliente *clientes, int tamCl) {
char cuil[25];
char auxEstado[20];

	if (getCuil_ById(clientes, tamCl, unPrestamo.idCliente, cuil) -1) {
	getEstadoPrestamo(prestamos, unPrestamo.idPrestamo, tamP, auxEstado);

		printf("%-9d        %-8d   %5.2f    %-9d     %-6s   %-12s \n",unPrestamo.idCliente
															 , unPrestamo.idPrestamo
															 , unPrestamo.importe
															 , unPrestamo.cuotas
															 , auxEstado
															 , cuil);
	}




}


int getCuil_ById(Cliente *clientes, int tamCl, int idCliente, char* cuil){
int retorno=-1;

	if(clientes!=NULL && tamCl>0){
		for(int i=0; i<tamCl; i++){
			if(clientes[i].isEmpty==0 && clientes[i].idCliente==idCliente){
				strcpy(cuil, clientes[i].cuil);
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}



int clientesMasActivos(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP){
	int retorno=-1;
	int mayorCantidad[tamCl];
	int masCantidad=0;
	int flag=0;
	if(clientes!=NULL && tamCl>0 && prestamos!=NULL && tamP>0){
		for(int i=0; i<tamCl; i++){
					if(clientes[i].isEmpty==0){
						mayorCantidad[i]=0;
					}
				}
		for(int i=0; i<tamCl; i++){
			for(int j=0; j<tamP; j++){
				if(!clientes[i].isEmpty && !prestamos[j].isEmpty && clientes[i].idCliente == prestamos[j].idCliente){
					if(prestamos[j].isPaid==0){
					mayorCantidad[i]++;

					}
				}
			}
		}
	}

	for(int i=0; i<tamCl; i++){
		if(flag || mayorCantidad[i]>masCantidad){
			mayorCantidad[i]=masCantidad;
			flag=1;
		}
	}

	printf("\n\t>-EL CLIENTE CON MAYOR CANTIDAD DE PRESTAMOS ACTIVOS ES-<\t\n");
			printf("ID CLIENTE NOMBRE  CANTIDAD");
			printf("-----------------------------------------\n");

		for(int i=0; i<tamCl; i++)
		{
			if(mayorCantidad[i]==masCantidad)
			{
				printf("| %-4d |  %-4s |%-5d \n",clientes[i].idCliente, clientes[i].nombre, masCantidad);
			}

		}

	return retorno;
}
