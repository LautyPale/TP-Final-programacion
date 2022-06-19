#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Sistema.h"

int main()
{
    return 0;
}

/// Menu opciones ///

/*
void menuOpciones ()
{
    int opcion = -1;
    int opcionClientes = -1, opcionClientesListar = -1;
    int opcionPedidos = -1, opcionPedidosListar = -1;
    int opcionProductos = -1;

    while (opcion != 0)
    {
        printf("1. Opcion Clientes\n");
        printf("2. Opcion Pedidos\n");
        printf("3. Opcion Productos\n");
        printf("Ingrese una de las opciones o 0 para salir: ");
        scanf("%d", opcion);

        switch (opcion)
        {
            case 0:
            {
                break;
            }

            case 1: /// Clientes
            {
                printf("1. Alta de Clientes\n");
                printf("2. Baja de Clientes\n");
                printf("3. Modificacion de Clientes\n");
                printf("4. Listar Clientes\n");
                printf("Ingrese una de las opciones o cualquier numero para salir: ");
                scanf("%d", &opcionClientes);

                switch (opcionClientes)
                {
                    case 1: /// Alta de Clientes
                    {
                        /// Funcion carga de clientes y guardar en archivo.
                        break;
                    }

                    case 2: /// Baja de Clientes
                    {
                        /// Funcion buscar cliente, dar de baja y guardar cambios en archivo
                        break;
                    }

                    case 3: /// Modificar Clientes
                    {
                        /// Funcion buscar cliente, modificar y guardar cambios en archivo
                        break;
                    }

                    case 4: ///Listar Clientes
                    {
                        printf("1. Ordenar por nombre y apellido Cliente\n");
                        printf("2. Ordenar por id Cliente\n");
                        printf("Ingrese una de las opciones o cualquier numero para salir: ");
                        scanf("%d", &opcionClientesListar);

                        switch (opcionClientesListar)
                        {
                            case 1:
                            {
                                /// Ordenar por insercion nombre y Apellido
                                break;
                            }

                            case 2:
                            {
                                /// Ordenar por Seleccion id del cliente
                                break;
                            }

                            default:
                            {
                                break;
                            }
                        }
                    }

                    default:
                    {
                        break;
                    }

                }

                break;
            }

            case 2: /// Pedidos
            {
                printf("1. Alta del Pedido\n");
                printf("2. Baja del Pedido\n");
                printf("3. Modificacion de Pedidos\n");
                printf("4. Listados y estadisticas\n");
                printf("Ingrese una de las opciones o cualquier numero para salir: ");
                scanf("%d", &opcionPedidos);

                switch (opcionPedidos);
                {
                    case 1: /// Alta del Pedido
                    {
                        /// Alta del pedido y guardar cambios en archivo
                        break;
                    }

                    case 2: /// Baja del Pedido
                    {
                        /// Buscar pedido en el archivo, anularlo y guardar cambios
                        break;
                    }

                    case 3: /// Modificacion de Pedidos
                    {
                        /// Buscar pedido, modificarlo y guardar cambios
                        break;
                    }

                    case 4: /// Listados y estadisticas
                    {
                        printf("1. Listar por orden de fecha\n");
                        printf("2. Mostrar todos los pedidos de un cliente\n");
                        printf("3. Listar top 10 de mejores clientes\n");
                        printf("4. Cliente con menos pedidos\n");
                        printf("Ingrese la opcion o cualquier numero para salir: ");
                        switch (opcionPedidosListar)
                        {
                            case 1:
                            {
                                /// Listar por orden de fecha (metodo de ordenamiento a eleccion del grupo)
                                break;
                            }

                            case 2:
                            {
                                /// Listar pedidos por cliente (busco uno en particular y muestro todos los pedidos que realizo
                                break;
                            }

                            case 3:
                            {
                                /// Listar top 10 de mejores clientes (por cantidad pedidos)
                                break;
                            }

                            case 4:
                            {
                                /// Buscar el peor cliente (por cantidad pedidos)
                                break;
                            }

                            default:
                            {
                                break;
                            }

                        }

                    }

                    default:
                    {
                        break;
                    }
                }

                break;
            }

            case 3: /// Productos
            {
                printf("1. Agregar Producto\n");
                printf("2. Eliminar Producto\n");
                printf("3. Editar Producto\n")
                printf("4. Ver Productos\n");
                printf("Ingrese una opcion o cualquier numero para salir: ");
                scanf("%d", &opcionProductos);

                switch(opcionProductos);
                {
                    case 1: /// Agregar Producto
                    {
                        /// Funcion agregar producto y guardar en archivo
                        break;
                    }

                    case 2:
                    {
                        /// Funcion eliminar producto y guardar en archivo
                        break;
                    }

                    case 3:
                    {
                        /// Funcion editar producto y guardar en archivo
                    }

                    case 4:
                    {
                        /// Funcion ver listado de productos
                    }

                    default:
                    {
                        break;
                    }
                }
                break;
            }

            default:
            {
                printf("El numero ingresado no corresponde a ninguna opcion");
            }
        }
    }
}
*/






