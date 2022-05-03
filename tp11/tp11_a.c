
#include <stdio.h>
#include <math.h>


int tam_entero(int );
int tam_decimal(float );
void partEntera_bin( int *, int,const int);
void partDecimal_bin(int *,float,const int);
void  imprimir_IEE754(int, int *,int *);

//funciones para pasarlo al estandar IEEE754
int get_ieee_sign (float);
int get_ieee_exp(int,int *,int,int);
void get_ieee_mantissa(int*, int *,  int*,int,int,int);



int main(void){ 

    puts("\n\n-------CONVERSOR DE FLOAT A IEEE754--------\n");

    float nf;

    printf("Ingrese el numero decimal o flotante: ");
    scanf("%f",&nf);

    //BIT DE SIGNO
    int bit_signo = get_ieee_sign (nf);//obtenemos el bit de signo

    //Despues de obtener el signo saco el valor absoluto
    float numero = fabs(nf);
    
    //CONVERSION A BIN

    //Separamos la parte entera de la decimal
    int p_entera = (int)numero;
    float p_decimal = numero - p_entera;
    const int TAM1 = tam_entero(p_entera);
    const int TAM2 = tam_decimal(p_decimal);

    //Convertimos la parte entera y decimal a binaria
    int arreglo_entero_b[TAM1];            //declaro un arreglo donde se va a guardar el num bin
    int arreglo_decimal_b[TAM2];
    partEntera_bin(arreglo_entero_b,p_entera,TAM1); //esta funcion devuelve la parte entera en binario
    partDecimal_bin(arreglo_decimal_b,p_decimal,TAM2); //esta funcion devuelve la parte decimal en  binario

    //CONVERTIMOS EN IEEE754

    //EXPONENTE
    int exponente[8]; //declaramos un arreglo para guardar el exponente en binario
    get_ieee_exp(p_entera,exponente,TAM1,TAM2);

    //MANTIZA
    int desplazamiento=get_ieee_exp(p_entera,exponente,TAM1,TAM2);
    int mantiza[23];
    get_ieee_mantissa(mantiza,arreglo_entero_b,arreglo_decimal_b,TAM1,TAM2,desplazamiento);

    //IMPRIMIMOS
    imprimir_IEE754(bit_signo,exponente,mantiza);

    
    return 0;
}

//Funcion que determina la cantidad de datos que va a tener la parte entera parte entera
int tam_entero(int n){
    if(n!=0){
        int cont=0;
        for (int i = 0; ; i++){
            int div = n;
            if(div!=0)
                cont++;
            else
                break; 
            div = (n/=2);
        }
        return cont;
    }else
        return 1;  
}

//Funcion que determina la cantidad de datos que va a tener la parte entera
int tam_decimal(float n){
    int cont=0;
    if (n!=0){
        for (int i = 0;  ; i++){
            int calc = (n*=2); 
            if(calc<0 || calc>1)
                break;
            else
                cont++; 
        }
        return cont;
    }else
        return 1;
}

//funcion obtener el num binario de la parte entera
void partEntera_bin(int *a,int b,const int tam){
    int n1=b;
    for (int i = 0; i<tam ; i++){
        *(a+i) = n1 % 2; 
        n1/=2;
    }

    //Ordena el numero binario invirtiendolo
     for (int i = 0; i<(tam/2) ; i++){
        int temp = *(a+i);
        *(a+i)= *(a+(tam-i-1));
        *(a+(tam-i-1))= temp;
    }
}

//funcion obtener el num binario de la parte decimal
void partDecimal_bin(int *a,float b,const int tam){
    float n=b;
     for (int i = 0; i< tam ; i++){
        int calc = (n*=2); 
        *(a+i)=calc;  
    }
}

//Funcion signo
int get_ieee_sign (float a){
    if(a>=0){
        return 0;
    }else{
        return 1;
    }
}

//Funcion expresion
int get_ieee_exp(int p_e,int *a,int tamE,int tamD){
    //PASAMOS EL BINARIO A NOTACION CIENTIFICA
    int desplazamiento=0;
    int exp_entero=0;
    if(tamE>=1)
        desplazamiento = tamE-1; 
    else
        desplazamiento = -tamD;
    if(p_e!=0)
        exp_entero = 127 + desplazamiento;
    partEntera_bin(a,exp_entero,8);
    return desplazamiento;
}

//Funcion mantiza
void get_ieee_mantissa(int *m,int *a,int*b,int tam1,int tam2, int desplazamiento){
    
     int temp[desplazamiento];

    if (tam1>=1){
        int cont=0;
        for (int i = tam1-desplazamiento ; i < tam1; i++)
            temp[cont++] = *(a+i); 
    }
    
    int cont=0;
    for (int i = 0; i < 23; i++){
        if (i< (desplazamiento))
            *(m+i)=temp[i];
        else if (i>=(desplazamiento) && i<(desplazamiento+tam2))
            *(m+i)=*(b+(cont++));
        else
            *(m+i)=0;
    }   
}

//Funcion que imprime los datos
void  imprimir_IEE754(int a,int *b,int *c){
        
    printf("\n\nSigno | Exponente | \t Mantiza         \n");
    printf("------|-----------|------------------------\n");
    printf("  %d   |  ", a);
    for (int i = 0; i < 8; i++)
        printf("%d", b[i]);
    printf(" | ");
    for(int i = 0; i < 23; i++)
        printf("%d", c[i]);
    puts("\n");
}
