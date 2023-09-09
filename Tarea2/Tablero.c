#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void*** tablero;
char** MatrizBTD;

int dimension;
int CantTesoros=0;

/*CreadorVida()
genera un numero aleatorio, entre 0 y 2, para luego ser sumado con 1 y retornar un numero random de rango 1 a 3
*/

int CreadorVida() {
    return (rand() % 3) + 1;
}

/*CreadorTesoro()
Gracias a rand(), crea un numero random, el cual se verifica si es el numero es menor o igual a 5, lo que se traduce en una probabilidad de 5%, donde
si se cumple, la CantTesoros aumentara y se retornara 1 (significando que si hay tesoro), de lo contrario se retornara 0
*/

int CreadorTesoro() {
    int random = rand() % 100;
    if (random <= 5) { 
        CantTesoros++;
        return 1; 
    }else{
        return 0; 
    }
}

/*IniciarTablero()
/*********/
/*int n: recibe un entero que indicara el tipo de matriz
/*******/
/*
Verificando el valor de n primero que nada, para saber la dimension de matriz (que tambien se declara globalmente), luego verificando nuevamente el n
se empieza la matriz a travez de bucles for y asignando espacios de memoria a travez de malloc, tanto para tablero como MatrizBTD, luego en otro bucle 
se asigna espacio de memoria para tierra para luego asignarle vida random y el tesoro con un 5% de probabilidad,  finalmente si existe un tesoro en 
la celda, se le asignara el char 'T' a MatrizBTD
*/

void IniciarTablero(int n) {
    int Vida;
    int i;
    int j;
    if (n == 1) {
        dimension = 7;
    } else if (n == 2) {
        dimension = 10;
    } else if (n == 3) {
        dimension = 12;
    }

    if (n == 1) {
        tablero = (void ***)malloc(7 * sizeof(void **));
        MatrizBTD = (char **)malloc(7 * sizeof(char *));

        for (int i = 0; i < 7; i++) {
            tablero[i] = (void **)malloc(7 * sizeof(void *));
            MatrizBTD[i] = (char *)malloc(7 * sizeof(char));

        }
    } else if (n == 2) {
        tablero = (void ***)malloc(10 * sizeof(void **));
        MatrizBTD = (char **)malloc(10 * sizeof(char *));

        for (int i = 0; i < 10; i++) {
            tablero[i] = (void **)malloc(10 * sizeof(void *));
            MatrizBTD[i] = (char *)malloc(10 * sizeof(char));

        }
    } else if (n == 3) {
        tablero = (void ***)malloc(12 * sizeof(void **));
        MatrizBTD = (char **)malloc(12 * sizeof(char *));

        for (int i = 0; i < 12; i++) {
            tablero[i] = (void **)malloc(12 * sizeof(void *));
            MatrizBTD[i] = (char *)malloc(12 * sizeof(char));

        }
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            Tierra *tierra = (Tierra *)malloc(sizeof(Tierra));
            tierra->vida = CreadorVida();
            tierra->es_tesoro = CreadorTesoro();

            tablero[i][j] = (void *)tierra;
            MatrizBTD[i][j] = ' ';

            if (((Tierra *)tablero[i][j])->es_tesoro == 1) {
                MatrizBTD[i][j] = 'T';
            }
        }
    }

    return;
}

/*PasarTurno()
A travez de dos bucles for, la matriz intenta encontrar las bombas y explotarlas, asi como verificar cuando se han encontrado tesoros, modificando la 
MatrizBTD y reduciendo la CantTesoros.
*/

void PasarTurno(){
    for(int i = 0;i<dimension;i++){
        for(int j = 0;j < dimension ;j++){
            if(MatrizBTD[i][j]=='B'|| MatrizBTD[i][j]=='D'){
                TryExplotar(i,j);
            }
            if(MatrizBTD[i][j]=='T' && ((Tierra*)tablero[i][j])->vida==0){
                CantTesoros-=1;
                MatrizBTD[i][j]=' ';
            }
            }
        }  
    return;
}

/*ColocarBomba()
/*********/
/*Bomba* b: es un puntero de la bomba la cual se entrega, para saber el tipo y asi manipularla
/*int fila: un entero de la fila donde se desea colocar
/*int columna: un entero de la columna donde se desea colocar
/*******/
/*
Esta funcion coloca bombas segun la entrada de filas y columnas, asi como el tipo, para luego definir la vida y colocar la tierra debajo de esta
copia el contenido para una direccion de memoria para finalmente colocarla en el tablero, asi como verificando si son un tesoro, para declarar 
que es una celda que contiene a ambos, o si no, simplemente definirlo como bomba
*/

