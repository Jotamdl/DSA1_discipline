#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void) {

    Heap* heap = heap_cria(10);

    int hData;
    
    while (scanf("%d", &hData) == 1) {
        heap_insere(heap, hData);
        heap_imprime(heap);
    }
    while (!heap_vazia(heap)) {
        heap_retira_imprime(heap);
    }    
    
    return 0;
}

/*
Input:
   45 20 75 15 90 30 10 60 5 85 100 25

Expected output:
    Inserindo: 45
    Heap atual: 45
    Inserindo: 20
    Heap atual: 45 20
    Inserindo: 75
    Heap atual: 75 20 45
    Inserindo: 15
    Heap atual: 75 20 45 15
    Inserindo: 90
    Heap atual: 90 75 45 15 20
    Inserindo: 30
    Heap atual: 90 75 45 15 20 30
    Inserindo: 10
    Heap atual: 90 75 45 15 20 30 10
    Inserindo: 60
    Heap atual: 90 75 45 60 20 30 10 15
    Inserindo: 5
    Heap atual: 90 75 45 60 20 30 10 15 5
    Inserindo: 85
    Heap atual: 90 85 45 60 75 30 10 15 5 20
    Capacidade aumentada para: 20
    Inserindo: 100
    Heap atual: 100 85 90 60 75 30 10 15 5 20 45
    Inserindo: 25
    Heap atual: 100 85 90 60 75 30 10 15 5 20 45 25
    100
    90
    85
    75
    60
    45
    30
    25
    20
    15
    10
    5
*/