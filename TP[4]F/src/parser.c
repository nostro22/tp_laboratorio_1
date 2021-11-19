#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char id[10];
	char nombre[21];
	char horasTrabajadas[10];
	char sueldo[10];
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		/// fscanf(punteroArchivo, formato(%d, %[^,]), ...)
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo); /// leer encabezado
		while(!feof(pFile))
		{
			/// traigo los datos
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
			if(feof(pFile))
			{
				break;
			}
			Employee* auxEmpleado = employee_newParametros(id, nombre,horasTrabajadas,sueldo);
			/// lo pongo en el array
			ll_add( pArrayListEmployee, auxEmpleado);

		}
		fclose(pFile);
		retorno=1;
		if(ll_len(pArrayListEmployee)==0)
		{
			retorno=-2;
		}
	}

	return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	printf("Cargando datos del archivo binario\n");
	int retorno=-1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		/// fread(punteroDato, tamanio, cantidad, punteroArchivo)
		Employee* auxEmpleado = employee_new();
		while(feof(pFile)==0)
		{
			fread(auxEmpleado, sizeof(Employee), 1, pFile);
			if(feof(pFile)!=0)
			{
				break;
			}
			ll_add(pArrayListEmployee, auxEmpleado);
			auxEmpleado = employee_new();
		}
		retorno=1;
		if(ll_len(pArrayListEmployee)==0)
		{
			retorno=-2;
		}
		fclose(pFile);

	}
	return retorno;
}

