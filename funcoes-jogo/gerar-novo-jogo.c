
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./funcoes-jogo.h"

int contemValorNoArray(int array[], int tamanhoArray, int valor) {
  for (int i = 0; i < tamanhoArray; i++) {
    if (array[i] == valor) return 1;
  }
  return 0;
}

void resetarTabuleiro(int** tabuleiro) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      tabuleiro[i][j] = 0;
    }
  }
}

void criarJogoAleatorio(int** tabuleiro) {
  srand(time(NULL));

  int qtdRegioes = 3, regioes[5];
  int valor, i = 0, temValorNoArray;
  do {
    valor = (rand() % 9) + 1;
    temValorNoArray = contemValorNoArray(regioes, qtdRegioes, valor);
    regioes[i] = valor;
    if (!temValorNoArray) i++;
  } while (temValorNoArray || i < qtdRegioes);

  do {
    resetarTabuleiro(tabuleiro);
    for (int i = 0; i < 3 * 9; i++) {
      int posicaoDisponivel;
      do {
        int valor = (rand() % 9) + 1;
        int x = (rand() % 9);
        int y = (rand() % 9);
        posicaoDisponivel =
            posicaoValidaParaColocarNumero(tabuleiro, x, y, valor);
        if (posicaoDisponivel) tabuleiro[x][y] = valor;
      } while (!posicaoDisponivel);
    }
  } while (!resolverSudoku(tabuleiro, 0, 0));
}

void removerPecas(char dificuldade, int** tabuleiro) {
  int qtdMaximaPecas = dificuldade == 'F' ? 6 : 3;
  int remocoesPossiveis = dificuldade == 'F' ? 3 : 3;

  for (int regiao = 0; regiao < 9; regiao++) {
    int regiaoComecoX = floor(regiao / 3) * 3;
    int regiaoComecoY = (regiao % 3) * 3;
    int pecasRegiao = qtdMaximaPecas - (rand() % remocoesPossiveis);
    int pecasARemover = 9 - pecasRegiao;
    while (pecasARemover > 0) {
      int x = regiaoComecoX + rand() % 3;
      int y = regiaoComecoY + rand() % 3;
      if (tabuleiro[x][y] != 0) {
        tabuleiro[x][y] = 0;
        pecasARemover--;
      }
    }
  }
}