#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multiplicacion(int a, int b){
    return a*b;
}

void respuestas(int x){
    int aleatorio = rand() % 4 ;

    if (x==1)  {
            char correctas[4][100]={
            {"Muy bien!"},
            {"Excelente!"},
            {"Buen trabajo!"},
            {"Siga con el buen trabajo!"}
        };
        printf("%s", &correctas[aleatorio]);

    } else{
            char incorrectas[4][100]={
            {"No. Por favor intente de nuevo."},
            {"Incorrecto. Intentar una vez más."},
            {"No te rindas!"},
            {"No. Sigue intentándolo."}
        }; 
        printf("%s", &incorrectas[aleatorio]);
    }

}

int porcentaje(int a, int b){
    return (100/(a+b))*10;
}


int main(){

    int correctas=0,incorrectas=0;

    while (correctas<10)
    {
    
        int a,b,entrada;
        srand(time(NULL));

        a = rand() % 9 + 1 ;
        b = rand() % 9 + 1 ;

        do
        {
            printf("\n\nCuanto es %d por %d? \n",a,b);
            scanf("%d",&entrada);
            if (entrada!=multiplicacion(a,b)){
                respuestas(0);
                incorrectas++;
            } else {
                respuestas(1);
                break;
            }
        } while(1);

        correctas++;
    }

    printf("\n\nSu porcentaje de respuestas es del: %d %%",porcentaje(correctas,incorrectas));
    
    if (porcentaje(correctas,incorrectas)<75)
    {
        printf("Pídale ayuda adicional a su maestro");
    }else{
        printf("Felicitaciones, está listo para pasar al siguiente nivel!");
    }
    

return 0;
}
