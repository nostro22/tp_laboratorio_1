/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Eduardo Andres Sosa Segovia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ArrayEmployees.h"
#include"INPUTS.h"

#define QTY_EMPLEADOS 1000
#define NOMBREAPELLIDOLENGTH 51
#define SALARIOMIN 1000
#define SALARIOMAX 2000
#define SECTORMIN 1
#define SECTORMAX 12
int main(void) {

Employee listaEmpleados[QTY_EMPLEADOS];
int idContador=1;
int cantidadEmpleadosActivos=0;
int auxIndex;
Employee auxEmploy;
int opcion;
int salir=0;
char confirmacion;
int cantidadSalarioMayorPromedio=0;
float sumatoriaSalarios=0;
float promedioSalario;
setbuf(stdout,NULL);
initEmployees(listaEmpleados, QTY_EMPLEADOS);


do
{

	printf("Base de datos de empleados ver.0\n\n"
			"1)Generar Atla de empleado\n"
			"2)Modificar Empleado\n"
			"3)Generar Baja Empleado\n"
			"4)Informes\n"
			"5)SALIR\n");
	pedirEntero(&opcion, "Opcion:", "ERROR", 1, 5);
	switch (opcion) {
		case 1:

			auxIndex=Employee_buscarEspacioLibre(listaEmpleados, QTY_EMPLEADOS);
			if(auxIndex!=-1)
			{
				auxEmploy.id=idContador;
				printf("Ingresando nuevo empleado en la nomina n° %d\n",auxIndex);
				printf("Maximo de longitud permitido %d caracteres\n",NOMBREAPELLIDOLENGTH);
				pedirCadena(auxEmploy.name, "Ingrese el nombre del empleado\n", "Reingrese nombre invalido\n", NOMBREAPELLIDOLENGTH);
				printf("Maximo de longitd permitido %d \n",NOMBREAPELLIDOLENGTH);
				pedirCadena(auxEmploy.lastName, "Ingrese el apellido del empleado\n", "Reingrese apellido invalido\n", NOMBREAPELLIDOLENGTH);
				printf("Valores aceptados %d-%d \n", SALARIOMIN, SALARIOMAX);
				pedirFlotante(&auxEmploy.salary, "Ingrese el salario del Empleado", "Reingrese salario invalido\n", SALARIOMIN, SALARIOMAX);
				printf("Valores aceptados %d-%d \n",SECTORMIN, SECTORMAX);
				pedirEntero(&auxEmploy.sector, "Ingrese el sector del Empleado", "Reingrese Sector invalido", SECTORMIN, SECTORMAX);
				printf("\n\n");
				printEncabezadoEmployee();
				printOneEmployee(auxEmploy);
				pedirCaracter(&confirmacion, "\n\nEsta Seguro que desea agregar al empleado a nomina ingrese  Y para confirmar");
				if(confirmacion=='Y'||confirmacion=='y')
				{
					addEmployee(listaEmpleados, QTY_EMPLEADOS, auxEmploy.id, auxEmploy.name, auxEmploy.lastName, auxEmploy.salary, auxEmploy.sector);
					idContador++;
					cantidadEmpleadosActivos++;
					printf("Empleado Agregado Exitosamente \n");
				}
				else
				{
					printf("Volviendo al menu \n");
				}
			}
			else
			{
				printf("Esta full la nomina ya no podemos pagar mas obras sociales ni impuesto \n");
			}
			system("pause");

			break;
		case 2:

			printf("Bienvenido al menu de modificacion\n\n");
			if(cantidadEmpleadosActivos>0)
			{
				pedirEntero(&auxEmploy.id, " ingrese el numero de empleado que desea modificar\n", "Ingreso invalido, reingrese rango permitido (1-32767)\n", 1, 32767);
				int empleadoConseguido=-1;
				empleadoConseguido=findEmployeeById(listaEmpleados, QTY_EMPLEADOS, auxEmploy.id);
				if(empleadoConseguido!=-1 && listaEmpleados[empleadoConseguido].isEmpty!=1)
				{   auxEmploy=listaEmpleados[empleadoConseguido];
					printEncabezadoEmployee();
					printOneEmployee(auxEmploy);
					pedirEntero(&opcion, "Ingrese:\n"
							"1)Modificar Nombre\n"
							"2)Modificar Apellido\n"
							"3)Modificar Salario\n"
							"4)Modificar Sector\n"
							"5)Volver al menu\n",
							"Opcion invalidad reingrese:\n"
							"1)Modificar Nombre\n"
							"2)Modificar Apellido\n"
							"3)Modificar Salario\n"
							"4)Modificar Sector\n"
							"5)Volver al menu\n", 1, 5);
					switch (opcion)
					{
						case 1:
							printf("Maximo de longitud permitido %d caracteres\n",NOMBREAPELLIDOLENGTH);
							pedirCadena(auxEmploy.name, "Ingrese el nombre del empleado\n", "Reingrese nombre invalido\n", NOMBREAPELLIDOLENGTH);

							break;
						case 2:
							printf("Maximo de longitd permitido %d \n",NOMBREAPELLIDOLENGTH);
							pedirCadena(auxEmploy.lastName, "Ingrese el apellido del empleado\n", "Reingrese apellido invalido\n", NOMBREAPELLIDOLENGTH);
												break;
						case 3:
							printf("Valores aceptados %d-%d \n", SALARIOMIN, SALARIOMAX);
							pedirFlotante(&auxEmploy.salary, "Ingrese el salario del Empleado", "Reingrese salario invalido\n", SALARIOMIN, SALARIOMAX);

												break;
						case 4:
							printf("Valores aceptados %d-%d \n",SECTORMIN, SECTORMAX);
							pedirEntero(&auxEmploy.sector, "Ingrese el sector del Empleado", "Reingrese Sector invalido", SECTORMIN, SECTORMAX);
												break;
						case 5:
							printf("Volviendo al menu \n");
												break;
					}
						printEncabezadoEmployee();
						printOneEmployee(auxEmploy);
						pedirCaracter(&confirmacion, "\n\nEsta Seguro que desea realizar este cambio; ingrese  Y para confirmar");
						if(confirmacion=='Y'||confirmacion=='y')
						{
							listaEmpleados[empleadoConseguido]=auxEmploy;
							printf("Empleado Actualizado Exitosamente \nVolviendo al menu \n");
						}


				}
				else
				{
					printf("El Id:%d no existe en la bade de datos.\n volviendo al menu\n",auxEmploy.id);
				}
			}
			else
			{
				printf("Aun no ha agregado ningun empleado solo puede modificar empleados registrados y activos \nVolviendo al menu\n");
			}
			system("pause");

					break;
		case 3:
			printf("Bienvenido al menu de Bajas\n\n");
			if(cantidadEmpleadosActivos>0)
			{
				pedirEntero(&auxEmploy.id, " ingrese el numero de empleado que desea dar de baja\n", "Ingreso invalido, reingrese rango permitido (1-32767)\n", 1, 32767);
				int empleadoConseguido=-1;
				empleadoConseguido=findEmployeeById(listaEmpleados, QTY_EMPLEADOS, auxEmploy.id);
				if(empleadoConseguido!=-1 && listaEmpleados[empleadoConseguido].isEmpty!=1)
				{
					printEncabezadoEmployee();
					printOneEmployee(auxEmploy);
					pedirCaracter(&confirmacion, "\n\nEsta Seguro que desea dar de baja a este empleado; ingrese  Y para confirmar");
					if(confirmacion=='Y'||confirmacion=='y')
					{
						listaEmpleados[empleadoConseguido].isEmpty=1;
						cantidadEmpleadosActivos--;
						printf("Empleado dado de baja Exitosamente \nVolviendo al menu \n");
					}
				}
			}
			else
			{
				printf("Aun no ha agregado ningun empleado solo puede dar de baja a empleados registrados y activos \nVolviendo al menu\n");
			}
			system("pause");
					break;
		case 4:
			printf("Bienvenido al menu de Informes\n\n");
					if(cantidadEmpleadosActivos>0)
					{
						pedirEntero(&opcion, "Ingrese:\n"
													"1)Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
													"2)Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n"
													"3)Volver al menu\n",
													"Ingreso Invalido reingrese:\n"
													"1)Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
													"2)Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n"
													"3)Volver al menu\n",1,3);
						switch (opcion) {
							case 1:
								pedirEntero(&opcion, "Ingrese:\n"
													"1)Orden Acendente.\n"
													"2)Orden Decendente. \n",
													"Ingreso Invalido reingrese:\n"
													"1)Orden Acendente.\n"
													"2)Orden Decendente. \n",1,2);
								if(opcion==1)//Ascendente
								{
									sortEmployees(listaEmpleados, QTY_EMPLEADOS, 1);
								}
								else//Descendente
								{
									sortEmployees(listaEmpleados, QTY_EMPLEADOS, 0);
								}
								printEmployees(listaEmpleados, QTY_EMPLEADOS);
								system("pause");
								break;
							case 2:
								sumatoriaSalarios=Employee_TotalSumaSalarios(listaEmpleados, QTY_EMPLEADOS);
								promedioSalario=Employee_PromedioSalarios(listaEmpleados,QTY_EMPLEADOS);
								cantidadSalarioMayorPromedio= Employee_ContadorEmpleadoSalarioSuperiorA(listaEmpleados, QTY_EMPLEADOS, promedioSalario);

								printf("Informe de Salarios \n\n");
								printf("Suma Total de todos los salarios: %.2f \n"
										"Promedio Salario General: %.2f\n"
										"Cantidad Empleados con Salario superior al promedio: %d\n",sumatoriaSalarios,promedioSalario,cantidadSalarioMayorPromedio);
														break;
							case 3:
								printf("Volviendo al menu \n");
														break;

						}
					}
					else
					{
						printf("Aun no ha agregado ningun empleado nada que informar \nVolviendo al menu\n");
					}
					system("pause");
					break;
		case 5:
				salir=1;
					break;

	}

	printf("Ingrese una tecla para continuar");
getchar();
}while(!salir);


}
