 
 #include <stdio.h>

int main(void){

    float num=0.2;
    int cont_f=0;

    //Determina el tamaño de la parte flotante
    float n=num;
    for (int i = 0;  ; i++){
        int calc = (n*=2); 
        if(calc<0 || calc>1)
           break;
        else
            cont_f++; 
    }
    printf("%d\n",cont_f);

     int p_decimal_b[cont_f];

    //Convierte la parte decimal en binario
     for (int i = 0; i< cont_f ; i++){
        int calc = (num*=2); 
        p_decimal_b[i]=calc;  
    }

    for (int i = 0; i < cont_f; i++)
        printf("%d", p_decimal_b[i]);


        return 0;
}