#include<stdio.h>

int main(void){

float peso,altura,resultado;

printf("Ingrese el peso:");
scanf("%f",&peso);
printf("Ingrese la altura:");
scanf("%f",&altura);

resultado = peso/(altura*altura);

printf("Su IMC es de: %.2f\n\n", resultado);
printf("Verifique su IMC con los siguientes indices:\n");
printf("Si es menor que 18.5 se encuentra con bajo peso\n");
printf("Si esta entre 18.5 y 24.9 se encuentra con un peso normal\n");
printf("Si esta entre 25 y 29.9 se encuentra con sobrepeso\n");
printf("Si es mayor a 30 es obeso\n");
	
return 0;
}
