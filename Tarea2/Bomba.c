#include "Bomba.h"
#include "Tierra.h"
#include "Tablero.h"
#include<stdlib.h>
#include<stdio.h>

extern int dimension;
extern char** MatrizBomba;

void TryExplotar(int fila, int columna){
    Bomba* Bomb=(Bomba*)tablero[fila][columna];
    if(Bomb->explotar==ExplosionPunto && Bomb->contador_turnos == 0){
        ExplosionPunto(fila,columna);
    }else if(Bomb->explotar== ExplosionX && Bomb->contador_turnos == 0){
        ExplosionX(fila,columna);   
    }else{
        Bomb->contador_turnos -= 1;
    }
    return;
}

void BorrarBomba(int fila, int columna){    
    Bomba* Bomb = (Bomba*)tablero[fila][columna];
    tablero[fila][columna] = Bomb->tierra_debajo;
    if(MatrizBomba[fila][columna]=='D'){
        MatrizBomba[fila][columna]='T';
    }else{
        MatrizBomba[fila][columna]=' ';
    }

    free(Bomb);
    return;
}

void ExplosionPunto(int fila, int columna){
    Bomba* Bomb =(Bomba*)tablero[fila][columna];
    Bomb->tierra_debajo->vida = 0;
    BorrarBomba(fila,columna);
    return;
}

void ExplosionX(int fila, int columna){
    ((Tierra*)tablero[fila][columna])->vida-=1;

    int desplazamientos[8][2] = {
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, // Celdas d
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}    // Celdas h y v
    };

    for (int i = 0; i < 8; i++) {
        int fila_actual = fila + desplazamientos[i][0];
        int columna_actual = columna + desplazamientos[i][1];

        
        if (fila_actual < 0) {
            fila_actual = dimension - 1; // Vuelve al extremo inferior
        } else if (fila_actual >= dimension) {
            fila_actual = 0; // Vuelve al extremo superior
        }
        if (columna_actual < 0) {
            columna_actual = dimension - 1; // Vuelve al extremo derecho
        } else if (columna_actual >= dimension) {
            columna_actual = 0; // Vuelve al extremo izquierdo
        }

        Tierra* tierraX = (Tierra*)tablero[fila_actual][columna_actual];
        tierraX->vida -=1;
        if(tierraX->vida<=0){
            tierraX->vida=0;
        }
        
    }
    if(MatrizBomba[fila][columna]=='D'){
        MatrizBomba[fila][columna]='T';
    }else{
        MatrizBomba[fila][columna]=' ';
    }
    BorrarBomba(fila,columna);
    return;
}
 