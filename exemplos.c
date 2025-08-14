#include <stdio.h>

int main(void) {
  int n;
  printf("Digite um numero: ");
  scanf("%i", &n);
  int fat = 1;
  while (n > 0) {
    fat *= n;
    n--;
  }
  printf("Fatorial: %i\n", fat);
}
