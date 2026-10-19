#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    
    // Definimos las credenciales correctas
    char Usuario[20] = "Marlon y David";
    char Verificacion_Identidad[20];
    char Asignaturas[20][50];
    char Estudiantes[20][50];
    char Nombre_Estudiante[50];
    char Nombre_Asignatura[50];

    int Contrasena = 123456;
    int Verificacion_Contrasena, Op, Yes_No, i; 
    int Asignaturas_C = 0, Estudiantes_C = 0; // Contadores reales que acumulan los registros

    // Matriz de calificaciones: [Fila = Estudiante][Columna = Asignatura]
    float Calificacion[20][20];

    // Inicializamos la matriz de calificaciones en ceros
    for(int r = 0; r < 20; r++) {
        for(int c = 0; c < 20; c++) {
            Calificacion[r][c] = 0.0;
        }
    }

    // Validación de usuario
    do
    {
        printf("Ingrese su Usuario:\n");
        printf("Profe el usuario es: Marlon y David\n");
        fgets(Verificacion_Identidad, sizeof(Verificacion_Identidad), stdin);
        Verificacion_Identidad[strcspn(Verificacion_Identidad, "\n")] = 0;

        printf("Ingrese la contrasena:\n");
        printf("Profe la contrasena es: 123456\n");
        scanf("%d", &Verificacion_Contrasena);
        getchar(); // Limpiar buffer

        if (strcmp(Usuario, Verificacion_Identidad) != 0 || Contrasena != Verificacion_Contrasena)
        {
            printf("Usuario o contrasena incorrectos. Intente de nuevo.\n");
            printf("Toque una tecla para continuar...\n");
            system("pause");
            system("cls");
        }

    } while (strcmp(Usuario, Verificacion_Identidad) != 0 || Contrasena != Verificacion_Contrasena);

    system("cls");
    printf("\n¡Acceso concedido! Bienvenido al sistema.\n");
printf("Toque una tecla para continuar\n");
            system("pause");
            system("cls");
    // Menú principal
    do
    {
        printf("\n--- MENU DE OPCIONES ---\n");
        printf("1. Registrar Asignaturas\n");
        printf("2. Registrar Estudiantes\n");
        printf("3. Registrar Calificaciones\n");
        printf("4. Buscar Estudiante\n");
        printf("5. Buscar promedio de Asignaturas\n");
        printf("6. Mostrar calificacion mas baja de cada estudiante por asignatura\n");
        printf("7. Quienes reprobaron\n");
        printf("8. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &Op);
        getchar(); // Limpiar el buffer

        switch (Op)
        {
        case 1: // Registrar Asignaturas
            {
                char continuar = 's';
                while (continuar == 's' || continuar == 'S')
                {
                    system("cls");
                    if (Asignaturas_C >= 20) {
                        printf("¡Capacidad maxima de asignaturas alcanzada!\n");
                        break;
                    }

                    printf("Escriba el nombre de la asignatura [%d]: ", Asignaturas_C + 1);
                    fgets(Asignaturas[Asignaturas_C], sizeof(Asignaturas[Asignaturas_C]), stdin);
                    Asignaturas[Asignaturas_C][strcspn(Asignaturas[Asignaturas_C], "\n")] = 0;
                    
                    Asignaturas_C++; // Incrementamos el contador real sin borrar lo anterior

                    printf("¿Quiere registrar otra asignatura? (s/n): ");
                    scanf(" %c", &continuar);
                    getchar();
                }
                system("cls");
            }
            break;

        case 2: // Registrar Estudiantes
            {
                char continuar = 's';
                while (continuar == 's' || continuar == 'S')
                {
                    system("cls");
                    if (Estudiantes_C >= 20) {
                        printf("¡Capacidad maxima de estudiantes alcanzada!\n");
                        break;
                    }

                    printf("Escriba el nombre del estudiante [%d]: ", Estudiantes_C + 1);
                    fgets(Estudiantes[Estudiantes_C], sizeof(Estudiantes[Estudiantes_C]), stdin);
                    Estudiantes[Estudiantes_C][strcspn(Estudiantes[Estudiantes_C], "\n")] = 0;
                    
                    Estudiantes_C++; // Incrementamos el contador real sin borrar lo anterior

                    printf("¿Quiere registrar otro estudiante? (s/n): ");
                    scanf(" %c", &continuar);
                    getchar();
                }
                system("cls");
            }
            break;

        case 3: // Registrar Calificaciones
            {
                system("cls");
                if (Asignaturas_C == 0 || Estudiantes_C == 0)
                {
                    printf("¡Error! Debe registrar al menos una asignatura y un estudiante primero.\n");
                    printf("Presione una tecla para continuar...\n");
                    system("pause");
                    system("cls");
                    break;
                }

                // Mostrar lista de estudiantes disponibles
                printf("--- LISTA DE ESTUDIANTES ---\n");
                for (int e = 0; e < Estudiantes_C; e++)
                {
                    printf("- %s (ID: %d)\n", Estudiantes[e], e);
                }

                printf("\nIngrese el nombre exacto del estudiante para registrar calificaciones:\n> ");
                fgets(Nombre_Estudiante, sizeof(Nombre_Estudiante), stdin);
                Nombre_Estudiante[strcspn(Nombre_Estudiante, "\n")] = 0;

                int pos_estudiante = -1;
                // Buscamos la posición numérica (fila) del estudiante
                for (int e = 0; e < Estudiantes_C; e++)
                {
                    if (strcmp(Estudiantes[e], Nombre_Estudiante) == 0)
                    {
                        pos_estudiante = e;
                        break;
                    }
                }

                if (pos_estudiante == -1)
                {
                    printf("\nEstudiante no encontrado en el sistema.\n");
                    printf("Presione una tecla para continuar...\n");
                    system("pause");
                    system("cls");
                    break;
                }

                printf("\n¡Estudiante encontrado! Ahora ingrese las notas:\n");
                system("pause");
                system("cls");

                // Recorremos todas las asignaturas para asignarle su nota a este estudiante
                for (int a = 0; a < Asignaturas_C; a++)
                {
                    printf("Estudiante: %s\n", Estudiantes[pos_estudiante]);
                    printf("Asignatura: %s\n", Asignaturas[a]);
                    printf("Ingrese la calificacion: ");
                    scanf("%f", &Calificacion[pos_estudiante][a]);
                    getchar(); // Limpiar buffer
                    printf("------------------------------------\n");
                }

                printf("\n¡Calificaciones guardadas exitosamente para %s!\n", Estudiantes[pos_estudiante]);
                printf("Presione una tecla para continuar...\n");
                system("pause");
                system("cls");
            }
            break;

        case 8: // Salir
            printf("\nSaliendo del sistema. ¡Hasta luego!\n");
            system("pause");
            break;

        default:
            printf("\nOpcion invalida. Intente de nuevo.\n");
            system("pause");
            system("cls");
        }

    } while (Op != 8);

    return 0;
}