#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
/**
 * @fn Employee employee_new*()
 * @brief
 * Costructor sin inicializar de EMPLOYEE en memoria dinamica
 * @return retorno Employee* un puntero al empleado guardado en memoria
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief
 * Costructor inicializado por texto de EMPLOYEE en memoria dinamica, dentro del mismo se parsean los datos para que coincidan con los atributos de employee
 * @param idStr parametro id en texto que se parametrizara a int
 * @param nombreStr parametro nombre conservara el formato char[128]
 * @param horasTrabajadasStr parametro hotasTrabajasdas en texto que se parametrizara a int
 * @param sueldoStr parametro sueldo en texto que se parametrizara a int
 * @return retorno Employee* un puntero al empleado guardado en memoria
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/**
 * @fn void employee_delete(Employee*)
 * @brief
 * Destructor de EMPLOYEE, lo libera de memoria dinamica y setea el puntero a NULL
 * @param this El empleado a eliminar
 * @return 0 si this NULL. 1 si se borro correctamente
 */
int employee_delete(Employee* this);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief
 * asigna el id del Employee usando el parametro como valor
 * @param this El empleado a asignar
 * @param id parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se asigno
 */
int employee_setId(Employee* this,int id);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief
 * obtiene el valor de id del Employee y lo asigna al parametro por referencia
 * @param this El empleado del cual se obtendra el valor
 * @param id parametro de la clase employee
 * @return  0 si fallo this NULL. 1 se obtuvo el valor
 */
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief
 * asigna el Nombre del Employee usando el parametro como valor
 * @param this El empleado a asignar
 * @param nombre parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se asigno
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief
 * obtiene el valor de nombre del Employee y lo asigna al parametro por referencia
 * @param this El empleado del cual se obtendra el valor
 * @param nombre parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se obtuvo el valor
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief
 * asigna el HorasTrabajadas del Employee usando el parametro como valor
 * @param this  El empleado a asignar
 * @param horasTrabajadas parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se asigno
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief
 * obtiene el valor de horasTrabajadas del Employee y lo asigna al parametro por referencia
 * @param this El empleado del cual se obtendra el valor
 * @param horasTrabajadas parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se obtuvo el valor
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief
 * asigna el sueldo del Employee usando el parametro como valor
 * @param this El empleado a asignar
 * @param sueldo parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se asigno
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief
 * obtiene el valor de sueldo del Employee y lo asigna al parametro por referencia
 * @param this El empleado del cual se obtendra el valor
 * @param sueldo parametro de la clase employee
 * @return 0 si fallo this NULL. 1 se obtuvo el valor
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @fn int employee_printData(Employee*)
 * @brief
 * Imprime todos los parametros de Employee en forma de columna ordenado
 * @param this El empleado a imprimir
 * @return 0 si fallo this NULL. 1 se imprimio
 */
int employee_printData(Employee* this);

/**
 * @fn int employee_ordenarPorNombre(void*, void*)
 * @brief
 * Obtiene la direcion de memoria de dos empleados llama a los get y obteniene los nombres y luego los compara
 * @param punteroUno direcion de memoria de un Empleado
 * @param punteroDos direcion de memoria de un Empleado
 * @return -2 si algun puntero es NULL, 0 si son iguales los nombres, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int employee_ordenarPorNombre(void* punteroUno, void* punteroDos);

/**
 * @fn int employee_ordenarPorHoras(void*, void*)
 * @brief
 *Obtiene la direcion de memoria de dos empleados llama a los get y obteniene las horasTrabajadas y luego las compara
 * @param punteroUno direcion de memoria de un Empleado
 * @param punteroDos direcion de memoria de un Empleado
 * @return -2 si algun puntero es NULL, 0 si son iguales las horasTrabajadas, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int employee_ordenarPorHoras(void* punteroUno, void* punteroDos);

/**
 * @fn int employee_ordenarPorId(void*, void*)
 * @brief
 *Obtiene la direcion de memoria de dos empleados llama a los get y obteniene los ID y luego los compara
 * @param punteroUno direcion de memoria de un Empleado
 * @param punteroDos direcion de memoria de un Empleado
 * @return -2 si algun puntero es NULL, 0 si son iguales los Id, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int employee_ordenarPorId(void* punteroUno, void* punteroDos);

/**
 * @fn int employee_ordenarSueldo(void*, void*)
 * @brief
 *Obtiene la direcion de memoria de dos empleados llama a los get y obteniene los Sueldos y luego los compara
 * @param punteroUno direcion de memoria de un Empleado
 * @param punteroDos direcion de memoria de un Empleado
 * @return -2 si algun puntero es NULL, 0 si son iguales los sueldo, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int employee_ordenarSueldo(void* punteroUno, void* punteroDos);
#endif // employee_H_INCLUDED
