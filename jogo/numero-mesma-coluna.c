#include <stdio.h>

#include "./jogo.h"

int numeroMesmaColuna(int** tabuleiro, int coluna, int numero) {
  for (int i = 0; i < 9; i++) {
    if (tabuleiro[i][coluna] == numero) {
      return 1;
    }
  }
  return 0;
}