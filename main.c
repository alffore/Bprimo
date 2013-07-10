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
/*
 * 
 */
int main(int argc, char** argv) {

    long n=atoi(*(argv+1));
    long cuenta;
    
    printf(" El número n: %ld es primo: %d\n",n,esPrimo(n));
    
    cuenta=buscaDP(n);
    
    printf("tantas parejas: %ld\n",cuenta);
    
    return (EXIT_SUCCESS);
}

int esPrimo(long n){
    
    
    long i;
    
    for(i=2;i<n;i++){
        
       // printf("%ld %d %ld\n",n,i,n%i);
        if(n%i==0)return 0;
        
    }
    
    return 1;
    
    
}


long buscaDP(long n){
    
    long i;
    
    long r=n/2;
    
    long cuenta=0;
    
    long t=0;
    
    for (i=n-1;i>=r;i--){
        
        if(esPrimo(i)==1 && esPrimo(n-i)==1){
            t=r*(r-1)*(r-1)+(r-n+i)*(r-n+i)*(3*r-2);
            t/=2;
            printf("%ld = %ld + %ld  :: r=%ld, a=%ld, t=%ld \n",n,i,n-i,r,r-n+i,t);
            cuenta++;
        }
        
    }
    
    
    return cuenta;
    
}