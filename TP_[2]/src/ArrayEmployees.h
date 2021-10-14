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
/**
 * @fn int initEmployees(Employee[], int)
 * @brief Recorre la lista de employee e inizializa en cada indice isEmpty a 0
 * @param list lista de employees a ser inicializada
 * @param len tamaño de la lista
 * @return  -1 si no se pudo realizar la inizializacion. 0 si se logro inicializar la operacion
 */
int initEmployees(Employee list[], int len);

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief busca el primer espacio libre en la lista de employee y luego agrega un employee con los datos recibidos por parametro
 * @param list lista de empleados donde se buscara el employee disponible
 * @param len tamaño de la lista
 * @param id parametro de Employee
 * @param name parametro de Employee
 * @param lastName parametro de Employee
 * @param salary parametro de Employee
 * @param sector parametro de Employee
 * @return -1 si hubo error o no habia espacio en la lista. 0 si se cargo correctamente el employee a la lista
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int Employee_buscarEspacioLibre(Employee[], int)
 * @brief Busca el primer espacio libre en la lista de employee y devuelve su indice
 * @param list lista de empleados donde se buscara el employee disponible
 * @param tam tamaño de la lista
 * @return -1 si no se logro encontrar un espacio libre o hubo algun error. un numero n que es el indice donde esta el espacio libre
 */
int Employee_buscarEspacioLibre(Employee list[], int tam);

/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief recorre la lista de empleados, busca un employee con el id recibido por parametro y retorna su posicion en la lista
 * @param list lista de employee a recorrer
 * @param len tamaño del array
 * @param id que se usara para buscar en la lista
 * @return -1 si hubo error o no se consiguio el empleado. Un numero n con la posicion del employee en la lista con el id recibido por parametro
 */
int findEmployeeById(Employee list[], int len,int id);

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief busca Employee cpn el id recibido por parametro en la lista verifica que este este activo, te lo muestra, pide confirmacion de eliminacion y luego realiza una baja logica
 * @param list lista de empleados donde se buscara el employee recibido por id
 * @param len tamaño de la lista
 * @param id para buscar al employee en la lista
 * @return -1 si hubo error o no se encontro el empleado. 0 si se consiguio el empleado y bien se elimino o se cancelo diccha eliminacion.
 */
int removeEmployee(Employee list[], int len, int id);

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Ordena la lista de employee que recibe por parametro, basandose en el apellido o lastName de los employee
 *  en caso de que coincida se usa como segundo criterio el sector. permite ordenar bien acendentemente o decendententemente
 * @param list lista de employee recibido para ordenar
 * @param len tamaño del array
 * @param order parametro que determina si se ordenara en forma acendente o decendente
 * @return -1 si hubo algun error. 0 si se ordeno correctamente
 */
int sortEmployees(Employee list[], int len, int order);

/**
 * @fn int printEmployees(Employee[], int)
 * @brief recibe una lista de employee por parametro e imprime los empleados activos en la misma
 * @param list lista de empleados donde se buscara a los employee
 * @param length tamaño de la lista
 * @return -1 si hubo error. 0 si se logro recorrer la lista completa e imprimir a los employee activos
 */
int printEmployees(Employee list[], int length);


/**
 * @fn void printEncabezadoEmployee()
 * @brief  Imprime un encabezados con los nombres de los datos de employee
 *
 */
void printEncabezadoEmployee();

/**
 * @fn void printOneEmployee(Employee)
 * @brief recibe un employee por parametro e imprime al mismo, en formato de columna sin nigun encabezado para determinar los datos
 * @param empleado
 */
void printOneEmployee(Employee empleado);

/**
 * @fn int contarEmpleadosActivos(Employee[], int)
 * @brief  recorre la lista de employee que recibe por parametro y cuenta todos los empleados activos y devuelve ese conteo
 * @param list lista de empleados donde se buscara a los employee
 * @param length tamaño de la lista
 * @return -1 si hubo error. n con el numero de empleados activos si se logro recorrer la lista y contar a los employee activos
 */
int contarEmpleadosActivos(Employee list[],int len);

/**
 * @fn float Employee_TotalSumaSalarios(Employee[], int)
 * @brief  recorre la lista de employee que recibe por parametro y suma todos salarios de los empleados activos y devuelve ese acumulador
 * @param list lista de empleados donde se buscara a los employee
 * @param length tamaño de la lista
 * @return -1 si hubo error. n con el numero de empleados activos si se logro recorrer la lista y acumular el salario de los employee activos
 */
float Employee_TotalSumaSalarios(Employee list[],int len);

/**
 * @fn float Employee_PromedioSalarios(Employee[], int)
 * @brief llamando a las funciones Employee_TotalSumaSalarios y contarEmpleadosActivos, devuelve por retorno el valor del promedio al dividir estos dos resultados
 * @param list lista de empleados donde se buscara a los employee
 * @param length tamaño de la lista
 * @return -1 si hubo error. n con el promedio de salario de los empleados activos
 */
float Employee_PromedioSalarios(Employee list[],int len);

/**
 * @fn int Employee_ContadorEmpleadoSalarioSuperiorA(Employee[], int, float)
 * @brief teniendo como piso el salarioGuia recibido como parametro recorre la lista y cuenta a los employee con mayor salario que este
 * @param list la lista de empleados a recorrer
 * @param len tamaño de la lista
 * @param salarioGuia el salario promedio que servira como piso
 * @return -1 si hubo error. n con la cantidad de empleados con salario por encima del promedio
 */
int Employee_ContadorEmpleadoSalarioSuperiorA(Employee list[],int len, float salarioGuia);

#endif /* ARRAYEMPLOYEES_H_ */
