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

/***
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief ask the entry of an integer only accepting values between the min and the maximum received per parameter and updates this value by reference
 * @param integer number requested and updated by reference
 * @param initial login message to instruct the user
 * @param messageError in case of error
 * @param min minimum number accepted
 * @param max number accepted
 * @return -1 if there was an error. 0 if the number was captured correctly
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);


/***
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief Solocita the entry of a float only accepting values between the min and the maximum received per parameter and updates this value by reference
 * @param floating the number requested and updated by reference
 * @param initial login message to instruct the user
 * @param messageError in case of error
 * @param min minimum number accepted
 * @param max number accepted
 * @return -1 if there was an error. 0 if the number was captured correctly
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);


/***
 * @fn int pedirCadena(char*, char*, char*, int)
 * @brief Solocita the entry of a string only accepting it if its length is less than the max received per parameter
 * @param string location where the requested string will be saved if it meets the length parameters
 * @param initial login message to instruct the user
 * @param messageError in case of error
 * @param max length allowed for the entered string
 * @return -1 if there was an error. 0 if the number was captured correctly
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);


/***
 * @fn int pedirCaracter(char*, char*)
 * @brief asks for a char to enter the user only takes the first char entered
 * @param character where the char was stored
 * @param message to intrude to the user
 * @return -1 in case of error. 0 in case of successful char capture
 */
int pedirCaracter(char* caracter, char* mensaje);

#endif /* INPUTS_H_ */
