#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma once

///-------------------------------------------------------------- Estructuras --------------------------------------------------------------///

typedef struct{
char nombre[30];
char apellido[30];
char mail[40]; /// 0 a 255 ASCII | especificador de formato: %c
unsigned long int telefono; /// 0 a 4,294,967,295 | especificador de formato: %lu
int dni;
char calleDireccion[50];
int calleNumero;
int idCliente;
int bajaCliente; /// 0 activo, 1 dado de baja.
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
int diaPedido;
int mesPedido;
int anioPedido;
int pedidoanulado; /// 0 activo, 1 pedido anulado
int idCliente; /// para poder listar todos los pedidos de un cliente en especifico
}stPedido;

///-------------------------------------------------------------- Prototipado --------------------------------------------------------------///

/// Clientes ///
void altaCliente (int cantClientes);
stCliente cargarCliente();
int bajaCliente (int idCliente);
stCliente ModificarUnClienteAuxiliar (stCliente cliente);
void BuscarYModificarUnCliente (int pos);
int BuscarDni (FILE* buf, int dni);
stCliente darDeBaja (stCliente cliente);

/// Pedidos ///

void altaPedido (int idCliente);
stPedido cargarPedido (stPedido pedido);
int bajaPedido (int idPedido);
stPedido darDeBajaPedido (stPedido pedido);
stPedido modificarUnPedido (stPedido pedido);
stPedido buscarYmodificarPedido (int idPedido);
int buscarIdPedido (FILE *buffer, int idPedido);
void mostrarUnPedido (stPedido pedido);
void MostrarPedidosDeUnCliente (int idCliente);
void archivoAarreglo ();
