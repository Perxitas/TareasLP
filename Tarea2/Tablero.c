#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void*** tablero;
char** MatrizBomba;

int dimension;
int CantTesoros=0;

//COMENTAR
int CreadorVida() {
    return (rand() % 3) + 1;
}
//COMENTAR
int CreadorTesoro() {
    int random = rand() % 100;
    if (random <= 5) { 
        CantTesoros++;
        return 1; 
    }else{
        return 0; 
    }
}

void IniciarTablero(int n){
    int Vida;
    int i;
    int j;
    if(n==1){
        dimension=7;
    }else if(n==2){
        dimension=10;
    }else if(n==3){
        dimension=12;
    }
    
    if(n == 1){
        tablero = (void***)malloc(7*sizeof(void**));
        for(int i = 0; i < 7;i++){
            tablero[i]=(void**)malloc(7*sizeof(void*));
        }

        MatrizBomba = (char**)malloc(7*sizeof(char*));
        for(int i = 0; i < 7;i++){
            MatrizBomba[i]=(char*)malloc(7*sizeof(char));
        }

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                Tierra* tierra = (Tierra*)malloc(sizeof(Tierra)); // Crear una instancia de Tierra
                tierra->vida = CreadorVida();
                tierra->es_tesoro = CreadorTesoro();
                tablero[i][j] = (void*)tierra;
                if (((Tierra*)tablero[i][j])->es_tesoro == 1){
                    MatrizBomba[i][j]='T';
                }
            }
        }
        
    }
    else if(n==2){
        
        tablero = (void***)malloc(10*sizeof(void**));
        for(int i = 0; i < 10;i++)   
            tablero[i]=(void**)malloc(10*sizeof(void*));

        MatrizBomba = (char**)malloc(10*sizeof(char*));
            for(int i = 0; i < 10;i++){
                MatrizBomba[i]=(char*)malloc(10*sizeof(char));
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                Tierra* tierra = (Tierra*)malloc(sizeof(Tierra)); // Crear una instancia de Tierra
                tierra->vida = CreadorVida();
                tierra->es_tesoro = CreadorTesoro();
                tablero[i][j] = (void*)tierra;
                if (((Tierra*)tablero[i][j])->es_tesoro == 1){
                    MatrizBomba[i][j]='T';
                }
            }
        }
    }
    else if(n==3){
        tablero = (void***)malloc(12*sizeof(void**));
        for(int i = 0; i < 12 ;i++){  
            tablero[i]=(void**)malloc(12*sizeof(void*));
        }
        MatrizBomba = (char**)malloc(12*sizeof(char*));
            for(int i = 0; i < 12;i++){
                MatrizBomba[i]=(char*)malloc(12*sizeof(char));
        }

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                Tierra* tierra = (Tierra*)malloc(sizeof(Tierra)); // Crear una instancia de Tierra
                tierra->vida = CreadorVida();
                tierra->es_tesoro = CreadorTesoro();
                tablero[i][j] = (void*)tierra;
                if (((Tierra*)tablero[i][j])->es_tesoro == 1){
                    MatrizBomba[i][j]='T';
                }
            }
        }
    }   
    return;
}

void PasarTurno(){
    for(int i = 0;i<dimension;i++){
        for(int j = 0;j < dimension ;j++){
            if(MatrizBomba[i][j]=='B'|| MatrizBomba[i][j]=='D'){
                TryExplotar(i,j);
            }
            if(MatrizBomba[i][j]=='T' && ((Tierra*)tablero[i][j])->vida==0){
                CantTesoros-=1;
                MatrizBomba[i][j]=' ';
            }
            }
        }  
    return;
}


void ColocarBomba(Bomba* b, int fila, int columna){
        fila -= 1;
        columna -= 1;
        Tierra* aux=(Tierra*)tablero[fila][columna]; 
        MatrizBomba[fila][columna];

        if(b->explotar==ExplosionPunto){
            b->contador_turnos = 1;
            b->tierra_debajo = aux;
            tablero[fila][columna]= malloc(sizeof(Bomba));
            memcpy(tablero[fila][columna],b,sizeof(Bomba));
            if(MatrizBomba[fila][columna]=='T'){
                MatrizBomba[fila][columna]='D'; //D significa que tiene bomba y tesoro
            }
            else{
                MatrizBomba[fila][columna]='B';
            }
        }
        else if(b->explotar==ExplosionX){ 
            b->contador_turnos = 3;
            b->tierra_debajo = aux;
            tablero[fila][columna]= malloc(sizeof(Bomba));
            memcpy(tablero[fila][columna],b,sizeof(Bomba));
            if(MatrizBomba[fila][columna]=='T'){
                MatrizBomba[fila][columna]= 'D'; //D significa que tiene bomba y tesoro
            }
            else{
                MatrizBomba[fila][columna]='B';
            }
        }   
        
    return;
}


void MostrarTablero(){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){   
            if(MatrizBomba[i][j]=='T' && ((Tierra*)tablero[i][j])->vida == 0){
                printf("*");

            }else if(MatrizBomba[i][j]=='B' || MatrizBomba[i][j]=='D'){
                printf("o");
            }
            else if(MatrizBomba[i][j]!='B'&& MatrizBomba[i][j]!='D'){
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


void MostrarBombas(){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            if(MatrizBomba[i][j]=='B' || MatrizBomba[i][j]=='D'){
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


void VerTesoros(){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){ 
            if(MatrizBomba[i][j]=='T'){
                printf("*");
            }else if(MatrizBomba[i][j]=='B'|| MatrizBomba[i][j]=='D'){
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


void BorrarTablero(){
    for (int i = 0; i < dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            free(tablero[i][j]);
        }
        free(tablero[i]); 
        free(MatrizBomba[i]);
        free(tablero);
        free(MatrizBomba);
    }
    return;
}