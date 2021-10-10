/*
 * ArrayEmployees.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Usuario
 */
#include "INPUTS.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int Employee_buscarEspacioLibre(Employee list[], int tam);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int id);
int sortEmployees(Employee list[], int len, int order);
int printEmployees(Employee list[], int length);
void printEncabezadoEmployee();
void printOneEmployee(Employee empleado);
int contarEmpleadosActivos(Employee list[],int len);
float Employee_TotalSumaSalarios(Employee list[],int len);
float Employee_PromedioSalarios(Employee list[],int len);
int Employee_ContadorEmpleadoSalarioSuperiorA(Employee list[],int len, float salarioGuia);

#endif /* ARRAYEMPLOYEES_H_ */
