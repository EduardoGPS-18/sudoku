#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "./jogo.h"

int verificaMesmoNumeroNaMesmaRegiao(int** tabuleiro, int regiao, int numero) {
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

int verificaMesmoNumeroNaMesmaLinha(int** tabuleiro, int linha, int numero) {
  for (int i = 0; i < 9; i++) {
    if (tabuleiro[linha][i] == numero) {
      return 1;
    }
  }
  return 0;
}

int verificaMesmoNumeroNaMesmaColuna(int** tabuleiro, int coluna, int numero) {
  for (int i = 0; i < 9; i++) {
    if (tabuleiro[i][coluna] == numero) {
      return 1;
    }
  }
  return 0;
}

int adicionarPecaTabuleiro(int** tabuleiro, Comando comando) {
  int regiao = comando.regiao - 1;
  int linha = comando.linha - 1;
  int coluna = comando.coluna - 1;
  int valor = comando.valor;
  int regiaoComecoX = floor(regiao / 3) * 3;
  int regiaoComecoY = (regiao % 3) * 3;

  int contemMesmoNumeroNaMesmaRegiao =
      verificaMesmoNumeroNaMesmaRegiao(tabuleiro, regiao, valor);
  int contemMesmoNumeroNaMesmaLinha =
      verificaMesmoNumeroNaMesmaLinha(tabuleiro, linha, valor);
  int contemMesmoNumeroNaMesmaColuna =
      verificaMesmoNumeroNaMesmaColuna(tabuleiro, coluna, valor);
  int jaContemOValorNaPosicao =
      tabuleiro[regiaoComecoX + linha][regiaoComecoY + coluna] == valor;

  if (jaContemOValorNaPosicao) {
    return -1;
  } else if (contemMesmoNumeroNaMesmaRegiao || contemMesmoNumeroNaMesmaLinha ||
             contemMesmoNumeroNaMesmaColuna) {
    return 1;
  } else {
    tabuleiro[regiaoComecoX + linha][regiaoComecoY + coluna] = comando.valor;
    return 0;
  }
}