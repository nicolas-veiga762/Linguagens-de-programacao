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
    	int 
        return 0;
		break;
	}
    case 2: {
		
        return 0;
    	break;
	}   
    case 3: {
		
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
    }
}