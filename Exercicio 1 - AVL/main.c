#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void) {
    char c;
    Avl* arv = Avl_criavazia();
    
    while (1) {
        scanf(" %c", &c);
        if (c == '0') {
            break;
        }
        arv = Avl_insere(arv, c);
        printf("\nArvore em ordem: ");
        Avl_imprime(arv);
        printf("\n");
    }
    while (1) {
        scanf(" %c", &c);
        if (c == '0') {
            break;
        }
        arv = Avl_retira(arv, c);
        printf("\nArvore em ordem: ");
        Avl_imprime(arv);
        printf("\n");
    }

    return 0;
}

/*
Input:
    f
    d
    b
    e
    g
    i
    h
    0
    b
    d
    e
    0

Expected output:
    Insercao do no: f
    Arvore em ordem: f 

    Insercao do no: d
    Arvore em ordem: d f 

    Insercao do no: b
    Rotacao simples a direita
    Rotacao a direita em f
    Arvore em ordem: b d f 

    Insercao do no: e
    Arvore em ordem: b d e f 

    Insercao do no: g
    Arvore em ordem: b d e f g 

    Insercao do no: i
    Rotacao simples a esquerda
    Rotacao a esquerda em d
    Arvore em ordem: b d e f g i 

    Insercao do no: h
    Rotacao dupla a direita-esquerda
    Rotacao a direita em i
    Rotacao a esquerda em g
    Arvore em ordem: b d e f g h i 

    Remocao do no: b
    Arvore em ordem: d e f g h i 

    Remocao do no: d
    Arvore em ordem: e f g h i 

    Remocao do no: e
    Rotacao simples a esquerda 
    Rotacao a esquerda em f
    Arvore em ordem: f g h i 
*/