#include "../jogo/jogo.h"
#include "./funcoes-jogo.h"

int faltandoPreencherCelula(int** tabuleiro) {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (tabuleiro[i][j] == 0) return 1;

  return 0;
}

int resolverSudoku(int** tabuleiro, int linha, int coluna) {
  if (!faltandoPreencherCelula(tabuleiro)) return 1;

  if (coluna == 9) {
    linha++;
    coluna = 0;
  }

  int celulaPreenchida = tabuleiro[linha][coluna] != 0;
  if (celulaPreenchida) return resolverSudoku(tabuleiro, linha, coluna + 1);

  for (int num = 1; num <= 9; num++) {
    if (posicaoValidaParaColocarNumero(tabuleiro, linha, coluna, num)) {
      tabuleiro[linha][coluna] = num;

      if (resolverSudoku(tabuleiro, linha, coluna + 1)) return 1;
    }

    tabuleiro[linha][coluna] = 0;
  }

  return 0;
}