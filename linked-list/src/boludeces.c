/*
 * boludeces.c
 *
 *  Created on: 18 abr. 2021
 *      Author: utnso
 */

#include <stdio.h>
#include <string.h>
#include "boludeces.h"

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
