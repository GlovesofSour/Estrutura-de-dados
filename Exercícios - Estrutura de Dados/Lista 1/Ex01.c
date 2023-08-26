/*Questão 1 - Crie uma struct chamada "Pessoa" que contenha os seguintes campos: nome, idade e altura. Em seguida,
escreva um programa que declare uma variável do tipo Pessoa, preencha seus campos e imprima os valores..*/

#include <stdio.h>

int main(void){

    typedef struct{
        char nome[20];
        int idade;
        float altura;
    }Pessoa;

    Pessoa pessoa;
        
        printf("\n======= CADASTRO DE PESSOA =======\n");
        printf("\nDigite o seu Nome: ");
        fflush(stdin);
        fgets(pessoa.nome, 20, stdin);
        printf("Digite a sua idade: ");
        scanf("%d", &pessoa.idade);
        printf("Digite a sua altura: ");
        scanf("%f", &pessoa.altura);
        printf("\n\n==================================\n");

        printf("\n======= REGISTRO DE PESSOA =======\n");
        printf("\nNome: %s", pessoa.nome);
        printf("idade: %d", pessoa.idade);
        printf("\nAltura: %.2f", pessoa.altura);
        printf("\n\n==================================\n");
    
    return 0;
}
