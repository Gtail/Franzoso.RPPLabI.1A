/*
 * Clientes.h
 *
 *  Created on: 3 ago. 2022
 *      Author: Gian
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_
#include "inputUtn.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


struct{
	int idCliente;
	char nombre[20];
	char apellido[20];
	char cuil[25];
	int isEmpty;
}typedef Cliente;

struct{
	int idCliente;
	int idPrestamo;
	float importe;
	int cuotas;
	int isPaid;
	int isEmpty;
}typedef Prestamo;

int main_Menu();


int altaDeCliente(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP, int* idCliente);
int modificarCliente(Cliente* clientes, int tamCl);


int mostrarClientes(Cliente* clientes, int tamCl);
void mostrarUnCliente(Cliente unCliente, Cliente* clientes, int tamCl);
int findEmptyCliente(Cliente* clientes, int tamCl, int* index);
int inicializarPrestamos(Prestamo* prestamos, int tamP);
int inicializarClientes(Cliente* clientes, int tamC);
int findCliente_ById(Cliente* clientes, int tamCl, int auxId, int* index);
int eliminarCliente(Cliente* clientes, int tamCl);

void mostrarUnPrestamo(Prestamo unPrestamo,Prestamo* prestamos, int tamP);
int mostrarPrestamos(Prestamo* prestamos, int tamP);
int getEstadoPrestamo(Prestamo* prestamos, int idPrestamo, int tamP, char* estadoP);
int findPrestamo_ById(Prestamo*  prestamos, int tamP, int auxId, int* index);

int AltaDePrestamo(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP, int *idPrestamo);
int saldarPrestamo(Cliente* clientes, Prestamo* prestamos, int tamP, int tamCl);
int reanudarPrestamo(Cliente* clientes, Prestamo* prestamos, int tamP, int tamCl);
int contarPrestamosActivos(Prestamo* prestamos, int tamP, int idCliente, int* cantidad);
void mostrarUnClienteCompleto(Prestamo* prestamos, int tamP, Cliente unCliente, Cliente* clientes, int tamCl);
int mostrarClientesCompleto(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP);



int getCuil_ById(Cliente *clientes, int tamCl, int idCliente, char* cuil);
void mostrarUnPrestamoCompleto(Prestamo *prestamos, int tamP, Prestamo unPrestamo,
		Cliente *clientes, int tamCl);
int mostrarPrestamosCompleto(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP);
int clientesMasActivos(Cliente* clientes, int tamCl, Prestamo* prestamos, int tamP);

#endif /* CLIENTES_H_ */
