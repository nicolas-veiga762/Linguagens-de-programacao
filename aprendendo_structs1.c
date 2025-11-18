#include<stdio.h>
#include<string.h>

struct Data
{
    int dia, mes, ano;
};

struct Produto
{
    int codigo;
    char descricao[50];
    float preco;
};

typedef struct {
    int burro;
    int lado_politico;
    float virgem;
    char chato[50];
    float analfabeto;
} luca;

int main(void) {
    struct  Produto x;
        
    x.codigo = 123;
    x.preco = 100;
    strcpy(x.descricao, "café");

    struct Data y;
    
    y.dia = 18;
    y.mes = 11;
    y.ano = 2025;

    luca z;

    z.burro = 1;
    z.lado_politico = 22;
    z.virgem = 100.0;
    strcpy(z.chato, "muito chato");
    z.analfabeto = 1;
}