#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void preguntas(int a,int b,int op){ //Funcion de preguntas
    switch (op)
    {
    case 1: printf("\n\nCuanto es %d mas %d? \n",a,b); break;
    case 2: printf("\n\nCuanto es %d menos %d? \n",a,b); break;
    case 3: printf("\n\nCuanto es %d por %d? \n",a,b); break;
    }
}

int operacion(int a,int b,int op){ //Funcion de operaciones
    switch (op)
    {
    case 1: return a+b; break;
    case 2: return a-b; break;
    case 3: return a*b; break;
    }
}

int porcentaje(int a, int b){ //Funcion de porcentaje
    return (100/(a+b))*10;
}

void respuestas(int x){ //Funcion de respuestas correctas e incorrectas
    int aleatorio = rand() % 4 + 1 ;

    if(x==0){
        switch (aleatorio)
        {
        case 1: printf("Muy bien!"); break;
        case 2: printf("Excelente!"); break;
        case 3: printf("Buen trabajo!"); break;
        case 4: printf("Siga con el buen trabajo!"); break; 
        }
    }

    if(x==1){
        switch (aleatorio)
        {
        case 1: printf("No. Por favor intente de nuevo."); break;
        case 2: printf("Incorrecto. Intentar una vez mas."); break;
        case 3: printf("No te rindas!"); break;
        case 4: printf("No. Sigue intentándolo."); break; 
        }
    }

}

int num_aleatorio(int dif){
    int potencia =  pow(10,dif);
    int a = rand() % potencia;
    return a;
}


int main(void){

    int seleccion,dificultad;
    int correctas=0,incorrectas=0;
    int problema,entrada;
    srand(time(NULL));

    do
    {

        printf("\n\nSeleccione el tipo de problema aritmetico:");
        printf("\n\n1.Suma \n2.Resta \n3.Multiplicacion \n4.Aleatorio \n5.Salir \n\n");
        scanf("%d",&seleccion);

        if (seleccion==5){  //Si la seleccion es 5 sale de la repeticion
            break;
        }

        printf("\n\nSeleccione el nivel de dificultad: ");
        scanf("%d",&dificultad);

        while(correctas<10){

            int a,b;

            a = num_aleatorio(dificultad);
            b = num_aleatorio(dificultad);
        
            do
            {

                if(seleccion==4){ //Genero un problema aleatorio
                    problema = rand() % 3 + 1 ;
                }else{
                    problema = seleccion;
                }

                preguntas(a,b,problema); //Llama a la pregunta segun sea la seleccion
                scanf("%d",&entrada);
                if (entrada!=operacion(a,b,problema)){  //Compara si la respuesta es incorrecta
                    respuestas(1);                      //Imprime una frase incorrecta
                    incorrectas++;
                } else {
                    respuestas(0); //Imprime una frase correcta
                    break;         //Si la respuesta es correcta cambia la pregunta
                }

            } while(1);

            correctas++;
        }

        printf("\n\nSu porcentaje de respuestas es del: %d%% ",porcentaje(correctas,incorrectas)); //Imprime el porcentaje
    
        if (porcentaje(correctas,incorrectas)<75)
        {   
            printf("Pidale ayuda adicional a su maestro \n\n");
        }else{
            printf("Felicitaciones, esta listo para pasar al siguiente nivel!\n\n");
        }  

    } while (1);


    return 0;
}