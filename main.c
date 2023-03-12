#include <stdio.h>
#include <stdlib.h>

#include "./arquivos/arquivos.h"
#include "./auxiliares/auxiliares.h"
#include "./jogo/jogo.h"
#include "./menu/menu.h"
#include "./tabuleiro/tabuleiro.h"

int main() {
  imprimirMenu();
  int op = pegarOpcao();
  char nomeArquivo[255];
  int** tabuleiro = inicializaTabuleiro();

  switch (op) {
    case 0:  // Sair do jogo
      printf("Saindo do jogo...\n");
      return 0;

    case 1:  // Gerar novo jogo
      // TODO: Implementar
      break;

    case 2:  // Carregar jogo
      lerNomeArquivo(nomeArquivo);
      importarArquivoParaMatriz(tabuleiro, nomeArquivo);
      imprimirTabuleiro(tabuleiro);
      break;
    case 3:  // Resolver jogo
      // TODO: Implementar
      break;
  }

  executandoJogo(tabuleiro);

  return 0;
}