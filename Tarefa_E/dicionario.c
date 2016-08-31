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
// Data: 2015-09-12
// 
// Este arquivo faz parte da tarefa E
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "bb.h"

void listapalavras (char *in, char *out);
void constroiDicionario (FILE * entrada);
char *proximaPalavra (FILE * entrada);
void inserePalavra (char *palavra);
void imprimeDicionario (double start, char *out);
void expandeBuffer ();
void expandeDic ();


char **dic;
int n, N;

/* O vetor de caracteres buffer[0..B-1] sera usado para 
// armazenamento temporario de uma palavra lida de stdin. */
char *buffer;
int B;

void
listapalavras (char *in, char *out)
{
    double start;
    time_t timer;
    FILE *entrada;
    entrada = fopen (in, "r");
    time (&timer);
    start = (double) timer;
    N = 16;
    dic = malloc (N * sizeof (char *));
    B = 4;
    buffer = malloc (B * sizeof (char));

    constroiDicionario (entrada);
    fclose (entrada);

    imprimeDicionario (start, out);

    free (buffer);
}

void
constroiDicionario (FILE * entrada)
{
    char *pal;
    n = 0;
    while ((pal = proximaPalavra (entrada)) != NULL) {
        if (!isdigit (pal[0])) {
            int i;
            for (i = 0; pal[i] != '\0'; i++)
            pal[i] = tolower (pal[i]);
            inserePalavra (pal);
        }
        else free (pal);
      }
}

char *
proximaPalavra (FILE * entrada)
{
    int i, c;
    char *pal;
    do {
        c = getc (entrada);
        if (c == EOF)
            return NULL;
    } while (!isalnum (c));
    i = 0;
    do {
        buffer[i++] = c;
        if (i >= B)
        expandeBuffer ();
        c = getc (entrada);
    } while (c != EOF && isalnum (c));
    buffer[i] = '\0';
    pal = malloc (strlen (buffer) + 1);
    strcpy (pal, buffer);
    return pal;
}

void
expandeBuffer ()
{
    char *novobuffer;
    int i;
    novobuffer = malloc (2 * B * sizeof (char));
    for (i = 0; i < B; i++)
        novobuffer[i] = buffer[i];
    B *= 2;
    free (buffer);
    buffer = novobuffer;
}

void
inserePalavra (char *pal)
{
    int i, j;
    if (n == 0) {
        dic[n++] = pal;
        return;
    }
    i = bb (pal);
    if ((i > 0 && strcmp (dic[i - 1], pal) == 0) || 
       (i < n && strcmp (dic[i], pal) == 0)){
        free (pal);
        return;
    }
    if (n == N)
        expandeDic ();
    for (j = n - 1; j >= i; j--)
        dic[j + 1] = dic[j];
    dic[i] = pal;
    n++;
}

void
expandeDic ()
{
    char **novodic;
    int i;
    novodic = malloc (2 * N * sizeof (char *));
    for (i = 0; i < N; i++)
        novodic[i] = dic[i];
    N *= 2;
    free (dic);
    dic = novodic;
}

void
imprimeDicionario (double start, char *out)
{
    int i;
    time_t timer;
    double finish;
    FILE *saida;
    saida = fopen (out, "w");
    for (i = 0; i < n; i++)
        fprintf (saida, "%s\n", dic[i]);
    time (&timer);
    finish = (double) timer;
    fprintf (saida, "\nTempo de Execuçao:\n");
    fprintf (saida, "%.f segundos", finish - start);
    fprintf (saida, "\n");

    fclose (saida);
}
