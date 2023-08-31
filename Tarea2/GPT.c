#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_MAX 10

// Enumeración para representar el tipo de contenido de una celda
typedef enum {
    Tierra,
    Vida1,
    Vida2,
    Vida3,
    Tesoro
} ContenidoCelda;

// Función para generar un valor aleatorio entre min y max
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para inicializar el tablero
void IniciarTablero(int n, ContenidoCelda tablero[TAMANO_MAX][TAMANO_MAX], int es_tesoro) {
    srand(time(NULL)); // Inicializar generador de números aleatorios

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = Tierra; // Inicializar con Tierra por defecto

            if (es_tesoro && rand_int(1, 100) <= 5) {
                tablero[i][j] = Tesoro; // 5% de probabilidad de ser un tesoro
            } else {
                int vida_prob = rand_int(1, 3); // Generar valor de vida aleatorio
                tablero[i][j] = vida_prob; // Asignar valor de vida
            }
        }
    }
}

// Función para imprimir el tablero
void ImprimirTablero(int n, ContenidoCelda tablero[TAMANO_MAX][TAMANO_MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5; // Tamaño del tablero
    ContenidoCelda tablero[TAMANO_MAX][TAMANO_MAX]; // Matriz para el tablero

    IniciarTablero(n, tablero, 1); // Inicializar tablero con posibilidad de tesoro

    ImprimirTablero(n, tablero); // Imprimir tablero

    return 0;
}