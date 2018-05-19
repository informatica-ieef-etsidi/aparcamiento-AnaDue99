//Desarrollador: Ana Dueñas
//Comentario: Al imprimir utilizo un +1 para que las plazas vayan de 1 al numero deseado, y no de 0 a uno menos7
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define NUMPLAZAS 8
char menu();
void leerFichero(char nombreFichero[], struct plaza aparcamiento[], int * dim);
void salvarFichero(char nombreFichero[], struct plaza aparcamiento[], int dim);
void recuento(struct Tplaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos);
void inicializar(struct Tplaza aparcamiento[], int dim);
int buscarPlazaLibre(struct Tplaza aparcamiento[], int dim, char tipo);
int buscarVehiculo(struct Tplaza aparcamiento[], int dim, char matricula[]);
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[8]);
int existeUsuario(struct usuario usuarioValido, char usuario[], char password[]);
struct Tplaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipo; // M - Moto / C - Coche
	char matricula[8];
};
struct TAux {
	char tipo;
	char matricula[8];

};
struct usuario {
	char usuario[50];
	char password[50];
};


void main() {

	struct Tplaza general[NUMPLAZAS];
	struct TAux aux;
	struct usuario MiUsuario = { "admin","1234" };
	char usuario[50];
	char password[50];
	int plazas=0, plazascoche=0, plazasmoto=0;
	int  nusuarios = 0, j = 0, k = 0, h = 0, auxx = 0, comp1 = 1;
	char opcion;
	printf("Para acceder al programa debe de ser un usuario registrado\n");

	do {
		printf("Introduzca su nombre de usuario\n");
		scanf_s("%s", &usuario, 50);
		getchar();
		printf("Introduzca su contraseña\n");
		scanf_s("%s", &password, 50);
		getchar();

		if (existeUsuario(MiUsuario, usuario, password) == 0) {
			printf("Usuario o contraseña erroneos\n");
			h = h++;
		}

	} while (existeUsuario(MiUsuario, usuario, password) == 0 && h != 3);//Tiene 3 intentos y se repite mientras los tenga o lo haga bien
	if (h == 3) {
		printf("Lo sentimos, ha agotado todos los intentos no puede acceder al programa\n");
		system("pause");
	}
	else {	
		
		leerFichero("aparcamiento.txt", general, &plazas);//HAY QUE PONER EL NUMERO DE PLAZAS QUE QUEREMOS AL PRINCIPIO DEL FICHERO
		if (plazas == 0) {
			inicializar(general, NUMPLAZAS);
			 plazas= NUMPLAZAS;
		}
		
		
		Sleep(500);
		system("cls");
		
		do {

			menu();

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
				do {
					if (aux.tipo == 'C' || aux.tipo == 'c' || aux.tipo == 'M' || aux.tipo == 'm') {
						printf("\tIntroduzca  la matricula de su vehiculo\n\n");
						do {
							scanf_s("%s", &aux.matricula, 8);
							getchar();

							for (j = 0; j < plazas; j++) {
								comp1 = strcmp(general[j].matricula, aux.matricula);
								if (comp1 == 0) {
									printf("El vehiculo con esa matricula ya esta en el aparcamiento,introduzca de nuevo una matricula\n");
									break;
								}
							}//Compara la matricula del coche con las que ya hay en el aparcamiento
							if (esMatriculaValida(aux.matricula) == 0) {
								printf("No es una matricula valida, tiene que ser de formato DDDDLLL,introduzca de nuevo matricula\n");
							}
						} while (esMatriculaValida(aux.matricula) == 0 || comp1 == 0);
						// Compara la matricula dada con las que ya hay en el aparcamiento


						if (buscarPlazaLibre(general, plazas, aux.tipo) == -1) {
							printf("No quedan plazas libres de %c\n", aux.tipo);
						}
						else {
							auxx = (buscarPlazaLibre(general, plazas, aux.tipo));//Se guarda en el auxx el nmero de plaza

							nusuarios = nusuarios++;
							strcpy_s(general[auxx].matricula, 8, aux.matricula);//Copia la matricula introducida en su memoria como matricula registrada

							general[auxx].estado = 1; //El estado de esta plaza ahora es lleno					
							printf("Ahora el vehiculo con matricula %s se encuentra en la plaza %d de %c\n", general[auxx].matricula, auxx + 1, general[auxx].tipo);
						}
					}

				} while (comp1 == 0);

				break;

			case 'A':
			case 'a':
				printf("Ha escogido abandonar el aparcamiento.\n\n");
				if (nusuarios == 0) { //Si aun no hay vehiculos 
					printf("No hay en estos momentos vehiculos en el aparcamiento\n");
				}
				else {
					printf("Introduzca su matricula.\n");
					scanf_s("%s", aux.matricula, 8);
					getchar();

					for (j = 0; j < plazas; j++) { //Compara la matricula con todas
						comp1 = strcmp(aux.matricula, general[j].matricula);
						if (comp1 == 0) {
							auxx = j;//guarda el j con el que coincide
							break;
						}
					}

					if (comp1 == 0) { //Si coincide con alguna 					
						
						printf("El coche de matricula %s ha abandonado la plaza de  numero %d", general[auxx].matricula, auxx + 1);
						general[auxx].estado = 0;
						strcpy_s(general[auxx].matricula,8,"-------");
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


				for (j = 0; j < plazas; j++) {//Recorre todas las plazas
					if (general[j].estado == 1) {
						printf("PLAZA de %c %2.d: matricula %s\n", general[j].tipo, j + 1, general[j].matricula);
					}
					else
						printf("PLAZA de %c %2.d: LIBRE\n", general[j].tipo, j + 1);
				}
				recuento(general, plazas, &plazascoche, &plazasmoto);
				printf("Numero  de plazas coches libres: %d\n", plazascoche);
				printf("Numero  de plazas motos libres: %d\n", plazasmoto);
				break;
			case 'S':
			case 's':
				printf("Ha decidido salir del programa.\n\t ¡Hasta la proxima!\n\n");
				salvarFichero("aparcamiento.txt", general, plazas);

				break;
			case 'B':
			case 'b':
				printf("Ha escogido buscar un vehiculo por matricula\n\n ");
				printf("Introduzca la matricula del vechiulo que quiere buscar:\n");
				scanf_s("%s", aux.matricula, 8);
				getchar();
				auxx = buscarVehiculo(general, plazas, aux.matricula);
				if (auxx != -1) { //Si coincide con una de coche
					printf("El coche de matricula %s se encuentra en la plaza %d\n", general[auxx].matricula, auxx + 1);
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
char menu() {
	printf("Seleccione una de estas opciones :\n	R - Reservar plaza\n	A - Abandonar plaza\n	E - Estado del aparcamiento\n	B - Buscar vehiculo por matricula\n	S - Salir del programa\n");
	return;
}
int esDigitoValido(char caracter) {
	int i, resultado;
	if (caracter >= 48 && caracter <= 57) {
		resultado = 1;//Es digito
	}
	else {
		resultado = 0;
	}
	return resultado;
}
int esLetraValida(char caracter) {
	int  resultado;
	if (caracter >= 97 && caracter <= 122) {
		caracter = caracter - 32;//Pasa a mayusculas
	}
	if (caracter > 65 && caracter <= 90 && caracter != 69 && caracter != 73 && caracter != 79 && caracter != 85) {
		resultado = 1;
	}
	else {
		resultado = 0;
	}
	return resultado;
}
int esMatriculaValida(char matricula[8]) {//DDDDLLL
	int resultado;
	if (esDigitoValido(matricula[1]) == 1 && esDigitoValido(matricula[2]) == 1 && esDigitoValido(matricula[3]) == 1 && esDigitoValido(matricula[0]) == 1 && esLetraValida(matricula[4]) && esLetraValida(matricula[5]) && esLetraValida(matricula[6])) {
		resultado = 1;
	}
	else {
		resultado = 0;
	}
	return resultado;
}
int existeUsuario(struct usuario usuarioValido, char usuario[], char password[]) {
	int resultado, comp, comp2;
	if (strlen(usuario) != 5) { //Si el usuario no mide 5
		resultado = 0;// No valido
	}
	else if (strlen(password) != 4) { //Si la contraseña no mide 4
		resultado = 0; //No valido
	}
	else {
		comp = strcmp(usuarioValido.usuario, usuario); //Comparamos
		if (comp == 0) {//Si coincide
			comp2 = strcmp(usuarioValido.password, password);//Comparamos
			if (comp2 == 0) {//Si coincide
				resultado = 1;
			}
		}
		else {
			resultado = 0;
		}
	}


	return resultado;
}
void recuento(struct Tplaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos) {
	int i;
	*nLibresCoches = 0;
	*nLibresMotos = 0;

	for (i = 0; i < dim; i++) {
		if (aparcamiento[i].estado == 0) {
			if (aparcamiento[i].tipo == 'C') {
				*nLibresCoches = *nLibresCoches++;
			}
			else
				*nLibresMotos = *nLibresMotos++;
		}
	}	
	

}
void inicializar(struct Tplaza  aparcamiento[], int dim) {
	int i,j;
	for (i = 0; i < dim; i++) {
		aparcamiento[i].estado = 0;
		for (j = 0; j < 8; j++) {
			aparcamiento[i].matricula[j] = '-';
		}
		aparcamiento[i].matricula[8] = '\0';
	}

	for (i = 0; i < dim / 3; i++) {
		aparcamiento[i].tipo = 'M';
	}
	for (i = dim / 3; i < dim; i++) {
		aparcamiento[i].tipo = 'C';
	}

}
int buscarPlazaLibre(struct Tplaza aparcamiento[], int dim, char tipo) {
	int i, plazalibre=0;
	for (i = 0; i < dim; i++) {
		if ((aparcamiento[i].tipo == tipo || aparcamiento[i].tipo == tipo - 32) && aparcamiento[i].estado == 0) {
			plazalibre = i;
			break;
		}
		else {
			plazalibre = -1;
		}
	}
	return plazalibre;
}
int buscarVehiculo(struct Tplaza aparcamiento[], int dim, char matricula[]) {
	int j, comp1, resultado;
	for (j = 0; j < dim; j++) {
		comp1 = strcmp(matricula, aparcamiento[j].matricula);//Compara  con las de coche que ya hay en el aparcamiento
		if (comp1 == 0) {
			resultado = j;
			break;
		}
		else {
			resultado = -1;
		}

	}
	return resultado;

}
void leerFichero(char nombreFichero[], struct Tplaza aparcamiento[], int * dim) {
	int i,numeroplazas=0;
	*dim = 0;
	FILE*fichero;
	errno_t error;
	error = fopen_s(&fichero,nombreFichero, "r");//Error al abrir el fichero?
	
	if (error == 0) {
		printf("¡Datos cargados!\n");
		Sleep(1500);
	}
	else {
		printf("Ha habido un error %d al cargar los datos\n", error);
		return; // return sale del programa
	}
	fscanf_s(fichero, "%d",dim);
	numeroplazas = *dim;
	if (numeroplazas != 0 ) {
		for (i = 0; i < numeroplazas; i++) {
			fscanf_s(fichero, "%d\t", &aparcamiento[i].estado);
			fscanf_s(fichero, "%c\t", &aparcamiento[i].tipo);
			fscanf_s(fichero, "%s\n", aparcamiento[i].matricula,8);
		}
	}	
	fclose(fichero);
	dim;
	
}
void salvarFichero(char nombreFichero[], struct Tplaza aparcamiento[], int dim) {
	FILE*fichero;
	errno_t error;
	int i;

	error = fopen_s(&fichero, nombreFichero, "w");//Error al abrir el fichero?
	Sleep(2000);
	if (error == 0) {
		printf("¡Datos cargados!\n");
		Sleep(1500);
	}
	else {
		printf("Ha habido un error %d al cargar los datos\n", error);
		return; // return sale del programa
	}

	fprintf(fichero, "%d\n", dim);
		for (i = 0; i < dim; i++) {
			fprintf(fichero, "%d\t", aparcamiento[i].estado);
			fprintf(fichero, "%c\t", aparcamiento[i].tipo);
			
			fprintf(fichero, "%s\n", aparcamiento[i].matricula);
		}
		
	
	fclose(fichero);
}
