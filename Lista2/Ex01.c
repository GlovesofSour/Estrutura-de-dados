/*Questão 1 - Escreva um programa em C que ordena um array 
de inteiros usando o algoritmo de ordenação por bolha.*/

#include <stdio.h>

void bubble_sort (int vetor[]);

int main(){

    int i, vetor[5] = {64,7,1,96,28};

    printf("Vetor inicial:\t ");
    for(i = 0 ; i < 5; i++){
        printf("\t%d", vetor[i]);
    }

    bubble_sort(vetor);

    printf("\nVetor ordenado: ");
    for(i = 0 ; i < 5; i++){
        printf("\t%d",vetor[i]);
    }

    return 0;
}

void bubble_sort (int vetor[]) {
    int i, j, aux;

    for (i = 1; i < 5; i++) {

        for (j = 0; j < 5 - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}