#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"

void lerNomeArquivo(char nomeArquivo[255]) {
  printf("Digite o nome do arquivo: ");
  fscanf(stdin, "%s", nomeArquivo);
  printf("\n");
}