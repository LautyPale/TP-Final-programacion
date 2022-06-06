#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define

typedef struct{
char nombre[30];
char apellido[30];
unsigned char mail[40]; /// 0 a 255 ASCII | especificador de formato: %c
unsigned long int telefono; /// 0 a 4,294,967,295 | especificador de formato: %lu
int dni;
char calleDireccion[50];
int calleNumero;
int idcliente;
int bajacliente;
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
idcliente
}stPedido;

int main()
{
    stCliente aux;
    aux = CargarUnCliente (aux);
    MostrarUnCliente (aux);


    return 0;
}
