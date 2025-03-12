#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 1000

struct pilha {
    int n; /* vet[n]: primeira posição livre do vetor */
    int vet[N]; /* vet[n-1]: topo da pilha */
/* vet[0] a vet[N-1]: posições ocupáveis */
};

Pilha* pilha_cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}

void pilha_push (Pilha* p, float v)
{
    if (p->n == N) { /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++; /* equivalente a: p->n = p->n + 1 */
}

float pilha_pop (Pilha* p)
{ 
    float v;
    if (pilha_vazia(p)) { 
        printf("Pilha vazia.\n");
        exit(1); 
    } /* aborta programa */
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

int pilha_vazia (Pilha *p)
{
    return p->n == 0; /*Return 1 se pilha vazia*/
}

