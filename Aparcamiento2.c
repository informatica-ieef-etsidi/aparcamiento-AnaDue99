//Desarrollador: Ana Dueñas
#include <stdio.h>
#include <Windows.h>
#include <string.h>


void main() {

	int plaza, i = 0, j = 0,k=0,l=0,comp1,comp2,comp3,comp4,comp5; //i y j de coches, k y l de motos. Comp para comparar cadenas
	char opcion,opcion2, matricula[8], matricula1[8], matricula2[8],matricula3[8],matricula4[8];
	do {
		printf("Seleccione una de estas opciones :\n	R - Reservar plaza\n	A - Abandonar plaza\n	E - Estado del aparcamiento\n	B - Buscar vehiculo por matricula\n	S - Salir del programa\n");
			

		scanf_s("%c", &opcion);

		Sleep(500);
		system("cls");
		switch (opcion) { //Bucle del menu de eleccion

		case 'R':
		case'r':
			printf("Ha escogido la opcion de reservar plaza\n\n");
			printf("Este aparcamiento tiene plazas para moto y coche.\n Si quiere aparcar un coche introduzca C.\n Si quiere aparcar una moto introduzca M\n");
			getchar();
			scanf_s("%c", &opcion2);
			
			switch (opcion2) {
			case 'C':
			case 'c':
				if (i == 1 && j == 1) { //Si ambas plazas estan llenas

					printf("No quedan plazas para coches en estos momentos.\n\n");


				}
				else {//Si no pide la matricula
					printf("\tIntroduzca  la matricula de su coche\n\n");

					//Dependiendo del estado del parking el coche se aparca en una plaza distinta

					if (i == 1 && j == 0) {
						scanf_s("%s", matricula2, 8);
						getchar();
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(matricula1, matricula2);
						comp4 = strcmp(matricula3, matricula2);
						comp5 = strcmp(matricula4, matricula2);
						if (comp3 == 0|| comp3==0|| comp4==0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", matricula2);
						}
						else {
							printf("Ahora la plaza 2 de coche esta ocupada por el coche de matricula:%s\n\n", matricula2);

							j = j++;
						}

					}
					else if (i == 0 && j == 1) {
						scanf_s("%s", matricula1, 8);
						getchar();
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(matricula1, matricula2);
						comp4 = strcmp(matricula1, matricula3);
						comp5 = strcmp(matricula1, matricula4);

						if (comp3 == 0|| comp4==0 || comp5==0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", matricula1);
						}
						else {

							printf("Ahora la plaza 1 de coche esta ocupada por el coche de matricula:%s\n\n", matricula1);
							i = i++;
						}
					}
					else {
						scanf_s("%s", matricula1, 8);
						getchar();
						comp4 = strcmp(matricula1, matricula3);
						comp5 = strcmp(matricula1, matricula4);
						if (comp4 == 0 || comp5 == 0 ) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", matricula1);
						}
						else {

							printf("Ahora la plaza 1 de coche esta ocupada por el coche de matricula:%s\n\n", matricula1);
							i = i++;
						}
					}
					getchar();
					break;
					
				}
			case 'm':
			case 'M':
				if (k == 1 && l == 1) { //Si ambas plazas de moto estan llenas

					printf("No quedan plazas para motos en estos momentos.\n\n");


				}
				else {//Si no, pide la matricula
					printf("\tIntroduzca  la matricula de su moto\n\n");

					//Dependiendo del estado del parking la moto se aparca en una plaza distinta

					if (k == 1 && l == 0) {
						scanf_s("%s", matricula4, 8);
						getchar();
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(matricula3, matricula4);
						comp4 = strcmp(matricula1, matricula4);
						comp5 = strcmp(matricula2, matricula4);
						if (comp3 == 0|| comp4==0 || comp5==0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", matricula4);
						}
						else {
							printf("Ahora la plaza 4 de moto esta ocupada por la moto de matricula:%s\n\n", matricula4);

							l = l++;
						}

					}
					else if (k == 0 && l == 1) {
						scanf_s("%s", matricula3, 8);
						getchar();
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(matricula3,matricula1);
						comp4 = strcmp(matricula3, matricula2);
						comp5 = strcmp(matricula3, matricula4);

						if (comp3 == 0|| comp4==0 || comp5==0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", matricula3);
						}
						else {

							printf("Ahora la plaza 3 de moto esta ocupada por la moto de matricula:%s\n\n", matricula3);
							k = k++;
						}
					}
					else {
						scanf_s("%s", matricula3, 8);
						getchar();
						comp3 = strcmp(matricula3, matricula1);
						comp4 = strcmp(matricula3, matricula2);
						if (comp3 == 0 || comp4 == 0 ) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", matricula3);
						}
						else {

							printf("Ahora la plaza 3 de moto esta ocupada por la moto de matricula:%s\n\n", matricula3);
							k = k++;
						}

						

					}
				}
				
				break;
			default: { printf("Por ahora solo se puede elegir entre plazas de motos y de coches\n Lo sentimos.\n");
			}
			}
		
			
			getchar();
			break;
		case 'A':
		case 'a':
			printf("Ha escogido abandonar el aparcamiento.\n\n");
			if (i == 0 && j == 0 && k == 0 && l == 0) {
				printf("Lo sentimos no hay vehiculos en estos momentos dentro del aparcamiento.\n");
			}
			else {
			printf("Elija si quiere sacar una moto o un coche.\n Para sacar una moto introduzca M\n Para sacar un coche introduzca C\n");
			getchar();
			scanf_s("%c",&opcion2);
			
			
				switch (opcion2) {
				case 'C':
				case 'c':
					printf("Ha escogido sacar un coche\n");
					if (i == 1 && j == 0) { //Si solo hay un coche 
						printf("Solo hay un coche en el parking\n\n");
						printf("El coche de la plaza 1 ha salido\n\n");
						i = i--;

					}
					else if (i == 0 && j == 1) { //Si solo hay un coche
						printf("Solo hay un coche en el parking\n\n");
						printf("El coche de la plaza 2 ha salido\n\n");
						j = j--;

					}
					else if (i == 1 && j == 1) { //Si hay mas, bucle para elegir de que plaza sacarlo
						printf("Escoja que coche quiere sacar, el de la plaza 1 o 2\n introduzca 1 o 2\n\n");
						printf("Plaza 1: %s\n", matricula1);
						printf("Plaza 2:%s\n", matricula2);
						scanf_s("%d", &plaza);
						switch (plaza)
						{
						case 1:
							printf("El coche de la plaza1 ha salido\n\n");
							i = i--;

							break;
						case 2:
							printf("El coche de la plaza2 ha salido\n\n");
							j = j--;


							break;
						default:
							//Si elige un numero de plaza inexistente
							printf("No hay tantas plazas de moto en el aparcamiento\n\n");


							break;
						}
					}
					else {
						//Si se elige aparcar y no hay coches
						printf("No hay coches en el aparcamiento en estos momentos\n\n");

					}
					getchar();
					break;
				case 'M':
				case 'm':
					printf("Ha escogido sacar una moto\n");
					if (k == 1 && l == 0) { //Si solo hay un coche 
						printf("Solo hay una moto en el parking\n\n");
						printf("El moto de la plaza 3 ha salido\n\n");
						k = k--;

					}
					else if (k == 0 && l == 1) { //Si solo hay un coche
						printf("Solo hay una moto en el parking\n\n");
						printf("La moto de la plaza 4 ha salido\n\n");
						l = l--;

					}
					else if (k == 1 && l == 1) { //Si hay mas, bucle para elegir de que plaza sacarlo
						printf("Escoja que coche quiere sacar, el de la plaza 1 o 2\n introduzca 1 o 2\n\n");
						printf("Plaza 3: %s\n", matricula3);
						printf("Plaza 4:%s\n", matricula4);
						scanf_s("%d", &plaza);
						switch (plaza)
						{
						case 3:
							printf("El coche de la plaza3 ha salido\n\n");
							k = k--;

							break;
						case 4:
							printf("El coche de la plaza4 ha salido\n\n");
							l = l--;


							break;
						default:
							//Si elige un numero de plaza inexistente
							printf("No hay tantas plazas de moto en el aparcamiento\n\n");


							break;
						}

					}
					else {
						//Si se elige aparcar y no hay coches
						printf("No hay motos en el aparcamiento en estos momentos\n\n");

					}
					break;
				default: { printf("Por ahora solo se puede elegir entre plazas de motos y de coches\n Lo sentimos.\n");
				}
				}
			}
			getchar();
			break;
		case 'E':
		case 'e':
			printf("Ha escogido ver el estado del aparcamiento.\n\n");
			printf("En estos momentos el aparcamiento se encuentra asi:\n\n");
			if (i == 0)
				printf("Plaza 1 de coche-Libre\n");
			else
				printf("Plaza 1-Ocupada por el coche de matricula:%s\n",matricula1);
			if (j == 0)
				printf("Plaza 2 de coche-Libre\n");
			else
				printf("Plaza 2-Ocupada por el coche de matricula:%s\n",matricula2);
			if (k == 0)
				printf("Plaza 3 de moto-Libre\n");
			else
				printf("Plaza 3-Ocupada por la moto de matricula:%s\n", matricula3);
			if (l== 0)
				printf("Plaza 4 de moto-Libre\n");
			else
				printf("Plaza 4-Ocupada por la moto de matricula:%s\n", matricula4);

			
			getchar();
			break;
		case 'S':
		case 's':
			printf("Ha decidido salir del programa.\n\t ¡Hasta la proxima!\n\n");
			getchar();
			break;
		case 'B':
		case 'b':
			printf("Ha escogido buscar un vehiculo por matricula\n\n ");
			printf("Introduzca la matricula del coche que quiere buscar:\n");
			scanf_s("%s", matricula, 8);
			comp1 = strcmp(matricula, matricula1);
			comp2 = strcmp(matricula, matricula2);
			comp3 = strcmp(matricula, matricula3);
			comp4 = strcmp(matricula, matricula4);
					
			if (comp1 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 1 de coche\n\n", matricula1);
			 }
			else if (comp2 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 2 de coche\n\n", matricula2);
			}
			else if (comp3 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 3 de moto\n\n", matricula3);
			}
			else if (comp4 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 4 de moto\n\n", matricula4);
			}
			else {
				printf("El vehiculo con matricula %s no se encuentra en el establecimiento\n\n", matricula);
			}
			getchar();
				break;
		default:
			
			printf("El programa aun no tiene mas opciones, elija entre las que muestra el menu\n\n");
			getchar();
			break;

		}

		system("pause"); //Parar
						
		system("cls"); //Borrar la consola

	}while (opcion != 'S'&& opcion!='s');
}

