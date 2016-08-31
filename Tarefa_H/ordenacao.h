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
// Data: 2015-11-2
// 
// Este arquivo faz parte da tarefa H
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdlib.h>
#include <stdio.h>

/* Recebe um vetor v[0...n-1] de inteiros e chama a funcao que rearranja-o em 
// ordem crescente.*/

void heap_sort (int *v, int n);

/* Recebe um vetor v[0...n-1] de strings e chama a funcao que rearranja-o em 
// ordem lexicografica.*/

void ordenacao_Digital (char *v[], int n);

#endif