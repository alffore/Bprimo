/* 
 * File:   main.c
 * Author: alfonso
 *
 * Created on 4 de julio de 2013, 01:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int esPrimo(long n);
long buscaDP(long n);

int timp;

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {

    long n = atoi(*(argv + 1));
    long cuenta;

    timp = 0 + atoi(*(argv + 2));

    printf("# El número n: %ld es primo: %d\n", n, esPrimo(n));

    cuenta = buscaDP(n);

    printf("# tantas parejas:%ld:%ld\n", n,cuenta);

    return (EXIT_SUCCESS);
}

/**
 * 
 * @param n
 * @return 
 */
int esPrimo(long n) {


    long i;

    for (i = 2; i < n; i++) {


        if (n % i == 0)return 0;

    }

    return 1;


}

/**
 * 
 * @param n
 * @return 
 */
long buscaDP(long n) {

    long i;

    long r = n / 2;

    long cuenta = 0;

    long t = 0;

    for (i = n - 1; i >= r; i--) {

        if (esPrimo(i) == 1 && esPrimo(n - i) == 1) {
            t = r * (r - 1)*(r - 1)+(r - n + i)*(r - n + i)*(3 * r - 2);
            t /= 2;
            if (timp > 0) {
                printf("%ld = %ld + %ld  :: r=%ld, a=%ld, t=%ld \n", n, i, n - i, r, r - n + i, t);
            } else {
                printf("%ld %ld %ld %ld %ld %ld\n", n, i, n - i, r, r - n + i, t);
            }
            cuenta++;
        }

    }


    return cuenta;

}