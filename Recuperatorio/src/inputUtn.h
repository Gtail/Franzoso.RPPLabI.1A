/*
 * inputUtn.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Gian
 */

#ifndef INPUTUTN_H_
#define INPUTUTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int idCliente;
	char empresa[51];
	char cuit[51];
	char direccion[51];
	char localidad[51];
} eCliente;

/***
 * \fn char PedirChar(char[], char*)
 * \brief  Pide un caracter al usuario y lo retorna en la cariable pasada por parametro
 *
 * \param mensaje
 * \param caracter

 */
void PedirChar(char mensaje[],char* caracter);



void getStringOne(char cadena[],char mensaje[],int tam);


/***
 * \fn int PedirNumeroEntero()
 * \brief Pide un numero entero al usuario y lo retorna
 * \param mensaje
 * \return int, el numero ingresado por el usuario
 */
int PedirNumeroEntero(char mensaje[]);


void PedirNumeroEnteroPuntero(int* numero,char mensaje[]);

/***
 * \fn void PedirNumeroEnteroExcluyente(int*, int*, char[], char[])
 * \brief
 *
 * \param numeroExcluyente
 * \param numero
 * \param mensaje
 * \param mensajeError
 */
void PedirNumeroEnteroExcluyente(int numeroExcluyente,int* numero,char mensaje[],char mensajeError[]);


/***
 * \fn int PedirNumeroEnteroConRango(char[], char[], int, int)
 * \brief  Pide al usuario un numero dentro del rango especificado
 *
 * \param mensaje: El mensaje a ser mostrado
 * \param mensajeError : El mensaje a ser mostrado en caso de error
 * \param min : El menor numero a ingresar
 * \param max : el maximo numero a ingresar
 * \return int: el numero ingresado por el usuario
 */
int PedirNumeroEnteroConRango(char mensaje[],char mensajeError[],int min, int max);

/***
 * \fn void PedirNumeroEnteroConRangoPuntero(int*, char[], char[], int, int)
 * \brief  Pide al usuario un numero dentro del rango especificado y lo guarda en la variable apuntada
 * \param int* numero: puntero a numero
 * \param mensaje: El mensaje a ser mostrado
 * \param mensajeError : El mensaje a ser mostrado en caso de error
 * \param min : El menor numero a ingresar
 * \param max : el maximo numero a ingresar
 */
void PedirNumeroEnteroConRangoPuntero(int* numero,char mensaje[],char mensajeError[],int min, int max);

/***
 * \fn void mostrarEntero(char[], int)
 * \brief Muestra un mensaje por pantalla
 *
 * \param mensaje : El mensaje a ser mostrado
 * \param numero : El numero a ser mostrado
 */
void mostrarEntero (char mensaje[],int numero);


/***
 * \fn int esNumerico(char cadena[]);
 * \brief Verifica si el valor que recibio es numerico
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esNumerico(char cadena[]);

/***
 *
 * \fn int esNumericoFlotante(char[])
 * \brief
 *
 * \param cadena
 * \return
 */
int esNumericoFlotante(char cadena[]);
/***
 * \fn int esTelefonoCuit(char cadena[]);
 * \brief Verifica si el valor que recibio es un telefono/Cuit/Cuil
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es telefono/Cuit/Cuil y 0 si no lo es
 */
int esTelefonoCuit(char cadena[]);



/***
 * \fn int esTelefono(char cadena[]);
 * \brief Verifica si el valor que recibio es un telefono
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esAlfaNumerico(char cadena[]);



/***
 * \fn int esSoloLetras(char cadena[]);
 * \brief Verifica si el valor recibido contiene solo letras
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es solo ' ' y letras /  0 si no lo es
 */
int esSoloLetras(char cadena[]);

/***
 * \fn int getStringNumeros(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringNumber(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);



/***
 * \fn int getStringNumeroFlotante(char[], char[], char[], int, int)
 * \brief
 *
 * \param mensaje
 * \param mensajeError
 * \param input
 * \param lenInput
 * \param reintentos
 * \return
 */

int getStringNumeroFlotante(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);


/***
 * \fn int getStringSoloLetras(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringSoloLetras(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);

/***
 * \fn int getStringAlfaNumerico(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringAlfaNumerico(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);

/***
 * \fn int  getStringTelefonoCuit(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringTelefonoCuit(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);

/***
 * \fn void MostrarMensaje(char[])
 * \brief
 *
 * \param mensaje
 */
void MostrarMensaje(char mensaje[]);

/***
 * \fn void MostrarMensajesRetornoFunciones(char[], char[], char[])
 * \brief
 *
 * \param mensaje1
 * \param mensaje2
 * \param mensaje3
 */

void MostrarMensajesRetornoFunciones(int estado, char mensaje1[],char mensaje2[],char mensaje3[],char mensaje4[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 *
* @fn void chargeSalary(float*, char[], char[])
* @brief Recibe un flotante y lo carga a traves de un
* auxiliar de char que despues es convertido nuevamente
* en flotante para poder ser cargado
* @param salario auxiliar
* @param mensaje al usuario
* @param mensajeError al usuario
*/
int chargeSalary(float *salario, char mensaje[], char mensajeError[]);


int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);


int getString1(char input[], int tam);

int isChar(char string[]);
#endif /* INPUTUTN_H_ */
