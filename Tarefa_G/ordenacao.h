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
// Data: 2015-10-13
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */
#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdlib.h>
#include <stdio.h>

/* Recebe um vetor v[0...n-1] e chama a funcao que ordena-o em ordem crescente
// com o algoritimo: Insertion sort, que tem um consumo de tempo proporcional a
// n no melhor caso e n² no pior. */

void insertion_sort (int *v, int n) ;

/* Recebe um vetor v[0...n-1] e chama a funcao que ordena-o em ordem crescente
// com o algoritimo: Merge sort, que tem um consumo de tempo proporcional a
// n.log n */

void merge_sort (int *v, int n);

/* Recebe um vetor v[0...n-1] e chama a funcao que ordena-o em ordem crescente
// com o algoritimo: Quick sort, que tem um consumo de tempo proporcional a
// n.log em media, mas n² no pior caso. */

void quick_sort (int *v, int n);

/* Recebe um vetor v[0...n-1] e chama a funcao que ordena-o em ordem crescente
// com o algoritimo: Heap sort, que tem um consumo de tempo proporcional a
// 3.n.log no maximo. */

void heap_sort (int *v, int n);

#endif