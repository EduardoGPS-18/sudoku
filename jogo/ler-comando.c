#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./jogo.h"

Comando lerComando() {
  printf("\nDigite um comando ou indique a celula a alterar: ");
  char comando[25];
  fscanf(stdin, "%s", comando);
  int tamanhoComando = strlen(comando) + 1;
  for (int i = 0; i < tamanhoComando; i++) {
    comando[i] = (char)tolower(comando[i]);
  }

  Comando comandoParaExecutar;

  int valido;
  do {
    valido = 1;
    if (strcmp(comando, "salvar") == 0) {
      comandoParaExecutar.acao = SALVAR;
    } else if (strcmp(comando, "voltar") == 0) {
      comandoParaExecutar.acao = VOLTAR_MENU;
    } else if (tamanhoComando - 1 == 4 && isdigit(comando[0]) &&
               isdigit(comando[1]) && isdigit(comando[2]) &&
               isdigit(comando[3])) {
      comandoParaExecutar.acao = ADICIONAR_NUMERO;
      comandoParaExecutar.regiao = comando[0] - '0';
      comandoParaExecutar.linha = comando[1] - '0';
      comandoParaExecutar.coluna = comando[2] - '0';
      comandoParaExecutar.valor = comando[3] - '0';
    } else {
      valido = 0;
    }
    if (valido == 0) {
      printf(
          "Comando invalido. Digite um comando ou indique a celula a "
          "alterar: ");
      scanf("%s", comando);
      tamanhoComando = strlen(comando) + 1;
    }

  } while (valido == 0);

  return comandoParaExecutar;
}