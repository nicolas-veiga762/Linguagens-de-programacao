#include<stdio.h>

int main() {
	//Acessando vetor com ponteiro
	
	int v1[5];
	
	int *p = v1; //ponteiro p apontando para v, não precisamos de &v(endereço de v) pois um vetor é um ponteiro para ele mesmo
	
	int i;
	for(i = 0; i < 5; i++) {
		scanf("%d", &p[i]); //não serve pra nada mas é só pra mostrar que funciona
	}
	
	//passagem por referencia
	
	int v2[] = {3, 6, 9, 12, 15};
	mostra_vetor(v, 5);
	return 0;
	
	//aritmética de ponteiros
	/*
	soma:
	endereço +- valor escalar = novo endereço
	
	subtração:
	endereço1 - endereço2 = valor escalar
	*/
	
	//trocando indice por ponteiro
	
	int v3[4] = {1, 4, 7, 11};
	int *i;
	for (i = v; i < v + 4; i++) {
		printf("v[%d]", i - v);
		printf("(%d)", i);
		printf("%d\n", *i);
	}
}

void mostra_vetor(int *p, int k) {
	int i;
	for(i = 0; i < k; i++) {
		printf("%d\n", p[i]); //p[i] é um ponteiro
	}
}