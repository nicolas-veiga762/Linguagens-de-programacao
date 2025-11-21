#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float *clona_vetor(float v[], int n) {
    float *p = malloc(n * sizeof(float));
    if (!p) return NULL;
    for (int i = 0; i < n; i++) {
        p[i] = v[i];
    }
    return p;
}

char *repete_string(const char *s, int vezes) {
    if (vezes <= 0) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    int len = strlen(s);
    long total = (long)len * vezes + 1;
    char *res = malloc(total);
    if (!res) return NULL;
    res[0] = '\0';
    for (int i = 0; i < vezes; i++) {
        strcat(res, s);
    }
    return res;
}

float *filtra_acima_media(float v[], int n, int *tamFiltrado) {
    float soma = 0.0f;
    for (int i = 0; i < n; i++) soma += v[i];
    float media = soma / n;

    float *p = malloc(n * sizeof(float));
    if (!p) {
        *tamFiltrado = 0;
        return NULL;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) {
            p[j++] = v[i];
        }
    }
    *tamFiltrado = j;
    return p;
}

void separa_pos_neg(int v[], int n, int **ppos, int *tpos, int **pneg, int *tneg) {
    int *pos = malloc(n * sizeof(int));
    int *neg = malloc(n * sizeof(int));
    if (!pos || !neg) {
        if (pos) free(pos);
        if (neg) free(neg);
        *ppos = NULL; *pneg = NULL;
        *tpos = *tneg = 0;
        return;
    }
    int ip = 0, in = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= 0) {
            pos[ip++] = v[i];
        } else {
            neg[in++] = v[i];
        }
    }
    *ppos = realloc(pos, ip * sizeof(int));
    *pneg = realloc(neg, in * sizeof(int));
    *tpos = ip;
    *tneg = in;
}

int *multiplos_de3(int v[], int n, int *p3) {
    int *p = malloc(n * sizeof(int));
    if (!p) {
        *p3 = 0;
        return NULL;
    }
    int contp3 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 3 == 0) {
            p[contp3++] = v[i];
        }
    }
    *p3 = contp3;
    p = realloc(p, contp3 * sizeof(int));
    return p;
}

void ex01(void) {
    int n;
    printf("Ex01 - clona_vetor\n");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float vet[n];
    printf("Digite os valores do vetor (float):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &vet[i]);
    }
    float *c = clona_vetor(vet, n);
    if (!c) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    printf("Vetor clonado:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");
    free(c);
}

void ex02(void) {
    printf("Ex02 - repete_string\n");
    char s[201];
    int vezes;
    printf("Digite a string (max 200 chars): ");
    scanf(" ");
    fgets(s, sizeof(s), stdin);
    size_t L = strlen(s);
    if (L > 0 && s[L-1] == '\\n') s[L-1] = '\\0';
    printf("Digite o numero de repeticoes: ");
    scanf("%d", &vezes);

    char *r = repete_string(s, vezes);
    if (!r) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    printf("Resultado: %s\n", r);
    free(r);
}

void ex03(void) {
    printf("Ex03 - filtra_acima_media\n");
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float vet[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%f", &vet[i]);
    }
    int tamFiltrado = 0;
    float *res = filtra_acima_media(vet, n, &tamFiltrado);
    if (!res) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    printf("Media filtrada - elementos acima da media (%.2f):\n", 0.0); 
    if (tamFiltrado == 0) {
        printf("Nenhum elemento acima da media\n");
    } else {
        for (int i = 0; i < tamFiltrado; i++) {
            printf("%.2f ", res[i]);
        }
        printf("\n");
    }
    free(res);
}

void ex04(void) {
    printf("Ex04 - separa_pos_neg\n");
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vet[i]);
    }
    int *pos = NULL, *neg = NULL;
    int tpos = 0, tneg = 0;
    separa_pos_neg(vet, n, &pos, &tpos, &neg, &tneg);
    printf("Positivos (ou zero) - %d elementos:\n", tpos);
    for (int i = 0; i < tpos; i++) {
        printf("%d ", pos[i]);
    }
    printf("\nNegativos - %d elementos:\n", tneg);
    for (int i = 0; i < tneg; i++) {
        printf("%d ", neg[i]);
    }
    printf("\n");
    free(pos);
    free(neg);
}

void ex05(void) {
    printf("Ex05 - multiplos_de3\n");
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vet[i]);
    }
    int qtd = 0;
    int *p = multiplos_de3(vet, n, &qtd);
    if (!p && qtd > 0) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    printf("Foram encontrados %d multiplos de 3:\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p);
}

int main(void) {
    printf("Ola professor Rui, escolha uma das opcoes a seguir para corrigir as questoes\n");
    printf("1 - ex01 (clona_vetor)\n");
    printf("2 - ex02 (repete_string)\n");
    printf("3 - ex03 (filtra_acima_media)\n");
    printf("4 - ex04 (separa_pos_neg)\n");
    printf("5 - ex05 (multiplos_de3)\n\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            ex01();
            break;
        }
        case 2: {
            ex02();
            break;
        }
        case 3: {
            ex03();
            break;
        }
        case 4: {
            ex04();
            break;
        }
        case 5: {
            ex05();
            break;
        }
        default: {
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}
