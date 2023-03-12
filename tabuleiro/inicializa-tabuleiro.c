#include <stdlib.h>

#include "tabuleiro.h"

int** inicializaTabuleiro() {
  int** tabuleiro = malloc(QUANTIDADE_REGIOES * sizeof(int*));

  for (int i = 0; i < QUANTIDADE_REGIOES; i++) {
    tabuleiro[i] = calloc(QUANTIDADE_REGIOES * sizeof(int), 1);
  }

  return tabuleiro;
}