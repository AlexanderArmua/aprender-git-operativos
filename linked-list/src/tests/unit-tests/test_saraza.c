#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <cspecs/cspec.h>
#include "../../../src/linkedList.h"

const int int_to_add = 35;

void add_int_to_list_end(list_t *);
void add_int_to_list_start(list_t *);

context (linked_list_creacion_modificacion) {

	describe("LINKED_LIST: Creación y vaciado de la lista") {
		list_t * lista = NULL;

		before {
			lista = create_list();
		} end

		it("CREATE_LIST: La lista se crea correctamente") {
			should_ptr(lista) not be null;

			clear_list(lista);
		} end

		skip("CLEAR_LIST: La lista se elimina correctamente (No se puede checkear el valor de una variable después del free)") {
			clear_list(lista);

			should_ptr(lista) be equal to(NULL);
		} end

	} end

	describe("LINKED_LIST: Agregado y Eliminado de elementos") {
		list_t * lista = NULL;

		before {
			lista = create_list();
		} end

		after {
			clear_list(lista);
		} end

		it("POP_LIST: Se agrega un elemento al final y se elimina correctamente") {
			add_int_to_list_end(lista);

			int * value = pop_list(lista);

			should_int(*value) be equal to(int_to_add);
			free(value);
		} end

		it("POP_LIST: Se agrega un elemento al principio y se elimina correctamente") {
			add_int_to_list_start(lista);

			int * value = pop_list(lista);

			should_int(*value) be equal to(int_to_add);
			free(value);
		} end

		it("POP_LIST: Lista vacia retorna NULL") {
			int * value = pop_list(lista);

			should_ptr(value) be null;
		} end

		it ("PEEK_LIST: Lista vacia retorna NULL") {
			int * value = peek_list(lista);

			should_ptr(value) be null;
		} end

		it ("PEEK_LIST: Se agrega un elemento al final y lo retorna correctamente") {
			add_int_to_list_end(lista);

			int * value = peek_list(lista);

			should_int(*value) be equal to(int_to_add);
		} end

		it ("PEEK_LIST: Se agrega un elemento al principio y lo retorna correctamente") {
			add_int_to_list_start(lista);

			int * value = peek_list(lista);

			should_int(*value) be equal to(int_to_add);
		} end
	} end

	describe("LINKED_LIST: Modificaciones a la lista, se mantiene el size") {
		list_t * lista = NULL;

		before {
			lista = create_list();
		} end

		after {
			clear_list(lista);
		} end

		it ("SIZE_LIST: Lista vacia tiene un tamaño de 0") {
			unsigned int size = size_list(lista);

			should_int(size) be equal to(0);
		} end

		it ("SIZE_LIST: Lista con 2 elementos deberia dar 2") {
			add_int_to_list_end(lista);
			add_int_to_list_end(lista);

			unsigned int size = size_list(lista);

			should_int(size) be equal to(2);
		} end

		it ("SIZE_LIST: Lista con 2 añadidos y 1 eliminado deberia dar 1") {
			add_int_to_list_end(lista);
			add_int_to_list_end(lista);

			int * value = pop_list(lista);
			free(value);

			unsigned int size = size_list(lista);

			should_int(size) be equal to(1);
		} end

		it ("SIZE_LIST: Lista con 2 añadidos al final y al principio y 2 eliminados deberia dar 0") {
			add_int_to_list_end(lista);
			add_int_to_list_start(lista);

			int * value = pop_list(lista);
			free(value);
			value = pop_list(lista);
			free(value);

			unsigned int size = size_list(lista);

			should_int(size) be equal to(0);
		} end
	} end

}

void add_int_to_list_end(list_t * lista) {
	int * value = malloc(sizeof(int));
	*value = int_to_add;

	push_last_list(lista, value);
}

void add_int_to_list_start(list_t * lista) {
	int * value = malloc(sizeof(int));
	*value = int_to_add;

	push_first_list(lista, value);
}

// gcc test_saraza.c -lcspecs

/*
it("Texto") {
	should...
} end
skip("Texto") {
	should...
} end
should_bool(<actual_boolean>) be equal to(<expected_boolean>);
should_bool(<actual_boolean>) not be equal to(<unexpected_boolean>);
should_char(<caracter_actual>) be equal to(<caracter_esperado>);
should_char(<caracter_actual>) not be equal to(<caracter_no_esperado>);
should_short(<actual_number>) be equal to(<expected_number>);
should_short(<actual_number>) not be equal to(<unexpected_number>);
should_int(<actual_number>) be equal to(<expected_number>);
should_int(<actual_number>) not be equal to(<unexpected_number>);
should_long(<actual_number>) be equal to(<expected_number>);
should_long(<actual_number>) not be equal to(<unexpected_number>);
should_float(<actual_float>) be equal to(<expected_float>);
should_float(<actual_float>) not be equal to(<unexpected_float>);
should_double(<decimal_actual>) be equal to(<decimal_esperado>);
should_double(<decimal_actual>) not be equal to(<decimal_no_esperado>);
should_ptr(<actual_pointer>) be equal to(<expected_pointer>);
should_ptr(<actual_pointer>) not be equal to(<unexpected_pointer>);
should_string(<actual_word>) be equal to(<expected_word>);
should_string(<actual_word>) not be equal to(<unexpected_word>);

should_bool(<actual_boolean>) be truthy;
should_bool(<actual_boolean>) not be truthy;
should_bool(<actual_boolean>) be falsey;
should_bool(<actual_boolean>) not be falsey;
should_ptr(<actual_pointer>) be null;
should_ptr(<actual_pointer>) not be null;

before {
    // Code to execute before each test
} end
after {
    // Code to execute after each test
} end
 */
