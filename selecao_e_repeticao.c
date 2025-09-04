#include <stdio.h>

void coordenadas (float x, float y) {
    if (x == 0 && y == 0) {
        printf("Origem\n");
    } else if (x == 0) {
        printf("Seu ponto está sobre o eixo y\n");
    } else if (y == 0) {
        printf("Seu ponto está sobre o eixo x\n");
    } else if (x>0 && y>0) {
        printf("Q1\n");
    } else if (x<0 && y<0) {
        printf("Q3\n");
    } else if (x>0 && y<0) {
        printf("Q4\n");
    } else {
        printf("Q2\n");
    }
}

int tipos_triangulos (float x, float y, float z) {
    float ordenador;

    if (x < y) ordenador = x; x = y; y = ordenador;
    if (x < z) ordenador = x; x = z; z = ordenador;
    if (y < z) ordenador = y; y = z; z = ordenador;

    if (x >= y+z) {
        printf("NAO FORMA TRIANGULO");
    } else if (x*x == y*y + z*z) {
        printf("TRIANGULO RETANGULO");
    } else if (x*x > y*y + z*z) {
        printf("TRIANGULO OBTUSANGULO");
    } else if (x*x < y*y + z*z) {
        printf("TRIANGULO ACUTANGULO");
    } else if (x == y == z) {
        printf("TRIANCULO EQUILATERO");
    } else if (x == y || y == z || x == z) {
        printf("TRIANGULO ISOSCELES");
    }


}


int main() {
    printf("Bom dia professor Rui, escolha uma das opções a seguir para corrigir as questões\n");
    printf("1 - Coordenadas de um Ponto\n");
    printf("2 - Tipos de Triangulos\n");
    printf("3 - Tempo de Jogo\n");
    printf("4 - Pares, Impares, Positivos e Negativos\n");
    printf("5 - Médias Ponderadas\n");
    printf("6 - Soma de Impares Consecutivos I\n");
    printf("7 - Soma de Impares Consecutivos II\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        float a, b;
        scanf("%f %f", &a, &b);
        coordenadas(a, b);
        return 0;
    break;
    case 2: 
        float c, d, e;
        scanf("%f %f %f", &c, &d, &e);
        tipos_triangulos(c, d, e);
        return 0;
    break;
    default:
        break;
    }
    
}