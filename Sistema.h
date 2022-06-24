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
int cantPedidos; /// para funciones top 10 y peor cliente
}stCliente;

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

/// Menu Opciones ///

void continuar ();

/// Clientes ///
void altaCliente ();
stCliente cargarCliente();
int bajaCliente (int idCliente);
stCliente ModificarUnClienteAuxiliar (stCliente cliente);
int BuscarYModificarUnCliente (int dni);
int BuscarDni (FILE* buf, int dni);
stCliente darDeBaja (stCliente cliente);

void MostrarEstructuras (stCliente cliente[], int validos);
void MostrarUnCliente (stCliente aux);
void MostrarArchivoClientes ();
void MostrarClientesActivosoInactivos (int opcion);
void InsertarDatoEnArregloOrdenadoPorNombre (stCliente cliente[], int validos, stCliente inser);
void OrdenamientoPorInsercionNombreYApellido (stCliente cliente[], int validos);
stCliente CopiarDeArchivoAEstructura (stCliente clienteord[]);
int CantidadDeRegistrosEnArchivo();
int BuscarPosicionMenorDNI (stCliente cliente[], int validos, int i);
void OrdenamientoPorSeleccionDNI (stCliente cliente[], int validos);


/// Pedidos ///

void altaPedido ();
stPedido cargarPedido (stPedido pedido);
int bajaPedido (int idPedido);
stPedido darDeBajaPedido (stPedido pedido);
stPedido modificarUnPedido (stPedido pedido);
int buscarYmodificarPedido (int idPedido);
int buscarIdPedido (FILE *buffer, int idPedido, int*flag);
void mostrarUnPedido (stPedido pedido);
void MostrarPedidosDeUnCliente (int idCliente);
int contarRegistrosPedidos (FILE *buffer);
void CopiarPedidosAarreglo (stPedido pedidos[], int validos);
void MostrarTodosLosPedidos ();
void ordenarPorFecha (stPedido arregloPedidos[], int validos);
void mostrarArregloPedidos(stPedido pedido[], int validos);
int CantidadDeRegistrosPedidos();

void MostrarArchivoPedidos ();
void Top10Clientes (stCliente arregloClientes[], int validos);
int posicionMayor (stCliente arregloClientes[], int pos, int validos);
stCliente peorCliente (stCliente arregloClientes[], int validos);
int posicionMenor (stCliente arregloClientes[], int pos, int validos);
void mostrarTop10 (stCliente arregloClientes[], int validos);

int anioMenor (stPedido arregloPedidos[], int pos, int validos);
int mesMenor (stPedido arregloPedidos[], int pos, int validos);
int diaMenor (stPedido arregloPedidos[], int pos, int validos);

