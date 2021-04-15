/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	//Loggear "soy un log"
	log_info(logger, "Soy un log");

	config = leer_config();

	//asignar valor de config a la variable valor
	if (config_has_property(config, "CLAVE")) {
		valor = config_get_string_value(config, "CLAVE");

		//Loggear valor de config
		log_info(logger, valor);
	}

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.
	// TODO: Ver por que cuando mando a una funcion no lo setea
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");

	//crear conexion
	conexion = crear_conexion(ip, puerto);

	//enviar CLAVE al servirdor
	enviar_mensaje(valor, conexion);

	paquete(conexion);

	terminar_programa(conexion, logger, config);

	return 0;
}

t_log* iniciar_logger(void)
{
	return log_create("tp0.log", "el_tp0", true, LOG_LEVEL_INFO);
}

t_config* leer_config(void)
{
	return config_create("tp0.config");
}

void leer_consola(t_log* logger)
{
	char* leido;

	//El primero te lo dejo de yapa
	leido = readline(">");
	while (strcmp(leido, "")) {
		log_info(logger, leido);
		leido = readline(">");
	}

	free(leido);
}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido1 = "Mensaje en paquete 01";
	char* leido2 = "Mensaje en paquete 02";
	char* leido3 = "Mensaje en paquete 03";
	t_paquete* paquete = crear_super_paquete();

	agregar_a_paquete(paquete, leido1, strlen(leido1) + 1);
	agregar_a_paquete(paquete, leido2, strlen(leido2) + 1);
	agregar_a_paquete(paquete, leido3, strlen(leido3) + 1);

	leido1 = readline("Ingrese un texto para enviar ");
	agregar_a_paquete(paquete, leido1, strlen(leido1) + 1);

	enviar_paquete(paquete, conexion);

	eliminar_paquete(paquete);
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
	liberar_conexion(conexion);
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
}
