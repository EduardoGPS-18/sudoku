#include <math.h>
#include <stdio.h>

#include "./jogo.h"

int numeroMesmaRegiao(int** tabuleiro, int regiao, int numero) {
  int regiaoComecoX = floor(regiao / 3) * 3;
  int regiaoComecoY = (regiao % 3) * 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[regiaoComecoX + i][regiaoComecoY + j] == numero) {
        return 1;
      }
    }
  }
  return 0;
}