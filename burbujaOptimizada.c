//*****************************************************************
//M. EN C. EDGARDO ADRIÃN FRANCO MARTÃNEZ
//Curso: AnÃ¡lisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de mediciÃ³n de tiempo en C y recepciÃ³n de parametros en C bajo UNIX
//CompilaciÃ³n: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementaciÃ³n de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//EjecuciÃ³n: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÃ“N DE FUNCIONES
//*****************************************************************

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	//******************************************************************
	//Variables del main
	//******************************************************************
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para mediciÃ³n de tiempos
	int n;												   //n determina el tamaÃ±o del algorito dado por argumento al ejecutar
	int i, j, aux;										   //Variables para loops
	int *numero;										   //variable apuntador para reservar memoria
	char *cambios = "Si";

	//******************************************************************
	//RecepciÃ³n y decodificaciÃ³n de argumentos
	//******************************************************************

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecuciÃ³n y cadena=n)
	if (argc != 2)
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n", argv[0]);
		exit(1);
	}
	//Tomar el segundo argumento como tamaÃ±o del algoritmo
	else
	{
		n = atoi(argv[1]);
	}

	//******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	//Reservar memoria para el arreglo "numero"
	numero = malloc(n * sizeof(int));

	if (numero == NULL)
		exit(1);

	//AsignaciÃ³n de los nÃºmeros al arreglo
	for (i = 0; i < n; i++)
		scanf("%d", &numero[i]);
	//******************************************************************
	//Algoritmo
	//******************************************************************

	i = 0;
	while (i < n - 1 && cambios != "No")
	{
		cambios = "No";
		for (j = 0; j < n - 1 - i; j++)
		{
			if (numero[j] > numero[j + 1])
			{
				aux = numero[j];
				numero[j] = numero[j + 1];
				numero[j + 1] = aux;
				cambios = "Si";
			}
		}
		i++;
	}
	//******************************************************************

	//******************************************************************
	//Evaluar los tiempos de ejecuciÃ³n
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	//CÃ¡lculo del tiempo de ejecuciÃ³n del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciÃ³nes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acciÃ³nes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente
	exit(0);
}

//************************************************************************
//DEFINICIÃ“N DE FUNCIONES
//************************************************************************
