#include <stdio.h>
#include <limits.h>

int main (int argnum, char *argv[]) {
    int num, ant = INT_MIN;
    FILE *entrada;
    entrada = fopen (argv[1], "r");
    while (fscanf (entrada, "%d", &num) != EOF) {
        if (num < ant) {
            printf("FUDEU\n");
            fclose (entrada);
            return 0;
        }
        ant = num;
    }
    printf("TUDO CERTO\n");
    return 0;
}
