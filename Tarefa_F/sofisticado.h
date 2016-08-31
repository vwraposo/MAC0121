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
#ifndef SOFISTICADO_H
#define SOFISTICADO_H

#include <stdio.h>

struct c {
    int num;
    int arq;
};

typedef struct c celula;

/* Funcao que recebe p em 1..m e rearranja o vetor v[1..m] de 
// modo que o "subvetor" cuja raiz é p seja um heap.
// Supõe que os "subvetores" cujas raízes são filhos
// de p já são heaps. */
void peneira (int p, int m, celula v[]);

/* Funcao que ira ordenar os elementos de todos os arquivos da vetor 
// arquivo[1...k] em um arquivo de saida */
int sofisticado (FILE **arquivo, FILE *saida, int k);

#endif