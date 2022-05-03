#include <stdio.h>
int main(void){

 int valor;
 int a,b,c,d;
do{
 printf("Escribir los 4 digitos a incriptar: \n");
 scanf("%d",&valor);
} while(valor>9999||valor<0);	
 
 //Obtener los digitos por separado
 d=valor%10;
 valor=valor/10;
 c=valor%10;
 valor=valor/10;
 b=valor%10;
 valor=valor/10;
 a=valor%10;

 //Proceso de digitos
 int cambio1=(a+7)%10;
 int cambio2=(b+7)%10;
 int cambio3=(c+7)%10;
 int cambio4=(d+7)%10;
 
 //Intercabio de digitos
 a=cambio3;
 b=cambio4;
 c=cambio1;
 d=cambio2;

 printf("El valor encriptado es: %d%d%d%d \n",a,b,c,d); 

}
