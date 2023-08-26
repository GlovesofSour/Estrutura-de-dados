/*Questão 2 - Crie uma struct chamada "Tipo" que possa armazenar um valor do tipo inteiro, um valor do tipo ponto
flutuante e uma letra. Escreva um programa que demonstre o uso da struct, atribuindo valores de diferentes tipos e
imprimindo-os.*/

#include <stdio.h>

int main(void){

    typedef struct{
        int inteiro;
        float ponto_flutuante;
        char letra;
    }Tipo;

    Tipo tipo;

    printf("\n======== TIPOS DE VALORES ========\n");
        printf("\nDigite um numero inteiro: ");
        scanf("%d", &tipo.inteiro);
        printf("Digite um numero real: ");
        scanf("%f", &tipo.ponto_flutuante);
        fflush(stdin);
        printf("Digite uma letra: ");
        scanf("%c", &tipo.letra);
        printf("\n==================================\n");

        printf("\n======= VALORES IMPRESSOS ========\n");
        printf("\nInteiro: %d", tipo.inteiro);
        printf("\nPonto Flutuante: %f", tipo.ponto_flutuante);
        printf("\nCaracter: %c", tipo.letra);
        printf("\n\n==================================\n");
    
    return 0;
}