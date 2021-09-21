/*
 * adaptarMenu.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>

void actualizarNumer(float nuevoNumero, float *variable)
{
	*variable=nuevoNumero;
}



void printMenu(float a,float b,int banderaA,int banderaB)
{
		printf("||                                                                                                                             ");
		printf("||///////////////////////////////////////////////////// \n||\n");
		if(banderaA)
		{
			printf("||                   A=x          ");
		}
		else
		{
			printf("||                   A=%.2f          ", a);
		}
		if(banderaB)
				{
					printf("B=y      \n||\n");
				}
				else
				{
					printf("B=%.2f      \n||\n",b);
				}

		printf("||          Ingrese la funcion que desea Realizar \n||\n");
		printf("|| 1  Cambiar Valor A   || 2  Cambiar Valor B   ||\n");
		printf("|| 3 Calcular todas las operaciones: a) A+B; b) A-B; c) Valor A/B; d) Valor A*B; e) Calcular Factorial A y B || \n");
		printf("|| 4 Imprimir Resultados ||\n");
		printf("|| 5 SALIR || \n");
}