void ColocarBomba(Bomba* b, int fila, int columna){
        fila -= 1;
        columna -= 1;
        Tierra* aux=(Tierra*)tablero[fila][columna]; 
        MatrizBTD[fila][columna];

        if(b->explotar==ExplosionPunto){
            b->contador_turnos = 1;
            b->tierra_debajo = aux;
            tablero[fila][columna]= malloc(sizeof(Bomba));
            memcpy(tablero[fila][columna],b,sizeof(Bomba));
            if(MatrizBTD[fila][columna]=='T'){
                MatrizBTD[fila][columna]='D'; //D significa que tiene bomba y tesoro
            }
            else{
                MatrizBTD[fila][columna]='B';
            }
        }
        else if(b->explotar==ExplosionX){ 
            b->contador_turnos = 3;
            b->tierra_debajo = aux;
            tablero[fila][columna]= malloc(sizeof(Bomba));
            memcpy(tablero[fila][columna],b,sizeof(Bomba));
            if(MatrizBTD[fila][columna]=='T'){
                MatrizBTD[fila][columna]= 'D'; //D significa que tiene bomba y tesoro
            }
            else{
                MatrizBTD[fila][columna]='B';
            }
        }   
        
    return;
}

/* MostrarTablero()
A travez de dos bucles for, obtiene informacion de las 2 matrices, para verificar cuadno hay tesoro descubierto, cuando la matrizBTD tiene bomba,
o cuando hay tierra y entrega la vida de esta, finalmente cada condicional permite printear la matriz en la forma del tablero del juego.
*/

void MostrarTablero(){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){   
            if(MatrizBTD[i][j]=='T' && ((Tierra*)tablero[i][j])->vida == 0){
                printf("*");

            }else if(MatrizBTD[i][j]=='B' || MatrizBTD[i][j]=='D'){
                printf("o");
            }
            else if(MatrizBTD[i][j]!='B'&& MatrizBTD[i][j]!='D'){
                printf("%d", ((Tierra*)tablero[i][j])->vida);
            }
            if (j < dimension - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
        
    return;
}

/* MostrarBombas()
A travez de dos bucles for, analizando la MatrizBTD, retorna de todas las bombas, sus turnos para explotar, las coordenadas, su tipo de explosion 
y finalmente la vida de la tierra que tienen debajo.
*/

void MostrarBombas(){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            if(MatrizBTD[i][j]=='B' || MatrizBTD[i][j]=='D'){
                printf("Turnos para explotar: %d\n\n",((Bomba*)tablero[i][j])->contador_turnos);
                printf("Coordenadas: %d %d\n\n",i+1,j+1);
                if(((Bomba*)tablero[i][j])->explotar==ExplosionPunto){
                    printf("Forma de explosion: ExplosionPunto\n\n");
                }else if(((Bomba*)tablero[i][j])->explotar==ExplosionX){
                    printf("Forma de explosion: ExplosionX\n\n");
                }
                printf("Vida de Tierra Debajo: %d\n",((Bomba*)tablero[i][j])->tierra_debajo->vida);
            }
        } 
    }
    return;
}

/* VerTesoros()
A travez de dos bucles de for, permite hacerle un seguimento a la MatrizBTD, para luego verificar que se encuentra dentro de la posicion i j en 
esa matriz, finalmente printea en forma del tablero de juego cada tesoro, bomba o vida.
*/

void VerTesoros(){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){ 
            if(MatrizBTD[i][j]=='T'){
                printf("*");
            }else if(MatrizBTD[i][j]=='B'|| MatrizBTD[i][j]=='D'){
                printf("o");
            }else{
                printf("%d", ((Tierra*)tablero[i][j])->vida);
            }
            if (j < dimension - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
    return;
}

/*
Libera la memoria asignada para las 2 matrices, a travez de dos bucles for para liberar cada celda del tablero, y luego 
liberando las filas tanto del tablero como de la matriz, para finalmente liberar la memoria asignada a tablero y MatrizBTD.
*/

void BorrarTablero(){
    for (int i = 0; i < dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            free(tablero[i][j]);
        }
        free(tablero[i]); 
        free(MatrizBTD[i]);
    }
    free(tablero);
    free(MatrizBTD);
    return;
}