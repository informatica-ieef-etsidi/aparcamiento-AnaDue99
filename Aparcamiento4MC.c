//Desarrollador: Ana Dueñas
//Comentario: Al imprimir utilizo un +1 para que las plazas vayan de 1 al numero deseado, y no de 0 a uno menos
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define NUMPLAZASC 10
#define NUMPLAZASM 10

struct Tplaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipo; // M - Moto / C - Coche
	char matricula[8];
};
struct TAux {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipo; // M - Moto / C - Coche
	char matricula[8];
	char usuario[50];
	char password[50];
};
struct usuario {
	char usuario[50];
	char password[50];
};


void main() {

	struct Tplaza coche[NUMPLAZASC], moto[NUMPLAZASM];
	struct TAux aux;
	struct usuario usuario1 = { "admin","1234" };

	int  i = 0, j = 0, k = 0, h = 0, auxx = 0, comp1, comp2,comp3,comp4;
	char opcion;
	printf("Para acceder al programa debe de ser un usuario registrado\n");

	do {
		printf("Introduzca su nombre de usuario\n");
	scanf_s("%s", &aux.usuario, 50);
		getchar();
		comp4 = strcmp(aux.usuario, usuario1.usuario); //Compara entre todos los usuarios
		if (comp4 == 0) {
			printf("Bienvenido %s\n", usuario1.usuario);
			do {
				printf("Introduzca su contrasena para entrar\n");
				scanf_s("%s", &aux.password, 50);
				getchar();
				comp3 = strcmp(aux.password, usuario1.password); //Compara  si es la contraseña

				if (comp3 == 0) {
					printf("Contrasena correcta\n");
					Sleep(200);
				}
				else {
					printf("Contrasena incorrecta\n");
					h = h++;

				}
			} while (comp3 != 0&&h!=3); //Hasta que la contraseña sea correcta se repite
		}
		else {
			printf("Lo sentimos, no se encuentra entre nuestros usuarios, intentelo de nuevo.\n");
			Sleep(2000);
			h = h++;
		}

	} while (comp4 != 0 && h != 3);//Tiene 3 intentos y se repite mientras los tenga o lo haga bien
	if (h == 3) {
		printf("Lo sentimos, ha agotado todos los intentos no puede acceder al programa\n");
		system("pause");
	}
	else {
		
		Sleep(500);
		system("cls");
		do {
			printf("Seleccione una de estas opciones :\n	R - Reservar plaza\n	A - Abandonar plaza\n	E - Estado del aparcamiento\n	B - Buscar vehiculo por matricula\n	S - Salir del programa\n");


			scanf_s("%c", &opcion);
			getchar();
			Sleep(500);
			system("cls");
			switch (opcion) { //Bucle del menu de eleccion

			case 'R':
			case'r':
				printf("Ha escogido la opcion de reservar plaza\n\n");
				printf("Introduzca su tipo de vehiculo:\n");
				printf("M-moto\nC-coche\n");

				scanf_s("%c", &aux.tipo);
				getchar();
				if (aux.tipo == 'C' || aux.tipo == 'c') {//Para coches
					printf("\tIntroduzca  la matricula de su coche\n\n");
					scanf_s("%s", &aux.matricula, 8);
					getchar();
					// Compara la matricula dada con las que ya hay en el aparcamiento
					for (j = 0; j < i; j++) {//Con las de coche

						comp1 = strcmp(aux.matricula, coche[j].matricula);

						if (comp1 == 0) {
							break;
						}
					}
					for (j = 0; j < k; j++) { //Con las de moto
						comp2 = strcmp(aux.matricula, moto[j].matricula);

						if (comp2 == 0) {
							break;
						}
					}//Compara con las motos
					if (comp1 == 0 || comp2 == 0) { //Si ya esta registrada
						printf("Lo sentimos, el vehiculo con esa matricula ya esta en el aparcamiento\n");
					}
					else { //Creamos un auxiliar auxx para determinar si hay plazas vacias en el aparcamiento que previamente hayan sido ocupadas
						   //Es decir: Se ocupan la 1, 2, 3 y se sale de la 1. El codigo sirve para detectar esto ultimo.
						for (j = 0; j < i; j++) {
							if (coche[j].estado == 0) {
								auxx = 0; //Si hay plazas vacias anteriores se guarda
								break;
							}
						}
						if (i == NUMPLAZASC && auxx != 0) { //Si i es el maximo y no hay plazas anteriores vacias
							printf("No quedan mas plazas de coche en el aparcamiento\n");
						}
						else { //Si quedan huecos
							for (j = 0; j < i; j++) { //Comprueba en que plaza exactamente hay hueco y lo guarda en auxx
								if (coche[j].estado == 0) {

									break;
								}
							}
							if (coche[j].estado == 0) {
								auxx = j;
							}
							else { //Si no hay huecos anteriores auxx será el i, es decir el numero en orden de la plaza
								auxx = i;
								i = i++;//Variable para ir aumentando el numero de plazas abarcadas
							}

							strcpy_s(coche[auxx].matricula, 8, aux.matricula);//Copia la matricula introducida en su memoria como matricula registrada
							coche[auxx].tipo = aux.tipo; //Lo mismo con el tipo
							coche[auxx].estado = 1; //El estado de esta plaza ahora es lleno
							printf("Ahora el vehiculo con matricula %s se encuentra en la plaza %d de coche\n", coche[auxx].matricula, auxx + 1);

						}

					}
				}
				else if (aux.tipo == 'M' || aux.tipo == 'm') {//Para motos, idem que con los coches con k en vez de i
					printf("\tIntroduzca  la matricula de su moto\n\n");
					scanf_s("%s", &aux.matricula, 8);
					getchar();
					for (j = 0; j < i; j++) {
						comp1 = strcmp(aux.matricula, coche[j].matricula);

						if (comp1 == 0) {
							break;
						}
					}
					for (j = 0; j < k; j++) {
						comp2 = strcmp(aux.matricula, moto[j].matricula);

						if (comp2 == 0) {
							break;
						}
					}

					if (comp1 == 0 || comp2 == 0) {
						printf("Lo sentimos, el vehiculo con esa matricula ya esta en el aparcamiento\n");
					}
					else {
						for (j = 0; j < k; j++) {
							if (moto[j].estado == 0) {
								auxx = 0;
								break;
							}
						}
						if (k == NUMPLAZASM && auxx != 0) {
							printf("No quedan mas plazas de moto en el aparcamiento\n");
						}
						else {
							for (j = 0; j < k; j++) {
								if (moto[j].estado == 0) {

									break;
								}
							}
							if (moto[j].estado == 0) {
								auxx = j;
							}
							else {
								auxx = k;
								k = k++;
							}

							strcpy_s(moto[auxx].matricula, 8, aux.matricula);
							moto[auxx].tipo = aux.tipo;
							moto[auxx].estado = 1;
							printf("Ahora el vehiculo con matricula %s se encuentra en la plaza %d de moto\n", moto[auxx].matricula, auxx + 1, moto[auxx].tipo);

						}
					}

				}
				else {
					printf("Escoja entre coche o moto\n");
				}
				break;

			case 'A':
			case 'a':
				printf("Ha escogido abandonar el aparcamiento.\n\n");
				if (i == 0 && j == 0) { //Si aun no hay vehiculos 
					printf("No hay en estos momentos vehiculos en el aparcamiento\n");
				}
				else {
					printf("Introduzca su matricula.\n");
					scanf_s("%s", aux.matricula, 8);
					getchar();
					for (j = 0; j < i; j++) { //Compara la matricula con todas las registradas de coches
						comp1 = strcmp(aux.matricula, coche[j].matricula);
						if (comp1 == 0) {
							auxx = j;//guarda el j con el que coincide
							break;
						}
					}
					for (j = 0; j < k; j++) {//Compara la matricula con todas las registradas de motos
						comp2 = strcmp(aux.matricula, moto[j].matricula);
						if (comp2 == 0) {
							auxx = j;//guarda el j con el que coincide
							break;
						}
					}

					if (comp1 == 0) { //Si coincide con alguna de coches
						coche[auxx].estado = 0;
						printf("El coche de matricula %s ha abandonado la plaza de  numero %d", coche[auxx].matricula, auxx + 1);
					}
					else if (comp2 == 0) {//Si coincide con alguna de motos
						moto[auxx].estado = 0;
						printf("La moto de matricula %s ha abandonado la plaza de  numero %d", moto[auxx].matricula, auxx + 1);
					}
					else {
						printf("No hay un vehiculo con matricula %s en el aparcamiento", aux.matricula);
					}
				}
				getchar();
				break;

			case 'E':
			case 'e':
				printf("Ha escogido ver el estado del aparcamiento.\n\n");
				printf("En estos momentos el aparcamiento se encuentra asi:\n\n");
				printf("\tCOCHES:\n");
				for (j = 0; j < NUMPLAZASC; j++) {//Recorre todas las plazas de coche
					if (coche[j].estado == 1) {
						printf("PLAZA %2d\t-\tcoche de matricula %s\n", j + 1, coche[j].matricula);
					}
					else
						printf("PLAZA %2d\t-\tLIBRE\n", j + 1);
				}
				printf("\tMOTOS:\n");
				for (j = 0; j < NUMPLAZASM; j++) {//Recorre todas las plazas de moto
					if (moto[j].estado == 1) {
						printf("PLAZA %2d\t-\tmoto de matricula %s\n", j + 1, moto[j].matricula);
					}
					else
						printf("PLAZA %2d\t-\tLIBRE\n", j + 1);
				}

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
				printf("Introduzca la matricula del vechiulo que quiere buscar:\n");

				scanf_s("%s", aux.matricula, 8);
				getchar();
				for (j = 0; j < i; j++) {
					comp1 = strcmp(aux.matricula, coche[j].matricula);//Compara  con las de coche que ya hay en el aparcamiento
					if (comp1 == 0) {
						j = auxx;//Si coincide lo guarda en auxx
						break;
					}
				}
				for (j = 0; j < k; j++) {
					comp2 = strcmp(aux.matricula, coche[j].matricula);//Compara  con las de moto que ya hay en el aparcamiento
					if (comp2 == 0) {
						j = auxx;//Si coincide lo guarda en auxx
						break;
					}
				}
				if (comp1 == 0) { //Si coincide con una de coche
					printf("El coche de matricula %s se encuentra en la plaza %d\n", coche[auxx].matricula, auxx + 1);
				}
				else if (comp2 == 0) {//Si coincide con una de moto
					printf("La moto de matricula %s se encuentra en la plaza %d\n", coche[auxx].matricula, auxx + 1);
				}
				else {
					printf("El vehiculo con matricula %s no se encuentra en el aparcamiento\n", aux.matricula);
				}




			}
			system("pause");
			system("cls"); //Borrar la consola
		} while (opcion != 'S'&& opcion != 's');
	}

}
