#include <stdio.h>

typedef struct {
    unsigned int mantiza: 23;
    unsigned int exp:8;
    unsigned int sign:1;

}ieee754;

typedef union {
    float nf;
    unsigned int a;
}conversor;


void imprimir_bits(unsigned int , int);

int main (void){

    float num;
    
    printf("Ingrese un numero de tipo float o decimal: ");
    scanf("%f",&num);

    conversor entrada = {entrada.nf = num};
    ieee754 convertir = {.mantiza = entrada.a, .exp= entrada.a >>23, .sign =entrada.a >>31};

    printf("\n\nSigno | Exponente | \t Mantiza         \n");
    printf("------|-----------|------------------------\n");
    printf("  ");
    imprimir_bits(convertir.sign,1);
    printf("   | ");
    imprimir_bits(convertir.exp,8);
    printf("  |  ");
    imprimir_bits(convertir.mantiza,23);
    printf("\t");

    return 0;
}

void imprimir_bits(unsigned int num, int bits){
    unsigned int mask = 1 << 31; 
    for(int i = 0; i < 32; i++){  
        if (i >= 32 - bits)
            printf("%d", mask & num ? 1 : 0);
        mask >>= 1;
    }
}