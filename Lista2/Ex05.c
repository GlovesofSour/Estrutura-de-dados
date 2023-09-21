/*Questão 5 - Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de ordenação por inserção.*/

#include <stdio.h>

void insertionSort(int arr[][2], int n);

int main() {
    int mat[][2] = {{12, 5}, {11, 6}, {13, 3}, {5, 8}, {6, 1}};
    int n = sizeof(mat) / sizeof(mat[0]);

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", mat[i][0], mat[i][1]);
    }

    insertionSort(mat, n);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", mat[i][0], mat[i][1]);
    }

    return 0;
}

void insertionSort(int arr[][2], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int key1 = arr[i][0];
        int key2 = arr[i][1];
        j = i - 1;

        while (j >= 0 && arr[j][0] > key1) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            j = j - 1;
        }

        arr[j + 1][0] = key1;
        arr[j + 1][1] = key2;
    }
}