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

int main() {
    printf("Ola professor Rui, escolha uma das opcoes a seguir para corrigir as questoes\n");
    printf("1 - Coordenadas de um Ponto\n");
    printf("2 - Tipos de Triangulos\n");
    printf("3 - Tempo de Jogo\n");
    printf("4 - Pares, Impares, Positivos e Negativos\n");
    printf("5 - Medias Ponderadas\n");
    printf("6 - Soma de Impares Consecutivos I\n");
    printf("7 - Soma de Impares Consecutivos II\n");
    printf("\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
    	float a, b;
        printf("Digite suas coordenadas.");
        scanf("%f %f", &a, &b);
        coordenadas(a, b);
        return 0;
		break;
	}
    case 2: {
		float c, d, e;
        printf("Digite as arestas do seu triangulo.");
        scanf("%f %f %f", &c, &d, &e);
        tipos_triangulos(c, d, e);
        return 0;
    	break;
	}   
    case 3: {
		int f, g, h, i;
    	printf("Digite o horario inicial (HH MM): \n");
    	scanf("%i %i", &f, &g);
    	printf("Digite o horario final (HH MM): \n");
    	scanf("%i %i", &h, &i);
    	tempo_de_jogo(f, g, h, i);
    	return 0;
    	break;
	}
	case 4: {
		int n1;
		printf("Digite os N numeros que voce quer verificar.\n");
		scanf("%i", &n1);
		pares_impares_positivos_negativos(n1);
		break;
	}
	case 5: {
		int n2;
		printf("Digite a quantia de N numeros nas medias ponderadas.\n");
		scanf("%i", &n2);
		medias_ponderadas(n2);
		break;
	}
	case 6: {
		int j, k;
		printf("Digite os numeros para a soma de impares consecutivos.\n");
		scanf("%i %i", &j, &k);
		soma_impares_consecutivos_1(j, k);
		break;
	}
	case 7: {
		int n3;
		printf("Digite a quantia de N numeros da soma de consecutivos.\n");
		scanf("%i", &n3);
		soma_impares_consecutivos_2(n3);
		break;
	}
    }
}