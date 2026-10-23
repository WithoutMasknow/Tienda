#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definimos
#define MAX_PRODUCTOS 10

// Variables Globales--------------------------------------
// Variables Globales--------------------------------------
// Variables Globales--------------------------------------
// Variables Globales--------------------------------------
// Variables Globales--------------------------------------

// Principales
char N_Producto[MAX_PRODUCTOS][50];
float P_Producto[MAX_PRODUCTOS];
int C_Productos = 0;

// Menu
int Op;
int Op2;

// Casos
float S_Inventario = 0;
float M_Caro;
float M_Barato;
float Promedio;

// Extras
int i = 0;
int Num = 0;
int Posicion = 0;
int Encontrado = 0;

// Funciones-----------------------------------------------
// Funciones-----------------------------------------------
// Funciones-----------------------------------------------
// Funciones-----------------------------------------------
// Funciones-----------------------------------------------

void Limpieza()
{
    printf("\n");
    system("pause");
    system("cls");
}

void Menu()
{
    printf("----Menu de opciones:----\n");
    printf("1. Registrar Productos.\n");
    printf("2. Editar Productos.\n");
    printf("3. Precio Total del Inventario.\n");
    printf("4. Producto Más Caro y Más Barato.\n");
    printf("5. Precio Promedio de los Productos.\n");
    printf("6.-Salir:\n");
    scanf("%d", &Op);
    getchar();

    Limpieza();
}

void Registrar_Producto()
{
    i = C_Productos;
    if (C_Productos <= MAX_PRODUCTOS)
    {
        printf("Escriba el nombre del producto a Registrar: ");
        fgets(N_Producto[i], sizeof(N_Producto[i]), stdin);
        N_Producto[i][strcspn(N_Producto[i], "\n")] = 0;
        printf("\n");

        printf("Escriba el precio de %s: ", N_Producto[i]);
        scanf("%f", &P_Producto[i]);
        getchar();
        printf("\n");

        system("cls");

        printf("Se Registro:\n");
        printf("%s vale: %.2f$", N_Producto[i], P_Producto[i]);

        Limpieza();

        C_Productos++;
    }
}

void Listas()
{
    int Listas = 1;
    for (i = 0; i < C_Productos; i++)
    {
        printf("%d.- %s: %.2f$ \n", Listas, N_Producto[i], P_Producto[i]);
        Listas++;
    }
}

void Editar_Productos()
{
    Posicion = 0;
    Encontrado = 0;
    do
    {
        

        if (C_Productos > 0)
        {
            Listas();
            printf("Escriba el Numero del producto a editar: ");
            scanf("%d", &Num);
            getchar();
            printf("\n");

            for (i = 0; i < C_Productos; i++)
            {
                if (i == Num - 1)
                {
                    printf("Producto Encontrado\n");

                    Posicion = i;
                    Encontrado = 1;

                    Limpieza();
                }
            }
            if (Encontrado == 1)
            {

                printf("----Menu de opciones:----\n");
                printf("1. Editar Nombre.\n");
                printf("2. Editar Precio.\n");
                printf("3. Editar Ambos.\n");
                printf("4. Borrar.\n");
                printf("5. Mostrar.\n");
                printf("6. Salir.\n");
                scanf("%d", &Op2);
                getchar();

                system("cls");

                switch (Op2)
                {
                case 1:
                    printf("Escriba el Nuevo Nombre de %s: ", N_Producto[Posicion]);
                    fgets(N_Producto[Posicion], sizeof(N_Producto[Posicion]), stdin);
                    N_Producto[Posicion][strcspn(N_Producto[Posicion], "\n")] = 0;
                    printf("Se cambio correctamente el nombre a %s\n", N_Producto[Posicion]);

                    Limpieza();

                    break;

                case 2:
                    printf("Escriba el Nuevo Precio de %s: ", N_Producto[Posicion]);
                    scanf("%f", &P_Producto[Posicion]);
                    getchar();
                    printf("El nuevo precio de %s es: %.2f$", N_Producto[Posicion], P_Producto[Posicion]);

                    Limpieza();

                    break;

                case 3:
                    printf("Escriba el Nuevo Nombre de %s: ", N_Producto[Posicion]);
                    fgets(N_Producto[Posicion], sizeof(N_Producto[Posicion]), stdin);
                    N_Producto[Posicion][strcspn(N_Producto[Posicion], "\n")] = 0;
                    printf("Se cambio correctamente el nombre a %s\n", N_Producto[Posicion]);

                    Limpieza();
                    printf("Escriba el Nuevo Precio de %s: ", N_Producto[Posicion]);
                    scanf("%f", &P_Producto[Posicion]);
                    getchar();
                    printf("El nuevo precio de %s es: %.f$", N_Producto[Posicion], P_Producto[Posicion]);

                    Limpieza();

                    break;

                case 4:

                    N_Producto[Posicion][0] = 0;
                    P_Producto[Posicion] = 0;

                    for (i = Posicion; i < C_Productos - 1; i++)
                    {
                        strcpy(N_Producto[i], N_Producto[i + 1]);
                    }

                    for (i = Posicion; i < C_Productos - 1; i++)
                    {
                        P_Producto[i] = P_Producto[i + 1];
                    }

                    printf("Producto y Precio eliminados Correctamente\n");

                    C_Productos--;

                    Limpieza();

                    break;

                case 5:
                    Listas();

                    Limpieza();

                    break;

                case 6:
                    break;

                default:
                    printf("Solo puede presionar un numero entre el 1 y 6.\n");
                    printf("Vuelva a intentarlo.\n");

                    Limpieza();

                    break;
                }
            }
            else
            {
                printf("No se Encontro el Producto\n");

                Limpieza();
            }
        }
        else
        {
            printf("No hay Productos registrados todavía\n");

            Limpieza();
        }

    } while (Op2 != 6);

    Limpieza();
}

