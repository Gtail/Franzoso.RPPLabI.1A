/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : Gian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Clientes.h"
#define TAMP 6
#define TAMAR 5
#define TAMC 5
#define TAMSV 4
#define TAMT 5
#define TAMCL 5


int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	Cliente clientes[TAMCL];
	Prestamo prestamos[TAMP];
	int idCliente=0;
	int idPrestamo=0;
	inicializarClientes(clientes, TAMCL);
	inicializarPrestamos(prestamos, TAMP);

	do{
		opcion=main_Menu();
		switch(opcion){
		case 1:
			puts("Usted a elegido la opcion 1: Alta de Cliente \n");
			altaDeCliente(clientes, TAMCL, prestamos, TAMP, &idCliente);
			break;
		case 2:
			puts("Usted a elegido la opcion 2: Modificar Cliente\n");
			modificarCliente(clientes, TAMCL);
			break;
		case 3:
			puts("Usted a elegido la opcion 3: Baja de Cliente \n");
			eliminarCliente(clientes, TAMCL);
			break;
		case 4:
			puts("Usted a elegido la opcion 4: Alta de Prestamo \n");
			AltaDePrestamo(clientes, TAMCL, prestamos, TAMP, &idPrestamo);
			break;
		case 5:
			puts("Usted a elegido la opcion 5: Saldar Prestamo \n");
			saldarPrestamo(clientes, prestamos, TAMP, TAMCL);
			break;
		case 6:
			puts("Usted a elegido la opcion 6: Reanudar Prestamo \n");
			reanudarPrestamo(clientes, prestamos, TAMP, TAMCL);
			break;
		case 7:
			puts("Usted a elegido la opcion 7: Imprimir Clientes \n");
			mostrarClientesCompleto(clientes, TAMCL, prestamos, TAMP);
			break;
		case 8:
			puts("Usted a elegido la opcion 8: Alta de Imprimir Prestamos \n");
			mostrarPrestamosCompleto(clientes, TAMCL, prestamos, TAMP);
			break;
		case 9:
			puts("Usted a elegido la opcion 9: Informar Clientes \n");
			clientesMasActivos(clientes, TAMCL, prestamos, TAMP);
			break;
		case 10:
			puts("Usted a elegido la opcion 10: Alta de Auto \n");
			break;
		case 11:
			puts("Usted a elegido la opcion 1: Salir \n");
			break;
		}


	}while(opcion!=11);
	return 0;
}
