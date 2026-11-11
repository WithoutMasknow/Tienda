#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definimos
#define MAX_PRODUCTOS 5
#define MAX_RECURSOS 3

// Variables Globales--------------------------------------

// Principales
char Nombre_P[MAX_PRODUCTOS][50];
float Tiempo_P[MAX_PRODUCTOS];
char Nombre_R[MAX_PRODUCTOS][MAX_RECURSOS][50];
float Recursos_Kg[MAX_PRODUCTOS][MAX_RECURSOS];
int Cantidad_P = 0;
char Yes_No[50];

// Variables Globales--------------------------------------

// Funciones-----------------------------------------------
void Limpieza();

void Authentificador();

int Menu();

void Registrar_Producto();
void Edita_Producto();
void Buscar_Producto();
void Ordenar_y_Mostrar();
void Calcular_T_R();

void Seguir();
// Funciones-----------------------------------------------

int main()
{
	int Op;
	system("cls");
	Authentificador();

	do {
		int Menu();
		Op = Menu();

		switch(Op) {
		case 1:
			Registrar_Producto();
			break;
		case 2:
			Edita_Producto();
			break;
		case 3:
			Buscar_Producto();
			break;
		case 4:
			Ordenar_y_Mostrar();
			break;
		case 5:
			Calcular_T_R();
			break;
		case 6:
			break;
			printf("Muchas Gracias por usar el Sistema");
			printf("Saliendo");
		}
	} while(Op != 6);

	Limpieza();
}
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
	char Usuario[20] = "1";
	char V_Identidad[20];
	int Contrasena = 1;
	int V_Contrasena;

	do
	{
		printf("Ingrese su Usuario:\n");
		printf("Profe el usuario es: Marlon y David\n");
		fgets(V_Identidad, sizeof(V_Identidad), stdin);
		V_Identidad[strcspn(V_Identidad, "\n")] = 0;
		printf("\n");
        // while (getchar()= \n)
        // {
        //     /* code */
        // }
        

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
int Menu() {
	int Op;
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
	} while(Op>6 || Op<1);
	return Op;
	Limpieza();
}

//Registrar Producto-------------------------------------
void Registrar_Producto() {
	int i;
	i = Cantidad_P;
	int C3;


	do {

		printf("Escriba el nombre del Producto a Registrar: ");
		fgets(Nombre_P[i], sizeof(Nombre_P[i]), stdin);
		Nombre_P[i][strcspn(Nombre_P[i], "\n")] = 0;
		printf("\n");
		printf("Escriba el tiempo necesario en MINUTOS para fabricar una Unidad o Caja (Use el punto no la coma): ");
		scanf("%f", &Tiempo_P[i]);
		getchar();
		printf(" minutos\n");

		C3 = 0;

		do {
			if(C3 == 3) {
				printf("SOLO PUEDES INGRESAR 3 RECURSO POR PRODUCTO\n");
				       Limpieza();
				       break;
			}
			printf("Escriba el nombre del recurso necesario para fabricar %s: ", Nombre_P[i]);
			fgets(Nombre_R[i][C3], sizeof(Nombre_R[i][C3]), stdin);
			Nombre_R[i][C3][strcspn(Nombre_R[i][C3], "\n")] = 0;

			printf("Escriba el PESO en KG para fabricar una Unidad o Caja (Use el punto no la coma): ");
			scanf("%f", &Recursos_Kg[i][C3]);
			getchar();
			printf("kg\n");

			C3++;

			Limpieza();
			printf("Desea seguir registrando recursos para %s (yes / no): ",Nombre_P[i]);
			void Seguir();

		} while(strcmp(Yes_No, "no") != 0 && strcmp(Yes_No, "NO") != 0 &&
            strcmp(Yes_No, "No") != 0);

		Cantidad_P++;
		printf("Desea registrar otro producto (yes / no): ");
		void Seguir();

	} while(strcmp(Yes_No, "no") != 0 && strcmp(Yes_No, "NO") != 0 &&
            strcmp(Yes_No, "No") != 0);

}
// Yes o No------------------------------------------------
void Seguir() {
	do {
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
}
void Edita_Producto(){
			printf("En proseso");
		}
void Buscar_Producto(){
			printf("En proseso");
		}
void Ordenar_y_Mostrar(){
			printf("En proseso");
		}
void Calcular_T_R(){
			printf("En proseso");
		}
// Funciones-----------------------------------------------
