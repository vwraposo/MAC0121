#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct pal{
    char *string;
    struct pal *prox;
};

typedef struct pal palavra;

/* Funcao malloc que retorna que retorna NULL caso nao consiga 
// alocar mais espaço */
void *mallocc (size_t nbytes) {
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == NULL)
      exit (EXIT_FAILURE);
   return ptr;
}

/* Funcao que recebe uma string e um inteiro que irá realocar 
// nessa string o valor desse inteiro atraves de uma string 
// auxiliar */
char* aloca (char *str, int n) {
    char *auxiliar;
    auxiliar = mallocc (n / 2);
    strcpy (auxiliar, str);
    free (str);
    str = mallocc (n);
    strcpy (str, auxiliar);
    free (auxiliar);

    return str;
}

/* Funcao que recebe uma celula da lista encadeada, imprime seu  
// conteúdo (string) libera a memoria que foi alocada para ela */
void imprime (palavra *p) { 
    palavra *t;
    while (p != NULL) {
        printf("%s\n", p->string);
        t = p;
        p = p->prox;
        free(t->string);
        free (t);
    }
}   

/* Funcao que le uma linha do texto e retorna ela como uma string
// ou NULL quando acabar o texto */
char* ler_linha () {
    int i = 0;
    int size = 120;
    char c, *linha;
    int fim;
    linha = mallocc (size);
    while ((fim = scanf ("%c", &c)) != EOF && c != '\n') {
        linha[i++] = c;
        if (i == size / 2) {
            size *= 2;
            linha = aloca (linha, size);
        }
    }
    linha[i] = '\0';
    if (!i && fim == EOF)
        return NULL;
    return linha;
}

/* Funcao que recebe uma string e uma celula da lista encadeada
// e verifica se a string ja está na lista, se nao estiver  
// coloca na posicao correta */
void poe_palavra (char *str, palavra *p) {
    if (p->prox == NULL) {
        palavra *nova;
        nova = mallocc (sizeof (palavra));
        p->prox = nova;
        nova->string = mallocc (strlen (str) + 1);
        strcpy (nova->string, str);
        nova->prox = NULL;
        return;
    }
    if (strcmp (str, p->prox->string) == 0) return;
    if (strcmp (str, p->prox->string) < 0) {
        palavra *t;
        palavra *n;
        n = mallocc (sizeof (palavra));
        t = p->prox;
        p->prox = n;
        n->string = mallocc (strlen (str) + 1);
        strcpy (n->string, str);
        n->prox = t;
        return;
    }
    poe_palavra (str, p->prox);     
}         

/* Funcao que recebe a linha lida e a cabeca da lista encadeada
// e busca na linha palavras, ao mesmo tempo converte os
// caracteres maiusculos para minusculos, para inserir na lista 
//usando a funcao "poe_palavra" */
 void acha_palavra (char *linha, palavra *p) {
    int i, j = 0;
    int flag = 0;
    int size = 120;
    char *str;
    str = mallocc (size);
    for (i = 0; linha[i] != '\0'; i++){
        if (j == size / 2) {
            size *= 2;
            str = aloca (str, size);
        }
        if (isalnum (linha[i])) {
            flag = 1;
            str[j++] = tolower (linha[i]);
        } 
        else if (flag) {
            flag = 0;  
            str[j] = '\0';
            poe_palavra (str, p);
            j = 0;
        }
    }
    if (flag) {
        str[j] = '\0';
        poe_palavra (str, p); 
    }
}

int main () {
    char *linha;
    palavra *cabeca;
    cabeca = mallocc (sizeof (palavra));
    cabeca->prox = NULL; 
    cabeca->string = NULL;
    linha = ler_linha (); 
    while (linha != NULL) {
        acha_palavra (linha, cabeca);
        linha = ler_linha ();
    }
    imprime (cabeca->prox);

    free (linha);
    free (cabeca);
    return 0;
}