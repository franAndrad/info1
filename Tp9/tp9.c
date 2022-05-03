#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    float min;
    float max;
}rango;

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

struct Perfil{
    char nombre[80];
    char apellido[80];
    char sexo[80];
    fecha nacimiento;
    float altura;
    float peso;
};

float BMI(struct Perfil);
int fMax(struct Perfil);
rango fIdeal(struct Perfil);
int edad(fecha);
void carga(struct Perfil *);
void imprimir(struct Perfil *);

int main(void){ 
    struct Perfil paciente;
    struct Perfil *p = &paciente;
    carga(p);
    printf("\nFicha Medica:\n");
    imprimir(p);
    printf("\nDatos extra\n");
    printf("\nBMI: %.2f\n", BMI(paciente));
    printf("Edad: %d anios\n", edad(paciente.nacimiento));
    printf("Frecuencia Cardiaca Ideal: %.2f bpm - %.2f bpm\n", fIdeal(paciente).min, fIdeal(paciente).max);
    printf("Frecuencia Cardiaca Maxima: %d bpm\n", fMax(paciente));
    return 0;
}

void imprimir(struct Perfil *p){ //Imprime todos los datos en pantalla
    printf("\nNombre: %s %s\n",p-> apellido, p -> nombre);
    printf("Genero: %s\n", p -> sexo);
    printf("Nacimiento: %d/%d/%d/n", p -> nacimiento.dia, p -> nacimiento.mes, p -> nacimiento.anio);
    printf("Altura: %.2f m\t", p -> altura);
    printf("Peso: %.2f kg\n", p -> peso);
    return;
}

float BMI(struct Perfil paciente){//Calcula el BMI
    return paciente.peso / (paciente.altura * paciente.altura);
}

void carga(struct Perfil *p){  //Carga los datos de la persona
    printf("Ingrese su nombre: ");
    scanf(" %[^\n]s", p->nombre);
    printf("Ingrese su apellido: ");
    scanf(" %[^\n]s", p->apellido);
    printf("Ingrese su genero: ");
    scanf(" %[^\n]s", p->sexo);
    printf("Ingrese su fecha de nacimiento en el sig formato (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &(p -> nacimiento.dia), &(p -> nacimiento.mes), &(p -> nacimiento.anio));
    printf("Ingrese su altura en metros: ");
    scanf("%f", &(p->altura));
    printf("Ingrese su peso en kilogramos: ");
    scanf("%f", &(p->peso));
    return;
}

int edad(fecha nacimiento){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fecha actual = {tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900};

    if(actual.mes < nacimiento.mes || (actual.mes == nacimiento.mes && actual.dia < nacimiento.dia))
        actual.anio--;
    return actual.anio - nacimiento.anio;
}

int fMax(struct Perfil paciente){
    return 220 - edad(paciente.nacimiento);
}

rango fIdeal(struct Perfil paciente){
    return (rango){fMax(paciente)*0.5, fMax(paciente)*0.85};
}