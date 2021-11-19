#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include  "ctype.h"

Employee* employee_new()
{
	Employee* employeeRetorno = NULL;
	employeeRetorno = (Employee*) malloc (sizeof(Employee));
	return employeeRetorno;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employeeRetorno = NULL;
	employeeRetorno = employee_new();
	if(employeeRetorno != NULL){
		employee_setId( employeeRetorno, atoi(idStr));
		employee_setNombre( employeeRetorno, nombreStr);
		employee_setHorasTrabajadas(employeeRetorno, atoi(horasTrabajadasStr));
		employee_setSueldo(employeeRetorno, atoi(sueldoStr));
	}
	return employeeRetorno;
}


int employee_delete(Employee* this)
{
	int retorno=0;
	if(this != NULL)
	{
		free(this);
		this = NULL;
		retorno=1;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->id = id;
		seCargo = 1;
	}
	return seCargo;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo = 1;
	}
	return seCargo;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		seCargo = 1;
	}
	return seCargo;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->sueldo = sueldo;
		seCargo = 1;
	}
	return seCargo;
}

int employee_getId(Employee* this,int* id)
{
	int retorno =0;
	if(this != NULL)
	{
		*id = this->id;
		retorno =1;
	}
	return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int retorno =0;
	if(this != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno =1;
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno =0;
	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno =1;
	}
	return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno =0;
	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno =1;
	}
	return retorno;
}

int employee_printData(Employee* this)
{
	int retorno=0;
	int id;
	char nombre[51];
	int horasTrabajadas;
	int sueldo;
	if(this !=NULL)
	{
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajadas);
		employee_getSueldo(this, &sueldo);
		printf("%-10d  %-15s  %-15d %-15d\n", id, nombre, horasTrabajadas, sueldo);
	}
	return retorno;
}

int employee_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		char auxNombreUno[128];
		char auxNombreDos[128];
		Employee* auxEmpleado = (Employee*)punteroUno;
		Employee* auxEmpleadoDos = (Employee*)punteroDos;
		employee_getNombre(auxEmpleado,auxNombreUno);
		employee_getNombre(auxEmpleadoDos,auxNombreDos);

		retorno=stricmp(auxNombreUno,auxNombreDos);

		auxEmpleado =NULL;
		auxEmpleadoDos=NULL;
	}

	return retorno;
}

int employee_ordenarPorHoras(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		int horasUno;
		int horasDos;
		Employee* auxEmpleado = (Employee*)punteroUno;
		Employee* auxEmpleadoDos = (Employee*)punteroDos;
		employee_getHorasTrabajadas(auxEmpleado,&horasUno);
		employee_getHorasTrabajadas(auxEmpleadoDos,&horasDos);

		if(horasUno>horasDos)
		{
			retorno=1;
		}
		else if(horasUno<horasDos)
		{
			retorno=-1;
		}
		auxEmpleado =NULL;
		auxEmpleadoDos=NULL;
	}
	return retorno;
}

int employee_ordenarPorId(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		int idUno;
		int idDos;
		Employee* auxEmpleado = (Employee*)punteroUno;
		Employee* auxEmpleadoDos = (Employee*)punteroDos;
		employee_getId(auxEmpleado,&idUno);
		employee_getId(auxEmpleadoDos,&idDos);

		if(idUno>idDos)
		{
			retorno=1;
		}
		else if(idUno<idDos)
		{
			retorno=-1;
		}
		auxEmpleado =NULL;
		auxEmpleadoDos=NULL;
	}
	return retorno;
}

int employee_ordenarSueldo(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		int sueldoUno;
		int sueldoDos;
		Employee* auxEmpleado = (Employee*)punteroUno;
		Employee* auxEmpleadoDos = (Employee*)punteroDos;
		employee_getSueldo(auxEmpleado,&sueldoUno);
		employee_getSueldo(auxEmpleadoDos,&sueldoDos);

		if(sueldoUno>sueldoDos)
		{
			retorno=1;
		}
		else if(sueldoUno<sueldoDos)
		{
			retorno=-1;
		}
		auxEmpleado =NULL;
		auxEmpleadoDos=NULL;
	}
	return retorno;
}


