#include <stdio.h>

int main (void){

    float num=-10.5; 
    int entera = (int)num;
    float decimal = num - entera;
    printf("%d\t%f",entera,decimal);


    return 0;
}