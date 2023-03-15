#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "./jogo.h"

int adicionarPecaTabuleiro(int** tabuleiro, Comando comando) {
  int valor = comando.valor;

  int regiao = comando.regiao - 1;
  int linha = comando.linha - 1;
  int coluna = comando.coluna - 1;

  int regiaoComecoX = floor(regiao / 3) * 3;
  int regiaoComecoY = (regiao % 3) * 3;

  int linhaEmRelacaoAoTabuleiro = (((regiao - 1) % 3) * 3) + linha;
  int colunaEmRelacaoAoTabuleiro = ((floor(regiao / 3)) * 3) + coluna;

  int nmrMesmaRegiao = numeroMesmaRegiao(tabuleiro, regiao, valor);
  int nmrMesmaLinha = numeroMesmaLinha(tabuleiro, linha, valor);
  int nmrMesmaColuna = numeroMesmaColuna(tabuleiro, coluna, valor);

  int jaContemOValorNaPosicao =
      tabuleiro[regiaoComecoX + linha][regiaoComecoY + coluna] == valor;

  if (jaContemOValorNaPosicao) {
    printf("Erro! A celula %d, %d da regiao %d já possui o valor %d\n",
           comando.linha, comando.coluna, comando.regiao,
           tabuleiro[regiaoComecoX + linha][regiaoComecoY + coluna]);
  } else if (nmrMesmaLinha) {
    printf("Erro! A linha %d já possui o valor %d\n", comando.linha, valor);
  } else if (nmrMesmaRegiao) {
    printf("Erro! A regiao %d já possui o valor %d\n", comando.regiao, valor);
  } else if (nmrMesmaColuna == 1) {
    printf("Erro! A coluna %d já possui o valor %d\n", comando.coluna, valor);
    ;
  } else {
    tabuleiro[regiaoComecoX + linha][regiaoComecoY + coluna] = comando.valor;
  }
}