#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "INPUTS.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/


int main()
{
	setbuf(stdout,NULL);
	int option = 0;
	int listaCargada=0;
	int errorControllerText =0;
	int errorControllerBin =0;
	char confirmacion ={' '};
	LinkedList* listaEmpleados = ll_newLinkedList();

	do{

		pedirEntero(&option,"---------------------------------------------------------------------------------\n"
				"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2.Cargar los datos de los empleados desde el archivo dataBn.bin (modo binario).\n"
				"3.Alta de empleado.\n"
				"4.Modificar datos de empleado.\n"
				"5.Baja de empleado-\n"
				"6.Listar empleados.\n"
				"7.Ordenar empleados.\n"
				"8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
				"9.Guardar los datos de los empleados en el archivo dataBn.bin (modo binario).\n"
				"10.Salir.\n"
				"---------------------------------------------------------------------------------\n"
				"Ingrese una opcion: ",

				"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2.Cargar los datos de los empleados desde el archivo dataBn.bin (modo binario).\n"
				"3.Alta de empleado.\n"
				"4.Modificar datos de empleado.\n"
				"5.Baja de empleado-\n"
				"6.Listar empleados.\n"
				"7.Ordenar empleados.\n"
				"8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
				"9.Guardar los datos de los empleados en el archivo dataBn.bin (modo binario).\n"
				"10.Salir.\n"
				"---------------------------------------------------------------------------------\n"
				"Opcion invalida, reingrese: ",1, 10,10);

		switch(option)
		{
		case 1:
			confirmacion=' ';
			if(listaCargada)
			{
				pedirCaracter(&confirmacion, "Cargar nuevamente eliminara los datos no guardados.\nIngrese c para confirmar la carga del archivo\n");
			}
			else
			{
				confirmacion='c';
			}


			if(confirmacion=='c'||confirmacion=='C')
			{
				ll_clear(listaEmpleados);
				errorControllerText = controller_loadFromText("data.csv",listaEmpleados);
				if(errorControllerText==0)
				{
					printf("ERROR carga de archivo\n");
				}
				else if (errorControllerText==-1)
				{
					printf("ERROR parseo de archivo\n");
				}
				else if(errorControllerText==-2)
				{
					printf("ERROR Archivo vacio\n");
				}
				else
				{
					listaCargada=1;
					printf("Datos cargados con exito...\nVolviendo al menu...\n");
				}
			}

			option=0;
			break;
		case 2:
			confirmacion=' ';
			if(listaCargada)
			{
				pedirCaracter(&confirmacion, "Cargar nuevamente eliminara los datos no guardados.\nIngrese c para confirmar la carga del archivo\n");
			}
			else
			{
				confirmacion='c';
			}


			if(confirmacion=='c'||confirmacion=='C')
			{
				ll_clear(listaEmpleados);
				errorControllerBin = controller_loadFromBinary("dataBn.bin",listaEmpleados);
				if(errorControllerBin==0)
				{
					printf("ERROR carga de archivo\n");
				}
				else if (errorControllerBin==-1)
				{
					printf("ERROR parseo de archivo\n");
				}
				else if(errorControllerBin==-2)
				{
					printf("ERROR Archivo vacio\n");
				}
				else
				{
					listaCargada=1;
					printf("Datos cargados con exito...\nVolviendo al menu...\n");
				}
			}

			option=0;
			break;
		case 3:
			if(listaCargada)
			{
				controller_addEmployee(listaEmpleados);
			}
			else
			{
				printf("Carge la base de datos primero\n");
			}

			break;
		case 4:
			if(listaCargada)
			{
				controller_editEmployee(listaEmpleados);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}

			break;
		case 5:
			if(listaCargada)
			{
				controller_removeEmployee(listaEmpleados);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}
			break;
		case 6:
			if(ll_len( listaEmpleados)>0)
			{
				controller_ListEmployee(listaEmpleados);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}
			break;
		case 7:
			if(listaCargada)
			{
				controller_sortEmployee(listaEmpleados);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}

			break;
		case 8:
			if(listaCargada)
			{
				controller_saveAsText("data.csv", listaEmpleados);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}

			break;
		case 9:
			if(listaCargada)
			{
				controller_saveAsBinary("dataBn.bin", listaEmpleados);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}

			break;
		case 10:

			printf("Liberando espacio de memoria...\n");
			printf("Lista Eliminada...\n");
			printf("Saliendo del sistema...\n");
			ll_deleteLinkedList(listaEmpleados);
			break;
		}

		system("pause");
	}while(option != 10);
	printf("Programa cerrado.\n");
	return 0;
}

