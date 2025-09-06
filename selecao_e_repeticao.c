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

void tipos_triangulos (float x, float y, float z) {
    float ordenador1;

    if (x < y) ordenador1 = x; x = y; y = ordenador1;
    if (x < z) ordenador1 = x; x = z; z = ordenador1;
    if (y < z) ordenador1 = y; y = z; z = ordenador1;

    if (x >= y+z) {
        printf("NAO FORMA TRIANGULO");
    } else {
    	if (x*x == y*y + z*z) {
        	printf("TRIANGULO RETANGULO");
    	} else if (x*x > y*y + z*z) {
    	    printf("TRIANGULO OBTUSANGULO");
   		} else if (x*x < y*y + z*z) {
    	    printf("TRIANGULO ACUTANGULO");
    	} else if (x == y && y == z) {
    	    printf("TRIANCULO EQUILATERO");
    	} else if (x == y || y == z || x == z) {
    	    printf("TRIANGULO ISOSCELES");
    	}	
	}
}

void tempo_de_jogo(int x, int y, int z, int w) {
	if (x == z && y == w) {
		printf("24 horas e 0 minutos");	
	} else {
		int temp1, temp2, difmin, horas, minutos;
		temp1 = x*60+y;
		temp2 = z*60+w;
		difmin = (temp2 - temp1 + 1440) % 1440;
		horas = difmin / 60;
		minutos = difmin % 60; 
		printf("Tempo entre %02d:%02d e %02d:%02d = %d horas e %d minutos\n", x, y, z, w, horas, minutos);
	}
}

void pares_impares_positivos_negativos(int x) {
	int positivos = 0, negativos = 0, pares = 0, impares = 0, guardador = 0;
	printf("Pode digitar os numeros!\n");
	for (int i = 0; i < x; i++) {
		scanf("%i", &guardador);
		if (guardador > 0) positivos++;
		if (guardador < 0) negativos++;
		if (guardador % 2 == 0) pares++;
		if (guardador % 2 == 1 || guardador % 2 == -1) impares++;
	}
	printf("%i valor(es) par(es)\n", pares);
	printf("%i valor(es) impar(es)\n", impares);
	printf("%i valor(es) negativo(s)\n", negativos);
	printf("%i valor(es) positivo(s)\n", positivos);
}

void medias_ponderadas(int x) {
	float num1 = 0, num2 = 0, num3 = 0, media = 0;
	limpar_tela();
	for (int i = 0; i < x; i++) {
		scanf("%f %f %f", &num1, &num2, &num3);
		media = ((num1*2)+(num2*3)+(num3*5))/10;
		printf("%.1f\n", media);
	}
}

void soma_impares_consecutivos_1(int x, int y) {
    int soma = 0;

    if (x > y) {
        int ordenador2 = x;
        x = y;
        y = ordenador2;
    }

    for (int i = x + 1; i < y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    printf("soma: %d\n", soma);
}

void soma_impares_consecutivos_2(int n) {
	printf("Pode digitar os numeros.\n");
	for (int i = 0; i < n; i++) {
		int soma = 0, x = 0, y = 0;
		scanf("%i %i", &x, &y);
		if (x > y) {
        	int ordenador2 = x;
        	x = y;
        	y = ordenador2;
    	}
		for (int j = x + 1; j < y; j++) {
        	if (j % 2 != 0) {
            	soma += j;
        	}
    	}
	printf("soma: %d\n", soma);	
	}
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