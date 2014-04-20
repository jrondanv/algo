#include <stdio.h>
#include <string.h>

#define maxN 100010
int N, E, i, cidade1, cidade2;
int dad[maxN];

//MTTTTTTTTTT IMPORTANTE!!!!!
//CIDADES NUMERADAS A PARTIR DE 1!!!!!!!!!

//doit!=0 implica realizar a uniao
int find(int x, int y, int doit){
   int i, j, t;
   i=x;
   j=y;
   while (dad[i]>0) i=dad[i];
   while (dad[j]>0) j=dad[j];
   while (dad[x]>0){
       t=x;
       x=dad[x];
       dad[t]=i;
   }
   while (dad[y]>0){
       t=y;
       y=dad[y];
       dad[t]=j;
   }
   
   if ((doit!=0) && (i!=j)){
       if(dad[j]<dad[i]){
           dad[j]+=dad[i]-1;
           dad[i]=j;
       }
       else{
           dad[i]+=dad[j]-1;
           dad[j]=i;
       }
   }
   return (i!=j);
   //retorna 0 se i e j estavam na mesma componente
}

int main(){
   scanf (" %d %d", &N, &E);
   memset(dad, 0, sizeof(dad));
   for (i=0; i<E; i++){
       char op;
       scanf (" %c %d %d", &op, &cidade1, &cidade2);
       if (op == 'F') find(cidade1, cidade2, 1);
       else {
            if (find(cidade1, cidade2, 0)) printf("N\n");
            else printf("S\n");
        }
   }
   return 0;
}