void Suma_Inventario()
{
    S_Inventario = 0;
    if (C_Productos > 0)
    {
        for (i = 0; i < C_Productos; i++)
        {
            S_Inventario = S_Inventario + P_Producto[i];
        }
        printf("El valor total del Inventario es de: %.2f\n", S_Inventario);

        Limpieza();
    }
    else
    {
        printf("No hay productos registrados.\n");

        Limpieza();
    }
}

void Mas_Caro_y_Mas_Barato()
{
    M_Caro = P_Producto[0];
    M_Barato = P_Producto[0];

    int Pos_Caro;
    int Pos_Barato;

    if (C_Productos > 0)
    {
        for (i = 0; i < C_Productos; i++)
        {
            if (M_Caro < P_Producto[i])
            {
                M_Caro = P_Producto[i];
                Pos_Caro = i;
            }
            if (M_Barato > P_Producto[i])
            {
                M_Barato = P_Producto[i];
                Pos_Barato = i;
            }
        }
        printf("El Producto mas Caro es %s: %.2f$\n", N_Producto[Pos_Caro], M_Caro);
        printf("El Producto mas Barato es %s: %.2f$\n", N_Producto[Pos_Barato], M_Barato);

        Limpieza();
    }
    else
    {
        printf("No hay productos registrados para calcular el promedio.\n");

        Limpieza();
    }
}

void Precio_Promedio()
{
    Promedio = 0;
    if (C_Productos > 0)
    {
        for (i = 0; i < C_Productos; i++)
        {
            Promedio = Promedio + P_Producto[i];
        }
        Promedio = Promedio / C_Productos;
        printf("El Promedio del Inventario es de: %.2f Porciento\n", Promedio);

        Limpieza();
    }
    else
    {
        printf("Ingrese Productos antes de ver la suma del inventario\n");

        Limpieza();
    }
}

// Codigo Principal-------------------------------------------
// Codigo Principal-------------------------------------------
// Codigo Principal-------------------------------------------
// Codigo Principal-------------------------------------------
// Codigo Principal-------------------------------------------

int main()
{

    // Authentificación-----------------------------------------
    char Usuario[20] = "Marlon y David";
    char V_Identidad[20];
    int Contrasena = 123456;
    int V_Contrasena;

    system("cls");

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

    do
    {
        Menu();
        switch (Op)
        {

            // Case 1------------------------------------------------
            // Case 1------------------------------------------------
            // Case 1------------------------------------------------
            // Case 1------------------------------------------------
            // Case 1------------------------------------------------

        case 1:
            Registrar_Producto();

            break;

            // Case 2------------------------------------------------
            // Case 2------------------------------------------------
            // Case 2------------------------------------------------
            // Case 2------------------------------------------------
            // Case 2------------------------------------------------

        case 2:
            Editar_Productos();

            break;

            // Case 3------------------------------------------------
            // Case 3------------------------------------------------
            // Case 3------------------------------------------------
            // Case 3------------------------------------------------
            // Case 3------------------------------------------------

        case 3:
            Suma_Inventario();

            break;

            // Case 4------------------------------------------------
            // Case 4------------------------------------------------
            // Case 4------------------------------------------------
            // Case 4------------------------------------------------
            // Case 4------------------------------------------------

        case 4:
            Mas_Caro_y_Mas_Barato();

            break;

            // Case 5------------------------------------------------
            // Case 5------------------------------------------------
            // Case 5------------------------------------------------
            // Case 5------------------------------------------------
            // Case 5------------------------------------------------

        case 5:
            Precio_Promedio();

            break;

            // Case 6------------------------------------------------
            // Case 6------------------------------------------------
            // Case 6------------------------------------------------
            // Case 6------------------------------------------------
            // Case 6------------------------------------------------

        case 6:

            break;

            // Deafault------------------------------------------------
            // Deafault------------------------------------------------
            // Deafault------------------------------------------------
            // Deafault------------------------------------------------
            // Deafault------------------------------------------------

        default:
            printf("Solo puede presionar un numero entre el 1 y 6.\n");
            printf("Vuelva a intentarlo.\n");

            Limpieza();

            break;
        }
    } while (Op != 6);
    printf("Saliendo");
}
