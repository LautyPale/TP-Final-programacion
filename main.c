#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sistema.h"



int main()
{

    return 0;
}

void menuOpciones ()
{
    int opcion = -1;
    int opcionClientes = -1;
    int opcionPedidos = -1;
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
                printf("4. Listar de Clientes\n");
                printf("Ingrese una de las opciones o cualquier numero para salir: ");
                scanf("%d", &opcionClientes);

                switch (opcionClientes)
                {
                    case 1:
                    {
                        ///Funcion carga de clientes y guardar en archivo.
                        break;
                    }
                }
                break;
            }

            case 2: /// Pedidos
            {

                break;
            }

            case 3: /// Productos
            {

                break;
            }

            default:
            {
                printf("El numero ingresado no corresponde a ninguna opcion");
            }
        }
    }

}







