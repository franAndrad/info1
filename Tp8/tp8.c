#include<stdio.h>

int main(void){

    char *temas[]={
        "violencia de genero  ",
        "inflacion            ",
        "problemas ambientales",
        "racismo              ",
        "inseguridad          "
    };   

    int frecuencia[5][11]={{0}};
    int respuestas[5]={0};
    int puntos[5]={0};
    int centinela=0,cont=1,mayor,menor,posMayor,posMenor;
    float promedio[5]={0};

    do{

        printf("\nCalifique estos problemas de conciencia social de 1(menos importante) a 10(mas importante).\n\n");

        for (int i=0;i<5;i++){
            do
            {
                printf("%s: ",temas[i]);
                scanf("%d",&respuestas[i]);
                if(respuestas[i] < 1 || respuestas[i] > 10)
                    printf("Ingrese un numero valido\n");
            } while (respuestas[i] < 1 || respuestas[i] > 10);
            puntos[i] += respuestas[i];    
        }

        for (int i=0;i<5;i++){
            for (int j=0;j<=10;j++){
                if (respuestas[i]==j)
                {
                    frecuencia[i][j]++;
                }
            }
        }

        printf("\n\nDesea que la encuesta la realice otra persona?\n1.Si\n2.Finalizar\n");

        do
        {
            scanf("%d",&centinela);
            if (centinela==1){
                cont++;
                break;
            }
            if (centinela==2)
                break;
            if (centinela != 1 || centinela != 2)
                printf("Ingrese un numero valido\n");   
        } while (centinela != 1 || centinela != 2);

    }while(centinela==1);


    //IMPRIME TABLA
    printf("__________Problema______");
    for(int i=1;i<=10;i++)
        printf("_|_%d", i);
    printf("_|_Promedio_\n");        
    
    for(int i=0;i<5;i++){
        printf("%s\t",temas[i]);
        for(int j=1;j<=10;j++){
            if(j==10){
                printf(" |  %d", frecuencia[i][j]);
            }else{
                printf(" | %d", frecuencia[i][j]);
            }
        }
        promedio[i] = puntos[i]/cont;
        printf(" | %f\n",promedio[i]);        
    }

    //CALCULA E IMPRIME EL MAXIMO E MINIMO
    mayor = puntos[0];
    menor = puntos[0];
    for (int i=0;i<5;i++){
        if (puntos[i]>mayor){
            posMayor=i;
        }
        if (puntos[i]<menor){
            posMenor=i;
        }
    }

    printf("\nLa problematica: %s ricibio mayor puntaje\nPuntos: %d\tPromedio: %f \n",temas[posMayor],puntos[posMayor],promedio[posMayor]);
    printf("La problematica: %s ricibio menor puntaje\nPuntos: %d\tPromedio: %f \n\n",temas[posMenor],puntos[posMenor],promedio[posMenor]);
    return 0;
}

