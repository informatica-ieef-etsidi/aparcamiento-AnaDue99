//Desarrollador: Ana Dueñas
#include <stdio.h>
#include <windows.h>

void main() {
	int plaza, i = 0, j = 0;
	char opcion, matricula[8], matricula1[8], matricula2[8];
	while (1) {  
		printf("Seleccione una de estas opciones :\n	R - Reservar plaza\n	A - Abandonar plaza\n	E - Estado del aparcamiento\n");

		scanf_s("%c", &opcion);
		
		Sleep(500);
		system("cls");
		switch (opcion) {

		case 'R':
		case'r':
			printf("Ha escogido la opcion de reservar plaza\n");
			if (i == 1 && j == 1) {
				printf("El parking esta lleno\n");
			

			}
			else {
				printf("\tIntroduzca los cuatro numeros de la matricula del coche\n");
				
				

				if (i == 1 && j == 0) {
					scanf_s("%s", matricula2, 8);
					getchar();
					
					
					printf("Ahora la plaza 2 esta ocupada por el coche de matricula:%s\n", matricula2);

					j = j++;
				
				}
				else if (i == 0 && j == 1) {
					scanf_s("%s", matricula1, 8);
					getchar();
					
					printf("Ahora la plaza 1 esta ocupada por el coche de matricula:%s\n", matricula1);
					i = i++;
					
				}
				else {
					scanf_s("%s", matricula1, 8);
					getchar();
					i = i++;
					matricula[8] = matricula1[8];
					
					printf("Ahora la plaza 1 esta ocupada por el coche de matricula:%s\n", matricula1);
					;
				}
			}

			break;
		case 'A':
		case 'a':
			printf("Ha escogido abandonar el aparcamiento.\n");
			if (i == 1 && j == 0) {
				printf("Solo hay un coche en el parking\n");
				printf("El coche de la plaza 1 ha salido\n");
				i = i--;
				
			}
			else if (i == 0 && j == 1) {
				printf("Solo hay un coche en el parking\n");
				printf("El coche de la plaza 2 ha salido\n");
				j = j--;
				
			}
			else if (i == 1 && j == 1) {
				printf("Escoja que coche quiere sacar, el de la plaza 1 o 2\n introduzca 1 o 2\n");
				printf("Plaza 1: %s\n", matricula1);
				printf("Plaza 2:%s\n", matricula2);
				scanf_s("%d", &plaza);
				switch (plaza)
				{
				case 1:
					printf("El coche de la plaza1 ha salido\n");
					i = i--;
					
					break;
				case 2:
					printf("El coche de la plaza2 ha salido\n");
					j = j--;
					
					
					break;
				default:
					printf("No hay tantas plazas en el aparcamiento\n");
					
					break;
				}
			}
			else {
				printf("No hay coches en el aparcamiento en estos momentos\n");
				
			}

			break;
		case 'E':
		case 'e':
			printf("Ha escogido ver el estado del aparcamiento.\n");
			printf("En estos momentos el aparcamiento se encuentra asi:\n");
			if (i == 0 && j == 0) {
				printf("Plaza 1-Libre\n");
				printf("Plaza 2-Libre\n");
			
			}
			else if (i == 0 && j == 1) {
				
				printf("Plaza1-Libre\n");
				printf("Plaza2-Ocupada por el coche de matricula:%s\n", matricula2);
				

			}
			else if (i == 1 && j == 0) {
				
				printf("Plaza1-Ocupada por el coche de matricula:%s\n", matricula1);
				printf("Plaza2-Libre\n");
				
			}
			else {
				
				printf("Plaza 1-Ocupada por el coche de matricula:%s\n", matricula2);
				printf("Plaza 2-Ocupada por el coche de matricula:%s\n", matricula1);
				
			}

			break;
		default: 
			printf("El programa aun no tiene mas opciones, elija entre las que muestra el menu\n");
		}
		printf("\ncargando...\n");
		system("pause");
		system("cls");

	}
}

