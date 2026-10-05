#include "Conversion.h"

/*
 * Conversion.c — Implementación de operaciones de conversión
 *
 * REGLA: no usar atoi, strtol ni ninguna función estándar de conversión
 */

/* ── ToInteger — corregida ──────────────────────────────────────────────── */

int ToInteger(const char *s) {
    int signo     = 1;
    int resultado = 0;
    if (*s == '-') { signo = -1; s++; }
    for (; *s != '\0'; s++)
        resultado = resultado * 10 + (*s - '0');
    return signo * resultado;
}

/* ── Operación libre ─────────────────────────────────────────────────────── */

/*
 * Convierte un número entero `n` a su representación en cadena en el buffer `dest`.
 * Retorna el puntero `dest`.
 */
char *FromInteger(int n, char *dest) {
    char *p = dest;
    int temp = n;
    int len = 0;

    if (n == 0) {
        *p++ = '0';
        *p = '\0';
        return dest;
    }

    if (n < 0) {
        *p++ = '-';
        temp = -n;
    }

    /* Guardamos el inicio de los dígitos para invertir la secuencia al final */
    char *start_digits = p;

    while (temp > 0) {
        *p++ = (char)('0' + (temp % 10));
        temp /= 10;
    }
    *p = '\0';

    /* Invertimos los dígitos acumulados (ya que salieron en orden inverso) */
    char *end_digits = p - 1;
    while (start_digits < end_digits) {
        char tmp = *start_digits;
        *start_digits = *end_digits;
        *end_digits = tmp;
        start_digits++;
        end_digits--;
    }

    return dest;
}