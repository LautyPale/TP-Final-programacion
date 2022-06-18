#include "Sistema.h"

/// PRUEBA MAXI
/// 16 de Junio 22:35

///-------------------------------------------------------------- CONSTANTES --------------------------------------------------------------///

const char archivoClientes[] = "Clientes";
const char archivoProductos[] = "Productos";
const char archivoPedidos[] = "Pedidos";
const int ANIO = 2022;

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

void altaPedido (int idCliente)
{
    FILE *bufferPedido = fopen(archivoPedidos, "a+b"); /// abro el archivo de pedidos para agregar algun pedido si se cumple el while de abajo
    FILE *bufferCliente = fopen(archivoClientes, "rb"); /// abro el archivo de clientes para comparar todos los id de clientes con el pedido por parametro
    stPedido nuevo;
    stPedido aux;
    stCliente buscarId; /// para comparar el id y agregar el pedido a ese cliente
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

            fseek(bufferPedido, sizeof(stPedido)*(-1), SEEK_END);
            if ( (fread(&aux, sizeof(stPedido), 1, bufferPedido) ) > 0 )
            {
                nuevo.idpedido = aux.idpedido + 1;
            }
            else
            {
                nuevo.idpedido = 1;
            }

            nuevo.idCliente = idCliente;
            nuevo = cargarPedido(nuevo);
            fwrite(&nuevo, sizeof(stPedido), 1, bufferPedido);

            system("cls");
        }

        fclose(bufferPedido);
    }
    else
    {
        printf("El cliente no existe o el ID es incorrecto");
    }

}

stPedido cargarPedido (stPedido pedido)
{
    printf("Ingrese el costo total del pedido: ");
    scanf("%f", &pedido.costopedido);

    printf("Ingrese la descripcion del pedido:\n");
    fflush(stdin);
    gets(pedido.descripcion);

    do
    {
        printf("Ingrese el anio del pedido: ");
        scanf("%d", &pedido.anioPedido);
        if (pedido.anioPedido < ANIO)
        {
            printf("El pedido no puede ser anterior al año actual");
        }
    } while (pedido.anioPedido < ANIO);

    do
    {
        printf("Ingrese el mes del pedido: ");
        scanf("%d", &pedido.mesPedido);
        if (pedido.mesPedido < 1 || pedido.mesPedido > 12)
        {
            printf("Ingrese un mes del 1 al 12.");
        }

    } while (pedido.mesPedido < 1 || pedido.mesPedido > 12);

    do
    {
        printf("Ingrese el dia del pedido: ");
        scanf("%d", &pedido.diaPedido);
        if (pedido.diaPedido < 1 || pedido.diaPedido > 31)
        {
            printf("Ingrese un dia del 1 al 31");
        }
    } while (pedido.diaPedido < 1 || pedido.diaPedido > 31);

    pedido.pedidoanulado = 0; /// el pedido esta siendo cargado por lo que no esta anulado (0 activo, 1 anulado)

    return pedido;
}

int bajaPedido (int idPedido)
{
    FILE *buffer = fopen(archivoPedidos, "r+b");
    stPedido aux;
    aux.pedidoanulado = 1; /// 1 = baja
    int flag = 0; /// flag para comprobar que existia el idPedido dado por el usuario

    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stPedido), 1, buffer) > 0 && flag == 0)
        {
            if (idPedido == aux.idpedido)
            {
                fseek(buffer, sizeof(stPedido)*(-1), SEEK_CUR);
                aux = darDeBajaPedido(aux);
                fwrite(&aux, sizeof(stPedido), 1, buffer);
                flag = 1;
            }
        }
        fclose(buffer);
    }

    return flag;
}

stPedido darDeBajaPedido (stPedido pedido)
{
    pedido.pedidoanulado = 1; /// dar de baja pedido
    return pedido;
}

