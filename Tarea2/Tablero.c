#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include<stdlib.h>
#include<stdio.h>

void*** tablero;
int dimension;

void IniciarTablero(int n){
    if(n = 1){
        printf("HOla");
        tablero = (void***)malloc(7*sizeof(void**));
        for(int i = 0; i < 7;i++)
            tablero[i]=(void**)malloc(7*sizeof(void*));
    }   
    else if(n=2){
        //Tablero 10x10
    }
    else{
        //Tablero 12x12
    }   
    return;
}

void PasarTurno(){
    // Su codigo
    return;
}


void ColocarBomba(Bomba* b, int fila, int columna){
    // Su codigo
    return;
}


void MostrarTablero(){
    // Su codigo
    return;
}


void MostrarBombas(){
    // Su codigo
    return;
}


void VerTesoros(){
    // Su codigo
    return;
}


void BorrarTablero(){
    // Su codigo
    return;
}