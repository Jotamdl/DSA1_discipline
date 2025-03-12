#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "estudante.h"

// Funcao principal para testes
int main() {
    Lista *lista = criaLista();

    lista = insere(lista, criaEstudante("Alice", 20, 8.5));
    lista = insere(lista, criaEstudante("Bob", 22, 7.8));
    lista = insere(lista, criaEstudante("Carlos", 19, 9.2));
    printf("\nLista atual");
    imprime(lista);
    printf("\nTamanho da lista: %d\n", tamanho(lista));

    lista = retira(lista, "Bob");
    printf("\nLista atual");
    imprime(lista);
    printf("\nTamanho da lista: %d\n", tamanho(lista));

    lista = retira(lista, "Alice");
    printf("\nLista atual");
    imprime(lista);
    printf("\nTamanho da lista: %d\n", tamanho(lista));

    Lista *p = busca(lista, "Daniela");

    if (p) {
        printf("\nEstudante localizada no cadastro!\n");
        imprimeNo(p);
    }
    else
        printf("\nEstudante não localizada no cadastro!\n");

    lista = insere(lista, criaEstudante("Amanda", 18, 7.2));
    printf("\nLista atual");
    imprime(lista);
    printf("\nTamanho da lista: %d\n", tamanho(lista));

    lista = insere(lista, criaEstudante("Daniela", 29, 9.5));
    printf("\nLista atual");
    imprime(lista);

    p = busca(lista, "Daniela");

    if (p) {
        printf("\nEstudante localizada no cadastro!\n");
        imprimeNo(p);
    }
    else
        printf("\nEstudante não localizada no cadastro!\n");

    destroiLista(lista);
    printf("\nTamanho da lista: %d\n", tamanho(lista));

    return 0;
}
