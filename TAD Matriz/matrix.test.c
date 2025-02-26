#include <stdio.h>
#include "matriz.h"

int main(void) {
    Matriz* mat = matriz_create(2,3);

    matriz_set(mat, 0, 0, 1);
    matriz_set(mat, 0, 1, 7);
    matriz_set(mat, 0, 2, 8);
    matriz_set(mat, 1, 0, 5);
    matriz_set(mat, 1, 1, 3);
    matriz_set(mat, 1, 2, 2);

    Matriz* mat2 = matriz_create(3,3);

    matriz_set(mat2, 0, 0, 1);
    matriz_set(mat2, 0, 1, -2);
    matriz_set(mat2, 0, 2, 4);
    matriz_set(mat2, 1, 0, -2);
    matriz_set(mat2, 1, 1, 2);
    matriz_set(mat2, 1, 2, 0);
    matriz_set(mat2, 2, 0, 4);
    matriz_set(mat2, 2, 1, 0);
    matriz_set(mat2, 2, 2, 3);

    matriz_print(mat);
    printf("\n\n");
    
    mat = matriz_transpose(mat);
    matriz_print(mat);
    printf("\n\n");
    
    mat = matriz_scalar_mul(mat, 2);
    matriz_print(mat);
    printf("\n\n");
    
    mat = matriz_add(mat, mat);
    matriz_print(mat);
    printf("\n\n");
    
    printf("%d\n\n", matriz_is_symmetric(mat));
    
    mat = matriz_sub(mat, mat);
    matriz_print(mat);
    printf("\n\n");
    
    printf("%d\n\n", matriz_is_symmetric(mat2));
    
    return 0;
}
