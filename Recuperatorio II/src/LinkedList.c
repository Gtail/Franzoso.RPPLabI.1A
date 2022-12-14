#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this= (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
	if(this!=NULL){
		returnAux=this->size;
	}
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	int tam;
	int i;
	Node *auxNode = NULL; //aca guardo el nodo encontrado en caso de obtenerlo

	if (this != NULL) {
		tam = ll_len(this);
		if (nodeIndex < tam && nodeIndex >= 0) {
			auxNode = this->pFirstNode; //aca debo agregar la direccion del primer nodo
			for (i = 0; i < nodeIndex; i++) {
				auxNode = auxNode->pNextNode; //contiene la primera direccion
			}
		}
	}
	return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;

	Node *newNode = NULL;
	Node *prevNode = NULL;

	if (this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this)) {
		newNode = (Node*) malloc(sizeof(Node));
		if (newNode != NULL) {
			newNode->pElement = pElement;
			if (nodeIndex == 0) {
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;

			} else {
				prevNode = getNode(this, nodeIndex - 1);
				if (prevNode != NULL) {
					newNode->pNextNode = prevNode->pNextNode;
					prevNode->pNextNode = newNode;

				}

			}
			this->size++;
			returnAux = 0;

		}
	}
	return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int tam;

	if (this != NULL) {
		tam = ll_len(this);
		if (addNode(this, tam, pElement) == 0) {

			returnAux = 0;
		}
	}

	return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *newNode = NULL;
	int tam;

	if (this != NULL) {
		tam = ll_len(this);
		if (index >= 0 && index < tam) {
			newNode = getNode(this, index);
			if (newNode != NULL) {
				returnAux = newNode->pElement;
			}
		}
	}

	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int tam;
    Node* newNode=NULL;

    if(this!=NULL)
    {
    	tam=ll_len(this);
    	if(index>=0 && index<tam)
    	{
    		newNode=getNode(this, index);
    		newNode->pElement=pElement;
    		returnAux=0;
    	}
    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	int tam;
	Node *removed_Node = NULL;
	Node *prevNode = NULL;

	if (this != NULL) {
		tam = ll_len(this);
		removed_Node = getNode(this, index);
		if (removed_Node != NULL && index >= 0 && index < tam) {
			if (index == 0) {
				this->pFirstNode = removed_Node->pNextNode;

			} else {
				prevNode = getNode(this, index - 1);
				if (prevNode != NULL) {
					prevNode->pNextNode = removed_Node->pNextNode;
				}
			}
			free(removed_Node);
			this->size--;
			returnAux = 0;
		}
	}
	return returnAux;

}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	int tamList;
	int i;

//elimina los elementos pero deja los nodos
// elimina todos los nodos menos la cabecera
// delete borra TODa la lista

	if (this != NULL) {
		tamList = ll_len(this);
		for (i = 0; i < tamList; i++) {
			ll_remove(this, 0);

			returnAux = 0;
		}

	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;


    if(this!=NULL)
    {
    	if(ll_clear(this)==0)
    	{
		free(this);
		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int tam;
	int i;
	Node *auxNode;

	if (this != NULL) {
		tam = ll_len(this);

		for (i = 0; i < tam; i++) {
			auxNode = (Node*) getNode(this, i);
//usar ll_get en lugar del get node y lo comparo con el pElement
			if(auxNode->pElement==pElement)
			{
				returnAux=i;
				break;
			}
		}

	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	if(tam==0)
    	{
    		returnAux=1;
    	}else{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;


    if(this!=NULL && index>=0 && ll_len(this)>=index)
    {
    		if(addNode(this, index, pElement)==0)
    		{
    			returnAux=0;
    		}

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;

	int tam;
	if (this != NULL) {
		tam = ll_len(this);
		if (index >= 0 && index < tam) {
			returnAux = ll_get(this, index);
			ll_remove(this, index);
		}
	}

	return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {
		if (ll_indexOf(this, pElement) != -1) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	int tam;
	void *auxPelement;
	int i;

	if (this != NULL && this2 != NULL) {
		tam = ll_len(this);
		returnAux = 1;
		for (i = 0; i < tam; i++) {
			auxPelement = ll_get(this2, i);
			if (ll_contains(this, auxPelement) == 0) {
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int tam;
	int i;
	void *pElement;

	if (this != NULL) {
		tam = ll_len(this);
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL && from>=0 && to<=tam && from<=tam && from<to) {
			//OBTENGO EL ELEMENTO POR CADA INDICE CON LL GET
			// CADA UNO LO AGREGO A LA NUEVA LISTA
			// trabajar con un do while() por la memoria
			for (i = from; i < to; i++) {
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
		}else{
			cloneArray=NULL;
		}

	}

	return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;

	int tam;

	if (this != NULL) {
		tam = ll_len(this);
		cloneArray = ll_subList(this, 0, tam);
	}

	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	int tam;
	int i;
	int j;
	void *aux1 = NULL;
	void *aux2 = NULL;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {
		tam = ll_len(this);
		for (i = 0; i < tam - 1; i++) {
			for (j = i + 1; j < tam; j++) {
				aux1 = ll_get(this, i);
				aux2 = ll_get(this, j);
				if ((pFunc(aux1, aux2) < 0 && order == 0)
						|| (pFunc(aux1, aux2) > 0 && order == 1)) {
					ll_set(this, j, aux1);
					ll_set(this, i, aux2);
				}
			}
		}
		returnAux = 0;
	}

	return returnAux;

}

LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) {
	LinkedList *filterList = NULL;
	int tamList;
	void *pElement=NULL;
	int i;
	if (this != NULL && pFunc != NULL) {
		filterList = ll_newLinkedList();
		if (filterList != NULL) {
			tamList = ll_len(this);
			for (i = 0; i < tamList; i++) {
				pElement=ll_get(this, i);
				if (pFunc(pElement)) {
					ll_add(filterList, pElement);
				}
			}
		}
	}
	return filterList;
}


/*
 *
 * 3) Asignar tiempos: Se deber? hacer uso de la funci?n map. la cual recibir? el linkedlist
 *  y una funci?n que asignar? a la pel?cula un valor de
 * duraci?n entre 100 y 240 minutos calculado de manera aleatoria
 * se mostrar? por pantalla el mismo.
 */
LinkedList* ll_map(LinkedList* list, void* (*pfunc)(void *t1)) {

	int tamList;
	void *pElement = NULL;
	int i;
	if (list != NULL && pfunc != NULL) {
		tamList = ll_len(list);
		if (tamList > 0) {
			for (i = 0; i < tamList; i++) {
				pElement = ll_get(list, i);
				if (pElement != NULL) {
					pElement = pfunc(pElement);
					if (pElement != NULL) {
						ll_set(list, i, pElement);
					}
				}
			}
		}
	}

	return list;
}
