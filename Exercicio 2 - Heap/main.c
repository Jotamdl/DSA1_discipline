#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void) {
    int hSize, i;
    
    scanf("%d", &hSize);
    int hData[hSize];
    
    for (i = 0; i < hSize; i++) {
        scanf(" %d", &hData[i]);
    }

    Heap* heap = heap_constroi(hData, hSize);
    heap_imprime(heap);
    
    return 0;
}

/*
Input:
    8
    5 6 1 4 2 8 7 3

Expected output:
    [8, 7, 6, 4, 5, 3, 1, 2]
*/