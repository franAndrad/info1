#include <stdio.h>
#include <stdlib.h>

#define GIROS 36000

int main(void){   
    
    int dado1[GIROS], dado2[GIROS];
    unsigned int frecuencia[GIROS]={0};

    for (int i = 0 ; i < GIROS ; i++){
        dado1[i] = ( rand() % 6 ) + 1; //obtengo los valores del dado 1
        dado2[i] = ( rand() % 6 ) + 1; //obtengo los valores del dado 2

        frecuencia[dado1[i]+dado2[i]]++ ; //calculo de la frecuencia
    }

    for (int i = 2; i < 13; i++)
    {
        printf("%d\t%d\n", i , frecuencia[i]);
    }
      
    return 0;

}