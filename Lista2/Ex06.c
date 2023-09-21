/*Questão 6 - Escreva uma função em C que realize uma busca sequencial em uma matriz bidimensional de inteiros para
encontrar um valor específico fornecido pelo usuário. A função deve retornar a posição da primeira ocorrência do valor
ou informar que o valor não foi encontrado*/

#include <stdio.h>

int buscaSequencial(int mat[3][3], int valor, int *linha, int *coluna);

int main() {
    int linha, coluna, mat[3][3] = {12, 5, 8, 11, 6, 2, 13, 3, 9};

    int valorProcurado;
    printf("Digite o valor que deseja procurar na matriz: ");
    scanf("%d", &valorProcurado);

    int encontrado = buscaSequencial(mat, valorProcurado, &linha, &coluna);

    if (encontrado) {
        printf("O valor %d foi encontrado na posicao (%d, %d).\n", valorProcurado, linha, coluna);
    } else {
        printf("O valor %d nao foi encontrado na matriz.\n", valorProcurado);
    }

    return 0;
}

int buscaSequencial(int mat[3][3], int valor, int *linha, int *coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == valor) {
                *linha = i;
                *coluna = j;
                return 1; 
            }
        }
    }
    return 0; 
}