#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void resta(float a, float b){
    system("cls");
    printf("El resultado de la resta es : %.2f", (a-b));
    system("pause");
}
float suma(float a, float b){
    return a + b;
}

int main(){
    int Op;
    float Num1, Num2, Resul;

    do{
        printf("Elige una opcion");
        printf("   1.-Sumar");
        printf("   2.-Restar");
        printf("   3.-Salir");

        printf("Ingrese el primer numero");
        scanf("%f" &Num1);
        printf("Ingrese el segundo numero");
        scanf("%f" &Num2);

        switch (Op){
            case 1:
            break;

            case 2:
