#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definimos
#define MAX_PRODUCTOS 10
#define MAX_RECURSOS 3

// Variables Globales--------------------------------------

// Principales
char Nombre_P[MAX_PRODUCTOS][50];
float Tiempo_P[MAX_PRODUCTOS];
char Nombre_R[MAX_PRODUCTOS * 3][50];
float Recurso_Kg[MAX_PRODUCTOS][MAX_RECUROS];
int Cantidad_P = 0;
char Yes_No;

// Variables Globales--------------------------------------

// Funciones-----------------------------------------------
void Limpieza();

void Authentificador();

void Menu();

void Registrar_Producto();
void Edita_Producto();
void Buscar_Producto();
void Ordenar_y_Mostrar();
void Calcular_T_R();
// Funciones-----------------------------------------------

int main()
{
	system("cls");
	void Authentificador();

	do {
		int Menu();
		int Op = Menu;

		switch(Op) {
		case 1:
			void Registrar_Producto();
			break;
		case 2:
			void Edita_Producto();
			break;
		case 3:
			void Buscar_Producto();
			break;
		case 4:
			void Ordenar_y_Mostrar();
			break;
		case 5:
      void Calcular_T_R();
			break;
    case 6:
      break;
		}
	} while(Op != 6);

}
system("cls");
// Funciones-----------------------------------------------

// Limpieza------------------------------------------------
void Limpieza()
{
	printf("\n");
	system("pause");
	system("cls");
}

// Authentificación-----------------------------------------
void Authentificador() {
	char Usuario[20] = "Marlon y David";
	char V_Identidad[20];
	int Contrasena = 123456;
	int V_Contrasena;

	do
	{
		printf("Ingrese su Usuario:\n");
		printf("Profe el usuario es: Marlon y David\n");
		fgets(V_Identidad, sizeof(V_Identidad), stdin);
		V_Identidad[strcspn(V_Identidad, "\n")] = 0;
		printf("\n");

		printf("Ingrese la contrasena:\n");
		printf("Profe la contrasena es: 123456\n");
		scanf("%d", &V_Contrasena);
		getchar();

		if (strcmp(Usuario, V_Identidad) != 0 || Contrasena != V_Contrasena)
		{
			printf("Usuario o contrasena incorrectos. Intente de nuevo.\n");
		}

		Limpieza();

	} while (strcmp(Usuario, V_Identidad) != 0 || Contrasena != V_Contrasena);

	printf("\n¡Acceso concedido! Bienvenido al sistema.\n");

	Limpieza();
}

// Menu----------------------------------------------------
int menu() {
	int Op
	do {
		printf("--------Menu de opciones:--------\n");
		printf("1. Registrar Producto.\n");
		printf("2. Editar Productos.\n");
		printf("3. Buscar Producto.\n");
		printf("4. Ordenar y ver.\n");
		printf("5. Calcular Tiempo Total de Fabricacion; Cantidad de Recurso Necesarios.\n");
		printf("6.-Salir:\n");
		scanf("%d", &Op);
		getchar();

		if(Op>6 || Op<1) {
			printf("PORFAVOR ESCRIBA UN VALOR DEL 1 AL 6\n");
			printf("Vuelva a intentarlo\n");
			Limpieza();
		}
	} while(Op>=1 && Op<=6);
	return Op;
}

//Registrar Producto-------------------------------------
void Registrar_Producto() {
	int i;
	i = Cantidad_P;
	int j;

	do {

		printf("Escriba el nombre del Producto a Registrar: ");
		fgets(Nombre_P[i], sizeof(Nombre_P[i]), stdin);
		Nombre_P[strcspn(Nombre_P), "\n")] = 0;
		printf("\n");
		printf("Escriba el tiempo necesario en MINUTOS para fabricar una Unidad o Caja (Use el punto no la coma): ");
		scanf("%f", &Tiempo_P[i]);
		getchar();
		printf(" minutos\n");

		j = 0;
		j = i + j;
		do {
			if(j > i + 3) {
				printf("SOLO PUEDES INGRESAR 3 RECURSO POR PRODUCTO\n);
				       Limpieza();
				       break;
			}
			printf("Escriba el nombre del recurso necesario para fabricar %s: ", Nombre_P[i]);
			fgets(Nombre_R[j], sizeof(Nombre_R[j]), stdin);
			Nombre_R[strcspn(Nombre_R), "\n")] = 0;

			printf("Escriba el PESO en KG para fabricar una Unidad o Caja (Use el punto no la coma): ");
			scanf("%f", &Recursos_kg[i][j-i]);
			getchar();
			printf("kg\n");
			j++;
			Limpieza();
			do {
				printf("Desea registrar otro recurso (yes / no): ");
				fgets(Yes_No, sizeof(Yes_No), stdin);
				Yes_No[strcspn(Yes_No, "\n")] = 0;

				if (strcmp(Yes_No, "yes") != 0 && strcmp(Yes_No, "no") != 0 &&
				        strcmp(Yes_No, "YES") != 0 && strcmp(Yes_No, "NO") != 0 &&
				        strcmp(Yes_No, "Yes") != 0 && strcmp(Yes_No, "No") != 0) {
					printf("\nOpcion invalida. Por favor escriba 'yes' o 'no'.\n");
					Limpieza();
				} else {
					break;
				}
			} while(1);
		} while(Yes_No !=no ||Yes_No !=NO || Yes_No != No);

		Cantidad_P++;

		do {
			printf("Desea seguir registrando productos (yes / no): ");
				fgets(Yes_No, sizeof(Yes_No), stdin);
				Yes_No[strcspn(Yes_No, "\n")] = 0;

				if (strcmp(Yes_No, "yes") != 0 && strcmp(Yes_No, "no") != 0 &&
				        strcmp(Yes_No, "YES") != 0 && strcmp(Yes_No, "NO") != 0 &&
				        strcmp(Yes_No, "Yes") != 0 && strcmp(Yes_No, "No") != 0) {
					printf("\nOpcion invalida. Por favor escriba 'yes' o 'no'.\n");
					Limpieza();
				} else {
					break;
				}
			} while(1);

		} while(Yes_No !=no ||Yes_No !=NO || Yes_No != No);

}

// Funciones-----------------------------------------------
