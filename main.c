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

    /// Variables Generales //7

    int flag = 0;

    /// Variables Clientes ///

    int opcionClientes = -1, opcionListarClientes = -1;
    int cantClientes = 0;
    int idCliente = -1;
    int DNICliente = -1;

    /// Variables Pedidos ///

    int opcionPedidos = -1, opcionListarPedidos = -1;
    int idPedido = -1;

    do
    {
        printf("[ 1 ] Clientes.\n");
        printf("[ 2 ] Pedidos.\n");

        printf("Ingrese una de las opciones o 0 para salir: ");
        scanf("%d", &opcionGeneral);

        system("cls");

        switch (opcionGeneral)
        {
            case 0:
            {
                break;
            }

            case 1:
            {
                /// Clientes ///
                do
                {
                    printf("[ 1 ] Alta Clientes.\n");
                    printf("[ 2 ] Baja Clientes.\n");
                    printf("[ 3 ] Modificar Clientes.\n");
                    printf("[ 4 ] Listar Clientes.\n");

                    printf("Ingrese una de las opciones o 0 para salir: ");
                    scanf("%d", &opcionClientes);

                    system("cls");

                    switch (opcionClientes)
                    {
                        case 0:
                        {
                            break;
                        }

                        case 1:
                        {
                            printf("Cuantos clientes desea cargar: ");
                            scanf("%d", &cantClientes);
                            altaCliente(cantClientes);
                            break;
                        }

                        case 2:
                        {
                            printf("Ingrese el ID del cliente: ");
                            scanf("%d", &idCliente);
                            flag = bajaCliente(idCliente);
                            if (flag == 0)
                            {
                                printf("\nNo se pudo encontrar el cliente buscado o el ID es incorrecto.\n");
                            }
                            else
                            {
                                printf("\nCliende dado de baja exitosamente.\n");
                            }
                            idCliente = -1;
                            break;
                        }

                        case 3:
                        {
                            printf("Ingrese el DNI del cliente: ");
                            scanf("%d", &DNICliente);
                            BuscarYModificarUnCliente(DNICliente);
                            break;
                        }

                        case 4:
                        {
                            do
                            {
                                printf("[ 1 ] Ordenar por nombre y apellido.\n");
                                printf("[ 2 ] Ordenar por DNI\n");

                                printf("Ingrese una de las opciones o 0 para salir: ");
                                scanf("%d", &opcionListarClientes);

                                system("cls");

                                switch (opcionListarClientes)
                                {
                                    case 0:
                                    {
                                        break;
                                    }

                                    case 1:
                                    {
                                        /// funcion metodo insercion nombre y apellido
                                        break;
                                    }

                                    case 2:
                                    {
                                        /// funcion metodo seleccion DNI
                                        break;
                                    }

                                    default:
                                    {
                                        printf("\nEl numero ingresado no corresponde a ninguna opcion.\n");
                                    }
                                }
                            } while (opcionListarClientes != 0);
                        }

                        default:
                        {
                            printf("\nEl numero ingresado no corresponde a ninguna opcion.");
                        }

                    }
                } while (opcionClientes != 0);
            }

            case 2:
            {
                /// Pedidos ///

                do
                {
                    printf("[ 1 ] Alta Pedidos\n");
                    printf("[ 2 ] Baja Pedidos\n");
                    printf("[ 3 ] Modificacion Pedidos\n");
                    printf("[ 4 ] Listado y estadisticas Pedidos\n");

                    printf("Ingrese una de las opciones o 0 para salir: ");
                    scanf("%d", &opcionPedidos);

                    system("cls");

                    switch (opcionPedidos)
                    {
                        case 0:
                        {
                            break;
                        }

                        case 1:
                        {
                            printf("Ingrese el ID del cliente: ");
                            scanf("%d", &idCliente);

                            altaPedido(idCliente);
                            break;
                        }

                        case 2:
                        {
                            printf("Ingrese el ID del pedido: ");
                            scanf("%d", &idPedido);

                            bajaPedido(idPedido);
                            idPedido = -1;
                            break;
                        }

                        case 3:
                        {
                            printf("Ingrese el ID del pedido: ");
                            scanf("%d", &idPedido);

                            buscarYmodificarPedido(idPedido);
                            idPedido = -1;
                            break;
                        }

                        case 4:
                        {
                            do
                            {
                                printf("[ 1 ] Listar Pedidos por Fecha.\n");
                                printf("[ 2 ] Mostrar Pedidos de un cliente.\n");
                                printf("[ 3 ] Top 10 mejores clientes.\n");
                                printf("[ 4 ] Peor Cliente.\n");

                                printf("Ingrese una opcion o 0 para salir: ");
                                scanf("%d", &opcionListarPedidos);

                                system("cls");

                                switch (opcionListarPedidos)
                                {
                                    case 0:
                                    {
                                        break;
                                    }

                                    case 1:
                                    {
                                        /// Funcion pedido por Fecha
                                        break;
                                    }

                                    case 2:
                                    {
                                        printf("Ingrese el ID del cliente: ");
                                        scanf("%d", &idCliente);

                                        MostrarPedidosDeUnCliente(idCliente);
                                        idCliente = -1;
                                        break;
                                    }

                                    case 3:
                                    {
                                        /// Funcion top 10 mejores clientes
                                        break;
                                    }

                                    case 4:
                                    {
                                        /// Funcion peor Cliente
                                        break;
                                    }

                                    default:
                                    {
                                        printf("\nEl numero ingresado no corresponde a ninguna opcion.\n");
                                    }
                                }

                            } while (opcionListarPedidos != 0);
                        }

                        default:
                        {
                            printf("\nEl numero ingresado no corresponde a ninguna opcion.\n");
                        }

                    }

                } while (opcionPedidos != 0);
            }

            default:
            {
                printf("\nEl numero ingresado no corresponde a ninguna opcion.\n");
            }

        }

    } while (opcionGeneral != 0);
}
