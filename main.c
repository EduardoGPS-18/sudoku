#include <stdio.h>
#include <stdlib.h>

#include "./arquivos/arquivos.h"
#include "./auxiliares/auxiliares.h"
#include "./funcoes-jogo/funcoes-jogo.h"
#include "./jogo/jogo.h"
#include "./menu/menu.h"
#include "./tabuleiro/tabuleiro.h"

int main() {
  char nomeArquivo[255];
  int** tabuleiro = inicializaTabuleiro();

  int voltarMenu = 0;

  do {
    imprimirMenu();
    int op = pegarOpcao();
    int executarJogo = 1;
    switch (op) {
      case 0:  // Sair do jogo
        printf("Saindo do jogo...\n");
        return 0;

      case 1:  // Gerar novo jogo

        criarJogoAleatorio(tabuleiro);
        removerPecas('F', tabuleiro);
        imprimirTabuleiro(tabuleiro);
        break;

      case 2:  // Carregar jogo
        lerNomeArquivo(nomeArquivo);
        importarArquivoParaMatriz(tabuleiro, nomeArquivo);
        imprimirTabuleiro(tabuleiro);
        break;
      case 3:  // Resolver jogo
        resolverSudoku(tabuleiro, 0, 0);
        printf("Tabuleiro resolvido: \n");
        imprimirTabuleiro(tabuleiro);
        printf("\n");
        executarJogo = 0;
        voltarMenu = -1;
        break;
    }

    if (executarJogo) voltarMenu = executandoJogo(tabuleiro);
  } while (voltarMenu == -1);

  return 0;
}