/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "arrayMovies.h"

int menuTen()
{
	int opcion;
	printf("\n\t>-MENU PRINCIPAL-<\t\n");
	printf("-----------------------------------------\n");
	printf(" Opcion 1 Cargar los datos de las Peliculas en Modo Texto \n");
	printf(" Opcion 2 Imprimir lista de peliculas \n");
	printf(" Opcion 3 Asignar Rating de peliculas \n");
	printf(" Opcion 4 Asignar Genero de peliculas \n");
	printf(" Opcion 5 Filtrar por Genero seleccionado \n");
	printf(" Opcion 10 Ordenar Peliculas \n");
	printf(" Opcion 11 Guardar Peliculas \n");
	printf(" Opcion 12 Salir \n");

	scanf("%d", &opcion);

	return opcion;
}

int subMenu_One()
{

	int opcion;
	printf("\n\t>-MENU FILTRADO-<\t\n");
	printf("-----------------------------------------\n");
	printf("\n Opcion 5 Filtrar Peliculas de Drama \n");
	printf("\n Opcion 6 Filtrar Peliculas de  Comedia \n");
	printf("\n Opcion 7 Filtrar Peliculas de  Accion\n");
	printf("\n Opcion 8 Filtrar Peliculas de Terror \n");
	printf("\n Opcion 9 SALIR \n");
	scanf("%d", &opcion);

	return opcion;
}

int Movies_MenuOrden()
{
	int opcion;

	printf("\n\t>-MENU ORDENAMIENTO-<\t\n");
	printf("-----------------------------------------\n");
	printf("1. Ordenar Ordenar por genero y Rating\n");
	printf("2. Mostrar Listado\n");
	printf("3. Salir \n");


	opcion=getValidInt("Ingrese una opcion 1-3 \n", "ERROR solo 1-3 \n", 1, 3);

	return opcion;
}

int Movies_MenuCriterio()
{
	int opcion;

	printf("\n\t>-CRITERIO DE ORDENAMIENTO-<\t\n");
	printf("-----------------------------------------\n");
	printf("0. Descendente\n");
	printf("1. Ascendente\n");

	opcion=getValidInt("Ingrese una Opcion 0 - 1", "Error Ingrese una opcion 0 - 1", 0, 1);

	return opcion;
}

eMovie* Movies_new(){
	eMovie* auxMovies;

	auxMovies = (eMovie*) malloc(sizeof(eMovie));

	Movies_setFields(auxMovies, 0, " sin asignar ", "No genero", 0);
	return auxMovies;

}
eMovie* Movies_newParametros(char *idStr, char *tituloStr, char *generoStr, char *ratingStr) {
	eMovie *pMovies = Movies_new();
	int auxId;
	float auxRating;

	auxId = atoi(idStr);
	auxRating = atof(ratingStr);

	if (pMovies != NULL && idStr != NULL && tituloStr != NULL && generoStr != NULL && ratingStr != NULL) {
		if (Movies_setFields(pMovies, auxId, tituloStr, generoStr,auxRating) != -1) {
			//printf("Campos asignados exitosamente \n");

		}else{
			Movies_delete(pMovies);
		}
	}

	return pMovies;
}

int Movies_setFields(eMovie* pMovies, int auxId, char* auxTitulo, char* auxGenero,
		int auxRating)
{
	int retorno=-1;
	int id=Movies_setId(pMovies, &auxId);
	int titulo=Movies_setTitulo(pMovies, auxTitulo);
	int genero=Movies_setGenero(pMovies, auxGenero);
	int rating=Movies_setRating(pMovies, auxRating);

	if(pMovies != NULL)
	{

		if(id==0&& titulo==0&& genero==0&& rating==0)
		{

			retorno=0;
		}else{
			printf("Error al asignar los datos \n");
		}
	}
	return retorno;
}


void Movies_delete(eMovie *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int Movies_setId(eMovie *this, int* id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		this->id_peli = *id;
		retorno = 0;
	}
	return retorno;
}
int Movies_setTitulo(eMovie *this, char *titulo) {
	int retorno = -1;

	if (this != NULL && titulo != NULL) {
		if (strlen(titulo) < 128 && strlen(titulo) > 3) {

			strcpy(this->titulo, titulo);
			retorno = 0;
		}
	}
	return retorno;
}

int Movies_setRating(eMovie* this, float rating){
	int retorno=-1;
	if(this!=NULL)
	{
		if((rating>0 && rating <11) || rating==0)
		{
			this->rating=rating;
			retorno=0;
		}
	}
	return retorno;
}

int Movies_setGenero(eMovie *this, char *genero) {
	int retorno = -1;

	if (this != NULL && genero != NULL) {
		if (strlen(genero) < 128 && strlen(genero) > 3) {
			strcpy(this->genero, genero);

			retorno = 0;
		}
	}

	return retorno;
}

int Movies_getId(eMovie *this, int *id) {
	int retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id_peli;
		retorno = 0;
	}
	return retorno;
}

int Movies_getTitulo(eMovie *this, char *titulo) {
	int retorno = -1;

	if (this != NULL && titulo != NULL) {
		strcpy(titulo, this->titulo);
		retorno = 0;
	}
	return retorno;
}

int Movies_getRating(eMovie *this, float* rating) {
	int retorno = -1;
	if (this != NULL && rating != NULL) {
		*rating = this->rating;
		retorno = 0;
	}
	return retorno;
}

int Movies_getGenero(eMovie* this, char* genero)
{
	int retorno=-1;
	 if(this!=NULL && genero!=NULL)
	    {
	        strcpy(genero, this->genero);

	        retorno=0;
	    }
	return retorno;
}

