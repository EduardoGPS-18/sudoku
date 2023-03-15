#include <stdio.h>

void salvarMatriz(int** matriz, char nomeArquivo[255]) {
  FILE* arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s", nomeArquivo);
    return;
  }
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      fprintf(arquivo, "%d ", matriz[i][j]);
    }
    fprintf(arquivo, "\n");
  }
  fclose(arquivo);
  printf("Salvo com sucesso em %s!\n", nomeArquivo);
}