#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"


int main(){
    srand(time(0));

    int accion=1 ,X ,Y ,FormaExpl ,Tamaño ,n ,NumTurno = 1;
    
    Bomba* Bomb = (Bomba*)malloc(sizeof(Bomba));

    while (CantTesoros > 0 || NumTurno == 1){ //sacar el numtur, que pasa si canttesoro es = 0?
        if (NumTurno == 1){
            printf("Bienvenido a TreasureFinder!\n\nPorfavor, Indicar el tamaño del tablero a jugar:\n\n1.7x7 2.10x10 3.12x12\n\nSu Elección: ");
            scanf("%d",&n);
            if(n==1){
                Tamaño=7;   
            }else if(n==2){
                Tamaño=10;    
            }
            else if(n==3){
                Tamaño=12;    
            }
            IniciarTablero(n);
            printf("Comenzando el juego...\n\n");
        }

        if(accion != 3 && accion != 2){ //Para no repetir la matriz mas de 1 vez
            printf("Tablero (Turno %d)\n", NumTurno);
            MostrarTablero();
        }
        
        printf("\nSeleccione una accion: \n1.Colocar Bomba 2.Mostrar Bombas 3.Mostrar Tesoros\nEscoja una opcion: ");
        scanf("%d",&accion);
        printf("\n\n");

        if(accion==1){ 
            printf("Indique coordenadas de la bomba:\n\nFila:");
            scanf("%d",&X);
            printf("\n");
            printf("Columna:");
            scanf("%d",&Y);
            printf("\n");
            printf("Indique la forma en que explota la bomba:\n\n1.Punto 2.X\n\nSu input:");
            scanf("%d",&FormaExpl);
            printf("\n");
            if(FormaExpl==1){
                Bomb->explotar = ExplosionPunto; 
            }else if(FormaExpl==2){
                Bomb->explotar=ExplosionX;   
            }
            ColocarBomba(Bomb, X, Y);
            PasarTurno();
        }else if(accion==2){
            MostrarBombas();
        }else if(accion==3){
            VerTesoros();
        }
        NumTurno++;
    }   
   
    printf("Ha encontrado todos los tesoros y por ende a ganado!\n\n");
    MostrarTablero();
            
    
    free(Bomb); 
    BorrarTablero();
}
