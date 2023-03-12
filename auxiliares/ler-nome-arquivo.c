#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"

void lerNomeArquivo(char nomeArquivo[255]) {
  limparBuffer();
  printf("Digite o nome do arquivo: ");
  fgets(nomeArquivo, 255, stdin);
  printf("\n");
}