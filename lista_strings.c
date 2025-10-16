#include<stdio.h>

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