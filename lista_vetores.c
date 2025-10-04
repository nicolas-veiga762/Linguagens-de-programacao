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

int ehprimo (int x) {
	int i;
	if (x <= 1) return 0;
	
	for (i = 2; i < x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
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

int soma_primos(int v[], int a) {
	int i;
	int qntd_primos = 0;
	int somatoria_primos = 0;
	printf("Digite os %i valores do vetor:\n", a);
	for (i = 0; i < a; i++) {
		scanf("%i", &v[i]);
	}
	
	for (i = 0; i < a; i++) {
		if (ehprimo(v[i])) {
			qntd_primos++;
			somatoria_primos += v[i];
		}
	}
	
	printf("Quantidade de primos no vetor: %i primos.\n ", qntd_primos);
    
    return somatoria_primos;
}

void busca_todos(int v[], int n, int chave, int indices[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (v[i] == chave) {
            indices[j] = i;
            j++;
        }
    }
    for (j = 0; j < n; j++) {
        indices[j] = -1;
    }
}

int busca_seq_rec(int v[], int n, int chave) {
    if (n == 0) return -1;
    if (v[n - 1] == chave) return n - 1;
    return busca_seq_rec(v, n - 1, chave);
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
    	int n;
    	printf("Digite a capacidade do vetor: ");
    	scanf("%i", &n);
    	
    	int vet4[n];
    	
    	int soma = soma_primos(vet4, n);
        printf("A soma retornada pela funcao foi: %i\n", soma);

        return 0;
    }
    case 4: {
    	int n, chave, i;
    	printf("Digite a capacidade do vetor: ");
    	scanf("%i", &n);
    	
    	int vet[n], indices[n];
    	
    	printf("Digite os %i valores do vetor:\n", n);
    	for (i = 0; i < n; i++) {
        	scanf("%i", &vet[i]);
    	}

    	printf("Digite a chave de busca: ");
    	scanf("%i", &chave);

    	busca_todos(vet, n, chave, indices);

    	printf("indices = {");
    	for (i = 0; i < n; i++) {
        	printf("%i", indices[i]);
        	if (i < n - 1) {
            	printf(", ");
        	}
    	}	
    	printf("}\n");

        return 0;
    }
    case 5: {
        int n, chave, i;
        printf("Digite a capacidade do vetor: ");
        scanf("%i", &n);
        
        int vet[n];
        
        printf("Digite os %i valores do vetor:\n", n);
        for (i = 0; i < n; i++) {
        	scanf("%i", &vet[i]);

		}
        printf("Digite a chave de busca: ");
        scanf("%i", &chave);
        
        int pos = busca_seq_rec(vet, n, chave);
        if (pos == -1) {
			printf("Chave nao encontrada.\n"); 	
		} else {
			printf("Chave encontrada na posicao %i.\n", pos);
		}
		
        return 0;
    }
    }
}
