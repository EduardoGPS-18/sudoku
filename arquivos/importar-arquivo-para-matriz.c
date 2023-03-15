#include <stdio.h>
#include <string.h>

#include "../tabuleiro/tabuleiro.h"
#include "./arquivos.h"

int importarArquivoParaMatriz(int **matriz, char fileName[255]) {
  char caminhoCompleto[255] = "./";
  strcat(caminhoCompleto, fileName);
  FILE *file = fopen(caminhoCompleto, "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo %s\n", fileName);
    return 1;
  }

  for (int i = 0; i < QUANTIDADE_REGIOES; i++) {
    for (int j = 0; j < QUANTIDADE_REGIOES; j++) {
      fscanf(file, "%d", &matriz[i][j]);
    }
  }
}