#include "sistema.h"

///-------------------------------------------------------------- CONSTANTES --------------------------------------------------------------///

const char archivoClientes[] = "Clientes";
const char archivoProductos[] = "Productos";
const char archivoPedidos[] = "Pedidos";

///-------------------------------------------------------------- ESTRUCTURAS --------------------------------------------------------------///

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

///-------------------------------------------------------------- FUNCIONES DE CLIENTES --------------------------------------------------------------///

void altaCliente ()
{
    FILE *buffer = fopen(archivoClientes, "a+b");
    stCliente aux;
    stCliente nuevo;
    int cantClientes = 0;
    int i = 0;

    if (buffer != NULL)
    {
        printf("Cuantos clientes desea cargar: ");
        scanf("%d", &cantClientes);

        for (i = 0; i < cantClientes; i++);
        {
            printf("Ingrese el DNI del cliente: ");
            scanf("%d", &nuevo.dni);

            while ( (fread (&aux, sizeof(stCliente), 1, buffer) ) > 0)
            {
                if (nuevo.dni == aux.dni)
                {
                    printf("El cliente ya existe");
                }
                else
                {
                    nuevo = cargarCliente(&nuevo.dni);
                    fwrite(&nuevo, sizeof(stCliente), 1, buffer);
                }
            }

            system("cls");
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo ya existe.");
    }
}

stCliente cargarCliente(int *dni)
{
    stCliente cliente;

    cliente.dni = (*dni);

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

    printf("Ingrese la direccion del cliente (calle): ");
    fflush(stdin);
    gets(cliente.calleDireccion);

    printf("Ingrese la direccion del cliente (numero): ");
    scanf("%d", &cliente.calleNumero);

    cliente.bajaCliente = 0;

    return cliente;
}

int bajaCliente (int idCliente)
{
    FILE *buffer = fopen(archivoClientes, "r+b");
    stCliente aux;
    aux.bajaCliente = 1;
    int flag = 0;
    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stCliente), 1, buffer) > 0 || idCliente == aux.idCliente)
        {
            fseek(buffer, stCliente*(-1), SEEK_CUR);
            fwrite(&aux.bajaCliente, sizeof(stCliente), 1, buffer);
            flag = 1;
        }
        fclose(buffer);
    }

    return flag;
}

///-------------------------------------------------------------- FUNCIONES DE PEDIDOS --------------------------------------------------------------///

void altaPedido (int idCliente)
{
    FILE *bufferPedido = fopen(archivoPedidos, "rb"); /// abro el archivo de pedidos para agregar algun pedido si se cumple el while de abajo
    FILE *bufferCliente = fopen(archivoClientes, "rb"); /// abro el archivo de clientes para comparar todos los id de clientes con el pedido por parametro
    stPedido aux;
    stCliente buscarId;
    int flag = 0;

    while ( (fread(&buscarId, sizeof(stCliente), 1, bufferCliente) ) > 0 )
    {
        if ( buscarId.idCliente == idCliente )
        {
            flag = 1;
        }
    }

    fclose(bufferCliente);

    if (flag == 1)
    {
        if (bufferPedido != NULL)
        {
            fclose(bufferPedido);
            bufferPedido = fopen(archivoPedidos, "ab");

            aux = cargarPedido(aux);

            fwrite(&aux, sizeof(stProducto), 1, buffer);
            system("cls");
        }
    }
    else
    {
        printf("El cliente no existe o el ID es incorrecto");
    }
    fclose(bufferPedido);
}

stPedido cargarPedido (stPedido pedido, int idCliente)
{
    return pedido;
}

///-------------------------------------------------------------- FUNCIONES DE PRODUCTOS --------------------------------------------------------------///

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

void crearProducto ()
{
    FILE *buffer = fopen(archivoProductos, "rb");
    stProducto aux;
    int cantProductos = 0;
    int i = 0;

    if (buffer != NULL)
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
    }
    else
    {
        printf("El archivo ya existe.")

    }
    fclose(buffer);
}

