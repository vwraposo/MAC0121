/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Victor Wichmann Raposo
// Numero USP: 9298020
// Sigla: VICTORWI
// Data: 2015-10-5
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>

struct c {
    int num;
    int arq;
};

typedef struct c celula;

void
peneira (int p, int m, celula v[])
{ 
   int f = 2 * p;
   celula x = v[p];
   while (f <= m) {
      if (f < m && v[f].num > v[f + 1].num) f++;
      if (x.num <= v[f].num) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}

int
sofisticado (FILE **arquivo, FILE *saida, int k)
{
    celula *v;
    int i, total = 0, n = k;
    v = malloc ((k + 1) * sizeof (celula));
    for (i = 1; i <= n; i++) {
        if (fscanf (arquivo[i], "%d", &v[i].num) == EOF) {
            i--; n--;
        }
        else v[i].arq = i;
    }
    for (i = n / 2; i >= 1; i--)
      peneira (i, n, v);
    while (n > 0) {
        fprintf (saida, "%d\n", v[1].num);
        total++;
        if (fscanf (arquivo[v[1].arq], "%d", &v[1].num) == EOF)
            v[1] = v[n--];
        peneira (1, n, v);        
    }
    free (v);
    return total;
}
