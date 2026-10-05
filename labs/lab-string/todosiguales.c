#include <stdio.h>
#include "String.h"

/*
 * todosiguales — imprime 1 si todos los argumentos son iguales, 0 si no.
 *
 * Uso: ./todosiguales hola hola hola  →  1
 *      ./todosiguales hola mundo      →  0
 *
 * Pista: compara cada argumento contra argv[1] usando AreEqual.
 *        Iterá con puntero (char **arg), no con indice entero.
 */


int main(int argc, char *argv[]) {
    (void)argc; /* Suprime warning de variable no usada */

    /* Si no se pasan argumentos o se pasa solo uno, se consideran todos iguales */
    if (argv[1] == NULL) {
        printf("1\n");
        return 0;
    }

    /* Recorremos desde argv[2] en adelante con puntero char **arg */
    for (char **arg = argv + 2; *arg != NULL; arg++) {
        if (!AreEqual(argv[1], *arg)) {
            printf("0\n");
            return 0;
        }
    }

    printf("1\n");
    return 0;
}