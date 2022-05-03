#include <stdio.h>

int main(void){

    int num=13;

    //Determina el tamaño de la parte entera
    int n=num;
    int cont=0;
    for (int i = 0; ; i++){
        int div = n;
        if(div!=0){
        cont++;
        }
        else
           break; 
        div = (n/=2);
    }

    int p_entera_b[cont];

    //Conversor de la parte entera a binario
    for (int i = 0; i<cont ; i++){
        p_entera_b[i] = num % 2; 
        num/=2;
    }

    //Ordena el numero binario invirtiendolo
     for (int i = 0; i<(cont/2) ; i++){
        int temp = p_entera_b[i];
        p_entera_b[i]= p_entera_b[cont-i-1];
        p_entera_b[cont-i-1]= temp;
    } 

    for (int i = 0; i < cont; i++)
        printf("%d", p_entera_b[i]);
    

    return 0;


}