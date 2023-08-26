/*Questão 3 - Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y.
Em seguida, implemente funções para calcular a distância entre dois pontos e a inclinação da reta que os conecta.*/

#include <stdio.h>
#include <math.h>

// Definição da struct Ponto
struct Ponto {
    float x;
    float y;
};

// Função para calcular a distância entre dois pontos
float calcularDistancia(struct Ponto p1, struct Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Função para calcular a inclinação da reta entre dois pontos
float calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    if (p2.x - p1.x == 0) {
        // Evitar divisão por zero (reta vertical)
        return INFINITY;
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main() {
    struct Ponto ponto1 = {2.0, 3.0};
    struct Ponto ponto2 = {5.0, 7.0};

    printf("Distância entre os pontos: %.2f\n", calcularDistancia(ponto1, ponto2));
    printf("Inclinação da reta: %.2f\n", calcularInclinacao(ponto1, ponto2));

    return 0;
}

