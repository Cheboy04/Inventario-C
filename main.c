#include <stdio.h>
#include <stdlib.h>

#define Productos 7
#define Descripcion 100
#define Nombre 50

void ingresoProducto(int id[Productos], float precio[Productos], int cantidad[Productos], char descripcion[Productos][Descripcion], char nombre[Productos][Nombre], int *numProductos) {
    if (*numProductos >= Productos) {
        printf("El inventario está lleno. No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese los datos del producto:\n");

    printf("ID: ");
    scanf("%d", &id[*numProductos]);

    printf("Precio: ");
    scanf("%f", &precio[*numProductos]);

    printf("Cantidad: ");
    scanf("%d", &cantidad[*numProductos]);

    printf("Descripción: ");
    fflush(stdin);  
    fgets(descripcion[*numProductos], Descripcion, stdin);
    descripcion[*numProductos][0] = '\0';  

    printf("Nombre: ");
    fgets(nombre[*numProductos], Nombre, stdin);
    nombre[*numProductos][0] = '\0'; 

    (*numProductos)++;
}

void editarProducto(int id[Productos], float precio[Productos], int cantidad[Productos], char descripcion[Productos][Descripcion], char nombre[Productos][Nombre], int numProductos) {
    int idProducto;
    int indiceProducto = -1;

    printf("Ingrese el ID del producto que desea editar: ");
    scanf("%d", &idProducto);


    for (int i = 0; i < numProductos; i++) {
        if (id[i] == idProducto) {
            indiceProducto = i;
            break;
        }
    }

    if (indiceProducto == -1) {
        printf("No se encontró un producto con el ID ingresado.\n");
        return;
    }

    printf("Ingrese los nuevos datos del producto:\n");

    printf("ID: ");
    scanf("%d", &id[indiceProducto]);

    printf("Precio: ");
    scanf("%f", &precio[indiceProducto]);

    printf("Cantidad: ");
    scanf("%d", &cantidad[indiceProducto]);

    printf("Descripción: ");
    fflush(stdin);
    fgets(descripcion[indiceProducto], Descripcion, stdin);
    descripcion[indiceProducto][0] = '\0';

    printf("Nombre: ");
    fgets(nombre[indiceProducto], Nombre, stdin);
    nombre[indiceProducto][0] = '\0'; 
}

void mostrarProductos(int id[Productos], float precio[Productos], int cantidad[Productos], char descripcion[Productos][Descripcion], 
char nombre[Productos][Nombre]) {
    printf("Productos ingresados:\n");
    printf("ID\tPrecio\tCantidad\tDescripción\t\tNombre\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%.2f\t%d\t\t%s\t\t\t%s\n", id[i], precio[i], cantidad[i], descripcion[i], nombre[i]);
    }
}

int main()
{
    int id[Productos]={1,2,3,4,5,6,7};
    float precio[Productos]={10,3.5,4.25,2,1.5};
    int cantidad[Productos]={12,20,7,15,25,16,30};
    char descripcion[Productos][Descripcion]={"RonAbu","Lark","Pepsi","Dasani","Bic"};
    char nombre[Productos][Nombre]={"ron","tabaco","cola","agua","fosforeras"};
    int numProductos = 0;

    int opcion;
    do {
        printf("\n");
        printf("----- MENU PRINCIPAL -----\n");
        printf("1. Ver productos ingresados\n");
        printf("2. Ingresar nuevo producto\n");
        printf("3. Modificar producto\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarProductos(id, precio, cantidad, descripcion, nombre);
                break;
            case 2:
                ingresoProducto(id, precio, cantidad, descripcion, nombre, &numProductos);
                break;
            case 3:
                editarProducto(id, precio, cantidad, descripcion, nombre, numProductos);
                break;
            case 4:
                printf("Programa cerrado.\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}