/*
 * ArrayEmployees.c
 *
 *  Created on: Oct 1, 2021
 *      Author: Usuario
 */

#include "ArrayEmployees.h"

int initEmployees(Employee list[], int len)
{
	int retorno=-1;

	if(list != NULL)
	{
		int i;
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno=0;
	}
 return retorno;
}

int Employee_buscarEspacioLibre(Employee list[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(list[i].isEmpty == 1)
		{
			index = i;
			break;
		}
	}

	return index;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno =-1;
	int index = Employee_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta un empleado...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				strcpy(list[index].name, name);
				strcpy(list[index].lastName, lastName);
				list[index].salary= salary;
				list[index].sector= sector;
				list[index].isEmpty=0;

				printf("\nSe cargo el empleado!\n\n");
			}
			else
			{
				printf("\nSe cancelo el alta del empleado.\n\n");
			}
			retorno = 0;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{

	int i;
	int index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno =-1;
	int index = findEmployeeById(list, len, id);

		if(index != -1) //Si existe el empleado
		{
			printf("\nDando de baja un empleado...\n\n");
			if(list!=NULL&&list[index].isEmpty==0)
			{
				list[index].isEmpty=1;

				printf("\nSe bajo el empleado!\n\n");
			}
			else
			{
				printf("\nSe cancelo la baja del empleado.\n\n");
			}
			retorno = 0;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	int i;
	int j;
	Employee auxEmployee;

	switch (order) {
		case 1://Decendente
			if(list !=NULL)
			{
				for(i=0; i<len-1; i++)
					{
						for(j=i+1; j<len; j++)
						{
							if(strcmp(list[i].lastName, list[j].lastName) == 1)
							{
								auxEmployee = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEmployee; //copiamos la estructura ENTERA
							}
							else if((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].sector>list[j].sector)
							{
								auxEmployee = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEmployee; //copiamos la estructura ENTERA
							}
						}
					}
				retorno=0;
			}
			break;
		case 0://Acendente
			if(list !=NULL)
			{
				for(i=0; i<len-1; i++)
					{
						for(j=i+1; j<len; j++)
						{
							if(strcmp(list[i].lastName, list[j].lastName) > 0)
							{
								auxEmployee = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEmployee; //copiamos la estructura ENTERA
							}
							else if((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].sector>list[j].sector)
							{
								auxEmployee = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEmployee; //copiamos la estructura ENTERA
							}
						}
					}
				retorno=0;
			}
					break;
	}


return retorno;

}

int printEmployees(Employee list[], int length)
{
	int retorno =-1;
	if(list!=NULL)
	{
		int i;
			printf("\nMostrando lista de Empleados...\n\n"
				   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "NAME", "LAST NAME", "SALARY", "SECTOR");
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == 0)
				{
					printOneEmployee(list[i]);
				}
			}
			printf("\n");
	}
	return retorno;
}

void printOneEmployee(Employee empleado)
{
	printf("%-5d %-20s %-20s %-20.2f %-20d\n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}
void printEncabezadoEmployee()
{
	printf("%-5s %-20s %-20s %-20s %-20s\n", "ID", "NAME", "LAST NAME", "SALARY", "SECTOR");
}

int contarEmpleadosActivos(Employee list[],int len)
{
	int retorno =-1;
	if(list!=NULL)
	{
		int i;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty == 0)
				{
					retorno++;
				}
			}
	}
	if(retorno!=-1)
	{
		retorno++;
	}
	return retorno;
}
float Employee_TotalSumaSalarios(Employee list[],int len)
{
	float retorno =-1;
	if(list!=NULL)
	{
		retorno=0;
		int i;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty == 0)
				{
					retorno+=list[i].salary;
				}

			}
	}
	if(retorno!=-1)
	{
		retorno++;
	}
	return retorno;
}

float Employee_PromedioSalarios(Employee list[],int len)
{
	float retorno =-1;
	int cantidadEmpleados;
	retorno=Employee_TotalSumaSalarios( list,len);
	cantidadEmpleados=contarEmpleadosActivos(list, len);
	if(retorno!=-1&&cantidadEmpleados>0)
	{
		retorno=retorno/cantidadEmpleados;
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}
int Employee_ContadorEmpleadoSalarioSuperiorA(Employee list[],int len, float salarioGuia)
{
	int retorno =-1;
	if(list!=NULL)
	{
		int i;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty == 0 &&list[i].salary > salarioGuia)
				{
					retorno++;
				}
			}
	}
	if(retorno!=-1)
	{
		retorno++;
	}
	return retorno;
}