int Movies_getdescripcionGenero(int genero , char* descripcionGenero)
{
	int retorno=-1;

		if(genero<5 &&  genero>=0 && descripcionGenero!=NULL)
		{
			switch(genero){
			case 0:
				strcpy(descripcionGenero, "Sin Asignar");
				break;
			case 1:
				strcpy(descripcionGenero, "Drama");
				break;
			case 2:
				strcpy(descripcionGenero, "Comedia");
				break;
			case 3:
				strcpy(descripcionGenero, "Accion");
				break;
			case 4:
				strcpy(descripcionGenero, "Terror");
				break;
			}
			retorno=0;
		}

		return retorno;
}

void Movies_mostrarUnaPelicula(eMovie* pelicula) {
	int id;
	char titulo[128];
	char genero[128];
	float rating;

	int id1=Movies_getId(pelicula, &id);
	int tit=Movies_getTitulo(pelicula, titulo);
	int gen=Movies_getGenero(pelicula, genero);
	int rat= Movies_getRating(pelicula, &rating);

	if (id1==0
			&& tit==0
			&& gen==0
			&& rat==0) {
		printf(
				"| %-4d |  %-12s|  %-12s|  %-4.2f |\n",
				id, titulo, genero, rating);
	} else {

		printf("Error al obontener los datos de la pelicula a mostrar \n");

	}

}

int obtenerId(char* path, int* id)
{
	int retorno=-1;
	FILE* pFile;

	if(path!=NULL && id!=NULL)
	{
		pFile=fopen(path,"r");
		fscanf(pFile,"%d",id);
		retorno=1;
	}
	fclose(pFile);
	return retorno;
}


int Movies_CompararId(void* passenger1, void* passenger2)
{
	int resultado = 0;
	eMovie* passenger = NULL;
	eMovie* passengerDos = NULL;
	int id1;
	int id2;

	if(passenger1!=NULL && passenger2!=NULL)
	{
		passenger = (eMovie*) passenger1;
		passengerDos = (eMovie*) passenger2;

		if((!Movies_getId(passenger, &id1)) && (!Movies_getId(passengerDos, &id2)))
		{
			//0 -> si son iguales
			//1 -> mayor
			//-1 -> menor
			if(id1 > id2)
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int Movies_CompararGenero_Rating(void *pelicula1, void *pelicula2) {

	int resultado;
	eMovie *pelicula = NULL;
	eMovie *peliculaDos = NULL;

	char nombre1[128];
	char nombre2[128];
	float rating1;
	float rating2;

//	Se deberá mostrar por pantalla un listado de las películas ordenadas por
//	género y dentro de las del mismo género que aparezcan ordenadas por rating descendente.
	pelicula = (eMovie*) pelicula1;
	peliculaDos = (eMovie*) pelicula2;

	if (pelicula1 != NULL && pelicula2 != NULL) {
		Movies_getRating(pelicula, &rating1);
		Movies_getRating(peliculaDos, &rating2);
		Movies_getGenero(pelicula, nombre1);
		Movies_getGenero(peliculaDos, nombre2);

		if(strcmp(nombre1, nombre2)<0)
		        {
			resultado=1;
		        }
		        else if(strcmp(nombre1, nombre2)>0)
		        {
		        	resultado=-1;
		        }
		        else
		        {
		            if(strcmp(nombre1, nombre2)==0)
		            {
		                if(rating1 > rating2)
		                {
		                	resultado = 1;
		                }
		                else if(rating1 < rating2)
		                {
		                	resultado = -1;
		                }
		            }
		        }

}
	return resultado;
}


void* asignarRating(void *t1) {
	eMovie *auxMovies = NULL;
	int min = 1;
	int max = 10;
	float rating;

	if (t1 != NULL) {
		auxMovies = (eMovie*) t1;
		if (auxMovies != NULL) {
			rating = (float) (rand() % (max - min + 1)) + min;
			Movies_setRating(auxMovies, rating);

		}
	}

	return auxMovies;
}

void* asignarGenero(void *t1) {
	eMovie *auxMovies = NULL;
	int min = 1;
	int max = 4;
	int genero;
	char auxGenero[128];

	if (t1 != NULL) {
		auxMovies = (eMovie*) t1;
		if (auxMovies != NULL) {
			genero = (rand() % (max - min + 1)) + min;
			Movies_getdescripcionGenero(genero, auxGenero);
			Movies_setGenero(auxMovies, auxGenero);

		}
	}

	return auxMovies;
}

int filtrarDrama(void* a)
{
	int retorno=0;
	eMovie* pMovies;

	if(a!=NULL){
		pMovies=(eMovie*) a;
		if(!strcmp(pMovies->genero,"Drama")){
		retorno=1;
		}
	}
	return retorno;
}

int filtrarComedia(void *a) {
	int retorno = 0;
	eMovie *pMovies;

	if (a != NULL) {
		pMovies = (eMovie*) a;
		if (!strcmp(pMovies->genero, "Comedia")) {
			retorno = 1;
		}
	}
	return retorno;
}


int filtrarAccion(void *a) {
	int retorno = 0;
	eMovie *pMovies;

	if (a != NULL) {
		pMovies = (eMovie*) a;
		if (!strcmp(pMovies->genero, "Accion")) {
			retorno = 1;
		}
	}
	return retorno;
}

int filtrarTerror(void *a) {
	int retorno = 0;
	eMovie *pMovies;

	if (a != NULL) {
		pMovies = (eMovie*) a;
		if (!strcmp(pMovies->genero, "Terror")) {
			retorno = 1;
		}
	}
	return retorno;
}

