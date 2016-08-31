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
// Data: 2015-11-23
// 
// Este arquivo faz parte da tarefa I
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include "btree.h"

static void limpa_lista (celula *aux);
static void imprime_lista (celula *p, FILE *saida) ;

int altura (arvore r) {
    if (r == NULL) 
        return -1; 
    else {
        int he = altura (r->esq);
        int hd = altura (r->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
}

arvore insere (arvore r, noh *novo) {  
    noh *filho, *pai;
    if (r == NULL) return novo;
    filho = r;
    while (filho != NULL) {
        int aux = strcmp (filho->str, novo->str);
        pai = filho;
        if (aux > 0)  filho = filho->esq;
        else  filho = filho->dir;
    }
    if (strcmp (pai->str, novo->str) > 0)  pai->esq = novo;
    else  pai->dir = novo;
    return r;
}

noh *find (arvore r, char *k) {
    int aux;
    if (r == NULL) return r;
    aux = strcmp (r->str, k);
    if (aux == 0)
        return r;
    if (aux > 0)
       return find (r->esq, k);
    else 
       return find (r->dir, k);
}

void imprime (arvore r, FILE* saida) {
    if (r != NULL) {
        imprime (r->esq, saida);
        fprintf (saida, "%s ", r->str);
        imprime_lista (r->list, saida);
        fprintf (saida, "\n");
        imprime (r->dir, saida); 
    }
}

/* Recebe uma lista encadeada p e imprime 
// o conteudo dessa lista em um arquivo saida */

static void imprime_lista (celula *p, FILE *saida) {
    if (p == NULL) return;
    imprime_lista (p->prox, saida);
    fprintf (saida, "%d, ", p->cont);
}

int contanoh (arvore r) {
    if (r == NULL) return 0;
    return 1 + contanoh (r->esq) + contanoh (r->dir);
}

void limpa_arvore (arvore r) {
    if (r == NULL) return;
    limpa_arvore (r->esq);
    limpa_arvore (r->dir);
    limpa_lista (r->list);
    free (r->str);
    free (r);
}

/* Recebe uma lista ligada p e da free em todas suas celulas */ 

static void limpa_lista (celula *p) {
    if (p == NULL) return;
    limpa_lista (p->prox);
    free (p);
}
