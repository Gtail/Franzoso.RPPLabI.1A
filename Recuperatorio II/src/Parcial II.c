/*
 ============================================================================
 Name        : Parcial.c
 Author      : Gian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayMovies.h"
#include "LinkedList.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));
	int option;
	int opcion;
	LinkedList* listaMovies = ll_newLinkedList();

	if (listaMovies == NULL) {
		puts("No se consiguio espacio en memoria \n");
	} else {

		do {
			option = menuTen();
			switch (option) {
			case 1:
				printf("\n Usted ha seleccionado 1: Cargar Peliculas Modo Texto \n");
				controller_loadFromText("movies.csv", listaMovies);
				break;
			case 2:
				printf("\n Usted ha seleccionado 2: Imprimir Lista de Peliculas \n");
				controller_ListMovies(listaMovies);
				break;
			case 3:
				printf("\n Usted ha seleccionado 3: Asignar Rating de Peliculas \n");
				controller_SetRating(listaMovies);
				break;
			case 4:
				printf("\n Usted ha seleccionado 5: Asignar Genero de Peliculas \n");
				controller_SetGenero(listaMovies);
				break;
			case 5:
				printf("\n Usted ha seleccionado 4: Filtrar por Tipo de Peliculas \n");
				do{
				opcion=subMenu_One();
				switch(opcion){
				case 5:
					controller_filterDrama(listaMovies);
					break;
				case 6:
					controller_filterComedia(listaMovies);
					break;
				case 7:
					controller_filterAccion(listaMovies);
					break;
				case 8:
					controller_filterTerror(listaMovies);
					break;
				case 9:
					printf("Menu Principal\n");
					break;

				}
				}while(opcion!=9);

				break;
			case 10:
				printf("\n Usted ha seleccionado 10: Ordenar por genero y Rating Descendente \n");
				controller_sortPassenger(listaMovies);
				break;
			case 11:
				printf("\n Usted ha seleccionado 11: Guardar Peliculas \n");
				if(controller_saveAsText("movies.csv", listaMovies)==1){
					printf("Peliculas guardadas exitosamente \n");
				}
				break;
			case 12:
				printf("\n Usted ha seleccionado 11: Salir \n");
				printf("Hasta luego\n");
				break;
			}
		} while (option != 12);

	}

	return 0;
}
