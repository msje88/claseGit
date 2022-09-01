/*
 ============================================================================
 Name        : ejercicio2-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);


	int numeroCliente;
	char estadoCivil;
	int edad;
	int temperatura;
	char genero;
	int contadorViudos;
	int flagMujerSolteraMasJoven;
	int edadMujerSolteraMasJoven;
	int numeroClienteMujerSolteraMasJoven;
	int precioPorPasajero;
	int contador;
	int precioTotalSinDescuento;
	int contadorMayores;
	int porcentajeMayores;
	int precioTotalConDescuento;
	char respuesta;

	contadorViudos=0;
	flagMujerSolteraMasJoven=1;
	precioPorPasajero=600;
	contador=0;
	contadorMayores=0;
	respuesta='s';




	while(respuesta=='s' && contador<=100){
			printf("Ingrese el numero de cliente: ");
			scanf("%d", &numeroCliente);
			fflush(stdin);

		do{
			printf("Ingrese el estado civil (s=soltero/c=casado/v=viudo): ");
			scanf("%c", &estadoCivil);
			fflush(stdin);
		}while(estadoCivil!='s' && estadoCivil!='c' && estadoCivil!='v');

		do{
			printf("Ingrese la edad (solo mayores de 17): ");
			scanf("%d", &edad);
			fflush(stdin);
		}while(edad<17);

		do{
			printf("Ingrese la temperatura corporal (entre 35 y 40): ");
			scanf("%d", &temperatura);
			fflush(stdin);
		}while(temperatura<35 || temperatura>40);

		do{
			printf("Ingrese el genero (f=femenino/m=masculino/o=no binario): ");
			scanf("%c", &genero);
			fflush(stdin);
		}while(genero!='f' && genero!='m' && genero!='o');

		if(edad>60)
		{
			contadorMayores++;

			if(estadoCivil=='v')
			{
			contadorViudos++;
			}
		}

		if(genero=='f' && estadoCivil=='s')
		{
			if(flagMujerSolteraMasJoven==1)
			{
				numeroClienteMujerSolteraMasJoven=numeroCliente;
				edadMujerSolteraMasJoven=edad;
				flagMujerSolteraMasJoven=0;
			}
			if(edad<edadMujerSolteraMasJoven)
			{
				numeroClienteMujerSolteraMasJoven=numeroCliente;
				edadMujerSolteraMasJoven=edad;
			}
		}

		contador++;

		printf("Desea continuar ingresando pasajeros?(s/n)");
		scanf("%c", &respuesta);
		fflush(stdin);

	}

	precioTotalSinDescuento=contador*precioPorPasajero;
	porcentajeMayores=(contadorMayores*100)/contador;

	if(contadorViudos!=0)
	{
		printf("La cantidad de personas con estado civil viudo de más de 60 años es: %d \n", contadorViudos);
	}

	if(edadMujerSolteraMasJoven!=0)
	{
		printf("el número de cliente de la mujer soltera más joven es: %d y su edad es: %d \n",
		numeroClienteMujerSolteraMasJoven, edadMujerSolteraMasJoven);
	}

	if(precioTotalSinDescuento!=0)
	{
		printf("El precio total sin descuento es: %d \n", precioTotalSinDescuento);
	}

	if (porcentajeMayores>50)
	{
		precioTotalConDescuento=precioTotalSinDescuento*0.75;
		printf("El precio total con descuento es: %d \n", precioTotalConDescuento);
	}


	return 0;
}
