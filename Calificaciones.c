#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ESTUDIANTES 20
#define MAX_ASIGNATURAS 10

int main()
{
    setlocale(LC_ALL, "");

    // --- VARIABLES DE CREDENCIALES Y AUTENTICACIÓN ---
    char Usuario[20] = "Marlon y David";
    char Verificacion_Identidad[20];
    int Contrasena = 123456;
    int Verificacion_Contrasena;

    // --- ARREGLOS DE DATOS PRINCIPALES ---
    char Asignaturas[MAX_ASIGNATURAS][50];
    char Estudiantes[MAX_ESTUDIANTES][50];
    float Calificacion[20][10];
    float Promedio;
    float Calificacion_T;

    // --- VARIABLES DE CONTROL Y CONTADORES ---
    int Op = 0, Op2 = 0;
    int Asignaturas_C = 0, Estudiantes_C = 0;
    int i_Asignaturas = 0, i_Estudiantes = 0; // i_Asignaturas me ayuda a saber donde se guarda lo que el usuario ponga
    int Listas = 1;
    int Num_Asignatura = 0, Num_Estudiantes = 0;
    int i = 0, b = 0, j = 0;
    int Borrar_Asignatura, Borrar_Estudiante;
    int Encontrado, Encontrado2, Posicion, Posicion2;

    // OTRA
    int i_Pedidas = 1;

    // Variables temporales para búsquedas
    char Nombre_Estudiante[50];
    char Nombre_Asignatura[50];

    do
    {
        // Pedir el nombre de usuario al usuario
        printf("Ingrese su Usuario:\n");
        printf("Profe el usuario es: Marlon y David\n");
        fgets(Verificacion_Identidad, sizeof(Verificacion_Identidad), stdin);
        Verificacion_Identidad[strcspn(Verificacion_Identidad, "\n")] = 0;

        // Pedir la contraseña al usuario
        printf("Ingrese la contrasena:\n");
        printf("Profe la contrasena es: 123456\n");
        scanf("%d", &Verificacion_Contrasena);
        getchar();
        if (strcmp(Usuario, Verificacion_Identidad) != 0 || Contrasena != Verificacion_Contrasena)
        {
            printf("Usuario o contrasena incorrectos. Intente de nuevo.\n");
            printf("Toque una tecla para continuar\n");
            system("pause");

            system("cls");
        }

        // Validación
    } while (strcmp(Usuario, Verificacion_Identidad) != 0 && Contrasena != Verificacion_Contrasena);

    system("cls");
    printf("\n¡Acceso concedido! Bienvenido al sistema.\n");
    printf("Toque una tecla para continuar\n");
    system("pause");

    system("cls");

    do
    {
        printf("Menu de opciones:\n");
        printf("1. Registrar Asignaturas\n");
        printf("2. Registrar Estudiantes\n");
        printf("3. Registrar Calificaciones\n");
        printf("4. Buscar Estudiante\n");
        printf("5. Buscar promedio de Asignaturas\n");
        printf("6. Mostrar calificacion mas baja de cada estudiante por asignatura\n");
        printf("7. Quienes reprobaron\n");
        printf("8.-Salir:\n");
        scanf("%d", &Op);
        getchar();

        i_Pedidas = 1;
        Listas = 1;
        Encontrado2 = 0;
        Encontrado = 0;

        switch (Op)
        {
        case 1:
            system("cls");
            Listas = 1;
            i_Pedidas = 1;
            do
            {

                printf("Menu de Opciones\n");
                printf("1.- Registrar Asignatura\n");
                printf("2.- Editar Asignatura\n");
                printf("3.- Borrar Asignatura\n");
                printf("4.- Mostrar Asignaturas\n");
                printf("5.- Salir\n");
                scanf("%d", &Op2);
                getchar();

                switch (Op2)
                {
                case 1:
                    system("cls");
                    printf("Escriba el nombre de la Asignatura a registrar: ");
                    fgets(Asignaturas[i_Asignaturas], sizeof(Asignaturas[i_Asignaturas]), stdin);
                    Asignaturas[i_Asignaturas][strcspn(Asignaturas[i_Asignaturas], "\n")] = 0;
                    Asignaturas_C = Asignaturas_C + 1;
                    printf("Asignatura registrada correctamente: %s\n", Asignaturas[i_Asignaturas]);
                    i_Asignaturas++;
                    printf("Presione algo para continuar\n");
                    system("pause");

                    system("cls");
                    break;

                case 2:
                    system("cls");
                    Listas = 1;
                    for (i = 0; i < Asignaturas_C; i++)
                    {
                        printf("%d.-  ", Listas++);
                        printf("Asignatura registrada: %s\n", Asignaturas[i]);
                    }
                    printf("Escriba el numero de la Asignatura a editar: ");
                    scanf("%d", &Num_Asignatura);
                    getchar();
                    printf("Escriba el nuevo nombre de la Asignatura: ");
                    fgets(Asignaturas[Num_Asignatura - 1], sizeof(Asignaturas[Num_Asignatura - 1]), stdin);
                    Asignaturas[Num_Asignatura - 1][strcspn(Asignaturas[Num_Asignatura - 1], "\n")] = 0;
                    printf("Asignatura editada correctamente: %s\n", Asignaturas[Num_Asignatura - 1]);
                    printf("Presione algo para continuar\n");
                    system("pause");

                    system("cls");
                    break;

                case 3:
                    system("cls");
                    Listas = 1;
                    for (i = 0; i < Asignaturas_C; i++)
                    {
                        printf("%d.-  ", Listas++);
                        printf("Asignatura registrada: %s\n", Asignaturas[i]);
                    }
                    printf("Escriba el numero de la Asignatura a borrar: ");
                    scanf("%d", &Num_Asignatura);
                    getchar();

                    Borrar_Asignatura = Num_Asignatura - 1;

                    if (Borrar_Asignatura >= 0 && Borrar_Asignatura < Asignaturas_C)
                    {
                        printf("Asignatura borrada correctamente: %s\n", Asignaturas[Num_Asignatura - 1]);
                        Asignaturas[Num_Asignatura - 1][0] = 0;

                        // Desplazar las asignaturas hacia la izquierda para rellenar el espacio
                        for (b = Borrar_Asignatura; b < Asignaturas_C - 1; b++)
                        {
                            strcpy(Asignaturas[b], Asignaturas[b + 1]);
                        }

                        // Limpiar la última posición que ahora queda duplicada al final
                        Asignaturas[Asignaturas_C - 1][0] = '\0';

                        // Reducir el contador total de asignaturas
                        Asignaturas_C--;
                        printf("Presione algo para continuar\n");
                        system("pause");

                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("Numero de asignatura invalido.\n");
                        printf("Presione algo para continuar\n");
                        system("pause");

                        system("cls");
                        break;
                    }

                case 4:
                    system("cls");
                    Listas = 1;
                    for (i = 0; i < Asignaturas_C; i++)
                    {
                        printf("%d.-  ", Listas++);
                        printf("Asignatura registrada: %s\n", Asignaturas[i]);
                    }
                    printf("Presione algo para continuar\n");
                    system("pause");

                    system("cls");
                    break;

                default:
                    break;
                }

            } while (Op2 != 5);
            break;

            // case2
            //  ============================================================
            //  ============================================================
            //  ============================================================
            //  ============================================================
            //  ============================================================

        case 2:
            system("cls");
            Listas = 1;
            i_Pedidas = 1;
            do
            {
                Listas = 1;
                for (i = 0; i != i_Pedidas; i++)
                {
                    if (i > 0)
                    {
                        printf("Presione algo para continuar\n");
                        system("pause");

                        system("cls");
                    }
                }

                printf("Menu de Opciones\n");
                printf("1.- Registrar Estudiante\n");
                printf("2.- Editar Estudiante\n");
                printf("3.- Borrar Estudiante\n");
                printf("4.- Mostrar Estudiantes\n");
                printf("5.- Salir\n");
                scanf("%d", &Op2);
                getchar();

                switch (Op2)
                {
                case 1:

                    system("cls");
                    printf("Escriba el nombre del Estudiante a registrar: ");
                    fgets(Estudiantes[i_Estudiantes], sizeof(Estudiantes[i_Estudiantes]), stdin);
                    Estudiantes[i_Estudiantes][strcspn(Estudiantes[i_Estudiantes], "\n")] = 0;
                    Estudiantes_C = Estudiantes_C + 1;
                    printf("Estudiante registrado correctamente: %s\n", Estudiantes[i_Estudiantes]);
                    i_Estudiantes++;
                    printf("Presione algo para continuar\n");
                    system("pause");

                    system("cls");
                    break;

                case 2:
                    Listas = 1;
                    system("cls");
                    for (i = 0; i < Estudiantes_C; i++)
                    {
                        printf("%d.-  ", Listas++);
                        printf("Estudiante registrado: %s\n", Estudiantes[i]);
                    }
                    printf("Escriba el numero del Estudiante a editar: ");
                    scanf("%d", &Num_Estudiantes);
                    getchar();
                    printf("Escriba el nuevo nombre del Estudiante: ");
                    fgets(Estudiantes[Num_Estudiantes - 1], sizeof(Estudiantes[Num_Estudiantes - 1]), stdin);
                    Estudiantes[Num_Estudiantes - 1][strcspn(Estudiantes[Num_Estudiantes - 1], "\n")] = 0;
                    printf("Estudiante editado correctamente: %s\n", Estudiantes[Num_Estudiantes - 1]);
                    printf("Presione algo para continuar\n");
                    system("pause");

                    system("cls");
                    break;

                case 3:
                    Listas = 1;
                    system("cls");
                    for (i = 0; i < Estudiantes_C; i++)
                    {
                        printf("%d.-  ", Listas++);
                        printf("Estudiante registrado: %s\n", Estudiantes[i]);
                    }
                    printf("Escriba el numero del Estudiante a borrar: ");
                    scanf("%d", &Num_Estudiantes);
                    getchar();

                    Borrar_Estudiante = Num_Estudiantes - 1;

                    if (Borrar_Estudiante >= 0 && Borrar_Estudiante < Estudiantes_C)
                    {
                        printf("Estudiante borrado correctamente: %s\n", Estudiantes[Num_Estudiantes - 1]);
                        Estudiantes[Num_Estudiantes - 1][0] = 0;

                        // Desplazar las asignaturas hacia la izquierda para rellenar el espacio
                        for (b = Borrar_Estudiante; b < Estudiantes_C - 1; b++)
                        {
                            strcpy(Estudiantes[b], Estudiantes[b + 1]);
                        }

                        // Limpiar la última posición que ahora queda duplicada al final
                        Estudiantes[Estudiantes_C - 1][0] = '\0';

                        // Reducir el contador total de estudiantes
                        Estudiantes_C--;
                        printf("Presione algo para continuar\n");
                        system("pause");

                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("Numero de estudiante invalido.\n");
                        printf("Presione algo para continuar\n");
                        system("pause");

                        system("cls");
                        break;
                    }

                case 4:
                    Listas = 1;
                    system("cls");
                    for (i = 0; i < Estudiantes_C; i++)
                    {
                        printf("%d.-  ", Listas++);
                        printf("Estudiante registrado: %s\n", Estudiantes[i]);
                    }
                    printf("Presione algo para continuar\n");
                    system("pause");

                    system("cls");
                    break;
                }

            } while (Op2 != 5);
            break;

            // case 3
            // ============================================================
            // ============================================================
            // ============================================================
            // ============================================================
            // ============================================================

        case 3:
            system("cls");
            Listas = 1;
            if (Asignaturas_C <= 0 || Estudiantes_C <= 0)
            {
                printf("No hay asignaturas o estudiantes registrados.\n");
                printf("Presione una tecla para continuar.\n");
                system("pause");

                system("cls");
                break;
            }
            else if (Asignaturas_C > 0 && Estudiantes_C > 0)
            {
                for (i = 0; i < Estudiantes_C; i++)
                {
                    printf("Estudiante registrados: %s\n", Estudiantes[i]);
                }
                printf("Ingrese el nombre del estudiante para registrar calificaciones:\n");
                fgets(Nombre_Estudiante, sizeof(Nombre_Estudiante), stdin);
                Nombre_Estudiante[strcspn(Nombre_Estudiante, "\n")] = 0;
                Encontrado = 0;
                for (i = 0; i < Estudiantes_C; i++)
                {
                    // Comparamos el estudiante en la posición [i] con el nombre buscado
                    if (strcmp(Estudiantes[i], Nombre_Estudiante) == 0)
                    {
                        Encontrado = 1; // Lo encontramos
                        Posicion = i;   // Guardamos la posición en la que está
                    }
                }

                if (Encontrado == 1)
                {

                    printf("Estudiante Encontrado.\n");
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    do
                    {
                        for (i = 0; i < Asignaturas_C; i++)
                        {

                            printf("Asignatura registrada: %s\n", Asignaturas[i]);
                        }
                        printf("En que asignatura desea ingresar la calificación para %s: ", Nombre_Estudiante);
                        fgets(Nombre_Asignatura, sizeof(Nombre_Asignatura), stdin);
                        Nombre_Asignatura[strcspn(Nombre_Asignatura, "\n")] = 0;
                        Encontrado2 = 0;
                        for (i = 0; i < Asignaturas_C; i++)
                        {
                            // Comparamos el estudiante en la posición [i] con el nombre buscado
                            if (strcmp(Asignaturas[i], Nombre_Asignatura) == 0)
                            {
                                Encontrado2 = 1; // Lo encontramos
                                Posicion2 = i;   // Guardamos la posición en la que está
                            }
                        }

                        if (Encontrado2 == 1)
                        {
                            printf("Asignatura Seleccionada.\n");
                            printf("Presione una tecla para continuar.\n");
                            system("pause");

                            system("cls");
                        }
                        else
                        {
                            printf("Asignatura no encontrada\n");
                            printf("Presione una tecla para continuar.\n");
                            system("pause");

                            system("cls");
                        }
                    } while (Encontrado2 != 1);

                    printf("Ingrese la calificación para %s en %s: ", Nombre_Estudiante, Nombre_Asignatura);
                    scanf("%f", &Calificacion[Posicion][Posicion2]);
                    getchar();
                    printf("Calificación registrada correctamente.\n");
                    printf("%s en la %s: %.2f/10\n", Nombre_Estudiante, Nombre_Asignatura, Calificacion[Posicion][Posicion2]);
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }
                printf("Estudiante no encontrado.\n");
                printf("Presione una tecla para continuar.\n");
                system("pause");

                system("cls");
                break;

                // case 4
                // ============================================================
                // ============================================================
                // ============================================================
                // ============================================================
                // ============================================================

            case 4:
                Listas = 1;
                system("cls");
                for (i = 0; i < Estudiantes_C; i++)
                {
                    printf("%d.-  ", Listas++);
                    printf("Estudiante registrado: %s\n", Estudiantes[i]);
                }
                printf("Escriba el nombre del Estudiante que desea buscar: \n");
                fgets(Nombre_Estudiante, sizeof(Nombre_Estudiante), stdin);
                Nombre_Estudiante[strcspn(Nombre_Estudiante, "\n")] = 0;
                for (i = 0; i < Estudiantes_C; i++)
                {
                    if (strcmp(Nombre_Estudiante, Estudiantes[i]) == 0)
                    {
                        Posicion = i;
                        Encontrado = 1;
                    }
                }
                if (Encontrado == 1)
                {
                    if (Asignaturas_C > 0)
                    {
                        printf("Las notas del estudiante : %s\n", Nombre_Estudiante);
                        for (j = 0; j < Asignaturas_C; j++)
                        {

                            printf("%s: %.2f/10\n", Asignaturas[j], Calificacion[Posicion][j]);
                        }
                        printf("Presione una tecla para continuar.\n");
                        system("pause");

                        system("cls");
                    }
                }
                else
                {
                    printf("Estudiante no encontrodo\n");
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }

                break;

                // case 5
                // ============================================================
                // ============================================================
                // ============================================================
                // ============================================================
                // ============================================================

            case 5:
                Listas = 1;
                Encontrado = 0;
                Calificacion_T = 0;
                system("cls");
                for (i = 0; i < Asignaturas_C; i++)
                {
                    printf("%d.-  ", Listas++);
                    printf("Asignatura registrada: %s\n", Asignaturas[i]);
                }
                printf("De que asignatura desea buscar el promedio: ");
                fgets(Nombre_Asignatura, sizeof(Nombre_Asignatura), stdin);
                Nombre_Asignatura[strcspn(Nombre_Asignatura, "\n")] = 0;
                if (Asignaturas_C > 0)
                {
                    for (i = 0; i < Asignaturas_C; i++)
                    {
                        if (strcmp(Nombre_Asignatura, Asignaturas[i]) == 0)
                        {
                            Encontrado = 1;
                            Posicion2 = i;
                        }
                    }
                }
                else
                {
                    printf("No hay asignaturas registradas\n");
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }
                if (Encontrado == 1)
                {
                    for (i = 0; i < Estudiantes_C; i++)
                    {
                        Calificacion_T = Calificacion_T + Calificacion[i][Posicion2];
                    }
                    Promedio = Calificacion_T / Estudiantes_C * 10;
                    printf("El promedio de la asignatura %s es: %.2f Porciento\n", Asignaturas[Posicion2], Promedio);
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }
                else
                {
                    printf("No se a encontrado la asignatura\n");
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }

                break;

            case 6:
                system("cls");
                printf("Calificaciones mas bajas de cada Estudiante por Asignatura\n");
                if (Estudiantes_C <= 0 || Asignaturas_C <= 0)
                {
                    printf("No hay estudiantes o asignaturas registradas en el sistema.\n");
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }
                else
                {
                    // Recorremos cada estudiante registrado
                    for (i = 0; i < Estudiantes_C; i++)
                    {
                        // Asumimos inicialmente que la nota más baja es la de la primera asignatura (índice 0)
                        float menor_nota = Calificacion[i][0];
                        int pos_asignatura = 0;

                        // Recorremos las demás asignaturas para comparar
                        for (j = 1; j < Asignaturas_C; j++)
                        {
                            if (Calificacion[i][j] < menor_nota)
                            {
                                menor_nota = Calificacion[i][j]; // Actualizamos la menor nota
                                pos_asignatura = j;              // Guardamos la posición de la asignatura
                            }
                        }

                        // Mostramos el resultado para el estudiante actual
                        printf("Estudiante: %s\n", Estudiantes[i]);
                        printf("Asignatura con nota mas baja: %s (Nota: %.2f)\n", Asignaturas[pos_asignatura], menor_nota);
                    }
                    printf("Presione una tecla para continuar.\n");
                    system("pause");

                    system("cls");
                    break;
                }
                break;

            case 7:
                system("cls");
                printf("--- Estudiantes Reprobados ---\n");

                if (Estudiantes_C <= 0 || Asignaturas_C <= 0)
                {
                    printf("No hay estudiantes o asignaturas registradas en el sistema.\n");
                }
                else
                {
                    int total_reprobados = 0;

                    // Recorremos cada estudiante
                    for (i = 0; i < Estudiantes_C; i++)
                    {
                        int reprobo_algun_lado = 0; // Bandera para saber si reprobó algo

                        printf("Estudiante: %s\n", Estudiantes[i]);

                        // Recorremos las asignaturas de ese estudiante
                        for (j = 0; j < Asignaturas_C; j++)
                        {
                            // Cambia el '6.0' por la nota mínima aprobatoria de tu escuela si es diferente
                            if (Calificacion[i][j] < 6.0)
                            {

                                printf("  -> Reprobó en %s con nota de: %.2f\n", Asignaturas[j], Calificacion[i][j]);
                                reprobo_algun_lado = 1;
                            }
                        }

                        if (reprobo_algun_lado == 0)
                        {
                            printf("  -> ¡Aprobado en todas las asignaturas!\n");
                        }
                    }
                }

                printf("Presione una tecla para continuar.\n");
                system("pause");
                system("cls");
                break;
            }
        }
    } while (Op != 8);

    printf("Gracias por usar el sistema, hasta luego.\n");
    return 0;
}
