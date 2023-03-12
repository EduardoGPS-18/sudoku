#include <stdio.h>

#include "../auxiliares/auxiliares.h"
#include "./tabuleiro.h"

void imprimirTabuleiro(int **tabuleiro) {
  for (int i = 0; i < QUANTIDADE_REGIOES; i++) {
    for (int j = 0; j < QUANTIDADE_REGIOES; j++) {
      printf("%d ", tabuleiro[i][j]);
      if (j == 2 || j == 5) printf(" ");
    }
    if (i == 2 || i == 5) {
      printf("\n");
    }
    printf("\n");
  }
}
