/*Questão 4 - Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de quicksor.*/

#include <stdio.h>

void swap(int* a, int* b);
int partition(int arr[][2], int low, int high);
void quickSort(int arr[][2], int low, int high);

int main() {
    int arr[][2] = {{12, 5}, {11, 6}, {13, 3}, {5, 8}, {6, 1}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[][2], int low, int high) {
    int pivot = arr[high][0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] <= pivot) {
            i++;
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
        }
    }
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    return (i + 1);
}

void quickSort(int arr[][2], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}