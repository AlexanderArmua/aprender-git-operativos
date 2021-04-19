/*
 * linkedList.h
 *
 *  Created on: 18 abr. 2021
 *      Author: utnso
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct Node {
	void * val;
	struct Node * next;
} node_t;

typedef struct List {
	unsigned int size;
	node_t * first_node;
	node_t * last_node;
} list_t;

/**
	* @NAME: create_list
	* @DESC: Retorna una lista vacía
	*
	* @RETURN: List {
	* 	size: 0,
	* 	first_node: NULL,
	* 	last_node: NULL
	* }
	*/
list_t* create_list();

/**
 * @NAME: size
 * @DESC: Retorna la cantidad de elementos de la lista
 */
unsigned int size_list(list_t * list);

/**
 * @NAME: peek
 * @DESC: Retorna el primer elemento sin sacarlo de la lista
 */
void * peek_list(list_t * list);

/**
 * @NAME: pop_list
 * @DESC: Retorna el primer elemento y lo elimina de la lista, PERO NO ELIMINA EL PUNTERO AL VALOR
 * @RETURN: Puntero al valor, recordar eliminarlo luego de usarlo
 */
void * pop_list(list_t * list);

/**
 * @NAME: push_list
 * @DESC: Inserta un elemento al final de la lista
 */
void push_last_list(list_t * list, void * value);

/**
 * @NAME: push_first_list
 * @DESC: Inserta un elemento al principio de la lista
 */
void push_first_list(list_t * list, void * value);

/**
 * @NAME: clear_list
 * @DESC: Libera la memoria de toda la lista (free)
 */
void clear_list(list_t * list);

#endif /* LINKEDLIST_H_ */


























