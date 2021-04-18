/*
 * boludeces.h
 *
 *  Created on: 18 abr. 2021
 *      Author: utnso
 */

#ifndef BOLUDECES_H_
#define BOLUDECES_H_

typedef struct {
	char * direccion;
	int habitantes;
} casa;

void aumentar_habitantes(casa*);
void setear_habitantes(casa*, int);
void imprimir(casa*);

void asignar_ip(char**);

void asignar_numero(int*);


#endif /* BOLUDECES_H_ */
