/* Autor:Oscar Eduardo FLetes Ixta, 07/04/22
	hacer un programa que utilice la estructura de alumno yalmacene los datos de 10 alumnos
	Debe tener el siguiente menu:
		-0.Salir
		1.Agregar alumnos
		2.Imprimr
		3.Alumnos Aprobados
		4.Alumnos Reprobados
		5.Promedio del grupo
		6.porcentaje de alumnos Aprobados
	
	Programa en lenguaje c, que utiliza la estructura de un alumno y almacena los datos de los alumnos, y tienela opcion de,
	agregar alumnos, imprmir los datos, imprime a los aprobados, reprobados, promdio del grupo y porcentaje, con el uso de
	estructuras, prototipos de funciones, switch, uso de milibreria.h
	
	Autor: Oscar Eduardo Fletes Ixta
	Escuela: UVM Campus Lomas Verdes
	Materia: Programcion Estructurada
	CICLO: 01/2022

	Programa en lenguaje c que muestra el uso de:
		* Declaracion de variables 
		* Variables del tipo char, float, int
		* Operaciones aritmeticas  
		* Uso de estrcturas
		* Uso de condiciones
		* uso de la libreria String.h
		* Funciones para cadenas de caractres
		* Funciones con parametros
		* Prototipos de funciones
		* Uso de milibreria.h para validacion de datos
		* Ciclo while
		* Ciclo do-while
		* Ciclo for 
		* printf para monstrar los valroes de las variables

	Objetivo:
	Mostrar el uso de variables char, float y int, condiciones, uso de la libreria string, milibreria.h, funciones para 
	cadenas de caracteres, uso de funciones con parametros, prototipos de funciones, ciclo while, ciclo for, realizar 
	operaciones aritmeticas e imprimirla.

	Breve descripcion:
	El programa  pide como entrada un menu para que tiene como opciones, agregar, imprimir, alumnos aprobados, 
	alumnos reprobados,promedio del grupo, porcentaje de los alumnos reprobados, alseleccionar la opcon 1(agregar) 
	pide 3 variable del tipo char, float, int(Nombre, promedio, faltas), se insertan, y ya se puede realizar lo demas del menu
	*/
	
#include<stdio.h>//libreria para el cuerpo de c
#include<stdlib.h>//libreria para prototipos de funciones, codigo ascii, entre otras mas funciones
#include<string.h>//libreria para uso de funciones para cadenas de caarcteres
#include "milibreria.h"//libreria que se creo para valdiar datos
//declaraciones globales
#define MAX 10 //macros
struct alumno{//uso de estrcturas
	char nombre[30];//variable de cadenas de 30 caracteres 
	float promedio;//variable con decimales
	int faltas;//variables de enteros 
};
//variable global
int n=0; //variable que dice cuantos alumnos hay en el arreglo
//Prototipos
int menu();
void agregar(struct alumno x[]);//Funcion con parametros 
void imprimir(struct alumno x[], int tipo);//Funcion con parametros 
void promgrupo(struct alumno x[]);//Funcion con parametros 
void porcentaje(struct alumno x[]);//Funcion con parametros 
//Principal
int main(){
	int opcion;//variables de enteros
	struct alumno grupo[MAX];//llama a la estrcutura para dos alumnos con MAX
	do{//ciclo do-while
		opcion=menu();//llamar a la funcion menu
		switch(opcion){//switch
			case 0: printf("Nos vemos...\n");//imprime mensaje 
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 1: agregar(grupo);//ejecuta la funcion agregaer con sus parametros
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 2: imprimir(grupo,0);//ejecuta la funcion imprimir todos los alumnos con sus parametros
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 3: imprimir(grupo,1);//ejecuta la funcion imprimir los alumnos que aprpobaron con sus parametros
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 4: imprimir(grupo,2);//ejecuta la funcion imprimir los alumnos que reprobaron con sus parametros
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 5: promgrupo(grupo);//ejecuta la funcion promedio del grupo con sus parametros
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 6: porcentaje(grupo);//ejecuta la funcion porcentaje de alumnos aprobados con sus parametros
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
		}
	}while(opcion!=0);//do-while termina cuando se inserta un numero diferente de 0
	return 0;
}

int menu(){
	int opcion;//variables de enteros
	printf("-----------MENU PRINCIPAL-----------\n");//imprime mensaje
	printf("0. Salir\n");//imprime mensaje
	printf("1. Agregar alumnos\n");//imprime mensaje
	printf("2. Imprimir\n");//imprime mensaje
	printf("3. Alumnos Aprobados\n");//imprime mensaje
	printf("4. Alumnos Reprobados\n");//imprime mensaje
	printf("5. Promedio del grupo\n");//imprime mensaje
	printf("6. porcentaje de alumnos Aprobados\n");//imprime mensaje
	printf("------------------------------------\n");//imprime mensaje
	opcion=leerd("Selecciona una opcion: ",0,6); //valida que el menu solo acepte de 0-6
	return opcion;
}

