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
/***
* @fn int initEmployees(Employee[], int)
* @brief Browse the employee list and start at each index isEmpty to 0
* @param list of employees to be initialized
* @param len list size
* @return -1 if inizialization could not be performed. 0 if initialization of the operation is achieved
*/
int initEmployees(Employee list[], int len);

/***
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief looks for the first free space in the employee list and then adds an employee with the data received by parameter
 * @param list of employees where to find the available employee
 * @param len list size
 * @param id parameter de Employee
 * @param name Employee parameter
 * @param lastName parametro de Employee
 * @param salary parametro de Employee
 * @param Employee parameter sector
 * @return -1 if there was an error or there was no space in the list. 0 if the employee was correctly uploaded to the list
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/***
 * @fn int Employee_buscarEspacioLibre(Employee[], int)
 * @brief Looks for the first free space in the employee list and returns its index
 * @param list of employees where to find the available employee
 * @param tam list size
 * @return -1 if no free space was found or there was some error. a number n which is the index where the free space is
 */
int Employee_buscarEspacioLibre(Employee list[], int tam);

/***
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief goes through the list of employees, looks for an employee with the id received by parameter and returns its position in the list
 * @param list list of employees to visit
 * @param len array size
 * @param id used to search the list
 * @return -1 if there was an error or the employee was not found. A number with the employee’s position in the list with the id received per parameter
 */
int findEmployeeById(Employee list[], int len,int id);

/***
 * @fn int removeEmployee(Employee*, int, int)
 * @brief searches Employee cpn the id received by parameter in the list verifies that this asset, shows you, asks for confirmation of elimination and then performs a logical download
 * @param list of employees where to find the employee received by id
 * @param len list size
 * @param id to find the employee in the list
 * @return -1 if there was an error or the employee was not found. 0 if the employee was found and either deleted or cancelled.
 */
int removeEmployee(Employee list[], int len, int id);

/***
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the employee list you receive per parameter, based on the employee’s last name or lastName
 In case of overlap the sector is used as the second criterion. it allows to order well accentuated or decently
 * @param list employee list received to order
 * @param len array size
 * @param order parametro that determines whether it is ordered accent or decendente
 * @return -1 if there was an error. 0 if ordered correctly
 */
int sortEmployees(Employee list[], int len, int order);

/***
 * @fn int printEmployees(Employee[], int)
 * @brief receives a list of employees per parameter and prints the active employees on it
 * @param list of employees where to look for employees
 * @param length list size
 * @return -1 if there was an error. 0 if the full list is traversed and the active employee is printed
 */
int printEmployees(Employee list[], int length);


/***
 * @fn void printEncabezadoEmployee()
 * @brief Prints a header with employee data names
 *
 */
void printEncabezadoEmployee();

/***
 * @fn void printOneEmployee(Employee)
 * @brief receives an employee per parameter and prints to it, in column format without any header to determine the data
 * @param employee
 */
void printOneEmployee(Employee empleado);

/***
 * @fn int countEmployeesActives(Employee[], int)
 * @brief goes through the employee list you receive per parameter and counts all active employees and returns that count
 * @param list of employees where to look for employees
 * @param length list size
 * @return -1 if there was an error. n with the number of active employees if you manage to go through the list and count the active employees
 */
int contarEmpleadosActivos(Employee list[],int len);

/***
 * @fn float Employee_TotalSumaSalarios(Employee[], int)
 * @brief goes through the list of employees it receives per parameter and adds all salaries of active employees and returns that accumulator
 * @param list of employees where to look for employees
 * @param length list size
 * @return -1 if there was an error. n with the number of active employees if you manage to go through the list and accumulate the salary of active employees
 */
float Employee_TotalSumaSalarios(Employee list[],int len);

/***
 * @fn float Employee_PromedioSalarios(Employee[], int)
 * @brief calling the functions Employee_TotalSumaSalarios y contarEmpleadosActives, returns the average value by dividing these two results
 * @param list of employees where to look for employees
 * @param length list size
 * @return -1 if there was an error. n with the average salary of the active employees
 */
float Employee_PromedioSalarios(Employee list[],int len);

/***
 * @fn int Employee_ContadorEmployedSalarioSuperiorA(Employee[], int, float)
 * @brief having as floor the salary received as parameter guides the list and counts the employees with greater salary than this
 * @param lists the list of employees to visit
 * @param len list size
 * @param salarioGuia the average salary that will serve as floor
 * @return -1 if there was an error. n with the number of employees with salary above average
 */
int Employee_ContadorEmpleadoSalarioSuperiorA(Employee list[],int len, float salarioGuia);

#endif /* ARRAYEMPLOYEES_H_ */
