#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};
struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    struct Producto *Productos;
};

void cargarClientes(struct Cliente *clientes, int cantidadClientes);
void generarProductos(struct Producto *productos, int cantidad);
float calcularCostoTotal(struct Producto producto);
void mostrarInformacion(struct Cliente *clientes, int cantidadClientes);

int main() {
    srand(time(NULL));

    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    getchar(); 

    struct Cliente *clientes = malloc(cantidadClientes * sizeof(struct Cliente));

    cargarClientes(clientes, cantidadClientes);
    mostrarInformacion(clientes, cantidadClientes);

    // Liberar memoria
    for (int i = 0; i < cantidadClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}

void cargarClientes(struct Cliente *clientes, int cantidadClientes) {
    for (int i = 0; i < cantidadClientes; i++) {
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        char nombre[100];
        gets(nombre);
        clientes[i].NombreCliente = strdup(nombre);

        clientes[i].ClienteID = i + 1;
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));

        generarProductos(clientes[i].Productos, clientes[i].CantidadProductosAPedir);
    }
}

void generarProductos(struct Producto *productos, int cantidad) {
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

    for (int i = 0; i < cantidad; i++) {
        productos[i].ProductoID = i + 1;
        productos[i].Cantidad = rand() % 10 + 1;            
        productos[i].TipoProducto = TiposProductos[rand() % 5]; 
        productos[i].PrecioUnitario = (rand() % 91) + 10; 
    }
}

float calcularCostoTotal(struct Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}

void mostrarInformacion(struct Cliente *clientes, int cantidadClientes) {
    for (int i = 0; i < cantidadClientes; i++) {
        printf("Cliente %d - Nombre: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
        float totalPagar = 0.0;
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("  Producto %d:\n", j + 1);
            printf("    ProductoID: %d\n", clientes[i].Productos[j].ProductoID);
            printf("    Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("    TipoProducto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("    PrecioUnitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            float costoTotal = calcularCostoTotal(clientes[i].Productos[j]);
            printf("    Costo total: %.2f\n", costoTotal);
            totalPagar += costoTotal;
        }
        printf("  Total a pagar: %.2f\n", totalPagar);
    }
}
