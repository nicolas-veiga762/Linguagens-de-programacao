#include <stdio.h>
#include <math.h>

void inc_dec(int *a, int *b) {
    (*a)++;
    (*b)--; 
}

void troca_valor(float *x, float *y) {
    float temp = 0;
    printf("Valores antes: %f e %f\n", *x, *y);
    temp = *x;
    *x = *y;
    *y = temp;  
    printf("Valores depois: %f e %f\n", *x, *y);
}

void calcula_circulo(float raio, float *perimetro, float *area) {
    *perimetro = 2 * 3.14 * raio;
    *area = 3.14 * pow(raio, 2);

    printf("Area: %f | Perimetro : %f", *area, *perimetro);
}

void calcula_hora(int totalMinutos, int *ph, int *pm) {
    *ph = totalMinutos / 60;
    *pm = totalMinutos % 60;
}

void max_min(int vet[], int tam, int *min, int *max) {
    *min = vet[0];
    *max = vet[0];
    for(int i = 1; i < tam; i++) {
        if (vet[i] < *min) {
            *min = vet[i];
        }
        if (vet[i] > *max) {
            *max = vet[i];
        }
    }
    printf("Maior valor: %d | Menor valor: %d\n", *max, *min);
}

void max_vetor(float vet[], int tam, float *max, int *indice) {
    *max = vet[0];
    *indice = 0;
    for(int i = 1; i < tam; i++) {
        if (vet[i] > *max) {
            *max = vet[i];
            *indice = i;
        }
    }
    printf("O valor %.2f, e o maior valor do vetor, e esta na posicao %i", *max, *indice);
}

void min_matriz(float mat[3][4], float *min, int *linha, int *coluna) {
    *min = mat[0][0];
    *linha = 0;
    *coluna = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] < *min) {
                *min = mat[i][j];
                *linha = i;
                *coluna = j;
            }
        }
    }

    printf("Menor valor: %.2f | Linha: %d | Coluna: %d\n", *min, *linha, *coluna);
}


int main(void) {
    printf("Ola professor Rui, escolha uma das opcoes a seguir para corrigir as questoes\n");
    printf("1 - inc_dec\n");
    printf("2 - troca_valor\n");
    printf("3 - calcula_circulo\n");
    printf("4 - calcula_hora\n");
    printf("5 - max_min\n");
    printf("6 - max_vetor\n");
    printf("7 - min_matriz\n");

    printf("\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            int c, d;
            scanf("%d", &c);
            scanf("%d", &d);
            inc_dec(&c, &d);
            printf("%d %d", c, d);
            break;
        }
        case 2: {
            float a, b;
            scanf("%f", &a);
            scanf("%f", &b);
            troca_valor(&a, &b);
            break;
        }
        case 3: {
            float r, area, perimetro;
            printf("Digite o raio do circulo: ");
            scanf("%f", &r);
            calcula_circulo(r, &perimetro, &area);
            break;
        }
        case 4: {
            int total, h, m;
            printf("Digite o total de minutos passados desde meia-noite: ");
            scanf("%d", &total);
            calcula_hora(total, &h, &m);
            printf("Hora atual: %02d:%02d\n", h, m);
            break;
        }
        case 5: {
            int n; 
            printf("Digite a capacidade do vetor: ");
            scanf("%d", &n);
            
            int vet[n]; 
            
            printf("Digite os valores do vetor: \n");
            for(int i = 0; i < n; i++) {
                scanf("%d", &vet[i]);
            }    
            
            int max = 0, min = 0;

            max_min(vet, n, &min, &max);
            break;
        }
        case 6: {
            int n;
            printf("Digite a capacidade do vetor: ");
            scanf("%d", &n);

            float vet[n];
            printf("Digite os valores do vetor:\n");
            for (int i = 0; i < n; i++) {
                scanf("%f", &vet[i]);
            }
        
            float max;
            int indice;
            max_vetor(vet, n, &max, &indice);
            break;
        }
        case 7: {
            float mat[3][4];

            printf("Digite os valores da matriz 3x4:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    scanf("%f", &mat[i][j]);
                }
            }
        
            float min;
            int iMin, jMin;
        
            min_matriz(mat, &min, &iMin, &jMin);
            break;
        }
    } 
    return 0;
}
