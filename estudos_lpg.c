#include<stdio.h>
#include<math.h>

//prova1

// Q1
int fat_impar (int n) {
	int i = 0, fat = 1;
	for (i = n; i >= 1; i--) {
		if (i % 2 != 0) {			//normal
			fat *= i;
		}
	}
	return fat;
}

//int fat_impar (int n) {
//	if (n <= 1) {
//		return 1;
//	} else if (n % 2 == 0) {			//recursiva
//		return fat_impar (n - 1);
//	} else {
//		return n * fat_impar (n - 2);
//	}
//}

//Q2

int maximo_produto (int v[], int n) {
	int i = 0;
	int armazenador = v[0] * v[1];
	int arbitrario = 0;
	for (i = 1; i < n - 1; i++) {
		arbitrario = v[i] * v[i + 1];
		if (arbitrario > armazenador) {
			armazenador = arbitrario;
		}
	}
	return armazenador;
}

//Q3

void menores_precos(int m, int n, float mat[m][n], float vet[n]) {
	int i, j;
	float soma, menor_soma = 999999;
	int linha_menor = 0;
	for (i = 0; i < m; i++) {
		soma = 0;
		for (j = 0; j < n; j++) {
			soma += mat[i][j];
			vet[j] = mat[linha_menor][j];
		}
		if (soma < menor_soma) {
			menor_soma = soma;
			linha_menor = i;
		}
	}
}

//Q4

void substring (char orig[], char dest[], int ini, int fim) {
	int i = 0, j = 0;
	for (i = ini; i <= fim && orig[i] != '\0'; i++) {
		dest[i] = orig[i];
		j++;
	}
	dest[j] = '\0';
}

//prova2

//Q1

int hiper (int n) {
	int i = 0;
	int fat = 1;         
	for (i = 1; i <= n; i++) {
		fat *= pow(i, i);
	}
	return fat;
}

int hiper_rec (int n) {
	if (n == 1) return 1;
	return pow(n, n) * hiper_rec(n - 1);
}

//Q2 ja fiz

//Q3

void max_lin (int LIN, int COL, int mat[LIN][COL], int vet[COL]) {
	int i, j;
	int maior_linha = 0;
	int maior = mat[0][0];
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			if (mat[i][j] > maior) {
				maior = mat[i][j];
				maior_linha = i;
			}
		}
	}
	for (j = 0; j < COL; j++) {
		vet[j] = mat[maior_linha][j];
	}
}

void copia_vogais (char orig[], char dest[]) {
	int i, j = 0, k;
	char vogais[5] = "aeiou";
	
	// forma noob
	for(i = 0; orig[i] != '\0'; i++) {
		if (orig[i] == 'a' || orig[i] == 'e' || orig[i] == 'i' || orig[i] == 'o' || orig[i] == 'u') {	
			dest[i] = orig[i];														
		}
		j++;
	}
	dest[j] = '\0';
	
	//forma pro
	for(i = 0; orig[i] != '\0'; i++) {
		for (k = 0; vogais[k] != '\0'; k++) {
			if (orig[i] == vogais[k]) {
				dest[j] = orig[i];	
				j++;
				break; // se achar vogal n precisa mais do loop;
			}
		}
	}
	dest[j] = '\0';
}

//prova3

//Q1 ja feito anteriormente

//Q2

void copia_pares_impares (int v[], int n, int vi[], int vp[]) {
	int i;
	int ci = 0, cp = 0;
	for (i = 0; i < n; i++) {
		if (v[i] % 2 != 0) {
			vi[ci] = v[i];
			ci++;
		} else {
			vp[cp] = v[i];
			cp++;
		}
	}
}

//Q3 ja feito anteriormente

//Q4 ja feito anteriormente

//lista séries

//Q1

void harmonica (int k) {
	int i = 0;
	int soma = 0.0;
	for (i = 1; i <= k; i++) {
		soma += 1.0/i;
	}
}

//Q2

void ln2 (int k) {
	int i = 0;
	double soma = 0.0;
	for (i = 1; i <= k; i++) {
		soma += (1.0/i) * (pow(-1, i + 1));
	}
}

//Q3

void forma1 (int k) {
	int i = 0;
	double soma = 0.0;
	for (i = 1; i <= k; i++) {
		soma += (4.0 /(2 * i - 1)) * (pow(-1, i + 1));
	}
	printf("%.10d", soma);
}

void forma2 (int k) {
	int i = 0, n = 0;
	double soma = 3.0, termo = 0.0;
	for (i = 2, n = 1; n <= k * 2; i += 2, n++) {
		termo = 4.0 / (i * (i + 1) * (i + 2));
		soma += pow(-1, n + 1) * termo;
	}
	printf("%.10d", soma);
}

//Q4

int fat (int n) {
	int i = 0, fat = 1;
	if (n == 0) {
		fat = 1;
	} else {
		for (i = n; i >= 1; i--) {
			fat *= i;
		}
	}
	return fat;
}

void euler (int n) {
	int i = 0;
	double soma = 0, termo = 0;
	for (i = 0; i <= n; i++) {
		termo = fat(i);
		soma += (1.0 / termo);
	}
}

