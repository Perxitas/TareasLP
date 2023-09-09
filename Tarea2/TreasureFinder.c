#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

/*main()
Declarando varios enteros y asignando memoria a la variable Bomb, entra a un while, el cual detecta que la CantTesoros siempre este arriba de 0,
empezando por una bienvenida si es que estamos en el primer turno, preguntamos el tamaño de la tabla, luego verifica que la accion sea 1 (evita repetir
la matriz si es que se selecciono 2 o 3),luego si la accion es 2 o 3 para sus respectivas funciones,si no se sigue pidiendo informacion y asi llamar 
finalmente a la funcion ColocarBomba, incrementa los Turnos y se vuelve al loop.
Al salir del while, se gana el juego al haber encontrado todos los tesoros(o se gana instantaneamente si no se genero ninguno).
*/
int main(){
    srand(time(0));

    int accion=1 ,X ,Y ,FormaExpl ,Tamaño ,n ,NumTurno = 1;
    
    Bomba* Bomb = (Bomba*)malloc(sizeof(Bomba));

    while (CantTesoros > 0 || NumTurno==1){
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
   
    printf("Ha encontrado todos los tesoros y por ende a ganado!\n\nTabla Final:\n\n");
    MostrarTablero();
            
    BorrarTablero();
    free(Bomb);
}
