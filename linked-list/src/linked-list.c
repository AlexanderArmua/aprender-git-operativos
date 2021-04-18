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
#include <string.h>

#include"CUnit/Basic.h"

typedef struct {
	char * direccion;
	int habitantes;
} casa;

void aumentar_habitantes(casa*);
void setear_habitantes(casa*, int);
void imprimir(casa*);

void asignar_ip(char**);

void asignar_numero(int*);

int main(void) {
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

	return EXIT_SUCCESS;
}

void aumentar_habitantes(casa * c) {
	c->habitantes ++;
}
void setear_habitantes(casa *c, int habitantes) {
	c->habitantes = habitantes;
}

void imprimir(casa * c) {
	printf("HAbitantes: %i\n", c->habitantes);
	printf("Direccion: %s\n", c->direccion);
}

void asignar_ip(char ** ip) { // jaja salu2
	strcpy(*ip, "127.0.0.1");
}

void asignar_numero(int * n) {
	*n = 100;
}

