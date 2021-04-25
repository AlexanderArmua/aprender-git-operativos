/*
 ============================================================================
 Name        : linked-list.c
 Author      : Alexander Armua Abregu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <commons/string.h>
#include "linkedList.h"
#include "boludeces.h"

void boludeando();

void hacer_cosas_con_lista();

void hacer_cosas_con_hilos();


int main(void) {

	hacer_cosas_con_lista();

	//boludeando();

	return EXIT_SUCCESS;
}

void hacer_cosas_con_hilos() {

}

/**
 * En este ejemplo,
 * 1. Creamos una lista vacia.
 * 2. Le insertamos algunos valores "al azar" al final de la lista.
 * 3. Le insertamos un valor al principio de la lista.
 * 4. Recorremos algunos elementos de la lista y hacemos free del valor.
 * 5. Termina de recorrer y dejamos un elemento sin borrar para probar que se libere solo.
 * 6. Llamamos a la funcion clear_list para que limpie solo lo faltante.
 */
void hacer_cosas_con_lista() {
	list_t * list = create_list();

	printf("-----List Size: %d-----\n", size_list(list));

	for (int i = 1; i <= 3; i++) {
		int * value = malloc(sizeof(int));
		*value = i * 123;

		push_last_list(list, value);
	}

	int * value = malloc(sizeof(int));
	*value = 999;

	push_first_list(list, value);

	printf("-----List Size: %d-----\n", size_list(list));

	for (int i = 0; i < 2; i++) {
		int * first_value = (int *) pop_list(list);

		printf(" [ %d ] -->", *first_value);
		free(first_value);
	}

	printf("\n-----List Size: %d-----\n", size_list(list));

	clear_list(list);
}

void boludeando() {
	// 01 START - String modify
	char * stringg = string_new();
	string_append(&stringg, "TEsting this");
	puts(stringg);
	// 01 END - String modify

	// 02 START - Struct modify
	casa * casita = malloc(sizeof(casa));
	casita -> habitantes = 0;
	casita -> direccion = string_new();
	string_append(&casita -> direccion , "CAlle falsa 1 2 3");

	imprimir(casita);

	setear_habitantes(casita, 5);
	aumentar_habitantes(casita);

	imprimir(casita);
	// 02 END - Struct modify

	// 03 START - Char and Int modify
	char * ip = malloc(15 * sizeof(char));
	asignar_ip(&ip);
	printf("IP: %s\n", ip);

	int * numero = malloc(sizeof(int));
	*numero = 1	;
	asignar_numero(numero);
	printf("Número: %d\n", *numero);
	// 03 END - Char and Int modify

	// FREES
	free(stringg);
	free(casita->direccion);
	free(casita);
	free(ip);
	free(numero);
}





