//Q5

void euler_exp (int n, int x) {
	int i = 0;
	double soma = 0;
	for (i = 0; i <= n; i++) {
		soma += pow(x, i) / (double)fat(i); //typecast para a função não fazer a divisão inteira, pois o retorno de fat é inteiro e soma é double;
	}
}

//questões slide matriz

//Q1

void media_pares (int l, int c, int mat[l][c]) {
	int i = 0, j = 0;
	int qntd_elem = 0, soma = 0;
	float media = 0;
	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			if (mat[i][j] % 2 == 0) {
				soma += mat[i][j];
				qntd_elem++;
			}
		}
	}
	if (qntd_elem > 0) {
		media = (float)soma / (float)qntd_elem;
	} else {
		media = 0;
	}
}

//Q2

void transposta(int l, int c, int mat[l][c]) {
	int i = 0, j = 0;
}

//Q3 ez

//lista strings

//Q1

int contem (char s[], char c) {
	int i = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if(s[i] == c) {
			return 1;
		}
	}
	return 0;
}

//Q2

int contem_letra (char s[], char c) {
	int i, qntd = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == c) {
			qntd += 1;
		}
	}
	return qntd;
}

//Q3

void concatena (char str1[], char str2[]) {
	int i = 0, j = 0;
	for(i = 0; str1[i] != '\0' ; i++);
	for(j = 0; str2[j] != '\0'; j++) {
		str1[i+j] = str2[j];
	}
	str1[i+j] = 0;
}

//Q4

int palindromo(char s[]) {
//	int i = 0, j = 0;
//	int tamanho_palavra = 0;
//	for (tamanho_palavra = 0; s[tamanho_palavra] != '\0'; tamanho_palavra++);
//	char arb_s[tamanho_palavra + 1];
//	for (i = 0; s[i] != '\0'; i++) {
//		arb_s[i] = s[i];													//forma que eu pensei na hora
//	}
//	arb_s[i] = '\0';
//	for (i = i - 1, j = 0; arb_s[j] != '\0'; j++, i--) {
//		if (s[j] != arb_s[i]) {
//			return 0; //não é palindromo;
//		}
//	}
//	return 1;

	int i, j;
    int tamanho = 0;

    for (tamanho = 0; s[tamanho] != '\0'; tamanho++);

    // Compara os caracteres da frente com os do final
    for (i = 0, j = tamanho - 1; i < j; i++, j--) {							//forma pesquisando
        if (s[i] != s[j]) {													
            return 0; // Não é palíndromo
        }
    }
    return 1; // É palíndromo
}

//Q5

void converte (char s[]) {
	int i = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 97 && s[i] <= 122) {
			s[i] -= 32;
		}
	}
}

//Q6

int digitos (char s[]) {
	int i = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] < '0' || s[i] > '9') {
			return 0;
		}
	}
	return 1;
}

//Q7 

int char_numero (char s[]) {
	int i = 0, num = 0;
	for (i = 0; s[i] != '\0'; i++) {
		num = num * 10 + (s[i] - '0');
	}
	return num;
}

//Q8

int extrair_data(char data[], int v[]) {
    if (data[2] != '/' || data[5] != '/' || data[10] != '\0') {
        return 0; 
    }

	int i = 0;
    for (i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (data[i] < '0' || data[i] > '9') {
            return 0; 
        }
    }

    v[0] = (data[0] - '0') * 10 + (data[1] - '0'); // dia
    v[1] = (data[3] - '0') * 10 + (data[4] - '0'); // mês
    v[2] = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0'); // ano

    return 1; 
}

//Q9

void trim (char s[]) {
	int n, i;
	for(n = 0; s[n] == ' '; n++);
	for(i = n; s[i] != '\0'; i++) {
		s[i-n] = s[i];
	}
	s[i-n] = '\0';
	for (i = i - n; s[i - 1] == ' ' && i != 0 ; i--);
	s[i] = '\0';
}

//Q10

void inverte (char s[]) {
	int i = 0, j = 0;
	int tamanho = 0;
	char temp;
	for (tamanho = 0; s[tamanho] != '\0'; tamanho++);	
	for (i = 0, j = tamanho - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

//Q11

void retirar (char str[], char c) {
	int i, j;
//	for (i = 0; str[i] != '\0'; i++) {
//		if (str[i] == c) {
//			for(j = i; str[j] != 0; j++) {		//forma 2 profissional
//				str[j] = str[j+1]; 
//			}
//			i--;
//		}
//	}
	
	for (i = 0, j = 0; str[i] != '\0'; i++) {
		if (str[i] != c) {
			str[j] = str[i];
			j++;								//forma 1 muito profissional
		}
	}
	str[j] = '\0';
	printf("%s", str);
}

//Q12

int compara(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

//Q13

void substring_lista (char orig[], char dest[], int ini, int fim) {
	int i = 0, j = 0;
	for (i = ini; i <= fim && orig[i] != '\0'; i++) {
		dest[i] = orig[i];
		j++;
	}
	dest[j] = '\0';
}

int main() {
		
}