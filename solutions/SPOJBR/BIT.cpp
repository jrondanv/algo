#include <stdio.h>

int main()
{
    int total=1,i=1,j=0,k=0,l=0,m=0;
    
    while(scanf("%d", &total) && total)
    {
                j = total / 50;
                k = (total - 50*j) / 10;
                l = (total - 50*j - 10*k) / 5;
                m = total - 50*j - 10*k - 5*l;
                printf("Teste %d\n%d %d %d %d\n\n",i,j,k,l,m);
                i++;
                
    }
}
