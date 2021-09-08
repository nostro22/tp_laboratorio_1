/*
 * calcularFunciones.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * @fn float calcularSuma(float, float)
 * @brief Calcula la suma de los parametros ingresandos retornando un float
 * @param a El primer numero
 * @param b El segundo numero
 * @return
 */


float calcularSuma(float a, float b)
{
	float resultado;
	resultado=a+b;
	return resultado;
}

/**
 * @fn float calcularResta(float, float)
 * @brief Calcula la resta de los parametros ingresandos retornando un float
* @param a El primer numero
 * @param b El segundo numero
 * @return
 */

float calcularResta(float a, float b)
{
	float resultado;
	resultado=a-b;
	return resultado;
}

/**
 * @fn float calcularDivision(float, float)
 * @brief Calcula la division de los parametros ingresandos retornando un float, retorna 0 si la division es imposible de realizar
 * @param a El primer numero
 * @param b El segundo numero
 * @return
 */

float calcularDivision(float a, float b)
{
	float resultado;
	if(a==0)
	{
		return 0;
	}
	else
	{
		resultado=a/b;
		return resultado;
	}
}

/**
 * @fn float calcularMultiplicacion(float, float)
 * @brief Calcula la multiplicacion de los parametros ingresandos retornando un float
 * @param a El primer numero
 * @param b El segundo numero
 * @return
 */

float calcularMultiplicacion(float a, float b)
{
	float resultado;
	resultado =a*b;
	return resultado;
}

/**
 * @fn int calcularFactorial(int)
 * @brief Calcula el factorial de numero positivos enteros, en caso de entrar algun otro ingreso invalido retorna 1, por lo que el filtro de input debe ser realizado aparte
 * @param x
 * @return
 */
int calcularFactorial(int x)
{
	float resultado;
	if(x>0)
	{
		resultado=x*calcularFactorial(x-1);
		return resultado;
	}
	else
	{
		return 1;
	}
}




