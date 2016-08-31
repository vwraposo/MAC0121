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

int 
minimo (int v[], int flag[], int k)
{
    int i, min = 0;
    for (i = 1; i <= k; i++)
        if (flag[i] == 0) {
            min = i;
            break;
        }
    for (i = min; i <= k; i++)
        if (flag[i] == 0) {
            if (v[i] < v[min])
                min = i;
        }
    return min;
}

int 
simplorio (FILE **arquivo, FILE *saida, int k) 
{
    int *v, *flag;
    int i, id, total = 0, n = k;
    v = malloc ((k + 1) * sizeof (int));
    flag = malloc ((k + 1) * sizeof (int));
    for (i = 1; i <= k; i++)
        flag[i] = 0;
    for (i = 1; i <= n; i++) 
        if (fscanf (arquivo[i], "%d", &v[i]) == EOF) {
            flag[i] = 1; n--;
        }
    while (n > 0) {
        id = minimo (v, flag, k);
        fprintf (saida, "%d\n", v[id]);
        total++;
        if (fscanf (arquivo[id], "%d", &v[id]) == EOF) {
            n--;
            flag[id] = 1;
        }
    }
    free (v);
    return total;
}