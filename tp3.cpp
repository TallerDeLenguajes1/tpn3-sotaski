#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
     int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;


Cliente CargarCliente(Cliente comprador,  int id);
Producto CargarProducto(Producto _producto);
float costo (Cliente UnCliente, char producto);

int main(){

    int cantClientes = 0;
    printf("ingrese la cantidad de clientes del uno al cinco");
    scanf("%d", &cantClientes);
    getchar();
    Cliente *compradores = (Cliente *) malloc(sizeof(Cliente)*cantClientes);
    for (int i = 0; i < cantClientes; i++)
    {
        compradores[i] = CargarCliente(compradores[i] , i+1);
    }
    //-------------------PUNTO 4----------------
    float _costo = 0;
    char *product = "Galletas";
    _costo = costo(compradores[1], *product);
    printf("El colsto total de %c es: %.2f\n", product, _costo);

    return 0;
}

Cliente CargarCliente(Cliente comprador, int id){
    int cantProduc = 0;
    char nombre[100];
    comprador.ClienteID = id;
    puts("\nIngrese el nombre del cliente: \n");
    fflush(stdin);
    gets(nombre);
    int tamanio = strlen(nombre);
    comprador.NombreCliente= (char *) malloc(sizeof(char)*tamanio);
    strcpy(comprador.NombreCliente, nombre); 
    fflush(stdin);
    comprador.CantidadProductosAPedir = 1 + rand()%5;
    printf("\n%d \n", comprador.CantidadProductosAPedir);
    
   // comprador.CantidadProductosAPedir = cantProduc;
    Producto *productos = (Producto*) malloc(sizeof(Producto)* comprador.CantidadProductosAPedir );
    Producto nuevo;
    for (int j = 0; j < comprador.CantidadProductosAPedir; j++)
    {   printf("%d\n", j);
        productos[j] = CargarProducto(nuevo);
        printf("-----");
    }
    
     printf("-|||||||-||||-|||-||||-");
     comprador.Productos = productos; 

    return comprador;
}

Producto CargarProducto(Producto _producto){
    printf("ID: ");
    
    scanf("%d", &_producto.ProductoID);
    
    printf("Ingrese la cantidad del producto(1 a 10): ");
    scanf("%d", &_producto.Cantidad);
    int tipo = 0;
    printf("tipo de producto(1 a 4): ");printf("asdsde---------e");
    fflush(stdin);
    scanf("%d", &tipo);
    int tamanio = strlen(TiposProductos[tipo-1]);
    _producto.TipoProducto = (char*) malloc(sizeof(char)*tamanio);
    
    strcpy(_producto.TipoProducto, TiposProductos[tipo-1]);
    int precio = rand()%(10,100);
    _producto.PrecioUnitario = precio;
    
    return _producto;
}

float costo (Cliente UnCliente, char producto){
    float cost = 0;
    for (int i = 0; i < UnCliente.CantidadProductosAPedir; i++)
    {
        if ( producto == *(UnCliente.Productos->TipoProducto))
        {
            cost = cost + UnCliente.Productos->PrecioUnitario;
            
        }
        UnCliente.Productos->TipoProducto++;           
    }
    return cost;
    
}