void agregar(struct alumno x[]){//funcion agregaer(parametros)
	int pregunta;//variables de enteros
	while(n<MAX){//ciclo while que indica que mientras n sea menor que MAX (10 alumnos)
		leers("Nombre: ",x[n].nombre,30);//Validacion de caracteres maximo 30 caracteres
		x[n].promedio=leerF("Promedio: ",0,10);//Validacion del promedio 0-10
		x[n].faltas=leerd("Faltas: ",0,32);//Validacion de las faltas 0-32
		pregunta=leerd("Agregar otro alumno? (1-si, 0-no): ",0,1);//pregunta que si quiere agregar otro alumno
		n++;//contador de los alumnos
		if(pregunta==0){//condicion, si pregunta es igual a 0 se termina el while 
			break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
		}
	}
	if(n==MAX){//condicon, si n es igual a max
		printf("Arreglo lleno!!!\n");//imprime mensaje
		system("PAUSE");//pausa el programa, se reanuda dando clic en cualquier tecla 
	}
}
//La funcion imprimir en el parametro tipo se le indica lo que va a imprimir
//0 a todos, 1 aprobados,2 reprobados
void imprimir(struct alumno x[], int tipo){//funcion imprimir(parametros)
	char mensaje[20];//variable de cadenas de 20 caracteres
	switch(tipo){//switch
		case 0: strcpy(mensaje,"TOTALES   ");// si tipo es igual 0 copia el texto totales  
				break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
		case 1: strcpy(mensaje,"APROBADOS ");// si tipo es igual 1 copia el texto aprobados
				break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
		case 2: strcpy(mensaje,"REPROBADOS");// si tipo es igual 2 copia el texto reprobados
				break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
	}
	printf("ALUMNOS %S---------------\n",mensaje);//imprime alumnos mas el tipo que se seleccione (0,1,2)
	printf("No.\tNOMBRE  \t\tFALTAS\tPROM\n");//imprime mensaje
	printf("---------------------------------------\n");//imprime mensaje
	for(int i=0;i<n;i++){//ciclo for para contar todos los alumnos
		switch(tipo){//switch para imprimir
			case 0: printf("%2d\t%-30s\t%2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);//imprime el numero del alumno, las faltas y el promedio
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 1: if(x[i].promedio>=7 && x[i].faltas <=6){//condicion, si el promedio es mayor o igual a 7 y si faltas es menor o igual a 6, alumnos aprobados
						printf("%2d\t%-30s\t%2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);//imprime el numero del alumno, las faltas y el promedio
					}
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
			case 2: if (x[i].promedio >7 && x[i].faltas >6){//condicion, si el promedio es menor a 7 y si faltas es mayor a 6, alumnos reprobados y el programa les cambia automaticamente 5
						x[i].promedio=5;//5 automatico
						printf("%2d\t%-30s\t%2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);//imprime el numero del alumno, las faltas y el promedio
						break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
					}if(x[i].promedio<7 && x[i].faltas <6 || x[i].promedio >7 && x[i].faltas >6){
						//condicio, si promedio es menor que 7 y faltas es menor que 6 o promedio es mayor que 7 y faltas mayor que 6, reprobados con la calificacion ya insertada 
						printf("%2d\t%-30s\t%2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);//imprime el numero del alumno, las faltas y el promedio
					}
					break;//Es para que termine la iteraccion en ejecucucion y volver al principio, para realizar otra iteraccion
		}
		
	}//-30 pone el nombre a la izq
	printf("----------------------------------\n");//imprime mensaje
	system("PAUSE");//pausa el programa, se reanuda dando clic en cualquier tecla 
}

void promgrupo(struct alumno x[]){//funcion promedio del grupo(parametros)
	float suma=0, promedio1=0; //variables con decimal 
	int i=0;//variables de enteros
	for(int i=0;i<n;i++){//ciclo for para acumular los promedios
		suma=suma+x[i].promedio;//sumar los promedios 
	}
	promedio1=suma/n;//Calcula el promedio 
	printf("El promedio del grupo es: %4.1f\n",promedio1);//imprime el promedio 
	system("PAUSE");////pausa el programa, se reanuda dando clic en cualquier tecla 
}

void porcentaje(struct alumno x[]){//funcion porcentaje de alumnos aprobados(parametros)
	float porcentaje=0; //variables con decimal
	int apr=0;//variables de enteros
	for(int i=0;i<n;i++){//ciclo for para acumular los alumnos aprobados 
		if(x[i].promedio>=7 && x[i].faltas <=6){//condicion, si el promedio del alumno es mayor o igual a 7 y si las faltas son menor o igual a 6
			apr++;//cuenta los aprobados 
		}
	}
	porcentaje=(apr*100)/n;//calcula el porcentaje de los aprobados 
	printf("El porcentaje de alumnos aprobados es: %4.2f%%\n",porcentaje);//imprime el porcentaje 
}
