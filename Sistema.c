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

    if (buffer)
    {
        printf("Cuantos clientes desea cargar: ");
        scanf("%d", &cantClientes);

        for (i = 0; i < cantClientes; i++)
        {
            printf("Ingrese el DNI del cliente: ");
            scanf("%d", &nuevo.dni);

            fseek(buffer, sizeof(stCliente)*(i), 0);
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
                fseek(buffer, 0, 0);
                if  ((fread(&aux, sizeof(stCliente), 1, buffer)) > 0 )
                {
                    fseek(buffer, sizeof(stCliente)*(-1), SEEK_END);
                    fread(&aux, sizeof(stCliente), 1, buffer);
                    nuevo.idCliente = aux.idCliente + 1;
                }
                else
                {
                    nuevo.idCliente = 1;
                }

                fseek(buffer, sizeof(stCliente)*(i), 0);
                nuevo = cargarCliente(nuevo);
                fwrite(&nuevo, sizeof(stCliente), 1, buffer);
                system("cls");
            }
        }
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

int BuscarYModificarUnCliente (int dni)
{
    FILE *buf = fopen(archivoClientes, "r+b");
    stCliente cliente;
    int pos = 0;
    int flag = 0;

    if(!buf)
    {
        printf("El archivo no se puede abrir.\n");
    }
    else
    {
        while ( (fread(&cliente, sizeof(stCliente), 1, buf) ) > 0 && dni != cliente.dni)
        {
            if (dni == cliente.dni)
            {
                pos = BuscarDni(buf, dni);
                fseek(buf, sizeof(stCliente)*(pos), 0);
                fread(&cliente, sizeof(stCliente), 1, buf);

                cliente = ModificarUnClienteAuxiliar (cliente);

                fseek(buf, sizeof(stCliente)*(-1), 1);
                fwrite(&cliente, sizeof(stCliente), 1, buf);
                flag = 1;
            }
        }
        fclose(buf);
    }
    return flag;
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

void MostrarEstructuras (stCliente cliente[], int validos){

    int i=0;

    for(i=0; i<validos; i++){
        MostrarUnCliente(cliente[i]);
    }
}

void MostrarUnCliente (stCliente aux){

    printf("-------------------------------------\n");
    printf("          ID: %i\n", aux.idCliente);
    printf("      NOMBRE: %s\n", aux.nombre);
    printf("    APELLIDO: %s\n", aux.apellido);
    printf("         DNI: %i\n", aux.dni);
    printf("      E-MAIL: %s\n", aux.mail);
    printf("       CALLE: %s\n", aux.calleDireccion);
    printf("DIRECCION Nº: %i\n", aux.calleNumero);
    printf("    TELEFONO: %lu\n", aux.telefono);
    printf("-------------------------------------\n");
}

void MostrarArchivoClientes (){
    FILE * buf = fopen(archivoClientes, "rb");
    stCliente aux;

    if (!buf){
        printf("EL ARCHIVO NO SE PUDO ABRIR\n");
    }else{

        while( (fread(&aux, sizeof(stCliente), 1, buf)) > 0)
        {
            MostrarUnCliente(aux);
        }
        fclose(buf);
    }
}

/// Nombre y apellido (insercion)

void InsertarDatoEnArregloOrdenadoPorNombre (stCliente cliente[], int validos, stCliente inser)
{
    stCliente aux;
    int i = validos;
    while (i >= 0 && (strcmpi(cliente[i].nombre,inser.nombre))> 0)
    {
        cliente[i+1]=cliente[i];
        i--;
    }
    while (i >= 0 && (strcmpi(cliente[i].nombre,inser.nombre)) == 0)
    {
        if ( ( strcmpi(cliente[i].apellido,inser.apellido) ) > 0)
        {
            cliente[i+1]=cliente[i];
            i--;
        }
        else if ( ( strcmpi(cliente[i].apellido,inser.apellido) ) < 0)
        {
            aux = cliente[i+1];
            cliente[i+1] = cliente[i];
            cliente[i] = aux;
            i--;
        }
        else
        {
            cliente[i+1]=cliente[i];
            i--;
        }
    }

    cliente[i+1] = inser;
}

void OrdenamientoPorInsercionNombreYApellido (stCliente cliente[], int validos)
{
    int i=0;
    while(i<validos-1)
    {
        InsertarDatoEnArregloOrdenadoPorNombre(cliente, i, cliente[i+1]);
        i++;
    }
}

/// DNI (seleccion)

stCliente CopiarDeArchivoAEstructura (stCliente clienteord[])
{
    FILE * buf = fopen(archivoClientes, "rb");
    int i=0;
    stCliente cliente;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR\n");
    }
    else{
        while((fread(&cliente, sizeof(stCliente), 1, buf)) > 0){
            clienteord[i] = cliente;
            i++;
        }
        fclose(buf);
    }
    return cliente;
}

