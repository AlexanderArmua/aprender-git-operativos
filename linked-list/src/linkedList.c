/*
 * linkedList.c
 *
 *  Created on: 18 abr. 2021
 *      Author: utnso
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// Funciones privadas
node_t * get_node_value(void * value);
int existe_un_elemento(list_t * list);

list_t* create_list() {
	// Es el equivalente a hacer "new LinkedList()" en Java
	list_t * list = (list_t *) malloc(sizeof(list_t));

	list->size = 0;
	list->first_node = NULL;
	list->last_node = NULL;

	return list;
}

// No es necesario, se podría checkear siempre por list->size, pero queda mas elegante.
unsigned int size_list(list_t * list) {
	return list->size;
}

void * peek_list(list_t * list) {
	void * return_value = NULL;

	// Si existe el primer elemento, retornamos ese valor. No hacemos free.
	if (existe_un_elemento(list)) {
		return_value = list->first_node->val;
	}

	return return_value;
}

void * pop_list(list_t * list) {
	void * value_return = NULL;

	// Si existe el primer elemento
	if (existe_un_elemento(list)) {
		// Guardamos el valor que vamos a retornar.
		value_return = list->first_node->val;

		// Guardamos referencia al siguiente de la lista (no importa si es NULL).
		node_t * next = list->first_node->next;

		// Liberamos de memoria el puntero al nodo (no liberamos el valor a retornar).
		free(list->first_node);

		// Hacemos que el primer elemento de la lista apunte al que guardamos como siguiente.
		list->first_node = next;

		// Si salió bien, restamos uno en el contador.
		list->size--;
	}

	return value_return;
}


void push_last_list(list_t * list, void * value) {
	node_t * node = get_node_value(value);

	// Si no existen elementos, metemos el nodo y que first y last apunten a el.
	if (!existe_un_elemento(list)) {
		list->first_node = node;
		list->last_node = node;
	} else {
		// Ya existe primer elemento, entonces el siguiente del ultimo es igual al nodo.
		list->last_node->next = node;
		// El nuevo ultimo es igual a nodo.
		list->last_node = list->last_node->next;
	}

	list->size++;
}

// CASI igual a push_last_list
void push_first_list(list_t * list, void * value) {
	node_t * node = get_node_value(value);

	// Como este nodo es el primero, hacemos que el siguiente del primero es el que ya estaba.
	node->next = list->first_node;

	// Ponemos el nodo como el primero
	list->first_node = node;

	// Si no habia nodos, también es el último
	if (list->last_node == NULL) {
		list->last_node = node;
	}

	list->size++;
}

void clear_list(list_t * list) {
	// Mientras exista un elemento recorrer.
	while (existe_un_elemento(list)) {
		// Hacemos un pop (ya por defecto, hace free del nodo).
		// No necesitamos castear a su tipo real, no nos importa. Solo queremos borrar memoria.
		void * v = pop_list(list);
		// Hacemos free del value.
		free(v);
	}

	free(list);
}

// Función auxiliar, recibe un valor y devuelve un nodo.
node_t * get_node_value(void * value) {
	node_t * node = (node_t *) malloc(sizeof(node_t));

	node->val = value;
	node->next = NULL;

	return node;
}

// Función auxiliar, devuelve " 1 "  si tiene elementos, también podría ser "size > 0"
int existe_un_elemento(list_t * list) {
	return list->first_node != NULL;
}



