#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIOS 5
#define MESES 12
#define MIN 10000
#define MAX 50000

void valoresAleatorios(int min, int max, int produccion[ANIOS][MESES], float promedio[ANIOS], int* maxPtr, int* minPtr, int* maxAnio, int* maxMes, int* minAnio, int* minMes);
void mostrarValores(int produccion[ANIOS][MESES]);
void promedioGanacia(float promedio[ANIOS]);
void maxYmin(int max, int min, int maxAnio, int maxMes, int minAnio, int minMes);

int main() {
    int produccion[ANIOS][MESES];
    int max = MIN, min = MAX, maxAno, maxMes, minAno, minMes;
    float promedio[ANIOS] = {0};

    srand(time(NULL));

    // A. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
      valoresAleatorios(MIN, MAX, produccion, promedio, &max, &min, &maxAno, &maxMes, &minAno, &minMes);

    // B. Mostrar por pantalla los valores cargados
      mostrarValores(produccion);

    // C. Sacar el promedio de ganancia por año y mostrarlos por pantalla
      promedioGanacia(promedio);

     // D. Obtener el valor máximo y el valor mínimo obtenido informando el año y el mes de cuándo ocurrió
      maxYmin(max, min, maxAno, maxMes, minAno, minMes);

    return 0;
}

void valoresAleatorios(int min, int max, int produccion[ANIOS][MESES], float promedio[ANIOS], int* maxPtr, int* minPtr, int* maxAnio, int* maxMes, int* minAnio, int* minMes){
    for(int i = 0; i < ANIOS; i++) {
        for(int j = 0; j < MESES; j++) {
            produccion[i][j] = MIN + rand() % (MAX - MIN + 1);
            promedio[i] += produccion[i][j];

            if(produccion[i][j] > *maxPtr) {
                *maxPtr = produccion[i][j];
                *maxAnio = i;
                *maxMes = j;
            }

            if(produccion[i][j] < *minPtr) {
                *minPtr = produccion[i][j];
                *minAnio = i;
                *minMes = j;
            }
        }
    }
}

void mostrarValores(int produccion[ANIOS][MESES]){
printf("Valores cargados en la matriz:\n");
    for(int i = 0; i < ANIOS; i++) {
        for(int j = 0; j < MESES; j++) {
            printf("%d ", produccion[i][j]);
        }
        printf("\n");
    }
}

void promedioGanacia(float promedio[ANIOS]){
     printf("\nPromedio de ganancia por anio:\n");
    for(int i = 0; i < ANIOS; i++) {
        printf("Anio %d: %.2f\n", i+1, promedio[i]);
    }
}

void maxYmin(int max, int min, int maxAnio, int maxMes, int minAnio, int minMes){
    printf("\nValor maximo obtenido: %d en el anio %d, mes %d\n", max, maxAnio+1, maxMes+1);
    printf("Valor minimo obtenido: %d en el anio %d, mes %d\n", min, minAnio+1, minMes+1);
}