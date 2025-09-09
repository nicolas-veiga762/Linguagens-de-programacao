#include <stdio.h>
#include <math.h>

void serie_harmonica(int x) {
    double somatoria = 0;
    for (int i = 1; i <= x; i++) {
        somatoria += (1.0/i);
    }
    printf("O valor da serie harmonica com %i termo(s) eh: %lf\n", x, somatoria);
}

void log_natural_dois(int x) {
    double somatoria = 0;
    double termo = 0;
    for (int i = 1; i <= x; i++) {
        termo = pow(-1, i+1) * (1.0 / i);
        somatoria += termo;
    }
    printf("Somatorio dos %d termos = %lf\n", x, somatoria);
    printf("Valor real de ln(2) = %lf\n", log(2));
}

void valor_pi_v1(int x) {
    double somatoria = 0;
    double termo = 0;
    for (int i = 0; i < x; i++) {
        termo = pow(-1, i) * (4.0 / (2*i + 1));
        somatoria += termo;
    }
    printf("Somatorio dos %d termos = %lf\n", x, somatoria);
    printf("Valor real de pi = %lf\n", acos(-1));
}

void valor_pi_v2(int x) {
    double somatoria = 3.0;
    double termo;
    int sinal = 1;
    for (int i = 1; i < x; i++) {
        int n = 2 + 2*(i-1);
        termo = (4.0 / ((double)n * (n + 1) * (n + 2))) * sinal;
        somatoria += termo;
        sinal *= -1;
    }
    printf("Somatorio dos %d termos = %lf\n", x, somatoria);
    printf("Valor real de pi = %lf\n", acos(-1));
}

void constante_euler(int n) {
    double somatoria = 0;
    double fatorial = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0) fatorial *= i;
        somatoria += 1.0 / fatorial;
    }
    printf("Somatorio dos %d termos = %lf\n", n, somatoria);
    printf("Valor real de e = %lf\n", exp(1));
}

void euler_exp(int n, double x) {
    double somatoria = 0;
    double termo = 1;
    somatoria = 1;
    for (int i = 1; i < n; i++) {
        termo *= x / i;
        somatoria += termo;
    }
    printf("Somatorio dos %d termos = %lf\n", n, somatoria);
    printf("Valor real de e^x = %lf\n", exp(x));
}

void seno_x(int n, double x) {
    double somatoria = 0;
    double termo = x;
    somatoria = x;
    for (int i = 1; i < n; i++) {
        termo *= -1 * x * x / ((2*i) * (2*i+1));
        somatoria += termo;
    }
    printf("Somatorio dos %d termos = %lf\n", n, somatoria);
    printf("Valor real de sen(x) = %lf\n", sin(x));
}

void cosseno_x(int n, double x) {
    double somatoria = 1;
    double termo = 1;
    for (int i = 1; i < n; i++) {
        termo *= -1 * x * x / ((2*i-1) * (2*i));
        somatoria += termo;
    }
    printf("Somatorio dos %d termos = %lf\n", n, somatoria);
    printf("Valor real de cos(x) = %lf\n", cos(x));
}

int main() {
    printf("Ola professor Rui, escolha uma das opcoes a seguir para corrigir as questoes\n");
    printf("1 - Serie harmonica\n");
    printf("2 - Logaritmo natural de 2\n");
    printf("3 - Valor de pi versao 1\n");
    printf("4 - Valor de pi versao 2\n");
    printf("5 - Constante de euler\n");
    printf("6 - Constante de euler elevado a x\n");
    printf("7 - Seno de x\n");
    printf("8 - Cosseno de x\n");
    printf("\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
        int k;
        printf("Digite uma constante K, para o numero de termos da somatoria.\n");
        scanf("%i", &k);
        serie_harmonica(k);
        return 0;
        break;
    }
    case 2: {
        int n;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &n);
        log_natural_dois(n);
        return 0;
        break;
    }   
    case 3: {
        int p;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &p);
        valor_pi_v1(p);
        return 0;
        break;
    }
    case 4: {
        int q;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &q);
        valor_pi_v2(q);
        return 0;
        break;
    }
    case 5: {
        int n;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &n);
        constante_euler(n);
        return 0;
        break;
    }
    case 6: {
        int n;
        double x;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &n);
        printf("Digite o valor de x.\n");
        scanf("%lf", &x);
        euler_exp(n, x);
        return 0;
        break;
    }
    case 7: {
        int n;
        double x;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &n);
        printf("Digite o valor de x.\n");
        scanf("%lf", &x);
        seno_x(n, x);
        return 0;
        break;
    }
    case 8: {
        int n;
        double x;
        printf("Digite uma constante N, para o numero de termos da somatoria.\n");
        scanf("%i", &n);
        printf("Digite o valor de x.\n");
        scanf("%lf", &x);
        cosseno_x(n, x);
        return 0;
        break;
    }
    }
}