/*
 * INPUTS.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief Solocita el ingreso de un entero solo aceptando valores entre el min y el maximo recibido por parametro y actualiza este valor por referencia
 * @param entero el numero que se pide y se actualizara por referencia
 * @param mensaje  de ingreso inicial para instruir al usuario
 * @param mensajeError en caso de error
 * @param min numero minimo aceptado
 * @param max numero maximo aceptado
 * @return -1 si hubo error. 0 si se capto el numero correctamente
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);


/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief Solocita el ingreso de un float solo aceptando valores entre el min y el maximo recibido por parametro y actualiza este valor por referencia
 * @param flotante el numero que se pide y se actualizara por referencia
 * @param mensaje  de ingreso inicial para instruir al usuario
 * @param mensajeError en caso de error
 * @param min numero minimo aceptado
 * @param max numero maximo aceptado
 * @return -1 si hubo error. 0 si se capto el numero correctamente
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);


/**
 * @fn int pedirCadena(char*, char*, char*, int)
 * @brief Solocita el ingreso de una cadena solo aceptandola si su longitud es menor a la max recibida por parametro
 * @param cadena lugar donde se guardara la cadena solicitada si cumple con los parametros de longitud
 * @param mensaje  de ingreso inicial para instruir al usuario
 * @param mensajeError en caso de error
 * @param max de longitud permitido para la cadena ingresada
 * @return -1 si hubo error. 0 si se capto el numero correctamente
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);


/**
 * @fn int pedirCaracter(char*, char*)
 * @brief solicita un char que ingrese el usuario solo toma el primer char ingresado
 * @param caracter lugar donde se guardara el char
 * @param mensaje mensaje para intruir al usuario
 * @return -1 en caso de error. 0 en caso de que sea exitoso la captacion del char
 */
int pedirCaracter(char* caracter, char* mensaje);

#endif /* INPUTS_H_ */
