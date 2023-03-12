#include <stdio.h>

#include "menu.h"

int pegarOpcao() {
  int opcao;
  do {
    scanf("%d", &opcao);
    if (opcao < 0 || opcao > 3) {
      printf("Opção inválida. Tente novamente.\n");
      imprimirMenu();
    }
  } while (opcao < 0 || opcao > 3);

  return opcao;
}