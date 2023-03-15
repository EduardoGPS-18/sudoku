#include <stdio.h>

#include "menu.h"

int pegarOpcao() {
  char opcao[10];
  do {
    scanf("%s", opcao);
    if (opcao[0] < '0' || opcao[0] > '3') {
      printf("Opção inválida. Tente novamente.\n");
      imprimirMenu();
    }
  } while (opcao[0] < '0' || opcao[0] > '3');

  return (int)opcao[0] - (int)'0';
}