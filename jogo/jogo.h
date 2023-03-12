#ifndef JOGO_H
#define JOGO_H
#include "../tabuleiro/tabuleiro.h"

enum Acao { ADICIONAR_NUMERO = 0, SALVAR = 1, VOLTAR_MENU = 2 };

typedef struct {
  int acao;
  int regiao;
  int linha;
  int coluna;
  int valor;
} Comando;

Comando lerComando();
void exibirComando(Comando comando);
int adicionarPecaTabuleiro(int** tabuleiro, Comando comando);
int executandoJogo(int** tabuleiro);

int verificaMesmoNumeroNaMesmaColuna(int** tabuleiro, int coluna, int numero);
int verificaMesmoNumeroNaMesmaLinha(int** tabuleiro, int linha, int numero);
int verificaMesmoNumeroNaMesmaRegiao(int** tabuleiro, int regiao, int numero);

#endif