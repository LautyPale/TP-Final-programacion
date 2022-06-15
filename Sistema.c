#include "Sistema.h"

///-------------------------------------------------------------- CONSTANTES --------------------------------------------------------------///

const char archivoClientes[] = "Clientes";
const char archivoProductos[] = "Productos";
const char archivoPedidos[] = "Pedidos";

///-------------------------------------------------------------- FUNCIONES DE CLIENTES --------------------------------------------------------------///

void altaCliente ()
{
    FILE *buffer = fopen(archivoClientes, "a+b");
    stCliente aux;
    stCliente nuevo;
    int cantClientes = 0;
    int i = 0;
    int flag = 0;

    if (buffer != NULL)
    {
        printf("Cuantos clientes desea cargar: ");
        scanf("%d", &cantClientes);

        for (i = 0; i < cantClientes; i++);
        {
            printf("Ingrese el DNI del cliente: ");
            scanf("%d", &nuevo.dni);

            while ( (fread (&aux, sizeof(stCliente), 1, buffer) ) > 0 && flag == 0)
            {
                if (nuevo.dni == aux.dni)
                {
                    flag = 1;
                }
            }

            if(flag == 1)
            {
                printf("\nEl cliente ya existe.\n");
            }
            else
            {

                fseek(buffer, sizeof(stCliente)*(-1), SEEK_END);
                if  ( (fread(&aux, sizeof(stCliente), 1, buffer) ) > 0 )
                {
                    nuevo.idCliente = aux.idCliente + 1;
                }
                else
                {
                    nuevo.idCliente = 1;
                }

                nuevo = cargarCliente(nuevo);
                fwrite(&nuevo, sizeof(stCliente), 1, buffer);
            }
        }
        system("cls");
        fclose(buffer);
    }
    else
    {
        printf("El archivo ya existe.");
    }
}

stCliente cargarCliente(stCliente cliente)
{

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

    cliente.bajaCliente = 0; /// 0 = activo

    return cliente;
}

int bajaCliente (int idCliente)
{
    FILE *buffer = fopen(archivoClientes, "r+b");
    stCliente aux;
    aux.bajaCliente = 1; /// 1 = baja
    int flag = 0;

    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stCliente), 1, buffer) > 0 && flag == 0)
        {
            if (idCliente == aux.idCliente)
            {
                fseek(buffer, sizeof(stCliente)*(-1), SEEK_CUR);
                aux = darDeBaja (aux);
                fwrite(&aux, sizeof(stCliente), 1, buffer);
                flag = 1;
            }
        }
        fclose(buffer);
    }

    return flag;
}

stCliente darDeBaja (stCliente cliente)
{
    cliente.bajaCliente = 1; /// dar de baja
    return cliente;
}

stCliente ModificarUnClienteAuxiliar (stCliente cliente)
{
    char control = 's';

    printf("Modificar nombre? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(cliente.nombre);
    }

    printf("Modificar apellido? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(cliente.apellido);
    }

    printf("Modificar mail? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese el mail: ");
        fflush(stdin);
        gets(cliente.mail);
    }

    printf("Modificar telefono? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese telefono: ");
        scanf("%lu", &cliente.telefono);
    }

    printf("Modificar DNI? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese DNI: ");
        scanf("%i", &cliente.dni);
    }

    printf("Modificar direccion (calle)? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese la calle: ");
        fflush(stdin);
        gets(cliente.calleDireccion);
    }

    printf("Modificar direccion (numero)? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        printf("Ingrese el numero de la direccion: ");
        scanf("%i", &cliente.calleNumero);
    }

    return cliente;
}

void BuscarYModificarUnCliente (int dni)
{
    FILE *buf = fopen(archivoClientes, "r+b");
    stCliente cliente;
    int pos = 0;

    if(!buf)
    {
        printf("El archivo no se puede abrir.\n");
    }
    else
    {
        pos = BuscarDni(buf, dni);
        fseek(buf, sizeof(stCliente)*(pos), 0);
        fread(&cliente, sizeof(stCliente), 1, buf);

        cliente = ModificarUnClienteAuxiliar (cliente);

        fseek(buf, sizeof(stCliente)*(-1), 1);
        fwrite(&cliente, sizeof(stCliente), 1, buf);

        fclose(buf);
    }
}

int BuscarDni (FILE* buf, int dni)
{
    stCliente aux;
    int i = 0;
    int flag = 0;

    while ( (fread(&aux, sizeof(stCliente), 1, buf) ) > 0 && flag == 0)
    {
        if (dni == aux.dni)
        {
            flag = 1;
        }
        i++;
    }
    return i-1;
}

/// Listar Clientes

/// Nombre y apellido (insercion)
/*
void InsertarDatoEnArregloOrdenadoPorNombre (stAlumno a[], int validos, stAlumno inser)
{
    int i=validos;

    while (i>=0 && strcmpi(a[i].nombre,inser.nombre) > 0)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1] = inser;
}

void OrdenamientoPorInsercion (stAlumno a[], int validos)
{
    int i=0;

    while(i<validos-1)
    {
        InsertarDatoEnArregloOrdenadoPorNombre(a, i, a[i+1]);
        i++;
    }
}
*/
/// DNI (seleccion)
/*
void OrdenarPorId ()
{

}

int BuscarPosicionMenorMatricula (int )
{
    int menor = a[i].matricula;
    int posmenor = i;

    for(i=i+1; i<validos; i++)
    {
        if(menor > a[i].matricula)
        {
            menor = a[i].matricula;
            posmenor = i;
        }
    }
    return posmenor;
}
*/
///-------------------------------------------------------------- FUNCIONES DE PEDIDOS --------------------------------------------------------------///
/*
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
*/
///-------------------------------------------------------------- FUNCIONES DE PRODUCTOS --------------------------------------------------------------///
/*
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
*/
/// LINEA 230 PRUEBA MAXI
