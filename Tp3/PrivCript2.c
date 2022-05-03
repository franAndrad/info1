#include <stdio.h>
int main(void){
 
 int valor;
 int a,b,c,d;
 int cambio1,cambio2,cambio3,cambio4;

 do{
 printf("Escribir los 4 digitos a desimcriptar: \n");
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

 //Revertir el proceso
 if(a<7){ cambio1=a+3; } 
 else{ cambio1=a-7; }

 if(b<7){ cambio2=b+3; }
 else{ cambio2=b-7; }

 if(c<7){ cambio3=c+3; }
 else{ cambio3=c-7;}

 if(d<7){ cambio4=d+3; } 
 else{ cambio4=d-7; }

 //Intercambio de digitos
 a = cambio3;
 b = cambio4;
 c = cambio1;
 d = cambio2;

 printf("El desemcriptado es: %d%d%d%d \n",a,b,c,d);
}
