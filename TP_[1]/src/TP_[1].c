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

/**
 * @fn int main(void)
 * @brief Es una calculadora basica, imprime constantemente una interface donde se muestran los valores de A y B,
 *  Se pueden realizar 7 funciones distintas que se filtran en un switch
 *  (1 actualizar valor A, 2 actualizar valor de B, 3 A+B, 4 A-B, 5 A/B, 6 A*B, 7 Factorial A y Factorial de B, 8 salir del programa)
 * @return
 */

int main(void) {
	setbuf(stdout,NULL);
	float a=0;
	float b=0;
	int continuar=1;
	float ingreso;
	int factorialB=0;
	int opcion=0;
	float resultado=0;
	char operacion[100]="                 Resultado Operacion: \n||                      ";
	char operacionDos[100]="";
	int enteroA;
	int enteroB;


	do
	{
		printMenu(a, b, resultado, operacion, factorialB, opcion, operacionDos);
		fflush(stdin);
		scanf("%d",&opcion);

		switch (opcion) {
			case 1:
				printf("Ingrese el valor de A \n");
				fflush(stdin);
				scanf("%f",&ingreso);
				actualizarNumer(ingreso, &a);

				break;
			case 2:
				printf("Ingrese el valor de B \n");
				fflush(stdin);
				scanf("%f",&ingreso);
				actualizarNumer(ingreso,&b);

					break;
			case 3:
				resultado=calcularSuma(a, b);
				strcpy(operacion, "El resultado de A+B es :");

					break;
			case 4:
				resultado=calcularResta(a, b);
				strcpy(operacion, "El resultado de A-B es :");
					break;
			case 5:
				resultado=calcularDivision(a, b);
				if(b==0)
				{
					strcpy(operacion, "No es posible Dividir por ");
				}
				else
				{
					strcpy(operacion, "El resultado de A/B es :");
				}

					break;
			case 6:
				resultado=calcularMultiplicacion(a, b);
				strcpy(operacion, "El resultado de A*B es :");
					break;
			case 7:

				enteroA=a;
				enteroB=b;

				if(a>=0 && (a-enteroA==0))
				{
					resultado=calcularFactorial(a);
					strcpy(operacion,"El Factorial de");
				}
				else
				{
					strcpy(operacion,"No existe el factorial de");
				}
				if(b>=0&& (b-enteroB==0))
				{
					factorialB=calcularFactorial(b);
					strcpy(operacionDos,"El Factorial de");
				}
				else
				{
					strcpy(operacionDos,"No existe el factorial de");
				}

					break;
			case 8:
				continuar=0;
					break;
			default:
				break;
		}

	}while(continuar);

	printf("Programa Cerrado, gracias por elegirnos");

	return EXIT_SUCCESS;
}
