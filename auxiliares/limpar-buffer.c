#include <stdio.h>

#include "auxiliares.h"

void limparBuffer() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}