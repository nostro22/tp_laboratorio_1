

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
 * \param pArrayListEmployee LinkedList*
 * \return int 0 error pArrayListEmployee NULL, 1 modificacion exitosa, 2 cancelacion por elecion de usurio, si se cancelo por acabarse los intentos o fallo captacion de datos
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


