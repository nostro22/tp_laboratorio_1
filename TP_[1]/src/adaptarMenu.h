/*
 * adaptarMenu.h
 *
 *  Created on: Sep 7, 2021
 *      Author: Usuario
 */

#ifndef ADAPTARMENU_H_
#define ADAPTARMENU_H_


/**
 * @fn void actualizarNumer(float, float*)
 * @brief recibe una variable float por parametro y la actualiza con el valor ingresado en el primer parametro
 * @param nuevoNumero float del valor que actualizara a la variable
 * @param variable pasada por referencia para actualizar por referencia
 */
void actualizarNumer(float nuevoNumero, float *variable);
/**
 * @fn void printMenu(float, float, int, int)
 * @brief interface que se muestra con las opciones del menu, mostrando siempre los valores de A y B
 * @param a primera variable numerica para usar en las distintas operaciones de la calculadora
 * @param b segunda variable numerica para usar en las distintas operaciones de la calculadora
 * @param banderaA Variable que avisa si ya se ingreso un valor en A para controlar el print default A=X
 * @param banderaB Variable que avisa si ya se ingreso un valor en B para controlar el print default B=Y
 */
void printMenu(float a,float b,int banderaA,int banderaB);


#endif /* ADAPTARMENU_H_ */
