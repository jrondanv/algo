#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIA_N 24 * 60 * 60
#define DIA_D 10 * 100 * 100
 
#define HORA 60 * 60 * 100
#define MINUTO 60 * 100
#define SEGUNDO 100
 
int main(){
   int h, m, s, c;
   long int horario;
   const double RAZAO = (double)DIA_D / (DIA_N);
 
   while( scanf( "%2d%2d%2d%2d", &h, &m, &s, &c ) != EOF ){
      horario = h * HORA + m * MINUTO + s * SEGUNDO + c;
      printf( "%07li\n", (long int)(horario * RAZAO) );
   }
 
   return 0;
}
