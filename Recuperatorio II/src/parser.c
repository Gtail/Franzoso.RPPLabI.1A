#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arrayMovies.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{
		int retorno=-1;
		int contPassenger=0;
		char buffer[4][30];

		eMovie* auxPelicula;


		if (pFile != NULL && pArrayListPeliculas != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			   printf("\n\t>-ID     Titulo          Genero      Rating-<\t\n");
				printf("------------------------------------------------------------\n");
				while (!feof(pFile))
				{


						if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3])==4)
						{
							auxPelicula=Movies_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

								if(auxPelicula != NULL)
								{
									ll_add(pArrayListPeliculas, auxPelicula);
									Movies_mostrarUnaPelicula(auxPelicula);

									contPassenger+=1;
									retorno=0;

								}
						}


				}

		}
		fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
		eMovie *auxPasajero;

		if (pFile != NULL && pArrayListPassenger != NULL)
		{

			while (!feof(pFile)) {
				auxPasajero = Movies_new();

				if (auxPasajero != NULL) {
					if (fread(auxPasajero, sizeof(eMovie), 1, pFile)==1) {
						ll_add(pArrayListPassenger, auxPasajero);
						//printf("ID %d", auxPasajero->id);
						retorno=0;
					}else{
						Movies_delete(auxPasajero);
					}
				}
			}
		}
		return retorno;

}
