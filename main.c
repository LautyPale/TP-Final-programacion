#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Sistema.h"

void menuOpciones ();

int main()
{
    menuOpciones ();
    return 0;
}

/// Menu opciones ///

void menuOpciones ()
{
    int opcionGeneral = -1;

    /// Variables Generales ///

    int flag = 0;

    /// Variables Clientes ///

    int opcionClientes = -1, opcionListarClientes = -1;
    int idCliente = -1;
    int DNICliente = -1;
    stCliente arregloClientes[1000];
    int validosClientes = 0;
    stCliente ClienteAux;


    /// Variables Pedidos ///

    int opcionPedidos = -1, opcionListarPedidos = -1;
    int idPedido = -1;
    int validosPedidos = 0;
    stPedido arregloPedidos[1000];

    do
    {
        printf("[ 1 ] Clientes\n");
        printf("[ 2 ] Pedidos\n\n");

        printf("Ingrese una de las opciones o 0 para salir: ");
        scanf("%d", &opcionGeneral);

        system("cls");

        switch (opcionGeneral)
        {
            case 0:

                break;


            case 1:

                /// Clientes ///
                do
                {
                    printf("[ 1 ] Alta Clientes\n");
                    printf("[ 2 ] Baja Clientes\n");
                    printf("[ 3 ] Modificar Clientes\n");
                    printf("[ 4 ] Listar Clientes\n\n");

                    printf("Ingrese una de las opciones o 0 para salir: ");
                    scanf("%d", &opcionClientes);
                    opcionGeneral = -1;

                    system("cls");

                    switch (opcionClientes)
                    {
                        case 0:

                            break;


                        case 1:

                            altaCliente();
                            break;

                        case 2:

                            printf("Ingrese el ID del cliente: ");
                            scanf("%d", &idCliente);
                            flag = bajaCliente(idCliente);
                            if (flag == 0)
                            {
                                printf("\nNo se pudo encontrar el cliente buscado o el ID es incorrecto.\n");
                            }
                            else
                            {
                                printf("\nCliente dado de baja exitosamente.\n");
                            }
                            idCliente = -1;
                            continuar ();
                            break;


                        case 3:

                            printf("Ingrese el DNI del cliente a modificar: ");
                            scanf("%d", &DNICliente);
                            flag = BuscarYModificarUnCliente(DNICliente);
                            if (flag == 0)
                            {
                                printf("\nNo se pudo encontrar el cliente buscado o el DNI es incorrecto.\n");
                            }
                            else
                            {
                                printf("\nCliente modificado exitosamente.\n");
                            }
                            DNICliente = -1;
                            continuar ();
                            break;


                        case 4:

                            do
                            {
                                printf("[ 1 ] Ordenar por nombre y apellido\n");
                                printf("[ 2 ] Ordenar por DNI (de menor a mayor)\n");
                                printf("[ 3 ] Mostrar por ID\n\n");

                                printf("Ingrese una de las opciones o 0 para salir: ");
                                scanf("%d", &opcionListarClientes);

                                system("cls");

                                switch (opcionListarClientes)
                                {
                                    case 0: ;

                                        break;

                                    case 1: ;

                                        validosClientes = CantidadDeRegistrosEnArchivo();
                                        CopiarDeArchivoAEstructura(arregloClientes);
                                        OrdenamientoPorInsercionNombreYApellido(arregloClientes, validosClientes);
                                        MostrarEstructuras(arregloClientes, validosClientes);
                                        continuar ();
                                        break;

                                    case 2:

                                        validosClientes = CantidadDeRegistrosEnArchivo();
                                        CopiarDeArchivoAEstructura(arregloClientes);
                                        OrdenamientoPorSeleccionDNI (arregloClientes, validosClientes);
                                        MostrarEstructuras(arregloClientes, validosClientes);
                                        continuar ();
                                        break;

                                    case 3:

                                        MostrarArchivoClientes ();
                                        continuar ();
                                        break;


                                    default:

                                        printf("El numero ingresado no corresponde a ninguna opcion.\n\n");
                                        continuar ();
                                        break;

                                }
                            } while (opcionListarClientes != 0);
                            break;

                        default:

                            printf("El numero ingresado no corresponde a ninguna opcion.\n\n");
                            continuar ();
                            break;


                    }
                } while (opcionClientes != 0);
                break;

            case 2: ;

                /// Pedidos ///

                do
                {
                    printf("[ 1 ] Alta Pedidos\n");
                    printf("[ 2 ] Baja Pedidos\n");
                    printf("[ 3 ] Modificacion Pedidos\n");
                    printf("[ 4 ] Listado y estadisticas Pedidos\n\n");

                    printf("Ingrese una de las opciones o 0 para salir: ");
                    scanf("%d", &opcionPedidos);
                    opcionGeneral = -1;
                    system("cls");

                    switch (opcionPedidos)
                    {
                        case 0:

                            break;


                        case 1:

                            altaPedido();
                            printf("El/los pedido/s han sido cargado/s exitosamente.\n");
                            continuar ();
                            break;

                        case 2:

                            printf("Ingrese el ID del pedido: ");
                            scanf("%d", &idPedido);

                            bajaPedido(idPedido);
                            idPedido = -1;
                            continuar ();
                            break;


                        case 3:

                            printf("Ingrese el ID del pedido: ");
                            scanf("%d", &idPedido);

                            buscarYmodificarPedido(idPedido);
                            idPedido = -1;
                            continuar ();
                            break;


                        case 4:

                            do
                            {
                                printf("[ 1 ] Listar Pedidos por Fecha\n");
                                printf("[ 2 ] Mostrar Pedidos de un cliente\n");
                                printf("[ 3 ] Mostrar todos los pedidos\n");
                                printf("[ 4 ] Top 10 mejores clientes\n");
                                printf("[ 5 ] Peor Cliente\n\n");

                                printf("Ingrese una opcion o 0 para salir: ");
                                scanf("%d", &opcionListarPedidos);

                                system("cls");

                                switch (opcionListarPedidos)
                                {
                                    case 0:

                                    break;


                                    case 1:

                                        validosPedidos = CantidadDeRegistrosPedidos();
                                        CopiarPedidosAarreglo(arregloPedidos, validosPedidos);
                                        ordenarPorFecha(arregloPedidos, validosPedidos);
                                        mostrarArregloPedidos(arregloPedidos, validosPedidos);
                                        continuar ();
                                        break;

                                    case 2:

                                        printf("Ingrese el ID del cliente: ");
                                        scanf("%d", &idCliente);
                                        MostrarPedidosDeUnCliente(idCliente);
                                        idCliente = -1;
                                        continuar ();
                                        break;

                                    case 3:

                                        MostrarArchivoPedidos ();
                                        continuar ();

                                        break;

                                    case 4:

                                        validosClientes = CantidadDeRegistrosEnArchivo();
                                        CopiarDeArchivoAEstructura(arregloClientes);
                                        Top10Clientes(arregloClientes, validosClientes);
                                        mostrarTop10(arregloClientes, validosClientes);
                                        continuar ();
                                        break;

                                    case 5:

                                        validosClientes = CantidadDeRegistrosEnArchivo();
                                        CopiarDeArchivoAEstructura(arregloClientes);
                                        ClienteAux = peorCliente(arregloClientes, validosClientes);
                                        MostrarUnCliente(ClienteAux);
                                        continuar ();
                                        break;

                                    default:

                                        printf("El numero ingresado no corresponde a ninguna opcion.\n\n");
                                        continuar ();
                                        break;

                                }

                            } while (opcionListarPedidos != 0);
                            break;

                        default:

                            printf("El numero ingresado no corresponde a ninguna opcion.\n\n");
                            break;


                    }

                } while (opcionPedidos != 0);
                break;

            default:

                printf("El numero ingresado no corresponde a ninguna opcion.\n\n");
                continuar ();
                break;
        }

    } while (opcionGeneral != 0);
}
