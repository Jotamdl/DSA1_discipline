#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#define MAX(x,y) ((x) > (y) ? (x) : (y))

struct Matriz {
    double** array;
    int rows;
    int cols;
};

Matriz* matriz_create(int rows, int cols) {
    Matriz* matriz = malloc(sizeof(Matriz));

    matriz->array = malloc(sizeof(double*) * rows);
    for (int i = 0; i < rows; i++) {
        matriz->array[i] = malloc(sizeof(double) * cols);
    }
    matriz->rows = rows;
    matriz->cols = cols;

    return matriz;
}

void matriz_destroy(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        free(matriz->array[i]);
    }
    free(matriz->array);
    free(matriz);
}

void matriz_print(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        for (int j = 0; j < matriz->cols; j++) {
            printf("%.4f ", matriz->array[i][j]);
        }
        printf("\n");
    }
}

double matriz_get(Matriz* matriz, int row, int col) {
    return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, double value) {
    matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz) {
    return matriz->rows;
}

int matriz_cols(Matriz* matriz) {
    return matriz->cols;
}

bool matriz_equals(Matriz* matriz1, Matriz* matriz2) {
    if (matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols) {
        return false;
    }

    for (int i = 0; i < matriz1->rows; i++) {
        for (int j = 0; j < matriz1->cols; j++) {
            if (matriz1->array[i][j] != matriz2->array[i][j]) {
                printf("\n%f != %f\n",matriz1->array[i][j],matriz2->array[i][j]);
                return false;
            }
        }
    }

    return true;

}

Matriz* matriz_add(Matriz* matriz1, Matriz* matriz2) {
    int rows = MAX(matriz1->rows, matriz2->rows);
    int cols = MAX(matriz1->cols, matriz2->cols);
    Matriz* matriz3 = matriz_create(rows, cols);

    double cell1, cell2;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cell1 = (matriz1->rows <= r || matriz1->cols <= c) ? 0 : matriz1->array[r][c];
            cell2 = (matriz2->rows <= r || matriz2->cols <= c) ? 0 : matriz2->array[r][c];

            matriz3->array[r][c] = cell1 + cell2;
        }
    }

    return matriz3;
}

Matriz* matriz_sub(Matriz* matriz1, Matriz* matriz2) {
    int rows = MAX(matriz1->rows, matriz2->rows);
    int cols = MAX(matriz1->cols, matriz2->cols);
    Matriz* matriz3 = matriz_create(rows, cols);

    double cell1, cell2;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cell1 = (matriz1->rows <= r || matriz1->cols <= c) ? 0 : matriz1->array[r][c];
            cell2 = (matriz2->rows <= r || matriz2->cols <= c) ? 0 : matriz2->array[r][c];

            matriz3->array[r][c] = cell1 - cell2;
        }
    }

    return matriz3;
}

Matriz* matriz_scalar_mul(Matriz* matriz, double scalar) {
    int rows = matriz->rows;
    int cols = matriz->cols;
    Matriz* matriz3 = matriz_create(rows, cols);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            matriz3->array[r][c] = matriz->array[r][c] * scalar;
        }
    }

    return matriz3;
}

Matriz* matriz_transpose(Matriz* matriz) {
    int rows = matriz->rows;
    int cols = matriz->cols;
    Matriz* matriz3 = matriz_create(cols, rows);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            matriz3->array[c][r] = matriz->array[r][c];
        }
    }

    return matriz3;
}


bool matriz_is_symmetric(Matriz* matriz) {
    Matriz* matriz3 = matriz_transpose(matriz);

    return matriz_equals(matriz, matriz3);
}
