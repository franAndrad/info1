#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 102

typedef struct{
    int record;
    char nombre[80];
    int cantidad;
    float precio;
}herramienta_t;

FILE *inicializar(void);
void menu_acceso(void);
int validacion_datos(int *);
void leer(FILE*);
void escribir(FILE*);
void borrar(FILE *);

int main(void){
    int operacion;
    void (*modo[3])(FILE *cfPtr)={leer,escribir,borrar};

    FILE* cfPtr = fopen("hardware.dat","rb+");
    if(cfPtr==NULL)
        cfPtr = inicializar();
    do{
        menu_acceso();
        validacion_datos(&operacion);
        modo[operacion](cfPtr);
    } while(operacion != 3);
    fclose(cfPtr);
   return 0;
}

//CREA EL ARCHIVO 
FILE *inicializar(void){ 
    herramienta_t t={0,0,0,0};
    puts("\nCreando archivo...\n");
    FILE *cfPtr = fopen("hardware.dat","wb");
    int pos=0;
    for (int i = 0; i < TAM; i++){
        fseek(cfPtr,sizeof(herramienta_t)*(pos++), SEEK_SET);
        fwrite(&t, sizeof(herramienta_t), 1, cfPtr);
    } 
    return fopen("hardware.dat","rb+");
}

//IMPRIME EL MENU
void menu_acceso(void){
    printf("\n\tINVENTARIO DE HERRAMIENTAS\n\n");
    printf("0) Listado \n");
    printf("1) Agregar \n");
    printf("2) Eliminar \n");
    printf("3) Salir\n\n");
}

//VALIDA QUE LOS DATOS INRGESADOS NO SEAN INCORRECTOS
int validacion_datos(int *a){
    do{
        printf("Ingrese la operacion a realizar: ");
        scanf("%d", a);
        if(*a<0 || *a>3){
            printf("\nError!\n\n");
        }
    }while (*a<0 || *a>3);     
    return *a;
}

//LEER EL LISTADO DE HERRAMIENTAS
void leer(FILE *cfPtr) {
    herramienta_t t;
    fseek(cfPtr, 0, SEEK_SET); //aca ponemos que comienze desde el inicio del archivo
    for (int i = 0; i < TAM; i++){ //esto es lo que hicimos para que repita
        fread(&t, sizeof(herramienta_t),1,cfPtr); //DESPUES ES LO MISMO
        if(t.cantidad !=0){
            printf("\n%d\t%10s\t%d\t%0.2f\n", t.record,t.nombre,t.cantidad,t.precio);
        }
    }
}

//FUNCION PARA ESCRIBIR LAS HERRAMIENTAS
void escribir(FILE *cfPtr) {

    //Validamos la posicion donde queremos escribir
    int pos;
    do{
        printf("\nIngrese la posicion donde quiere escribir :");
        scanf("%d", &pos);
        if(pos<1||pos>100){
            puts("La posicion ingresada es incorrecta");
        }
    } while (pos<1||pos>100);

    //Escribimos los datos
    herramienta_t t;
    printf("\nNombre  : ");
    scanf(" %[^\n]s", t.nombre);
    printf("Cantidad: ");
    scanf("%d", &(t.cantidad));
    printf("Precio  : ");
    scanf("%f", &(t.precio));
    t.record=(pos);

    //Agregamos el dato en esa posicion
    fseek(cfPtr,sizeof(herramienta_t)*(pos-1), SEEK_SET);
    fwrite(&t, sizeof(herramienta_t), 1, cfPtr);

}

//FUNCION PARA BORRAR LAS HERRAMIENTAS
void borrar(FILE *cfPtr){

    //Validamos la posicion donde queremos escribir
    int pos;
    do{
        printf("\nIngrese la posicion donde quiere borrar:");
        scanf("%d", &pos);
        if(pos<1||pos>100){
            puts("La posicion ingresada es incorrecta");
        }
    } while (pos<1||pos>100);

    //Eliminamos el dato en esa posicion
    herramienta_t t = (herramienta_t){pos, {(char)0}, 0, 0};
    fseek(cfPtr, sizeof(herramienta_t)*(pos-1), SEEK_SET);
    fwrite(&t, sizeof t, 1, cfPtr);

    puts("\nEl articulo a sido eliminado correctamente");
}
