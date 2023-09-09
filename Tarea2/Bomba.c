#include "Bomba.h"
#include "Tierra.h"
#include "Tablero.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

extern int dimension;
extern char** MatrizBTD;

/*TryExplotar()
/******/
/*int fila: recibe un entero de la fila en la cual se hara la funcion
/*int columna: recibe un entero de la columna en la cual se hara la funcion
/******/
/*
Se declara Bomb, para facilitar el manejo de la bomba deseada, luego a travez de condicionales se verifica el tipo de bomba para entrar a la funcion
de su tipo, si es que no estan aun listas para explotar, se les reduce la vida.
*/

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

/*BorrarBomba()
/******/
/*int fila: recibe un entero de la fila en la cual se hara la funcion
/*int columna: recibe un entero de la columna en la cual se hara la funcion
/******/
/*
Gracias a la declaracion de bomb, se devuelve la tierra donde alguna vez estuvo, sacandola del struct de la bomba, para luego verificar a travez de
condicionales y la MatrizBTD, que si es que hubo tesoro ahi, que la MatrizBTD vuelva a 'T' de lo contrario que vuelva a ' '
*/

void BorrarBomba(int fila, int columna){    
    Bomba* Bomb = (Bomba*)tablero[fila][columna];
    tablero[fila][columna] = Bomb->tierra_debajo;
    if(MatrizBTD[fila][columna]=='D'){
        MatrizBTD[fila][columna]='T';
    }else{
        MatrizBTD[fila][columna]=' ';
    }

    free(Bomb);
    return;
}

/*ExplosionPunto()
/******/
/*int fila: recibe un entero de la fila en la cual se hara la funcion
/*int columna: recibe un entero de la columna en la cual se hara la funcion
/*
A travez de Bomb, se reduce la vida de la tierra, siendo este daño de 3 la vida queda en 0, luego llama a la funcion BorrarBomba
*/

void ExplosionPunto(int fila, int columna){
    Bomba* Bomb =(Bomba*)tablero[fila][columna];
    Bomb->tierra_debajo->vida = 0;
    BorrarBomba(fila,columna);
    return;
}

/*ExplosionX()
/******/
/*int fila: recibe un entero de la fila en la cual se hara la funcion
/*int columna: recibe un entero de la columna en la cual se hara la funcion
/******/
/*
Se declaran variables enteros, para luego restarle la vida a la posicion donde esta la bomba, luego a travez de una matriz para obtener las coordenadas 
en forma de X, entrando al bucle, generamos las nuevas direcciones, hasta 4 veces para poder generar la X, si las coordenadas se salen de la matriz se
ajustan a las dimensiones de la matriz, luego de esto, se declara tierraX, que sera las diagonales que se les quitara vida, terminando el for
verificamos que tipo era con MatrizBTD, para concluir con BorrarBomba()
*/

void ExplosionX(int fila, int columna){
    int filaX,columnaX;

    ((Bomba*)tablero[fila][columna])->tierra_debajo->vida -= 1;
    
    int formaX[4][2] = {
        {-1, -1}, 
        {-1, 1}, 
        {1, -1}, 
        {1, 1}
    };

    for (int i = 0; i < 4; i++) {
        filaX = fila + formaX[i][0];
        columnaX = columna + formaX[i][1];

        if (filaX < 0) {
            filaX = dimension - 1;
        } else if (filaX >= dimension) {
            filaX = 0; 
        }
        
        if (columnaX < 0) {
            columnaX = dimension - 1; 
        } else if (columnaX >= dimension) {
            columnaX = 0; 
        }

        Tierra* tierraX = (Tierra*)tablero[filaX][columnaX];
        tierraX->vida -=1;
        if(tierraX->vida<=0){
            tierraX->vida=0;
        }
        
    }
    if(MatrizBTD[fila][columna]=='D'){
        MatrizBTD[fila][columna]='T';
    }else{
        MatrizBTD[fila][columna]=' ';
    }
    BorrarBomba(fila,columna);
    return;
}
 