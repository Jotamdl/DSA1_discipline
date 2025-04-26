#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

struct avl {
    char info;
    struct avl* esq;
    struct avl* dir;
    int altura;
};

// Funcao para criar um novo no Avl
Avl* Avl_cria (char c) {
    Avl* p = (Avl*)malloc(sizeof(Avl));
    if (p == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return NULL;
    }

    p->info = c;
    p->esq = NULL;
    p->dir = NULL;
    p->altura = 1; // Um novo no comeca com altura 1
    return p;
}


// Raiz apontando para NULL
Avl* Avl_criavazia (void){

    return NULL;
}


// ordem crescente, simetrica
void Avl_imprime (Avl* r){
    if (r != NULL ){
        Avl_imprime(r-> esq); // imprime sae /
        printf("%c ", r-> info); //mostra informacao /
        Avl_imprime(r-> dir); // imprime sad /
    }
}

// Funcao recursiva para liberar os nos a partir da raiz r
void Avl_libera (Avl* r){
    if (r != NULL) {
        Avl_libera(r-> esq); //libera das folhas
        Avl_libera(r-> dir); // ate chegar a
        free(r);         //raiz r
    }
}


// Busca de acordo com a arvoreordenacao da arvore - O(log n) arvore balanceada
Avl* Avl_busca (Avl* r, char c){
    if (r == NULL) return NULL; // arvore vazia, nao encontrou
    else if (c == r-> info) return r;
    else if (c < r->info) return Avl_busca(r->esq, c);
    else return Avl_busca(r->dir,c);
}

// Funcao para retornar o maior valor entre dois inteiros
static int maximo (int a, int b) {
    return (a > b) ? a : b;
}

// Funcao para obter a altura de um no Avl
static int altura (Avl* a) {
    if (a == NULL) {
        return 0;
    }
    return a->altura;
}

// Funcao para atualizar a altura de um no Avl
static void atualizaAltura(Avl* a) {
    if (a != NULL) {
        a->altura = 1 + maximo(altura(a->esq), altura(a->dir));
    }
}

// Funcao para calcular o fator de balanceamento de um no Avl
int fatorBalanceamento(Avl* a) {
    if (a == NULL) {
        return 0;
    }

    return altura(a->esq) - altura(a->dir);
}

// Funcao para rotacao simples a esquerda na arvore Avl
Avl* rotacaoEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL) {
        return a; // Nenhuma rotacao necessaria
    }
    printf("\nRotacao a esquerda em %c", a->info);
    Avl* pivo = a->dir;
    a->dir = pivo->esq;
    pivo->esq = a;
    // Atualiza alturas
    atualizaAltura(a);
    atualizaAltura(pivo);
    return pivo; // Novo no raiz apos a rotacao
}

// Funcao para rotacao simples a direita na arvore Avl
Avl* rotacaoDireita(Avl* a) {
    printf("\nRotacao a direita em %c", a->info);
    if (a == NULL || a->esq == NULL) {
        return a; // Nenhuma rotacao necessaria
    }

    Avl* pivo = a->esq;
    a->esq = pivo->dir;
    pivo->dir = a;

    // Atualiza alturas
    atualizaAltura(a);
    atualizaAltura(pivo);

    return pivo; // Novo no raiz apos a rotacao
}

// Funcao para rotacao dupla a direita (rotacao esquerda-direita)
Avl* rotacaoEsquerdaDireita(Avl* a) {
    if (a == NULL || a->esq == NULL) {
        return a; // Nenhuma rotacao necessaria
    }
    a->esq = rotacaoEsquerda(a->esq);
    return rotacaoDireita(a);
}

// Funcao para rotacao dupla a esquerda (rotacao direita-esquerda)
Avl* rotacaoDireitaEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL) {
        return a; // Nenhuma rotacao necessaria
    }
    a->dir = rotacaoDireita(a->dir);
    return rotacaoEsquerda(a);
}

// Funcao para rebalancear um no AVL apos insercao ou remocao
Avl* reequilibrar(Avl* a) {
    if (a == NULL) {
        return NULL;
    }
    // Atualiza a altura do no atual
    atualizaAltura(a);
    // Verifica o fator de balanceamento
    int fb = fatorBalanceamento(a);
    // Caso 1: Desbalanceamento para a direita (Rotacao Esquerda)
    if (fb < -1) {
        if (fatorBalanceamento(a->dir) > 0) {
            printf("\nRotacao dupla a direita-esquerda");
            a->dir = rotacaoDireita(a->dir);
            return rotacaoEsquerda(a);
        } else {
            printf("\nRotacao simples a esquerda");
            return rotacaoEsquerda(a);
        }
    }
    // Caso 2: Desbalanceamento para a esquerda (Rotacao Direita)
    if (fb > 1) {
        if (fatorBalanceamento(a->esq) < 0) {
            printf("\nRotacao dupla a esquerda-direita");
            a->esq = rotacaoEsquerda(a->esq);
            return rotacaoDireita(a);
        } else {
        printf("\nRotacao simples a direita");
        return rotacaoDireita(a);
        }
    }
    return a; // Nenhum rebalanceamento necessorio
}


// Funcao de insercao
Avl* Avl_insere (Avl* a, char info){
    // Caso base: se o no for NULL, cria um novo no com a chave
    if (a == NULL) {
        printf("Insercao do no: %c", info);
        return Avl_cria(info);
    }

    if (info < a->info) {
        a->esq = Avl_insere(a->esq, info);
    } else if (info > a->info) {
        a->dir = Avl_insere(a->dir, info);
    }

    // Rebalanceia a arvore AVL apos a insercao
    return reequilibrar(a);
}

// Funcao de remocao
Avl* Avl_retira (Avl* r, int c){

    // arvore vazia
    if (r == NULL)
        return NULL;

    else if (r-> info > c)
        r-> esq = Avl_retira(r->esq , c);
    else if (r-> info < c)
        r-> dir = Avl_retira(r->dir, c);
    else {//achou o elemento
        printf("Remocao do no: %c", c);
        // Caso 1: basta liberar a memoria alocada pelo elemento e ter como valor de retorno a raiz atualizada, que passa a ser NULL.
        if (r-> esq == NULL && r-> dir == NULL) {
            free (r);
            r = NULL;
        }
        // Caso 2: so um filho a direita
        else if (r-> esq == NULL) {
            Avl* t = r;
            r = r-> dir;
            free (t);
        }
        // so tem um filho a esquerda
        else if (r-> dir == NULL) {
            Avl* t = r;
            r = r-> esq;
            free (t);
        }
        // Caso 3:
        else {
            Avl* f = r-> esq;
            while (f-> dir != NULL) {
                f = f-> dir;
            }
            r-> info = f-> info;
            f-> info = c;
            r-> esq = Avl_retira(r->esq ,c);
        }
       }

        return reequilibrar(r);
}
