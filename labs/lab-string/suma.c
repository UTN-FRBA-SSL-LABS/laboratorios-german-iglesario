#include <stdio.h>
#include "Conversion.h"

/*
 * suma — imprime la suma de todos los argumentos interpretados como enteros.
 *
 * Uso: ./suma 1 2 3    →  6
 *      ./suma -5 10    →  5
 *
 * Pista: usa ToInteger de Conversion.h para convertir cada argumento.
 *        Iterá con puntero (char **arg), no con indice entero.
 */

int main(int argc, char *argv[]) {
    (void)argc; /* Suprime warning de variable no usada */

    int total = 0;

    /* Recorremos desde argv[1] en adelante usando el puntero char **arg */
    for (char **arg = argv + 1; *arg != NULL; arg++) {
        total += ToInteger(*arg);
    }

    printf("%d\n", total);
    return 0;
}