int CantidadDeRegistrosEnArchivo()
{
    FILE * buf = fopen(archivoClientes, "rb");
    int cant;

    if(!buf) {
        printf("error");
    } else {
        fseek(buf,0,2);
        cant = ftell(buf) / sizeof(stCliente);
        fclose(buf);
    }
    return cant;
}

int BuscarPosicionMenorDNI (stCliente cliente[], int validos, int i)
{
    int menor = cliente[i].dni;
    int posmenor = i;

    for(i=i+1; i<validos; i++)
    {
        if(menor > cliente[i].dni)
        {
            menor = cliente[i].dni;
            posmenor = i;
        }
    }
    return posmenor;
}

void OrdenamientoPorSeleccionDNI (stCliente cliente[], int validos)
{
    int i=0, posmenor;
    stCliente aux;

    while(i<validos)
    {
        posmenor = BuscarPosicionMenorDNI(cliente, validos, i);

        aux=cliente[i];                 /// GUARDO LOS DATOS DE cliente[i] EN aux PARA NO PERDER DATOS
        cliente[i]=cliente[posmenor];   /// GUARDO EN cliente[i] LOS DATOS DE MENOR DNI
        cliente[posmenor]=aux;          /// DEVUELVO LOS DATOS QUE HABIA EN cliente[i] AL LUGAR QUE DEJO EL DATO DE MENOR DNI

        i++;
    }
}

///-------------------------------------------------------------- FUNCIONES DE PEDIDOS --------------------------------------------------------------///

