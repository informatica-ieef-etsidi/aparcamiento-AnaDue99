//Desarrollador: Ana Dueñas
#include <stdio.h>
#include <Windows.h>
#include <string.h>
struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipo; // M - Moto / C - Coche
	char matricula[8]; // Formato de la matrícula: NNNNLLL
};


void main() {
	struct plaza plaza1 = { 0, 'C' }, plaza2 = { 0, 'C' }, plaza3 = { 0, 'M' }, plaza4 = { 0, 'M' }, comp;
	int  comp1, comp2, comp3, comp4, comp5, plaza; //i y j de coches, k y l de motos. Comp para comparar cadenas
	char opcion, opcion2;
	do {
		Sleep(3000);
		system("cls");
		printf("Seleccione una de estas opciones :\n	R - Reservar plaza\n	A - Abandonar plaza\n	E - Estado del aparcamiento\n	B - Buscar vehiculo por matricula\n	S - Salir del programa\n");
		scanf_s("%c", &opcion);
		getchar();
		switch (opcion) { //Bucle del menu de eleccion

		case 'R':
		case'r':
			printf("Ha escogido la opcion de reservar plaza\n\n");
			printf("Este aparcamiento tiene plazas para moto y coche.\n Si quiere aparcar un coche introduzca C.\n Si quiere aparcar una moto introduzca M\n");
			scanf_s("%c", &opcion2);
			getchar();
			switch (opcion2) {
			case 'C':
			case 'c':
				if (plaza1.estado == 1 && plaza2.estado == 1) { //Si todas las plazas estan llenas

					printf("No quedan plazas para coches en estos momentos.\n\n");


				}
				else {//Si no pide la matricula
					printf("\tIntroduzca  la matricula de su coche\n\n");

					//Dependiendo del estado del parking el coche se aparca en una plaza distinta

					if (plaza1.estado == 1 && plaza2.estado == 0) {
						scanf_s("%s", plaza2.matricula, 8);
						getchar();
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(plaza1.matricula, plaza2.matricula);
						comp4 = strcmp(plaza3.matricula, plaza2.matricula);
						comp5 = strcmp(plaza4.matricula, plaza2.matricula);

						if (comp3 == 0 || comp3 == 0 || comp4 == 0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", plaza2.matricula);
						}
						else {
							printf("Ahora la plaza 2 de coche esta ocupada por el coche de matricula:%s\n\n", plaza2.matricula);

							plaza2.estado = plaza2.estado++;
						}

					}
					else if (plaza1.estado == 0 && plaza2.estado == 1) {
						scanf_s("%s", plaza1.matricula, 8);
						getchar();
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(plaza2.matricula, plaza1.matricula);
						comp4 = strcmp(plaza3.matricula, plaza1.matricula);
						comp5 = strcmp(plaza4.matricula, plaza1.matricula);


						if (comp3 == 0 || comp4 == 0 || comp5 == 0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", plaza1.matricula);
						}
						else {

							printf("Ahora la plaza 1 de coche esta ocupada por el coche de matricula:%s\n\n", plaza1.matricula);
							plaza1.estado = plaza1.estado++;
						}
					}
					else {
						scanf_s("%s", plaza1.matricula, 8);
						comp4 = strcmp(plaza1.matricula, plaza3.matricula);
						comp5 = strcmp(plaza1.matricula, plaza4.matricula);
						if (comp4 == 0 || comp5 == 0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", plaza1.matricula);
						}
						else {

							printf("Ahora la plaza 1 de coche esta ocupada por el coche de matricula:%s\n\n", plaza1.matricula);
							plaza1.estado = plaza1.estado++;
						}
					}

					break;

				}
			case 'm':
			case 'M':
				if (plaza3.estado == 1 && plaza4.estado == 1) { //Si ambas plazas de moto estan llenas

					printf("No quedan plazas para motos en estos momentos.\n\n");


				}
				else {//Si no, pide la matricula
					printf("\tIntroduzca  la matricula de su moto\n\n");

					//Dependiendo del estado del parking la moto se aparca en una plaza distinta

					if (plaza3.estado == 1 && plaza4.estado == 0) {
						scanf_s("%s", plaza4.matricula, 8);
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(plaza3.matricula, plaza4.matricula);
						comp4 = strcmp(plaza1.matricula, plaza4.matricula);
						comp5 = strcmp(plaza2.matricula, plaza4.matricula);
						if (comp3 == 0 || comp4 == 0 || comp5 == 0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", plaza4.matricula);
						}
						else {
							printf("Ahora la plaza 4 de moto esta ocupada por la moto de matricula:%s\n\n", plaza4.matricula);

							plaza3.estado = plaza3.estado++;
						}

					}
					else if (plaza3.estado == 0 && plaza4.estado == 1) {
						scanf_s("%s", plaza3.matricula, 8);						
						//Para que no se introduzcan vehiculos con igual matricula
						comp3 = strcmp(plaza3.matricula, plaza1.matricula);
						comp4 = strcmp(plaza3.matricula, plaza2.matricula);
						comp5 = strcmp(plaza3.matricula, plaza4.matricula);

						if (comp3 == 0 || comp4 == 0 || comp5 == 0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", plaza3.matricula);
						}
						else {

							printf("Ahora la plaza 3 de moto esta ocupada por la moto de matricula:%s\n\n", plaza3.matricula);
							plaza3.estado = plaza3.estado++;
						}
					}
					else {
						scanf_s("%s", plaza3.matricula, 8);
						comp3 = strcmp(plaza3.matricula, plaza1.matricula);
						comp4 = strcmp(plaza3.matricula, plaza2.matricula);
						if (comp3 == 0 || comp4 == 0) {
							printf("El vehiculo con matricula %s ya esta en el aparcamiento, lo sentimos\n\n", plaza3.matricula);
						}
						else {

							printf("Ahora la plaza 3 de moto esta ocupada por la moto de matricula:%s\n\n", plaza3.matricula);
							plaza3.estado = plaza3.estado++;
						}



					}
				}
				break;

			default:  printf("Por ahora solo se puede elegir entre plazas de motos y de coches\n Lo sentimos.\n");

			}
			break;
		case 'A':
		case 'a':
			printf("Ha escogido abandonar el aparcamiento.\n\n");
			if (plaza1.estado == 0 && plaza2.estado == 0 && plaza3.estado == 0 && plaza4.estado == 0) {
				printf("Lo sentimos no hay vehiculos en estos momentos dentro del aparcamiento.\n");
			}
			else {
				printf("Elija si quiere sacar una moto o un coche.\n Para sacar una moto introduzca M\n Para sacar un coche introduzca C\n");
				scanf_s("%c", &opcion2);
				
				switch (opcion2) {
				case 'C':
				case 'c':
					printf("Ha escogido sacar un coche\n");
					if (plaza1.estado == 1 && plaza2.estado == 0) { //Si solo hay un coche 
						printf("Solo hay un coche en el parking\n\n");
						printf("El coche de la plaza 1 ha salido\n\n");
						plaza1.estado = plaza1.estado--;

					}
					else if (plaza1.estado == 0 && plaza2.estado == 1) { //Si solo hay un coche
						printf("Solo hay un coche en el parking\n\n");
						printf("El coche de la plaza 2 ha salido\n\n");
						plaza2.estado = plaza2.estado--;

					}
					else if (plaza1.estado == 1 && plaza2.estado == 1) { //Si hay mas, bucle para elegir de que plaza sacarlo
						printf("Escoja que coche quiere sacar, el de la plaza 1 o 2\n introduzca 1 o 2\n\n");
						printf("Plaza 1: %s\n", plaza1.matricula);
						printf("Plaza 2:%s\n", plaza2.matricula);
						scanf_s("%d", &plaza);						
						switch (plaza)
						{
						case 1:
							printf("El coche de la plaza1 ha salido\n\n");
							plaza1.estado = plaza1.estado--;

							break;
						case 2:
							printf("El coche de la plaza2 ha salido\n\n");
							plaza2.estado = plaza2.estado--;


							break;
						default:
							//Si elige un numero de plaza inexistente
							printf("No hay tantas plazas de moto en el aparcamiento\n\n");
						}
					}
					else {
						//Si se elige aparcar y no hay coches
						printf("No hay coches en el aparcamiento en estos momentos\n\n");

					}

					break;
				case 'M':
				case 'm':
					printf("Ha escogido sacar una moto\n");
					if (plaza3.estado == 1 && plaza4.estado == 0) { //Si solo hay un coche 
						printf("Solo hay una moto en el parking\n\n");
						printf("La moto de la plaza 3 ha salido\n\n");
						plaza3.estado = plaza3.estado--;

					}
					else if (plaza3.estado == 0 && plaza4.estado == 1) { //Si solo hay un coche
						printf("Solo hay una moto en el parking\n\n");
						printf("La moto de la plaza 4 ha salido\n\n");
						plaza4.estado = plaza4.estado--;

					}
					else if (plaza3.estado == 1 && plaza4.estado == 1) { //Si hay mas, bucle para elegir de que plaza sacarlo
						printf("Escoja que coche quiere sacar, el de la plaza 1 o 2\n introduzca 1 o 2\n\n");
						printf("Plaza 3: %s\n", plaza3.matricula);
						printf("Plaza 4:%s\n", plaza4.matricula);
						scanf_s("%d", &plaza);						
						switch (plaza)
						{
						case 3:
							printf("El coche de la plaza3 ha salido\n\n");
							plaza3.estado = plaza3.estado--;

							break;
						case 4:
							printf("El coche de la plaza4 ha salido\n\n");
							plaza4.estado = plaza4.estado--;


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
				default: printf("Por ahora solo se puede elegir entre plazas de motos y de coches\n Lo sentimos.\n");

				}

				break;
		case 'E':
		case 'e':
			printf("Ha escogido ver el estado del aparcamiento.\n\n");
			printf("En estos momentos el aparcamiento se encuentra asi:\n\n");
			if (plaza1.estado == 0)
				printf("Plaza 1 de %s-Libre\n");
			else
				printf("Plaza 1 de %s-Ocupada por el vehiculo de matricula:%s\n", plaza1.tipo, plaza1.matricula);
			if (plaza2.estado == 0)
				printf("Plaza 2 de %s-Libre\n");
			else
				printf("Plaza 2 de %s-Ocupada por el vehiculo de matricula:%s\n", plaza2.tipo, plaza2.matricula);
			if (plaza3.estado == 0)
				printf("Plaza 3 de %s-Libre\n");
			else
				printf("Plaza 3 de %s-Ocupada por el vehiculo de matricula:%s\n", plaza3.tipo, plaza3.matricula);
			if (plaza4.estado == 0)
				printf("Plaza 4 de %s-Libre\n");
			else
				printf("Plaza 4 de %S-Ocupada por el vehiculo de matricula:%s\n", plaza4.tipo, plaza4.matricula);



			break;
		case 'S':
		case 's':
			printf("Ha decidido salir del programa.\n\t ¡Hasta la proxima!\n\n");

			break;
		case 'B':
		case 'b':
			printf("Ha escogido buscar un vehiculo por matricula\n\n ");
			printf("Introduzca la matricula del coche que quiere buscar:\n");
			scanf_s("%s", comp.matricula, 8);
			comp1 = strcmp(comp.matricula, plaza1.matricula);
			comp2 = strcmp(comp.matricula, plaza2.matricula);
			comp3 = strcmp(comp.matricula, plaza3.matricula);
			comp4 = strcmp(comp.matricula, plaza4.matricula);

			if (comp1 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 1 de %s\n\n", plaza1.matricula, plaza1.tipo);
			}
			else if (comp2 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 2 de coche\n\n", plaza2.matricula, plaza1.tipo);
			}
			else if (comp3 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 3 de moto\n\n", plaza3.matricula, plaza1.tipo);
			}
			else if (comp4 == 0) {
				printf("El vehiculo de matricula %s se encuentra en la plaza 4 de moto\n\n", plaza4.matricula, plaza1.tipo);
			}
			else {
				printf("El vehiculo con matricula %s no se encuentra en el establecimiento\n\n", comp.matricula, plaza1.tipo);
			}

			break;
		default:

			printf("El programa aun no tiene mas opciones, elija entre las que muestra el menu\n\n");

			break;


			}
		}
	}while (opcion != 'S'&& opcion != 's');
	system("pause"); //Parar
}

