
#ifndef KRUSKAL_H   /* Include guard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

#define VERTICES 5

typedef struct _ARISTA {
    vertice v;
    vertice u;
    int costo;
} arista;

typedef struct _RAMA {
    struct _ARISTA a;
    struct _RAMA * sig;
} rama;

typedef struct _ENCABEZADO {
    int cuenta;
    tipo_elemento primer_elemento;
} encabezado;

typedef struct _NOMBRE {
    tipo_nombre nombre_conjunto;
    tipo_elemento siguiente_elemento;
} nombre;

/*El conjunto combina encuentra está determinado por
un conjunto de encabezados, y de nombres*/
typedef struct _CONJUNTO_CE {
    encabezado encabezado_conjuntos[VERTICES];
    nombre nombres[VERTICES];
} conjunto_ce;


void inicial(tipo_nombre, tipo_elemento, conjunto_ce*);
void combina(tipo_nombre, tipo_nombre, conjunto_ce*);
tipo_nombre encuentra(tipo_elemento, conjunto_ce*);
void kruskal(rama*);

void inserta(int, int, int, rama**);
arista * sacar_min(rama**);
void lista(rama*);


#endif
