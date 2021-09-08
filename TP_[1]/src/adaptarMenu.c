/*
 * adaptarMenu.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn void actualizarNumer(float, float*)
 * @brief  Actualiza por referencia el valor de la variable float ingresada
 * @param nuevoNumero   El nuevo valor a guardar
 * @param variable  la variable a actualizar
 */

void actualizarNumer(float nuevoNumero, float *variable)
{
	*variable=nuevoNumero;
}

/**
 * @fn void printMenu(float, float, float, char[], int, int, char[])
 * @brief Imprime el menu base de la calculadora, con el tipo de operacion que se realizo mensaje de error y resultados
 * @param a  El valor actual de A
 * @param b  El valor actual de B
 * @param resultado El resultado de la operacion
 * @param operacion Un mensaje con el tipo de operacion que se realizo
 * @param factorialB El resultado del calculo Factorial B
 * @param opcion Un paremetro que se usa para filtrar el menu a mostrar si la operacion realizada es el factorial
 * @param operacionDos El mensaje del resultado del calculo de factorial B
 */

void printMenu(float a,float b, float resultado, char operacion[],int factorialB, int opcion, char operacionDos[])
{
	if(opcion==7)//calcular factorial
	{
		printf("||                                                                                                                             ");
		printf("||///////////////////////////////////////////////////// \n||\n");
		printf("||      A=%.2f                   B=%.2f      \n||\n", a ,b);
		if(a>=0)
		{
			printf("|| %s %.2f es: %.2f y ",operacion,a,resultado);
		}
		else
		{
			printf("|| %s %.2f y ",operacion,a);
		}
		if(b>=0)
		{
			printf("%s %.2f es: %.2f \n||",operacionDos,b,(float)factorialB);
		}
		else
		{
			printf("%s %.2f \n||",operacionDos,b);
		}

	}
	else
	{
		printf("||                                                                                                                             ");
		printf("||///////////////////////////////////////////////////// \n||\n");
		printf("||     A=%.2f                   B=%.2f      \n||\n", a ,b);
		printf("|| %s %.2f \n||\n",operacion,resultado);
	}


		printf("||          Ingrese la funcion que desea Realizar \n||\n");
		printf("|| 1  Cambiar Valor A   || 2  Cambiar Valor B   || 3 Calcular A+B || 4 Calcular A-B || \n");
		printf("|| 5 Calcular Valor A/B || 6 Calcular Valor A*B || 7 Calcular Factorial A y B || \n");
		printf("|| 8 SALIR || \n ");
}
