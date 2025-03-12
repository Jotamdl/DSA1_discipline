//////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementacao do TAD Lista duplamente encadeada para armazenar dados do TAD Estudante    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estudante.h"
#include "lista.h"


/* Observe que a interface será a mesma (lista.h) de lista simplemente encadeada mas a mplementação do tipo (struct + funções - lista.c) precisam corresponder a litta duplamente encadeada*/

struct lista {
    Estudante *aluno;
    struct lista *ant;
    struct lista *prox;
};


Lista* criaLista (){
    return NULL;
}

// Insere um estudante no início da lista
Lista* insere(Lista *l, Estudante *e) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return l;

    novo->aluno = e;
    novo->prox = l;
    novo->ant = NULL;

    if (l) l->ant = novo;

    return novo; // Retorna o novo início da lista
}

// Remove um estudante pelo nome
Lista* retira(Lista *l, const char *nome) {
    Lista *atual = l;
    while (atual) {
        if (strcmp(getNome(atual->aluno), nome) == 0) {
            if (atual->ant)
                atual->ant->prox = atual->prox;
            else
                l = atual->prox; // Atualiza o início da lista

            if (atual->prox)
                atual->prox->ant = atual->ant;

            destroiEstudante(atual->aluno);
            free(atual);
            return l;
        }
        atual = atual->prox;
    }
    return l;
}


// Destroi a lista, liberando memória
void destroiLista(Lista *l) {
    Lista *atual = l;
    while (atual) {
        Lista *temp = atual;
        atual = atual->prox;
        destroiEstudante(temp->aluno);
        free(temp);
    }
}

//-----------------Novas funções-------------------
// Implementar função para imprimir toda a lista de estudantes
void imprime(Lista *l){
    Lista *t = l;
    
    if (t!=NULL) {
        imprimeEstudante(t->aluno);
        imprime(t->prox);
    }
    return;
}

// Implementar função para imprimir somente um nó da lista de estudantes apontado por p
void imprimeNo(Lista *p){
    imprimeEstudante(p->aluno);
    return;
}

// Implementar função de busca um estudante pelo nome, retorna o ponteiro para o nó, se encontrado e, NULL, caso contrário
Lista* busca(Lista *l, char* nome){
    Lista *t = l;
    while (t) {
        if(strcmp(getNome(t->aluno), nome) == 0) {
            return t;
        }
        t = t->prox;
    }
    return NULL;
}
// Implementar função de retorna o comprimento da lista
int tamanho(Lista *l){
    int count = 0;
    Lista *t = l;

    while (t != NULL) {
        count++;
        t = t->prox;
    }
    return count;
}
