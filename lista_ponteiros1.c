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
            break;
        }
        case 6: {
            break;
        }
        case 7: {
            break;
        }
    } 
    return 0;
}
