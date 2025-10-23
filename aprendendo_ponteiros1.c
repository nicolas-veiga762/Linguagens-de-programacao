#include<stdio.h>
#include<math.h>

int main() {
    //Em diversas situações, é necessário ter acesso direto a endereços de memória de variáveis e funções;
    
    //Um ponteiro (também chamado de apontador) é uma variável cujo conteúdo é um endereço de memória;

	// Quando um ponteiro contém o endereço de outra variável, normalmente diz-se que o mesmo aponta para a variável.
	
	/*
		Um ponteiro pode apontar para:
		– Uma variável.
		– Outro ponteiro.
		– Uma área de memória alocada dinamicamente.
		– Uma função.
		
		Situações Típicas de Uso de Ponteiros
			• Passagem de parâmetros por referência;
			• Alocação Dinâmica de Memória:
				– Vetores (strings);
				– Matrizes (vetores de strings);
			• Polimorfismo, com ponteiros para funções.
	*/
	
	//Declaração de ponteiros.
	
	int *p1;    //ponteiro para int.
	float *p2;	//ponteiro para float.
	
	/*
		Operadores sobre Ponteiros
			• Há dois operadores unários:
				& : aplicado sobre qualquer variável, recupera o seu endereço;
				* : aplicado sobre um ponteiro, acessa o valor apontado por ele (operador de indireção).
	*/
	
	//Exemplo 1
	int a  = 5;
	
	
	printf("A = %d\n", a); // Mostra valor da variável a.
	
	printf("Endereço de A = %d\n", &a);  // Mostra endereço da variável a.

	printf("Endereço de A = %p\n", &a); // Mostra endereço da variável a (em hexa).
	
	//Exemplo 2 usando ponteiro.
	
	int a = 5;
	
	int *p = &a; //Endereço de a.
	
	printf("A = %d\n", *p); //Mostra valor de vaviável a.
	
	printf("Endereco de A = %d\n", p); //Mostra endereço da variavel a.
	
	printf("Endereco de A = %p\n"); //Mostra endereço da variavel a (em hexa).
	
	//Exemplo 3 mais ponteiros
	
	int a, b, c, *p1, *p2;
	
	p1 = &a; // endereço de a.
	p2 = &b; // endereço de b.

	*p1 = 3; // a = 3;
	
	scanf("%d", p2); // &b (usuário digitou 5)
	
	c = *p1 * *p2; // c = a * b;
	
	printf("C = %d\n", c); // Mostra c.
	
	//Exemplo 4 cuidar com a inicialização
	
	int *p;
	
	printf("%d\n", *p); // p não foi inicializado!
	
	/*
		• Todo ponteiro não inicalizado aponta para um endereço desconhecido.
			– Risco alto do programa travar!
			
		• É fundamental que todo ponteiro seja inicializado!
	*/
	
	//Se tivesse no código.
	int n = 5;
	p = &n;
	//Dae daria certo!
	
	//Aplicações: Passagem por referência
	
	/*
		• O uso mais simples de ponteiros consiste no mecanismo chamado passagem de parâmetro por referência.
		
		• Em alguns casos, é necessário que uma função modifique uma variável que está fora de seu escopo.
		
		• Tais casos normalmente envolvem situações em que a função precisa retornar mais de um valor.
		
		• Nesses casos, a função recebe como parâmetro o endereço (referência) da variável que precisa modificar.
		
		• O parâmetro dessa função será, portanto, um ponteiro.
		
		• O exemplo típico de passagem por referência é a função scanf(), que recebe o endereço da variável que vai receber o valor lido do teclado: scanf("%d", &n);
	*/
	
	//Exemplo de passagem por referência.
	
	/*
	
	int main(){
 		int n = 1;
 		
 		printf("%d\n", n);
 		
 		inc( &n ); // Passagem por referência.
 		
 		printf("%d\n", n);
 		
 		return 0;
	}
		
	void inc( int *x ){ // Parâmetro é ponteiro!
 		(*x)++; // Utiliza * para acessar variável.
	}
	
	*/
	
	float x1, x2;
	
	printf("Digite coeficientes de 'a', 'b' e 'c': ");
	scanf("%d%d%d", &a, &b, &c);
	
	if(raizes(a, b, c, &x1, &x2)) {
		printf("As raizes existem e são x1: %f e x2: %f", x1, x2);
	} else {
		printf("As raizes não existem.");
	}
}

int raizes(float a, float b, float c, float *x1, float *x2) {
	int delta = (pow(b, 2))	- 4*a*c;
	
	if (delta < 0) {
		return 0;
	}
	
	*p1 = (-b + sqrt(delta))/(2*a);
	*p2 = (-b + sqrt(delta))/(2*a);
	
	return 1;
}