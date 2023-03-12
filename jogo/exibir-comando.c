#include <stdio.h>

#include "./jogo.h"

void exibirComando(Comando comando) {
  switch (comando.acao) {
    case ADICIONAR_NUMERO:
      printf("Foi enviado um comando para adicionar numero!\n");
      printf("Comando: Regiao->%d, Linha->%d, Coluna->%d, Valor->%d\n",
             comando.regiao, comando.linha, comando.coluna, comando.valor);
      break;
    case SALVAR:
      printf("Foi enviado um comando para salvar");
      break;
    case VOLTAR_MENU:
      printf("Foi enviado um comando para voltar ao menu");
      break;
  }
}