stPedido modificarUnPedido (stPedido pedido)
{
    char control = 's';

    printf("Modificar descripcion? s/n");
    fflush(stdin);
    scanf("%c", &control);
    if (control == 's')
    {
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(pedido.descripcion);
    }

    printf("Modificar costo? s/n");
    fflush(stdin);
    scanf("%c", &control);
    if (control == 's')
    {
        printf("Ingrese costo: ");
        scanf("%f", &pedido.costopedido);
    }

    printf("Modificar fecha? s/n");
    fflush(stdin);
    scanf("%c", &control);
    if (control == 's')
    {
        do
        {
            printf("Ingrese el anio del pedido: ");
            scanf("%d", &pedido.anioPedido);
            if (pedido.anioPedido < ANIO)
            {
                printf("El pedido no puede ser anterior al año actual");
            }
        } while (pedido.anioPedido < ANIO);

        do
        {
            printf("Ingrese el mes del pedido: ");
            scanf("%d", &pedido.mesPedido);
            if (pedido.mesPedido < 1 || pedido.mesPedido > 12)
            {
                printf("Ingrese un mes del 1 al 12.");
            }

        } while (pedido.mesPedido < 1 || pedido.mesPedido > 12);

        do
        {
            printf("Ingrese el dia del pedido: ");
            scanf("%d", &pedido.diaPedido);
            if (pedido.diaPedido < 1 || pedido.diaPedido > 31)
            {
                printf("Ingrese un dia del 1 al 31");
            }
        } while (pedido.diaPedido < 1 || pedido.diaPedido > 31);
    }

    printf("Modificar id del cliente? s/n");
    fflush(stdin);
    scanf("%c", &control);
    if (control == 's')
    {
        printf("Ingrese id del cliente: ");
        scanf("%d", &pedido.idCliente);
    }
    return pedido;
}

stPedido buscarYmodificarPedido (int idPedido)
{
    FILE *buffer = fopen(archivoPedidos, "r+b");
    stPedido pedido;
    int pos = 0;

    if (!buffer)
    {
        printf("El archivo no se puede abrir.\n");
    }
    else
    {
        pos = buscarIdPedido(buffer, idPedido);
        fseek(buffer, sizeof(stPedido)*(pos), 0);
        fread(&pedido, sizeof(stPedido), 1, buffer);

        pedido = modificarUnPedido(pedido);

        fseek(buffer, sizeof(stPedido)*(-1), 1);
        fwrite(&pedido, sizeof(stPedido), 1, buffer);

        fclose(buffer);
    }
    return pedido;
}

int buscarIdPedido (FILE *buffer, int idPedido)
{
    stPedido aux;
    int i = 0;
    int flag = 0;

    while ( (fread(&aux, sizeof(stPedido), 1, buffer)) > 0 && flag == 0)
    {
        if (idPedido == aux.idpedido)
        {
            flag = 1;
        }
        i++;
    }

    return i-1;
}

/// Listar Pedidos ///

void mostrarUnPedido (stPedido pedido)
{
    printf("\nID del pedido: %d", pedido.idpedido);

    printf("\nDescripcion: %s", pedido.descripcion);

    printf("\nCosto: %.2f", pedido.costopedido);

    printf("\nPedido del Cliente nro: %d", pedido.idCliente);

    printf("Fecha del pedido: %d/%d/%d", pedido.diaPedido, pedido.mesPedido, pedido.anioPedido);

    if (pedido.pedidoanulado == 0)
    {
        printf("Pedido activo: SI");
    }
    else
    {
        printf("Pedido activo: NO");
    }
}

/// Fecha ///
/*
void ordenarPorFecha ()
{

}

void elegirFecha (stPedido pedidos[])
{
    FILE *buffer = fopen(archivoPedidos, "rb");

}
*/
/// Clientes ///

void MostrarPedidosDeUnCliente (int idCliente)
{
    FILE *buffer = fopen(archivoPedidos, "rb");
    stPedido pedido;
    int i = 0;

    if (buffer != NULL)
    {
        while ( (fread(&pedido, sizeof(stPedido), 1, buffer) ) > 0)
        {
            if (idCliente == pedido.idCliente)
            {
                printf("--------------Mostrando pedido %d del cliente nro: %d--------------", i+1, idCliente);
                mostrarUnPedido(pedido);
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo no pudo ser abierto");
    }
}

/// Top 10 Clientes

/*
void listarTop10Clientes ()
{

}
*/

/// Peor Cliente

/*
void PeorCliente ()
{

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

