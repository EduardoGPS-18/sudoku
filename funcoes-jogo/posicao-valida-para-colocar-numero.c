#include "../jogo/jogo.h"

int numeroMesmaRegiaoEmLinhaColuna(int** tabuleiro, int linha, int coluna,
                                   int numero) {
  int linhaComeco = (linha / 3) * 3;
  int colunaComeco = (coluna / 3) * 3;
  for (int i = linhaComeco; i < linhaComeco + 3; i++)
    for (int j = colunaComeco; j < colunaComeco + 3; j++)
      if (tabuleiro[i][j] == numero) return 1;

  return 0;
}

int posicaoValidaParaColocarNumero(int** tabuleiro, int linha, int coluna,
                                   int num) {
  int numeroNaLinha = numeroMesmaLinha(tabuleiro, linha, num);
  int numeroNaColuna = numeroMesmaColuna(tabuleiro, coluna, num);
  int numeroNaRegiao =
      numeroMesmaRegiaoEmLinhaColuna(tabuleiro, linha, coluna, num);

  if (numeroNaLinha || numeroNaColuna || numeroNaRegiao) return 0;

  return 1;
}