void altaPedido ()
{
    FILE *buffer = fopen(archivoPedidos, "a+b");
    FILE *bufferClientes = fopen(archivoClientes, "rb");
    stCliente aux;
    stPedido nuevo;
    stPedido aux2;
    int cantPedidos = 0;
    int i = 0;
    int flag = 0;

    if (buffer)
    {
        printf("Cuantos pedidos desea cargar: ");
        scanf("%d", &cantPedidos);

        for (i = 0; i < cantPedidos; i++)
        {
            printf("Ingrese el ID del cliente: ");
            scanf("%d", &nuevo.idCliente);

            fseek(bufferClientes, 0, 0);
            while ( (fread (&aux, sizeof(stCliente), 1, bufferClientes) ) > 0 && flag == 0)
            {
                if (nuevo.idCliente == aux.idCliente)
                {
                    flag = 1;
                }
            }

            if(flag == 0)
            {
                printf("\nEl cliente no existe.\n");
            }
            else
            {
                fseek(buffer, 0, 0);
                if  ((fread(&aux, sizeof(stPedido), 1, buffer)) > 0 )
                {
                    fseek(buffer, sizeof(stPedido)*(-1), SEEK_END);
                    fread(&aux2, sizeof(stPedido), 1, buffer);
                    nuevo.idpedido = aux2.idpedido + 1;
                }
                else
                {
                    nuevo.idpedido = 1;
                }

                fseek(buffer, sizeof(stPedido)*(i), 0);
                nuevo = cargarPedido(nuevo);
                fwrite(&nuevo, sizeof(stPedido), 1, buffer);
                system("cls");
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo ya existe.");
    }
}

stPedido cargarPedido (stPedido pedido)
{
    printf("------------------------- Cargar nuevo pedido -------------------------\n");

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
            printf("\nEl pedido no puede ser anterior al año actual.\n");
        }
    } while (pedido.anioPedido < ANIO);

    do
    {
        printf("Ingrese el mes del pedido: ");
        scanf("%d", &pedido.mesPedido);
        if (pedido.mesPedido < 1 || pedido.mesPedido > 12)
        {
            printf("\nIngrese un mes del 1 al 12.\n");
        }

    } while (pedido.mesPedido < 1 || pedido.mesPedido > 12);

    do
    {
        printf("Ingrese el dia del pedido: ");
        scanf("%d", &pedido.diaPedido);
        if (pedido.diaPedido < 1 || pedido.diaPedido > 31)
        {
            printf("\nIngrese un dia del 1 al 31.\n");
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
    printf("\n------------------------------------------------------------------");

    printf("\nID del pedido: %d", pedido.idpedido);

    printf("\nDescripcion: %s", pedido.descripcion);

    printf("\nCosto: %.2f", pedido.costopedido);

    printf("\nPedido del Cliente nro: %d", pedido.idCliente);

    printf("\nFecha del pedido: %d/%d/%d", pedido.diaPedido, pedido.mesPedido, pedido.anioPedido);

    if (pedido.pedidoanulado == 0)
    {
        printf("\nPedido activo: SI");
    }
    else
    {
        printf("\nPedido activo: NO");
    }

    printf("\n------------------------------------------------------------------\n");
}

/// Fecha ///

void ordenarPorFecha ()
{
    FILE * buffer = fopen(archivoPedidos, "rb");

    int posmenor;
    stPedido aux;
    int i = 0;

    int validos = contarRegistrosPedidos(buffer);
    stPedido arregloPedidos[validos];
    while (i < validos)
    {
        arregloPedidos[i] = CopiarPedidosAarreglo(buffer, i);
        i++;
    }

    i = 0;

    while (i < validos)
    {
        posmenor = fechaMenor(arregloPedidos, i, validos);
        aux = arregloPedidos[posmenor];
        arregloPedidos[posmenor] = arregloPedidos[i];
        arregloPedidos[i] = aux;
        i++;
    }
    fclose(buffer);
}

int fechaMenor (stPedido arregloPedidos[], int pos, int validos)
{
    stPedido menor = arregloPedidos[pos];
    int posmenor = pos;
    int i = pos + 1;

    while (i < validos)
    {
        if (menor.anioPedido > arregloPedidos[i].anioPedido)
        {
            menor = arregloPedidos[i];
            posmenor = i;
        }
        else if (menor.anioPedido == arregloPedidos[i].anioPedido)
        {
            if (menor.mesPedido > arregloPedidos[i].mesPedido)
            {
                menor = arregloPedidos[i];
                posmenor = i;
            }
            else if (menor.mesPedido == arregloPedidos[i].mesPedido)
            {
                if (menor.diaPedido > arregloPedidos[i].mesPedido)
                {
                    menor = arregloPedidos[i];
                    posmenor = i;
                }
            }
        }
    }
    return posmenor;
}

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

void MostrarTodosLosPedidos ()
{
    FILE *buffer = fopen(archivoPedidos, "rb");
    stPedido pedido;
    char continuar = 'n';

    if (buffer != NULL)
    {
        while ( (fread(&pedido, sizeof(stPedido), 1, buffer) ) > 0)
        {
            mostrarUnPedido(pedido);
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo no pudo ser abierto");
    }

    printf("Ingrese c para continuar: ");
    fflush(stdin);
    scanf("%c", &continuar);
    system("cls");
}

/// Top 10 Clientes ///
/*
void Top10Clientes (stPedido arreglo[], int validos)
{

}
*/

/// Peor Cliente

/*
void PeorCliente ()
{

}
*/

///-------------------------------------------------------------- FUNCIONES AUXILIARES --------------------------------------------------------------///

/// Pasar de archivo de pedidos a arreglo de pedidos para ordenar

int contarRegistrosPedidos (FILE *buffer)
{
    stPedido aux;
    int i = 0;

    if (!buffer)
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }
    else
    {
        while ( (fread(&aux, sizeof(stPedido), 1, buffer) ) > 0)
        {
            i++;
        }
    }

    return i;
}

stPedido CopiarPedidosAarreglo (FILE *buffer, int i)
{
    stPedido pedido;

    fseek(buffer, (sizeof(stPedido)*i), 0);
    fread(&pedido, sizeof(stPedido), 1, buffer);

    return pedido;
}

/// Pasar de archivo de clientes a arreglo de clientes para ordenar

int contarRegistrosClientes (FILE *buffer)
{
    stCliente aux;
    int i = 0;

    if (!buffer)
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }
    else
    {
        while ( (fread(&aux, sizeof(stCliente), 1, buffer) ) > 0)
        {
            i++;
        }
    }

    return i;
}

stCliente CopiarClientesAarreglo (stCliente clienteord[])
{
    FILE * buf = fopen(archivoClientes, "rb");
    int i = 0;
    stCliente cliente;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR\n");
    }
    else{
        while((fread(&cliente, sizeof(stCliente), 1, buf)) > 0){
            clienteord[i] = cliente;
            i++;
        }
        fclose(buf);
    }
    return cliente;
}
