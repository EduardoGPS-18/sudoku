#include <stdio.h>

#include "./jogo.h"

int numeroMesmaLinha(int** tabuleiro, int linha, int numero) {
  for (int i = 0; i < 9; i++) {
    if (tabuleiro[linha][i] == numero) {
      return 1;
    }
  }
  return 0;
}