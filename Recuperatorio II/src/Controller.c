#include <stdio.h>
#include <stdlib.h>
#include "arrayMovies.h"
#include "LinkedList.h"
#include "parser.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListMovies)
{
	FILE* pFile;
	int retorno;
	pFile=fopen(path,"r");

	if(pFile!=NULL && pArrayListMovies!=NULL){

		if(parser_PassengerFromText(pFile, pArrayListMovies)!=-1){

			retorno=0;
		}else{
			retorno=-1;
		}

	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	pFile=fopen(path,"rb");


	if( pArrayListPassenger!=NULL && path!=NULL)
	{

		if(pFile!= NULL)
		{

			if(parser_PassengerFromBinary(pFile, pArrayListPassenger)==0){
			retorno=0;
			}
		}
	fclose(pFile);
	}
    return retorno;
}


/** \brief Listar Peliculas
 * \param
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListMovies(LinkedList *pArrayListMovies) {
	int retorno = -1;
	int tamList;
	int i;
	eMovie *auxPassenger;
	if (pArrayListMovies != NULL) {
		tamList = ll_len(pArrayListMovies);
		for (i = 0; i < tamList; i++) {
			auxPassenger = (eMovie*) ll_get(pArrayListMovies, i);
			Movies_mostrarUnaPelicula(auxPassenger);
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		int criterio=0;
		int opcion;
		char confirmar[4];
		strcpy(confirmar,"no");
		LinkedList* copia;
		if(pArrayListPassenger!=NULL)
		{
			copia = ll_clone(pArrayListPassenger);

			if(copia!=NULL)
			{
				do
				{
					opcion = Movies_MenuOrden();
					if(opcion!=2 && opcion!=3)
					{
						criterio = Movies_MenuCriterio();
					}
					switch(opcion)
					{
						case 1:
							if(!ll_sort(copia,Movies_CompararGenero_Rating,criterio))
							{
								if(criterio)
								{
									puts("Se ha ordenado la lista de forma descendente \n");
								}
								else
								{
									puts("Se ha ordenado la lista por de forma ascendente \n");

								}
							}else{
								printf("Error orden \n");
							}
							break;
						case 2:
							controller_ListMovies(copia);
							break;
						case 3:
							getStringSoloLetras("Esta seguro de Salir? si/no \n", "Error. ingrese solo letras \n", confirmar, 4, 2);
							strlwr(confirmar);
							ll_deleteLinkedList(copia);
							break;
						}
				}while(stricmp(confirmar,"si"));
			}
		}

	    return retorno;
	}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	int tamList;
	int auxId;
	char auxTitulo[128];
	char auxGenero[128];
	float auxRating;

	eMovie *auxMovies=NULL;
	FILE *pFile;

	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			tamList = ll_len(pArrayListPassenger);
			fprintf(pFile, "id,titulo,genero,rating\n");
			for (i = 0; i < tamList; i++) {
				auxMovies = (eMovie*) ll_get(pArrayListPassenger, i);
				if(auxMovies!=NULL){
				Movies_getId(auxMovies, &auxId);
				Movies_getTitulo(auxMovies, auxTitulo);
				Movies_getGenero(auxMovies, auxGenero);
				Movies_getRating(auxMovies, &auxRating);
				fprintf(pFile,"%d,%s,%s,%.2f\n", auxId, auxTitulo, auxGenero, auxRating);

				retorno = 1;
				}

			}
		}

	}
	fclose(pFile);
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno=-1;
	int i;
	int tamList;
	eMovie* auxPassenger;
	FILE* pFile;
	pFile=fopen(path,"wb");

	if(path!=NULL && pArrayListPassenger!=NULL){
	tamList=ll_len(pArrayListPassenger);
		for(i=0;i<tamList;i++){
			auxPassenger=(eMovie*)ll_get(pArrayListPassenger, i);
			fwrite(auxPassenger,sizeof(eMovie),1,pFile);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_SetRating(LinkedList* pArrayMovies) {
	int retorno = -1;

	if ( pArrayMovies != NULL) {
		ll_map(pArrayMovies, asignarRating);
		controller_ListMovies(pArrayMovies);
		retorno=0;
	}
	return retorno;
}

int controller_filterDrama(LinkedList* pArrayMovies)
{
	int retorno=-1;

	LinkedList* listaDrama=NULL;


	if(pArrayMovies!=NULL){
			listaDrama=ll_filter(pArrayMovies, filtrarDrama);
			if(listaDrama!=NULL){
				controller_ListMovies(listaDrama);
				controller_saveAsText("peliculasDrama.csv", listaDrama);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int controller_SetGenero(LinkedList* pArrayMovies) {
	int retorno = -1;

	if ( pArrayMovies != NULL) {
		ll_map(pArrayMovies, asignarGenero);
		controller_ListMovies(pArrayMovies);
		retorno=0;
	}
	return retorno;
}


int controller_filterComedia(LinkedList* pArrayMovies)
{
	int retorno=-1;

	LinkedList* listaComedia=NULL;


	if(pArrayMovies!=NULL){
			listaComedia=ll_filter(pArrayMovies, filtrarComedia);
			if(listaComedia!=NULL){
				controller_ListMovies(listaComedia);
				controller_saveAsText("peliculasComedia.csv", listaComedia);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int controller_filterAccion(LinkedList* pArrayMovies)
{
	int retorno=-1;

	LinkedList* listaAccion=NULL;


	if(pArrayMovies!=NULL){
			listaAccion=ll_filter(pArrayMovies, filtrarAccion);
			if(listaAccion!=NULL){
				controller_ListMovies(listaAccion);
				controller_saveAsText("peliculasAccion.csv", listaAccion);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int controller_filterTerror(LinkedList* pArrayMovies)
{
	int retorno=-1;

	LinkedList* listaTerror=NULL;


	if(pArrayMovies!=NULL){
			listaTerror=ll_filter(pArrayMovies, filtrarTerror);
			if(listaTerror!=NULL){
				controller_ListMovies(listaTerror);
				controller_saveAsText("peliculasTerror.csv", listaTerror);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}
