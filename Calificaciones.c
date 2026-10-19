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
    int Verificacion_Contrasena, Op, Yes_No, i, i_Pedidas, Asignaturas_C = 0, Estudiantes_C = 0;

    float Calificacion[Estudiantes][Asignaturas];


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
        if (strcmp(Usuario, Verificacion_Identidad) != 0 && Contrasena != Verificacion_Contrasena)
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

        switch (Op)
        {
        case 1:
            for (i = 0; i != i_Pedidas; i++)
            {
                if (i > 0)
                {
                    printf("Presione algo para continuar\n");
                    ststem("pause");
                    syste("cls");
                }

                printf("Escriba la asignatura\n");
                fgets(Asignaturas[i], sizeof(Asignaturas[i]), stdin);
                Asignaturas[i][strcspn(Asignaturas[i], "\n")] = 0;
                printf("Quiere resgistrar otra asignatura? (1=Si, 2=No): ");
                scanf("%d", &Yes_No);
                getchar();
                Asignaturas_C = Asignaturas_C + 1;
                if (Yes_No == 1)
                {
                    i_Pedidas++;
                }
            }
            break;

        case 2:
            for (i = 0; i != i_Pedidas; i++)
            {
                if (i > 0)
                {
                    printf("Presione algo para continuar\n");
                    ststem("pause");
                    syste("cls");
                }

                printf("Escriba el nombre del estudiante");
                fgets(Estudiantes[i], sizeof(Estudiantes[i]), stdin);
                Estudiantes[i][strcspn(Estudiantes[i], "\n")] = 0;
                printf("Quiere resgistrar otro estudiante? (1=Si, 2=No): ");
                scanf("%d", &Yes_No);
                getchar();
                Estudiantes_C = Estudiantes_C + 1;
                if (Yes_No == 1)
                {
                    i_Pedidas++;
                }
            }
            break;

        case 3:
            if (Asignaturas_C == 0 && Estudiantes_C == 0)
            {
                printf("No hay asignaturas o estudiantes registrados.\n");
                break;
            }
            else if (Asignaturas_C > 0 && Estudiantes_C > 0)
            {
                for (i = 0; i <= Estudiantes_C; i++)
                {
                    printf("Estudiante registrados: %s", Estudiantes[i]);
                }
                printf("Ingrese el nombre del estudiante para registrar calificaciones:\n");
                fgets(Nombre_Estudiante, sizeof(Nombre_Estudiante), stdin);
                Nombre_Estudiante[strcspn(Nombre_Estudiante, "\n")] = 0;

                if (strcmp(Estudiantes[i], Nombre_Estudiante) == 0)
                {
                    printf("Estudiante Encontrado.\n");
                    pritnf("Presione una tecla para continuar.\n");
                    system("pause");
                    system("cls");
                    do
                    {
                        printf("En que asignatura desea ingresar la calificación para %s:", Nombre_Estudiante[50]);
                        fgets(Nombre_Asignatura, sizeof(Nombre_Asignatura), stdin);
                        Nombre_Asignatura[strcspn(Nombre_Asignatura, "\n")] = 0;

                        if (strcmp(Asignaturas[i], Nombre_Asignatura) == 0)
                        {
                            printf("Asignatura Seleccionada.\n");
                            pritnf("Presione una tecla para continuar.\n");
                            system("pause");
                            system("cls");
                        }
                        else
                            (strcmp(Asignaturas[i], Nombre_Asignatura) != 0);
                        {
                            printf("Asignatura no encontrada\n");
                            pritnf("Presione una tecla para continuar.\n");
                            system("pause");
                            system("cls");
                        }
                    } while (strcmp(Asignaturas[i], Nombre_Asignatura) != 0);
                    printf("Ingrese la calificación para %s en %s: ", Nombre_Estudiante, Nombre_Asignatura);
                    scanf("%f", &Calificacion[Estudiantes][Asignaturas]);
                    printf("Calificación registrada correctamente.\n");
                    pritnf("%s en la %s: %.2f\n", Nombre_Estudiante, Nombre_Asignatura, Calificacion[Estudiantes][Asignaturas]);
                    pritnf("Presione una tecla para continuar.\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("Estudiante no encontrado.\n");
                pritnf("Presione una tecla para continuar.\n");
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                printf("Buscar Estudiante\n");
                Buscar_Estudiante();
                break;

            case 5:
                system("cls");
                printf("Buscar promedio de Asignaturas\n");
                Promedio_Asignaturas();
                break;

            case 6:
                system("cls");
                printf("Mostrar calificacion mas baja de cada estudiante por asignatura\n");
                Calificacion_Mas_Baja();
                break;

            case 7:
                system("cls");
                printf("Quienes reprobaron\n");
                Quienes_Reprobaron();
            }
        }
        while (Op < 1 || Op >= 8)
            ;
        printf("Gracias por usar el sistema, hasta luego.\n");
        return 0;
    }