/*Questão 2 - Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e
o mergesort, usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b);
void bubbleSort(int arr[], int n);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main() {
    srand(time(NULL));

    int sizes[] = {100, 5000, 20000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int arr[size];

        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }

        clock_t start = clock();
        bubbleSort(arr, size);
        clock_t end = clock();
        double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Bubble Sort para tamanho %d: %.4f segundos\n", size, elapsed_time);

        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }

        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();
        elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("QuickSort para tamanho %d: %.4f segundos\n", size, elapsed_time);

        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }

        start = clock();
        mergeSort(arr, 0, size - 1);
        end = clock();
        elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("MergeSort para tamanho %d: %.4f segundos\n\n", size, elapsed_time);
    }

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}