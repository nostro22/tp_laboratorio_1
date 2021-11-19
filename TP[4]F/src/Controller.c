#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "INPUTS.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	int retorno=0;
	int errorParse=0;

	if(path!=NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile!=NULL)
		{
			errorParse=parser_EmployeeFromText(pFile , pArrayListEmployee);
			if(errorParse==-1)
			{
				retorno=-1;
			}
			else if(errorParse==-2)
			{
				retorno=-2;
			}
			else
			{
				retorno=1;
			}
		}


	}
	return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int errorParse=0;
	if(path!=NULL)
	{
		FILE* pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			errorParse =parser_EmployeeFromBinary(pFile , pArrayListEmployee);
			if(errorParse==-1)
			{
				retorno=-1;
			}
			else if(errorParse==-2)
			{
				retorno=-2;
			}
			else
			{
				retorno=1;
			}
		}

	}


	return retorno;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int i;
	char id[10];
	char nombre[21];
	char horasTrabajadas[10];
	char sueldo[10];
	int idMayor;
	char confirmacion =' ';
	int auxSueldo;
	int auxHoras;
	int error=0;
	int listaLength;
	Employee* pEmploy;
	int idEmpleadoActual;

	if(pArrayListEmployee!=NULL)
	{
		listaLength = ll_len(pArrayListEmployee);
		pEmploy=(Employee*) ll_get(pArrayListEmployee, 0);
		employee_getId(pEmploy, &idMayor);
		for (i = 0; i < listaLength; i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(idMayor<idEmpleadoActual)
			{
				employee_getId(pEmploy, &idMayor);
			}
		}
		idMayor+=1;
		itoa(idMayor,id,10);
		printf("Bienvenido porfavor ingrese los datos del empleado id:%s que desea agregar:\n",id);
		error = pedirCadenaSoloLetras(nombre, "Ingrese el nombre del empleado:\n", "Error reingreso solo se permiten letras y una logitud maxima de 21\n", 21,5);
		if(error==1)
		{
			error=pedirEntero(&auxHoras, "Ingrese horas trabajadas:\n", "Error valores permitidos entre 0-9999. Reingrese\n", 0, 9999,10);
		}
		if(error==1)
		{
			error=pedirEntero(&auxSueldo, "Ingrese Sueldo del trabajador:\n", "Error valores permitidos entre 10000-999999. Reingrese\n", 10000, 999999,10);
		}
		if(error==1)
		{
			itoa(auxHoras, horasTrabajadas,10);
			itoa(auxSueldo,sueldo,10);
			Employee* auxEmpleado = employee_newParametros(id, nombre,horasTrabajadas,sueldo);
			printf(" %-10s %-15s %-15s %-15s \n","ID","NOMBRE","HORAS","Sueldo");
			employee_printData(auxEmpleado);
			pedirCaracter(&confirmacion, "Ingrese S si desea agregar al empleado mostrado\n");
			if(confirmacion=='s'||confirmacion=='S')
			{
				ll_add( pArrayListEmployee, auxEmpleado);
				printf("Empleado Agregado con exito!\n");
				retorno=1;
			}
			else
			{
				printf("Se cancelo la alta. Volviendo al menu\n");
				retorno=2;
			}

		}
	}
	if(error==-1)
	{
		printf("intentos agotados Volviendo al menu\n");
		retorno=3;
	}
	return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	char nombre[21];
	int idNumber;
	char confirmacion =' ';
	int auxSueldo;
	int auxHoras;
	int noError=0;
	int listaLength;
	int option=0;
	int indiceEmpleado=-1;
	int i;
	Employee* pEmploy;
	int idEmpleadoActual;

	char auxViejoNombre[21];
	int auxViejoHoras;
	int auxViejoSueldo;

	if(pArrayListEmployee!=NULL)
	{


		noError=pedirEntero(&idNumber, "Ingrese el Id del empleado que desea modificar:\n", "No es un Id posible ingrese solo enteros positivos", 1, 9999, 6);
		if(noError==-1)
		{
			printf("Volviendo al menu intentos agotados\n");
		}
		else
		{

			listaLength = ll_len(pArrayListEmployee);
			for (i = 0; i < listaLength; i++)
			{
				pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(pEmploy, &idEmpleadoActual);
				if(idNumber==idEmpleadoActual)
				{
					indiceEmpleado=i;
					break;
				}
			}
			if(indiceEmpleado!=-1)
			{

				printf(" %-10s %-15s %-15s %-15s \n","ID","NOMBRE","HORAS","Sueldo");
				pEmploy=(Employee*) ll_get(pArrayListEmployee, indiceEmpleado);
				employee_printData(pEmploy);
				pedirCaracter(&confirmacion, "Ingrese S si este es el empleado que desea modificar\n");
				{
					if(confirmacion=='s'||confirmacion=='S')
					{
						pedirEntero(&option,"---------------------------------------------------------------------------------\n"
								"1.Modifica Nombre del empleado.\n"
								"2.Modifica Horas trabajadas del empleado.\n"
								"3.Modifica salario del empleado.\n"
								"4.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Ingrese una opcion: ",

								"1.Modifica Nombre del empleado.\n"
								"2.Modifica Horas trabajadas del empleado.\n"
								"3.Modifica salario del empleado.\n"
								"4.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Opcion invalida, reingrese: ",1, 4,10);

						switch (option) {
						case 1:
							noError = pedirCadenaSoloLetras(nombre, "Ingrese el nuevo nombre del empleado:\n", "Error reingreso solo se permiten letras y una logitud maxima de 21\n", 21,5);
							if(noError==1)
							{
								employee_getNombre(pEmploy, auxViejoNombre);
								employee_setNombre(pEmploy, nombre);

								printf(" %10s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
								employee_printData(pEmploy);

								pedirCaracter(&confirmacion, "Ingrese S si quiere guardar esta modificacion\n");
								if(confirmacion=='s'||confirmacion=='S')
								{
									printf("Modificacion exitosa volviendo al menu\n ");
									retorno=1;
								}
								else
								{
									employee_setNombre(pEmploy, auxViejoNombre);
									printf("Revirtiendo cambios volviendo al menu\n ");
									retorno=2;
								}
							}
							break;
						case 2:
							noError=pedirEntero(&auxHoras, "Ingrese modificacion de horas trabajadas:\n", "Error valores permitidos entre 0-9999. Reingrese\n", 0, 9999,10);
							if(noError==1)
							{
								employee_getHorasTrabajadas(pEmploy, &auxViejoHoras);
								employee_setHorasTrabajadas(pEmploy, auxHoras);

								printf(" %10s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
								employee_printData(pEmploy);
								pedirCaracter(&confirmacion, "Ingrese S si quiere guardar esta modificacion\n");
								if(confirmacion=='s'||confirmacion=='S')
								{
									printf("Modificacion exitosa volviendo al menu\n ");
									retorno=1;
								}
								else
								{
									employee_setHorasTrabajadas(pEmploy, auxViejoHoras);
									printf("Revirtiendo cambios volviendo al menu\n ");
									retorno=2;
								}
							}
							break;
						case 3:
							noError=pedirEntero(&auxSueldo, "Ingrese nuevo sueldo del empleado:\n", "Error valores permitidos entre 10000-999999. Reingrese\n", 10000, 999999,10);
							if(noError==1)
							{
								employee_getSueldo(pEmploy, &auxViejoSueldo);
								employee_setSueldo(pEmploy, auxSueldo);

								printf(" %10s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
								employee_printData(pEmploy);

								pedirCaracter(&confirmacion, "Ingrese S si quiere guardar esta modificacion\n");
								if(confirmacion=='s'||confirmacion=='S')
								{
									printf("Modificacion exitosa volviendo al menu\n ");
									retorno=1;
								}
								else
								{
									employee_setSueldo(pEmploy, auxViejoSueldo);
									printf("Revirtiendo cambios volviendo al menu\n ");
									retorno=2;
								}
							}
							break;
						case 4:
							noError=-1;
							printf("Se cancelo la modificacion. Volviendo al menu\n");
							retorno=2;
							break;
						}

					}
					else
					{
						printf("Se cancelo la modificacion. Volviendo al menu\n");
						retorno=3;
					}
				}
			}
			else
			{
				printf("Empleado no encontrado. Volviendo al menu\n");
				retorno=3;
			}
		}
	}
	return retorno;
}



int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int idNumber;
	char confirmacion =' ';
	int noError=0;
	int listaLength;
	int indiceEmpleado=-1;
	int i;
	Employee* pEmploy;
	int idEmpleadoActual;
	if(pArrayListEmployee!=NULL)
	{


		noError=pedirEntero(&idNumber, "Ingrese el Id del empleado que desea eliminar:\n", "No es un Id posible ingrese solo enteros positivos", 1, 9999, 6);
		if(noError==-1)
		{
			printf("Volviendo al menu intentos agotados\n");
			retorno=3;
		}
		else
		{

			listaLength = ll_len(pArrayListEmployee);
			for (i = 0; i < listaLength; i++)
			{
				pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(pEmploy, &idEmpleadoActual);
				if(idNumber==idEmpleadoActual)
				{
					indiceEmpleado=i;
					break;
				}
			}
			if(indiceEmpleado!=-1)
			{

				printf(" %10s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
				pEmploy=(Employee*) ll_get(pArrayListEmployee, indiceEmpleado);
				employee_printData(pEmploy);
				pedirCaracter(&confirmacion, "Ingrese S si este es el empleado que desea eliminar\n");
				{
					if(confirmacion=='s'||confirmacion=='S')
					{
						ll_remove(pArrayListEmployee, indiceEmpleado);
						retorno=1;
					}
					else
					{
						printf("Se cancelo la Baja. Volviendo al menu\n");
						retorno=2;
					}
				}
			}
		}
	}
	else
	{
		printf("ERROR referencia a lista de empleados NULL\n");
	}
	return retorno;

}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i=0;
	int retorno=0;
	if(pArrayListEmployee!=NULL)
	{
		int lenList = ll_len(pArrayListEmployee);
		printf(" %-10s %-15s %-15s %-15s \n","ID","NOMBRE","HORAS","Sueldo");
		for (i = 0; i < lenList; ++i)
		{
			Employee* pEmpleado =(Employee*) ll_get(pArrayListEmployee, i);
			employee_printData(pEmpleado);
		}
		retorno=1;
	}

	return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	printf("Entre aqui");
	int retorno =0;
	int opcioningreso=-1;
	if(pArrayListEmployee!=NULL)
	{
		int (*pFuncionOrdenamiento)(void*,void*);


		pedirEntero(&opcioningreso,"---------------------------------------------------------------------------------\n"
				"1-Ordenar por ID acendente.\n"
				"2-Ordenar por ID decendente.\n"
				"3-Ordenar por nombre acendente.\n"
				"4-Ordenar por nombre decendente.\n"
				"5-Ordenar por Horas trabajadas acendente.\n"
				"6-Ordenar por Horas trabajadas decendente.\n"
				"7-Ordenar por Sueldo acendente.\n"
				"8-Ordenar por Sueldo decendente.\n"
				"9-Salir\n"
				"--------------------------------------------------------------------------------\n"
				"Ingrese una opcion: ",

				"1-Ordenar por ID acendente.\n"
				"2-Ordenar por ID decendente.\n"
				"3-Ordenar por nombre acendente.\n"
				"4-Ordenar por nombre decendente.\n"
				"5-Ordenar por Horas trabajadas acendente.\n"
				"6-Ordenar por Horas trabajadas decendente.\n"
				"7-Ordenar por Sueldo acendente.\n"
				"8-Ordenar por Sueldo decendente.\n"
				"9-Salir\n"
				"--------------------------------------------------------------------------------\n"
				"Opcion invalida, reingrese: ",1, 10,10);


		switch(opcioningreso)
		{
		case 1:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarPorId;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 1);
			break;
		case 2:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarPorId;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 0);
			break;
		case 3:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarPorNombre;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 1);
			break;
		case 4:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarPorNombre;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 0);
			break;
		case 5:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarPorHoras;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 1);
			break;
		case 6:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarPorHoras;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 0);
			break;
		case 7:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarSueldo;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 1);
			break;
		case 8:
			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = employee_ordenarSueldo;
			ll_sort(pArrayListEmployee, pFuncionOrdenamiento, 0);
			break;
		case 9:

			printf("Volviendo al menu\n");
			retorno=2;
			break;
		}

		if(opcioningreso<0&&opcioningreso>9)
		{
			retorno=1;
		}


	}


	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

	int id;
	char nombre[21];
	int horasTrabajadas;
	int sueldo;
	Employee* pEmpleado;


	printf("Guardando... Generando archivo texto\n");
	int retorno=0;
	int tamArray= ll_len(pArrayListEmployee);

	FILE* pFile;
	if(path!=NULL)
	{
		retorno=2;
		pFile = fopen(path, "w");

		if(pFile!=NULL)
		{
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldoChar\n");

			for (int var = 0; var < tamArray; ++var)
			{
				pEmpleado=(Employee*)ll_get(pArrayListEmployee, var);
				employee_getId(pEmpleado, &id);
				employee_getNombre(pEmpleado, nombre);
				employee_getSueldo(pEmpleado, &sueldo);
				employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);

				fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);

			}
			printf("Archivo escrito con exito!\n");
			retorno=1;
		}
		fclose(pFile);
	}

	return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	printf("Guardando... Generando archivo binario\n");
	int retorno=0;
	int tamArray= ll_len(pArrayListEmployee);

	FILE* pFile;
	if(path!=NULL)
	{
		retorno=2;
		pFile = fopen(path, "wb");

		if(pFile!=NULL)
		{
			for (int var = 0; var < tamArray; ++var)
			{
				Employee* pAuxEmpleado =(Employee*) ll_get(pArrayListEmployee,var);
				fwrite(pAuxEmpleado, sizeof(Employee), 1, pFile);
			}
			printf("Archivo escrito con exito!\n");
			retorno=1;
		}
		fclose(pFile);
	}
	return retorno;
}

