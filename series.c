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
		
        return 0;
		break;
	}
	case 5: {
		
        return 0;
		break;
	}
	case 6: {
		
        return 0;
		break;
	}
	case 7: {
		
        return 0;
		break;
	}
    case 8: {

        return 0;
        break;
    }
    }
}
