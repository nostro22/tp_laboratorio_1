/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Eduardo Andres Sosa Segovia
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calcularFunciones.h"
#include "adaptarMenu.h"
#define LIMITECALCULOFACTORIAL 12

/**
 * @fn int main(void)
 * @brief Es una calculadora basica, imprime constantemente una interface donde se muestran los valores de A y B,
 *  Se pueden realizar 5 funciones distintas que se filtran en un switch
 * 1. Ingresar 1er operando (A=x) // 2. Ingresar 2do operando (B=y) // 3. Calcular todas las operaciones // 4. Informar resultados // 5. Salir
 * @return
 */

int main(void) {
	setbuf(stdout,NULL);
	float a=0;
	float b=0;
	int continuar=1;
	float ingreso;
	int opcion=0;
	float resultadoSuma=0;
	float resultadoResta=0;
	float resultadoDivision=0;
	float resultadoMultiplicacion=0;
	unsigned long int resultadoFactorialA=0;
	unsigned long int resultadoFactorialB=0;
	int banderaAsignadoA=1;
	int banderaAsignadoB=1;
	int banderaSinCalcular=1;
	char mensajeRespuestaDivision[50];

	do
	{
		printMenu(a, b,banderaAsignadoA,banderaAsignadoB);
		fflush(stdin);
		scanf("%d",&opcion);

		switch (opcion) {
			case 1:
				printf("Ingrese el valor de A \n");
				fflush(stdin);
				scanf("%f",&ingreso);
				actualizarNumer(ingreso, &a);
				banderaAsignadoA=0;
				banderaSinCalcular=1;

				break;
			case 2:
				printf("Ingrese el valor de B \n");
				fflush(stdin);
				scanf("%f",&ingreso);
				actualizarNumer(ingreso,&b);
				banderaAsignadoB=0;
				banderaSinCalcular=1;

					break;
			case 3:
				resultadoSuma=calcularSuma(a, b);
				resultadoResta=calcularResta(a, b);
				if(b==0)
				{
					strcpy(mensajeRespuestaDivision, "No es posible Dividir por ");
					resultadoDivision=0;
				}
				else
				{
					resultadoDivision=calcularDivision(a, b);
					strcpy(mensajeRespuestaDivision, "");
				}

				resultadoMultiplicacion=calcularMultiplicacion(a, b);

				if(sePuedeCalcularFactorial(a)&&a<=LIMITECALCULOFACTORIAL)
				{
					resultadoFactorialA=calcularFactorial(a);
				}
				if(sePuedeCalcularFactorial(b)&&b<=LIMITECALCULOFACTORIAL)
				{
					resultadoFactorialB=calcularFactorial(b);
				}

				banderaSinCalcular=0;

					break;
			case 4:
				if(banderaSinCalcular==0) //Significa que se realizaron los calculos antes de llamar IMprimir resultados
				{
					if(banderaAsignadoA==0&&banderaAsignadoB==0)
					{
						printf("Resultados Obtenidos: \n");
						printf("a)El resultado de %.2f+%.2f es : %.2f\n\n",a,b,resultadoSuma);
						printf("b)El resultado de %.2f-%.2f es : %.2f\n\n",a,b,resultadoResta);
						printf("c)El resultado de %.2f/%.2f es : %s %.2f\n\n",a,b,mensajeRespuestaDivision,resultadoDivision);
						printf("d)El resultado de %.2f*%.2f es : %.2f\n\n",a,b,resultadoMultiplicacion);
					}
					if(banderaAsignadoA==0)
					{
						if(sePuedeCalcularFactorial(a)&&a<=LIMITECALCULOFACTORIAL)
						{
							printf("E)El Factorial de %.2f es : %lu",a,resultadoFactorialA);
						}
						if(a>LIMITECALCULOFACTORIAL)
						{
							printf("E)El Factorial de %.2f no es computable supera el limite de memoria. (limite: %d)",a,LIMITECALCULOFACTORIAL);
						}
						if(!(sePuedeCalcularFactorial(a)))
						{
							printf("E)El Factorial de %.2f no es calculable %.2f no es entero y positivo",a,a);
						}
					}
					if(banderaAsignadoB==0)
					{
						if(sePuedeCalcularFactorial(b)&&b<=LIMITECALCULOFACTORIAL)
						{
							printf(" y el Factorial de %.2f es : %lu\n\n",b,resultadoFactorialB);
						}
						if(b>LIMITECALCULOFACTORIAL)
						{
							printf(" y el factorial de %.2f no es computable supera el limite de memoria. (limite: %d)",b,LIMITECALCULOFACTORIAL);
						}
						if(!(sePuedeCalcularFactorial(b)))
						{
							printf(" y el Factorial de %.2f no es calculable %.2f no es entero y positivo \n\n",b,b);
						}
					}

				}

				if(banderaAsignadoA&&banderaAsignadoB)
				{
				printf("Recuerde Ingresar los valores de A y B\n");
				}
				if(banderaSinCalcular)
				{
				printf("Recuerde llamar a la funcion calcular todo antes de imprimir resultados\n\n");
				}

				printf("Presione Enter para Volver al menu");
				fflush(stdin);
				getchar();

					break;
			case 5:
				continuar=0;
					break;
		}

	}while(continuar);

	printf("Programa Cerrado, gracias por elegirnos");

	return EXIT_SUCCESS;
}
