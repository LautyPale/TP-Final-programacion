#include "sistema.h"

/// Constantes ///

const char archivoClientes[] = "Clientes";
const char archivoProductos[] = "Productos";
const char archivoPedidos[] = "Pedidos";

/// Estructuras ///

typedef struct{
char nombre[30];
char apellido[30];
char mail[40]; /// 0 a 255 ASCII | especificador de formato: %c
unsigned long int telefono; /// 0 a 4,294,967,295 | especificador de formato: %lu
int dni;
char calleDireccion[50];
int calleNumero;
int idCliente;
int bajaCliente;
}stCliente;

typedef struct{
char nombreproducto[30];
int idproducto;
float precioproducto;
}stProducto;

typedef struct{
char descripcion[70];
float costopedido;
int idpedido;
char fechapedido[10];
int pedidoanulado;
}stPedido;

/// Funciones ///

void crearCliente ()
{
    FILE *buffer = fopen(archivoClientes, "rb");
    stCliente aux;
    int cantClientes = 0;
    int i = 0;

    if (buffer == NULL)
    {
        fclose(buffer);

        buffer = fopen(archivoClientes, "ab");

        printf("Cuantos clientes desea cargar: ");
        scanf("%d", &cantClientes);

        for (i = 0; i < cantClientes; i++);
        {
            printf("Ingrese los datos del cliente %d:", i+1);
            aux = cargarCliente()
            fwrite(&aux, sizeof(stCliente), 1, buffer);
            system("cls");
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo ya existe.")
        fclose(buffer);
    }
}

void crearProducto ()
{
    FILE *buffer = fopen(archivoProductos, "rb");
    stProducto aux;
    int cantProductos = 0;
    int i = 0;

    if (buffer == NULL)
    {
        fclose(buffer);

        buffer = fopen(archivoClientes, "ab");

        printf("Cuantos productos desea cargar: ");
        scanf("%d", &cantProductos);

        for (i = 0; i < cantClientes; i++);
        {
            printf("Ingrese los datos del producto %d:", i+1);
            aux = tiposProductos(aux);
            fwrite(&aux, sizeof(stProducto), 1, buffer);
            system("cls");
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo ya existe.")
        fclose(buffer);
    }
}

void crearPedido (int idCliente)
{
    FILE *buffer = fopen(archivoPedidos, "rb"); /// abro el archivo de pedidos para agregar algun pedido si se cumple el while de abajo
    FILE *buffer = fopen(archivoClientes, "rb"); /// abro el archivo de clientes para comparar todos los id de clientes con el pedido por parametro
    stPedido aux;
    stCliente buscarId;
    int flag = 0;

    while ( (fread(&buscarId, sizeof(stCliente), 1, buffer) ) > 0 )
    {
        if ( buscarId.idCliente == idCliente )
        {
            flag = 1;
        }
    }

    if (flag == 1)
        if (buffer == NULL)
        {
            fclose(buffer);

            buffer = fopen(archivoPedidos, "ab");

            aux = cargarPedido(aux);

            fwrite(&aux, sizeof(stProducto), 1, buffer);
            system("cls");

            fclose(buffer);
        }
        else
        {
            printf("El archivo ya existe.")
            fclose(buffer);
        }
    }
    else
    {
        printf("El cliente no existe o el ID es incorrecto");
    }
}

stCliente cargarCliente(stCliente cliente)
{
    printf("Ingrese el ID: ");
    scanf("%d", &cliente.idCliente);

    printf("Ingrese el nombre del cliente: ");
    fflush(stdin);
    gets(cliente.nombre);

    printf("Ingrese el apellido del cliente: ");
    fflush(stdin);
    gets(cliente.apellido);

    printf("Ingrese el mail del cliente: ");
    fflush(stdin);
    gets(cliente.mail);

    printf("Ingrese el telefono del cliente: ");
    scanf("%lu", &cliente.telefono);

    printf("Ingrese el DNI del cliente: ");
    scanf("%d", &cliente.dni);

    printf("Ingrese la direccion del cliente (calle): ");
    fflush(stdin);
    gets(cliente.calleDireccion);

    printf("Ingrese la direccion del cliente (numero): ");
    scanf("%d", &cliente.calleNumero);

    cliente.bajaCliente = 0;

    return cliente;
}

stProducto tiposProductos (stProducto producto)
{
    printf("Ingrese el nombre del producto: ");
    fflush(stdin);
    gets(producto.nombreproducto);

    printf("Ingrese el ID del producto: ");
    scanf("%d", &producto.idproducto);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto.precioproducto);

    return producto;
}

stPedido cargarPedido (stPedido pedido)
{
    int idCliente;

    printf("Ingrese el ID del cliente: ");
    scanf("%d", &idCliente);

    return pedido;
}
