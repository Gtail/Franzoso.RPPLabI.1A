/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#ifndef PASSENGER_H
#define PASSENGER_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "inputUtn.h"

typedef struct
{

	//id_peli,titulo,genero,duracion
	int id_peli;
	char titulo[128];
	char genero[128];
	float rating;

}eMovie;

//Constructores y destructores
eMovie* Movies_new();
eMovie* Movies_newParametros(char *idStr, char *nombreStr, char *apellidoStr, char *precioStr);
void Movies_delete();

//SETTERS
int Movies_setId(eMovie* this,int* id);
int Movies_setTitulo(eMovie* this,char* titulo);
int Movies_setGenero(eMovie *this, char *genero);
int Movies_setRating(eMovie* this, float rating);
int Movies_setFields(eMovie* pMovies, int auxId, char* auxTitulo, char* auxGenero, int auxRating);


//GETTERS
int Movies_getId(eMovie* this,int* id);
int Movies_getTitulo(eMovie* this,char* titulo);
int Movies_getGenero(eMovie* this, char* genero);
int Movies_getRating(eMovie* this,float* rating);
int Movies_getdescripcionGenero(int estadoVuelo , char* descripcionGenero);


//Herramientas
void Movies_mostrarUnaPelicula(eMovie* pelicula);
int obtenerId(char* path, int* id);
int buscar_PeliculaPorId(LinkedList *pArrayListPassenger, int *id);


//Menus
int subMenu_Dos();
int menuTen();
int subMenu_One();
int Movies_MenuOrden();
int Movies_MenuCriterio();

//Comparadores
int Movies_CompararGenero_Rating(void* pelicula1, void* pelicula2);

//Rating
void* asignarRating(void* t1);
void* asignarGenero(void *t1);

//Filtros
int filtrarDrama(void* a);
int filtrarComedia(void* a);
int filtrarAccion(void* a);
int filtrarTerror(void* a);

#endif /* PASSENGER_H_ */
