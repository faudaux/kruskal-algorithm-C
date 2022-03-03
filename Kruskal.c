#include "Kruskal.h"

int main() {
    int M_costos[VERTICES][VERTICES];
    rama * arbol = NULL;

    for (int i = 0; i <= VERTICES - 1; i++) {
        for (int j = (i+1); j <= VERTICES - 1; j++) {
            printf("Ingrese el coste de la arista entre los vertices %d y %d: ", i, j);
            scanf("%d", &M_costos[i][j]);

        }
    }


    for (int i = 0; i <= (VERTICES-1); i++) {
        for (int j = (i+1); j <= (VERTICES-1); j++) {
            if (M_costos[i][j]) {
                inserta(i, j, M_costos[i][j], &arbol);
            }
        }
    }

    printf("Grafo ingresado (prioridad menor a mayor): \n");
    lista(arbol);
    kruskal(arbol);

    return 0;
}




void inicial(tipo_nombre A, tipo_elemento v, conjunto_ce * C) {


    C->nombres[v].nombre_conjunto = A;
    C->nombres[v].siguiente_elemento = 0;

    C->encabezado_conjuntos[A].cuenta = 1;
    C->encabezado_conjuntos[A].primer_elemento = v;


}


void combina(tipo_nombre A, tipo_nombre B, conjunto_ce * C) {
    int i;
    if(C->encabezado_conjuntos[A].cuenta >= C->encabezado_conjuntos[B].cuenta){
        i = C->encabezado_conjuntos[B].primer_elemento;

        while(C->nombres[i].siguiente_elemento != 0){
            C->nombres[i].nombre_conjunto = A;
            i = C->nombres[i].siguiente_elemento;
        }
        C->nombres[i].nombre_conjunto = A;

        C->nombres[i].siguiente_elemento = C->encabezado_conjuntos[A].primer_elemento;

        C->encabezado_conjuntos[A].primer_elemento = C->encabezado_conjuntos[B].primer_elemento;

        C->encabezado_conjuntos[A].cuenta = C->encabezado_conjuntos[A].cuenta + C->encabezado_conjuntos[B].cuenta;

    } else {
        i = C->encabezado_conjuntos[A].primer_elemento;

        while(C->nombres[i].siguiente_elemento != 0){
            C->nombres[i].nombre_conjunto = B;
            i = C->nombres[i].siguiente_elemento;
        }
        C->nombres[i].nombre_conjunto = B;
        C->nombres[i].siguiente_elemento = C->encabezado_conjuntos[B].primer_elemento;
        C->encabezado_conjuntos[B].primer_elemento = C->encabezado_conjuntos[A].primer_elemento;
        C->encabezado_conjuntos[B].cuenta = C->encabezado_conjuntos[B].cuenta + C->encabezado_conjuntos[A].cuenta;
    }
}

tipo_nombre encuentra(tipo_elemento v, conjunto_ce * C) {
    return C->nombres[v].nombre_conjunto;
}


void inserta(int v, int u, int costo, rama** top){
    rama* nueva = NULL;
    rama* aux = *top;
    nueva = (rama*)malloc(sizeof(rama));
    nueva->a.v = v;
    nueva->a.u = u;
    nueva->a.costo = costo;
    nueva->sig = NULL;



    if(aux == NULL){
        *top = nueva;
    } else {
        while(aux->sig != NULL){
            if(aux->sig->a.costo > nueva->a.costo){
                break;
            }
            aux = aux->sig;
        }
        nueva->sig = aux->sig;
        aux->sig = nueva;

    }


}

void lista(rama* top){
    rama * contador = top;

    do {
        printf("Arista %d-%d.\nCosto %d.\n", contador->a.v, contador->a.u, contador->a.costo);
        contador = contador->sig;
    } while(contador->sig != NULL);

    printf("Arista %d-%d.\nCosto %d.\n", contador->a.v, contador->a.u, contador->a.costo);

    return;
}

arista* sacar_min(rama** top){
    rama* contador = *top;
    return &(contador)->a;
}


void kruskal(rama* top){
    int comp_n = VERTICES;

    rama * aux = top;
    rama * T = NULL;
    conjunto_ce * componentes = (conjunto_ce*)malloc(sizeof(conjunto_ce));
    arista* a;
    tipo_nombre comp_siguiente = 0, comp_u, comp_v;


    for(int i = 0; i <= VERTICES-1; i++){
        comp_siguiente++;
        inicial(comp_siguiente, i, componentes);
    }


    while(comp_n > 1){
        a = sacar_min(&aux);
        aux = aux->sig;
        comp_u = encuentra(a->u, componentes);
        comp_v = encuentra(a->v, componentes);

        if(comp_u != comp_v){
            combina(comp_v, comp_u, componentes);
            comp_n = comp_n-1;
            inserta(a->v, a->u, a->costo, &T);
        }
    }

    printf("\n-------------------\n");
    printf("Nuevo arbol: \n");
    printf("-------------------\n");
    lista(T);
}



