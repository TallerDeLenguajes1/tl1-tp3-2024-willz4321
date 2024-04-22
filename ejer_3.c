#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarNombres(char *nombres[], int cantidad);
void listarNombres(char *nombres[], int cantidad);
int obtenerCantidadNombres();

int main(int argc, char const *argv[]) {
    int cantidadNombres = obtenerCantidadNombres();
    char *nombres[cantidadNombres];
    char *Buff;

    Buff = (char *)malloc(100 * sizeof(char));

    cargarNombres(nombres, cantidadNombres);
    listarNombres(nombres, cantidadNombres);

    free(Buff);

    return 0;
}
int obtenerCantidadNombres() {
    int cantidad;
     printf("Ingrese la cantidad de nombres: ");
     scanf("%d",cantidad);
     return cantidad;
}

void cargarNombres(char *nombres[], int cantidad) {
    char *Buff;
    Buff = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(Buff);
        nombres[i] = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombres[i], Buff);
    }

    free(Buff);
}

void listarNombres(char *nombres[], int cantidad) {
    printf("\nNombres almacenados:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre [%d]: %s\n", i + 1, nombres[i]);
    }
}
