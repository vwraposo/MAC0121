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

#include "ordenacao.h"

/* Esta função rearranja o vetor v[0..n-1] em
// ordem crescente. */

static void insercao (int n, int v[]);

/*A função mergesort rearranja o vetor v[p..r-1]
// em ordem crescente. */

static void mergesort (int p, int r, int v[]);

/* A função recebe um vetor v[p..r], com p <= r+1,
// e rearranja o vetor em ordem crescente. */

static void quicksort (int v[], int p, int r);

/* Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente. */

static void heapsort (int n, int v[]);

/* Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente. */

static void intercala (int p, int q, int r, int v[]);

/* Recebe vetor v[p..r] com p < r. Rearranja os 
// elementos do vetor e devolve j em p..r tal que 
// v[p..j-1] <= v[j] < v[j+1..r]. */

static int separa (int v[], int p, int r);

/* Recebe p em 1..m e rearranja o vetor v[1..m] de 
// modo que o "subvetor" cuja raiz é p seja um heap.
// Supõe que os "subvetores" cujas raízes são filhos
// de p já são heaps. */

static void peneira (int p, int m, int v[]);


/*// Funcoes Publicas //////////////////////////////////////////
//////////////////////////////////////////////////////////////*/

void 
insertion_sort (int *v, int n) 
{
    insercao (n, v);
}

void 
merge_sort (int *v, int n) 
{
    mergesort (0, n, v);
}

void 
quick_sort (int *v, int n)
{
    quicksort (v, 0, n - 1);
}

void 
heap_sort (int *v, int n)
{
    heapsort (n, v - 1);
}

/*// Funcoes Privadas //////////////////////////////////////////
//////////////////////////////////////////////////////////////*/

static void
insercao (int n, int v[])
{
   int i, j, x;
   for (j = 1; j < n; ++j) {
      x = v[j];
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}

static void
mergesort (int p, int r, int v[])
{
   if (p < r-1) {
      int q = (p + r)/2;
      mergesort (p, q, v);
      mergesort (q, r, v);
      intercala (p, q, r, v);
   }
}

static void 
quicksort (int v[], int p, int r)
{
   int j;                         
   if (p < r) {                   
      j = separa (v, p, r);       
      quicksort (v, p, j-1);      
      quicksort (v, j+1, r);      
   }
}

static void
heapsort (int n, int v[])
{
   int p, m, x;
   for (p = n/2; p >= 1; --p)
      peneira (p, n, v);
   for (m = n; m >= 2; --m) {
      x = v[1], v[1] = v[m], v[m] = x;
      peneira (1, m-1, v);
   }
}

/*// Funcoes Auxiliares /////////////////////////////////////////
//////////////////////////////////////////////////////////////*/

static void
intercala (int p, int q, int r, int v[])
{
   int i, j, k, *w;
   w = malloc ((r-p) * sizeof (int));
   for (i = 0, k = p; k < q; ++i, ++k) w[i] = v[k];
   for (j = r-p-1, k = q; k < r; --j, ++k) w[j] = v[k];
   i = 0; j = r-p-1;
   for (k = p; k < r; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

static int
separa (int v[], int p, int r)
{
   int c = v[p], i = p+1, j = r, t;
   while (i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j; 
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }                
   v[p] = v[j], v[j] = c;
   return j; 
}

static void
peneira (int p, int m, int v[])
{ 
   int f = 2*p, x = v[p];
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}