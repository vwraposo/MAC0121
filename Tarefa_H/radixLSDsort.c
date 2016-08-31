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

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "ordenacao.h"


/* Verifica se o vetor de inteiros v[0...n] esta em ordem crescente.
// Devolve 1 se estiver e 0 caso contrario.*/

int verify (int v[], int n);

/* Cria um vetor v[0....n-1] com elementos gerados aleatoriamente */

void new_array (int v[], int n);

/* Converte um vetor v[0...n-1] de inteiros em um vetor s[0...n-1] de strings */

void int_to_str (char *s[], int v[], int n);

/* Converte um vetor s[0...n-1] de strings em um vetor v[0...n-1] de inteiros */

void str_to_int (char *s[], int v[], int n);

int 
main () 
{
    int n = 40000, v[320000], i;
    char *s[320000];
    double start, finish, elapsed;

    for (i = 0; i < 320000; i++) 
        s[i] = malloc (9 * sizeof (char));

    for (n = 40000; n <= 320000; n*=2) {
        printf ("n = %d\n", n);

        new_array (v, n);
        int_to_str (s, v, n);

        start = (double) clock () / CLOCKS_PER_SEC;
        heap_sort (v, n);
        finish = (double) clock () / CLOCKS_PER_SEC;
        elapsed = finish - start;
        if (verify (v, n))
            printf ("\t Heapsort: %fs\n", elapsed);

        start = (double) clock () / CLOCKS_PER_SEC;
        ordenacao_Digital (s, n);
        finish = (double) clock () / CLOCKS_PER_SEC;
        elapsed = finish - start;
        str_to_int (s, v, n);
        if (verify (v, n))
            printf ("\t Ordenacao Digital: %fs\n", elapsed);
    } 
    
    for (i = 0; i < 320000; i++) 
        free (s[i]);

    return 0;
}

int
verify (int v[], int n)
{
    int i;
    for (i = 1; i < n; i++)
        if (v[i] < v[i-1]) return 0;
    return 1;
}

void 
new_array (int *v, int n) 
{
    int r, i;
    srand (42);
    for (i = 0; i < n; i++) {
        r = 100000000 + ((rand ()) % 899999999);
        v[i] = r;
    }
}

void
int_to_str (char *s[], int v[], int n)
{
    int i, j, num;
    for (i = 0; i < n; i++) {
        num = v[i];
        for (j = 8; j >= 0; j--){
            s[i][j] = num % 10 + '0';
            num = num / 10;
        }
        s[i][9] = '\0';
    }
}

void 
str_to_int (char *s[], int v[], int n) 
{
    int i;
    for (i = 0; i < n; i++)
        v[i] = atoi (s[i]);
}