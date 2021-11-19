

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Camino donde se encuentra el archivo a cargar
 * \param pArrayListEmployee LinkedList*  Lista de punteros de empleados
 * \return int 0 si fallo por path NULL o file NULL, -1 error en error parseo de datos y -2 error archivo vacio
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo dataBn.bin (modo binario).
 * \param path char* Camino donde se encuentra el archivo a cargar
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si fallo por path NULL o file NULL, -1 error en error parseo de datos y -2 error archivo vacio
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si pArrayList es NULL,   1 si la carga fue exitosa, 2 si se cancelo la carga por eleccion usuario, 3 si se cancelo por acabarse los intentos o fallo captacion de datos
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado, solicita al usurio un id del empleado, lo muestra y permite selecionar distintos tipos de modificacion (nombre, horas, sueldo)
 *
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 error pArrayListEmployee NULL, 1 modificacion exitosa, 2 cancelacion por elecion de usurio, si se cancelo por acabarse los intentos o fallo captacion de datos
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado solicita al usurio un id del empleado, lo muestra y pide confirmacion antes de eliminarlo de la lista e liberar la memoria dinamica
 *
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si pArrayListEmployee NULL, 1 eliminacion exitosa, 2 cancelacion de eliminacion por elecion de usurio, 3 cancelacion por agotamiento de intentos o empleado no encontrado
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados recorre la lista de punteros y llama a la funcion employee_printData
 *
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si pArrayListEmployee es NULL. 1 si fue ecitosa la impresion
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 * Se le pide al usuario que selecione la opcion de ordenamiento usando las disintas funciones de ordenamiento con un puntero a funcion y ll_sort se ejecutan estas sobre la lista
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si es NULL el array. 1 si fue exitoso el ordenamiento. 2 si se cancelo por selecion de usuario
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el camino hacia el archivo a guardar
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si el path es NULL. 1 si fue exitoso elguardado. 2 si pArrayListEmployee es NULL
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo dataBn.bin (modo binario).
 *
 * \param path char* el camino hacia el archivo a guardar
 * \param pArrayListEmployee LinkedList*
 * \return int int 0 si el path es NULL. 1 si fue exitoso elguardado. 2 si pArrayListEmployee es NULL
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


