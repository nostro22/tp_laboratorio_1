/*
 * calcularFunciones.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calcularSuma(float a, float b)
{
	float resultado;
	resultado=a+b;
	return resultado;
}

float calcularResta(float a, float b)
{
	float resultado;
	resultado=a-b;
	return resultado;
}

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

float calcularMultiplicacion(float a, float b)
{
	float resultado;
	resultado =a*b;
	return resultado;
}

unsigned long int calcularFactorial(int x)
{
	unsigned long int resultado;
	if(x>0)
	{
		resultado=x*calcularFactorial(x-1);
		return resultado;
	}
	else
	{
		return (unsigned long int)1;
	}
}

int verificarEsEntero(float a)
{
	int retorno=0;
	int enteroA=a;
	if(a>=0 && (a-enteroA==0))
	{
		retorno=1;
	}
	return retorno;
}

int sePuedeCalcularFactorial(float numero)
{
	int retorno;
	retorno=0;

	if(numero>=0 && verificarEsEntero(numero))
	{
		retorno=1;
	}
	return retorno;
}

