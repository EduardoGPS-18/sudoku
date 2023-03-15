#ifndef FUNCOES_JOGO_H
#define FUNCOES_JOGO_H

int resolverSudoku(int** tabuleiro, int linha, int coluna);
int posicaoValidaParaColocarNumero(int** tabuleiro, int linha, int coluna,
                                   int num);
void criarJogoAleatorio(int** tabuleiro);
void removerPecas(char dificuldade, int** tabuleiro);

#endif