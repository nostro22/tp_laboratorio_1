/*
 * calcularFunciones.h
 *
 *  Created on: Sep 7, 2021
 *      Author: Usuario
 */


#ifndef CALCULARFUNCIONES_H_
#define CALCULARFUNCIONES_H_
/**}
 * @fn float calcularSuma(float, float)
 * @brief Toma dos floats a y b; los suma devolviendo un float como el resultado de la suma
 * @param a numero 1 a ingresar
 * @param b numero 2 a ingresar
 * @return float resultado operacion
 */
float calcularSuma(float a, float b);
/**
 * @fn float calcularResta(float, float)
 * @brief Toma dos floats a y b; los resta devolviendo un float como el resultado de la resta
 * @param a numero 1 a ingresar
 * @param b numero 2 a ingresar
 * @return float resultado operacion
 */
float calcularResta(float a, float b);
/**
 * @fn float calcularDivision(float, float)
 * @brief Toma dos floats a y b; los divide devolviendo un float como el resultado de la division
 * @param a numero 1 a ingresar
 * @param b numero 2 a ingresar
 * @return float resultado operacion
 */
float calcularDivision(float a, float b);
/**
 * @fn float calcularMultiplicacion(float, float)
 * @brief Toma dos floats a y b; los multiplica devolviendo un float como el resultado de la multiplicacion
 * @param a numero 1 a ingresar
 * @param b numero 2 a ingresar
 * @return float resultado operacion si intenta dividir por cero regresara el valor 0
 */
float calcularMultiplicacion(float a, float b);
/**
 * @fn unsigned long int calcularFactorial(int)
 * @brief Toma un int y calcula el factorial, esta funcion no realiza la correcion de parametro asi que debe asegurarse de ingresar un int positivo
 * @param x un numero entero
 * @return regresa un unsigned long int con el resultado del factorial calculado
 */
unsigned long int calcularFactorial(int x);
/**
 * @fn int sePuedeCalcularFactorial(float)
 * @brief Toma un numero float y determina si este es positivo o negativo, esta funcion usa la funcion es verificarEsEntero para operar
 * @param numero float al que se desea determinar si se le puede calcular factorial
 * @return 1 si el numero es entero y positivo (se calcular factorial); 0 si no es posible.
 */
int sePuedeCalcularFactorial(float numero);
/**
 * @fn int verificarEsEntero(float)
 * @brief recibe un numero float y usando casteo determina si dicho numero es entero
 * @param a numero a determinar si es entero
 * @return 1 si el numero es entero; 0 si no lo es
 */
int verificarEsEntero(float a);

#endif /* CALCULARFUNCIONES_H_ */


