#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float *p, x;
    p = malloc(sizeof(float));
    scanf("%f", p);
    printf("%f", *p);
    x = *p;
    printf("end. de x: %f\n", &x);
    printf("end. alocado: %f\n", p);
}