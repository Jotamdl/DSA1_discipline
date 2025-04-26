#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

struct heap {
    int n;      // numero de elementos armazenados no heap
    int nmax;   // numero maximo de elementos no heap
    int * v;  // vetor de prioridades

};

Heap* heap_cria (int nmax){

    Heap* h = (Heap *) malloc( sizeof(Heap));
    h->n = 0;
    h-> nmax = nmax;
    h->v = (int *) malloc(h-> nmax*sizeof (int ));
    return h;
}

void heap_libera (Heap* h){

    free(h->v);
    free(h);
}

int heap_vazia (Heap* h){

    return (h->n==0);

}

static void troca (Heap* h, int i, int j){

    int tmp = h->v[i]; h->v[i] = h->v[j];
    h->v[j] = tmp;
}

static void sobe (Heap* h, int i) {
    //a partir do no i
    while (i > 0) {
        int p = pai(i); //p e a raiz de i
        if (h->v[p] > h->v[i]) break ; //se a raiz e maior que i esta em ordem, nada a fazer
        troca(h,p,i); //senoo troca
        i = p; // e verifica novel acima o novel
    }
}

void heap_insere (Heap* h, int value){
    if (h->n==h->nmax) {
        h->nmax *= 2;
        h->v = (int*) realloc(h->v, h->nmax * sizeof(int));;
        printf("Capacidade aumentada para: %d\n", h->nmax);
    }
    
    printf("Inserindo: %d\n", value);
    h->v[h->n++] = value;
    sobe(h,h->n-1);
}

static void desce (Heap* h, int i)
{
    // pai e o i
    int c = esq(i); //c e o filho esquerdo
    while (c < h->n) {
        int c2 = dir(i);    //c2 e o filho direito
        if (c2 < h->n && h->v[c2] > h->v[c])
            c = c2; //escolhe o maior e compara com o pai
        if (h->v[c] < h->v[i])
            break ; //se o pai e maior que o filho, mantem
        troca(h,i,c);   //senao troca os valores
        i = c;
        c = esq(i);
    }
}

int heap_retira (Heap* h) {

    int r = h->v[0];
    h->v[0] = h->v[--h->n];
    desce(h,0);
    return r;
}

void heap_retira_imprime(Heap* h) {
    printf("%d\n",heap_retira(h));
}

Heap* heap_constroi (int* vec, int size) {
    Heap* h = heap_cria(size);
    h->n=size;
    int i;
    int j = 0;
    for (i = (int)size/2; i < size; i++) {
        h->v[i] = vec[j++];
    }
    for (i = (int)size/2; i > 0; i--) {
        h->v[i-1] = vec[j++];
        desce(h, i-1);
    }
    
    return h;
}

void heap_imprime(Heap* h) {
    printf("Heap atual:");
    for (int i = 0; i < h->n; i++) {
        printf(" %d",h->v[i]);
    } 
    printf("\n");

}
