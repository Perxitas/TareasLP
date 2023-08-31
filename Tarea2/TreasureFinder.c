#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"


int main(){
    int Tamaño=7;
    for (int i = 0; i < Tamaño; i++) {
        for (int j = 0; j < Tamaño; j++) {
            printf("Hola");
            int valor = *((int*)tablero[i][j]); // Convertir void* a int
            printf("%d", valor);
            if (j < Tamaño - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

/* EJEMPLOS DE RANDOM PARA FACILITAR SU USO.
*
*   srand(time(0)); // Setea la seed del random.
*   int ejemplo_vida = (rand() % 3) + 1; // Obtiene al azar la vida de Tierra a asignar.
*/