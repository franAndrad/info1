#include<stdio.h>
int main(void){
  
	printf("\nROGRAMA PARA CALCULAR EL PAGO SEMANAL DE CADA EMPLEADO\n");
	printf("\nPara acceder al pago debera colocar el codigo correspondiente:\n");
	printf("\n 0->salir \n 1->generente \n 2->trabajador/hora \n 3->trabajador/comision \n 4->trabajador/destajo\n");

 //Variables generales
 int codigo;
 float salario;
 float ganancia_hora;
 //Variable trabajador por hora
 int horas;
 //Variable trabajador por comisiones
 int ventas;
 int precio_articulos=50;
 //Variable trabajador a destajo
 int cantidad;
 int ganancia_produccion=20;

   do{
	printf("\nIngrese el codigo: ");
	scanf("%d",&codigo);

	switch(codigo){

		case 1:
		       salario=1000; //Pago fijo semanal		       
		       printf("\nEl pago del gerente es: $%.3f\n",salario);
	        break;

 		case 2:
		       salario=500; //Pago fijo semanal
		       printf("\nIngrese la cantidad de horas trabajadas: ");
		       scanf("%d",&horas);
		       if(horas>=40){
			ganancia_hora= ((salario/40)*1.5); //Ganancia extra por hora
		       	salario = salario + ((horas-40)*ganancia_hora);
		       }
		       else{
		        salario = (horas*(salario/40));
		       }
		       printf("El pago del trabajador por hora es: $%.3f\n",salario);
		break;

		case 3:
		       salario = 250; //Pago fijo semanal
		       printf("\nIngrese la cantidad de ventas: ");
		       scanf("%d",&ventas);
		       salario = salario + (((ventas*precio_articulos)*5.7)/100);
		       printf("El pago del trabajador por comision es: $%.3f\n",salario);
		break;

		case 4:
		       salario=100; //Pago fijo semanal
		       printf("\nIngrese la cantidad de articulos producidos: ");
		       scanf("%d",&cantidad);
		       salario = salario + (ganancia_produccion*cantidad);
		       printf("El pago del trabajador a destajo es: $%.3f\n",salario);
		break;
	}

   }while(codigo>0);

}
