#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int compara(float a[], float b[], int n) {
    int i;

    printf("Digite os %i valores do vetor 1:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    printf("Digite os %i valores do vetor 2:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void fibonacci(int v[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i == 0) {
			v[i] = 0;
		} else if (i == 1) {
			v[i] = 1;
		} else {
			v[i] = v[i-1] + v[i-2];
		}
	}
	
	printf("Sequencia de fibonacci com %i termos: \n", n);
	for (i = 0; i < n; i++) {
		printf("%i\t", v[i]);
	}
	printf("\n");
}

int main() {
    printf("Ola professor Rui, escolha uma das opcoes a seguir para corrigir as questoes\n");
    printf("1 - Comparacao de vetores\n");
    printf("2 - Vetor de fibonacci\n");
    printf("3 - Soma de primos\n");
    printf("4 - Busca todos\n");
    printf("5 - Versao recursiva busca sequencial\n");
    printf("\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
        int x;
        printf("Digite a capacidade do vetor: ");
        scanf("%i", &x);

        float vet1[x], vet2[x];
        int iguais = compara(vet1, vet2, x);
        
        if (iguais) {
        	printf("Os vetores sao iguais em todas as posicoes.");
		} else {
			printf("Os vetores nao sao iguais em suas posicoes.");
		}
        return 0;
    }
    case 2: {
    	int a;
    	printf("Digite a quantidade de n termos da sequencia de fibonacci: ");
    	scanf("%i", &a);
    	
    	int vet3[a];
    	fibonacci(vet3, a);
    	
        return 0;
    }   
    case 3: {
        return 0;
    }
    case 4: {
        return 0;
    }
    case 5: {
        return 0;
    }
    }
}
