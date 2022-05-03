#include <stdio.h>

#define columnas 4
#define filas 3

int main(void){

   int i,j;
   int respuesta;
   int n_ecuacion=1;
   char incognitas[]={'X','Y','Z','R'};
   float resultados[3];
   float matriz[filas][columnas] = {0};

   printf("\n\n RESOLVER SISTEMAS DE ECUACIONES POR GAUSS JORDAN \n");

   //Menu de ingreso
    do{
        //Ingresar los valores de el sistema de ecuaciones 3x3
        printf("\n Ingrese los valores de las ecuaciones en el siguiente orden (a)X+(b)Y+(c)Z=(d) \n\n");
        for(i=0;i<filas;i++){
           for(j=0;j<columnas;j++){
                printf(" Ingrese los valores de la ecuacion %d en %c : ", n_ecuacion , incognitas[j]);
                scanf("%f", &matriz[i][j]);
            }
            n_ecuacion++;
        }

        printf("\n");

        //Imprime la matriz equivalente al sistema de ecuaciones
        for(i=0;i<filas;i++){
           for(j=0;j<columnas;j++){
               char separador;
               printf("%5.2f %c", matriz[i][j], separador = (j==2)?'|':' ');
           }
            printf("\n");
        }

        printf("\nLa matriz equivalente es correcta? \n\n Si->1 \n No->2 \n\n ");
        scanf("\n%d", &respuesta);

    }while(respuesta!=1);
    

  if(matriz[0][0]==0 || matriz[1][1]==0 || matriz[2][2]==0)
    printf("Tiene infinitas soluciones, es compatible indeterminado");

  else {
     
    //Hacemos e21(escalar) y luego e31(escalar)
        for(i=1;i<filas;i++){
          float escalar = (- matriz[i][0] / matriz[0][0]);
           for(j=0;j<columnas;j++)
                matriz[i][j] = (escalar * matriz[0][j]) + matriz[i][j] ;
        }

    //Hacemos e32(escalar) y luego e12(esclar)
        for(i=0;i<filas;i+=2){
          float escalar = (- matriz[i][1] / matriz[1][1]);
           for(j=0;j<columnas;j++)
                matriz[i][j] = (escalar * matriz[1][j]) + matriz[i][j] ;
        }
    
    //Hacemos e13(escalar) y luego e23(esclar)
        for(i=0;i<2;i++){
          float escalar = (- matriz[i][2] / matriz[2][2]);
           for(j=0;j<columnas;j++)
                matriz[i][j] = (escalar * matriz[2][j]) + matriz[i][j] ;
        }

    //dividimos las filas y obtenemos el resultado
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            matriz[i][3]= matriz[i][3] /matriz[i][i];
            matriz[i][i]=1;
        }
     } 

    printf("\n Los resultados son: \n");

    //Imprime los resultados
    for(i=0;i<filas;i++){
        resultados[i]= matriz[i][3];
        printf(" %c = %f \n", incognitas[i], resultados[i]);
    }

    printf("\n");

  }
}

