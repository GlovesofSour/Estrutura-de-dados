/*Questão 3 - Implemente uma versão do algoritmo de ordenação por inserção que ordene em ordem decrescente em
vez de crescente.*/

#include <stdio.h>

void insertion_sort(int *a);

int main(){

    int i, vetor[5] = {64,7,1,96,28};

    printf("Vetor inicial:\t ");
    for(i = 0 ; i < 5; i++){
        printf("\t%d",vetor[i]);
    }

    insertion_sort(vetor);

    printf("\nVetor ordenado: ");
    for(i = 0 ; i < 5; i++){
        printf("\t%d",vetor[i]);
    }

    return 0;
}

void insertion_sort(int *a){
    int i,j, tmp;

    for(i = 0; i < 5; i++){
        tmp = a[i];
        for(j = i-1; j>= 0 && tmp > a[j]; j--)
        {
            a[j+1] = a[j];
        }
        {
            a[j+1] = tmp;
        }
    }
}