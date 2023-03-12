
#include <stdio.h>

#include "jogo.h"

enum Resultado { SUCESSO = 0, FALHA = 1, FALHA_NUMERO_EXISTE_NA_POSICAO = -1 };

int executandoJogo(int** tabuleiro) {
  do {
    Comando c = lerComando();
    switch (c.acao) {
      case SALVAR:
        break;
      case VOLTAR_MENU:
        return 1;
      case ADICIONAR_NUMERO:
        int resultado = adicionarPecaTabuleiro(tabuleiro, c);
        if (resultado == FALHA) {
          printf("Não foi possível adicionar a peça no tabuleiro!\n");
          printf("Você perdeu!\n");
          return 1;
        } else if (resultado == FALHA_NUMERO_EXISTE_NA_POSICAO) {
          printf("Não foi possível adicionar a peça no tabuleiro!\n");
          printf("O número %d já existe na região %d, linha %d e coluna %d!\n",
                 c.valor, c.regiao, c.linha, c.coluna);
        }
        imprimirTabuleiro(tabuleiro);
        break;
    }
  } while (1);

  return 0;
}