#include <stdio.h> 
#include <stdlib.h> 
# include <time.h> 
# define N 3     
# define N2 N*N 
# define N4 N2*N2 
int A[N2+1][N2+1],Rows[4*N4+1],Cols[N4*N2+1],Row[4*N4+1][N2+1],Col[N4*N2+1][5]; 
int Ur[N4*N2+1],Uc[4*N4+1],V[4*N4+1],C[N4+1],I[N4+9],Node[N4+1],M1[N4*N2]; 
int i,j,k,l,m0,m1,r,p,r1,c,c1,c2,n=N4*N2,m=4*N4,x,y,s,min,clues,nodes; 
char L[66]=".123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz#*~"; 

inline int read_int() {
    char c;
    while ((c=fgetc(stdin)) < 48 || c > 57);
    int p = c-48;
    while ((c=fgetc(stdin)) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int testes;

int main(int argc,char*argv[]){
  p=1;
  r=0;for(x=1;x<=N2;x++)for(y=1;y<=N2;y++)for(s=1;s<=N2;s++){ 
            r++;Cols[r]=4;Col[r][1]=x*N2-N2+y;Col[r][2]=(N*((x-1)/N)+(y-1)/N)*N2+s+N4; 
            Col[r][3]=x*N2-N2+s+N4*2;Col[r][4]=y*N2-N2+s+N4*3;} 
            for(c=1;c<=m;c++)Rows[c]=0; 
            for(r=1;r<=n;r++)for(c=1;c<=Cols[r];c++){ 
            x=Col[r][c];Rows[x]++;Row[x][Rows[x]]=r;} 

  for (testes=read_int(); testes; testes--) {
            i=0;for(x=1;x<=N2;x++)for(y=1;y<=N2;y++){ 
            m1: c=fgetc(stdin);j=0;if(c=='-' || c=='.'|| c=='0' || c=='*')goto m7; 
               while(L[j]!=c && j<=N2)j++;if(j>N2)goto m1; 
            m7:A[x][y]=j;i++;} 

            for(i=1;i<=n;i++)Ur[i]=0;for(i=1;i<=m;i++)Uc[i]=0;for(i=1;i<=N4;i++)Node[i]=0; 
            clues=0;for(x=1;x<=N2;x++)for(y=1;y<=N2;y++) 
            if(A[x][y]){clues++;r=x*N4-N4+y*N2-N2+A[x][y]; 
            for(j=1;j<=Cols[r];j++){c1=Col[r][j];if(Uc[c1]){goto m6;} 
            Uc[c1]++;for(k=1;k<=9;k++){Ur[Row[c1][k]]++;}}} 
            for(c=1;c<=m;c++){V[c]=0;for(i=1;i<=9;i++)if(Ur[Row[c][i]]==0) 
             {V[c]++;x=Row[c][i];Row[c][i]=Row[c][V[c]];Row[c][V[c]]=x;}Rows[c]=V[c];} 

               m1=0;for(c=1;c<=m;c++)if(V[c]<2 && Uc[c]==0){m1++;M1[m1]=c;} 
               i=clues;m0=0;nodes=0; 
            m2:i++;I[i]=0;min=n+1;if(i>N4 || m0)goto m4; 
            m22:if(m1==0)goto m21;if(Uc[M1[m1]]==0 && V[M1[m1]]==1){C[i]=M1[m1];m1--;goto m3;} 
               m1--;goto m22; 
            m21:if(nodes&1) for(c=1;c<=m;c++){if(!Uc[c])if(V[c]<min){min=V[c];C[i]=c;}} 
              if(!(nodes&1))for(c=m;c>=1;c--){if(!Uc[c])if(V[c]<min){min=V[c];C[i]=c;}} 
               if(min==0 || min>n)goto m4; 
            m3:c=C[i];I[i]++;if(I[i]>Rows[c])goto m4; 
               r=Row[c][I[i]];if(Ur[r])goto m3;m0=0; 

               if(p){k=N4;j=N2;x=(r-1)/k+1;y=((r-1)%k)/j+1;s=(r-1)%j+1;A[x][y]=s; 
                 if(i==N4){for(x=1;x<=N2;x++){for(y=1;y<=N2;y++)printf("%c",L[A[x][y]]);printf("\n");}if(p==1)goto m6;}} 

               for(j=1;j<=Cols[r];j++){c1=Col[r][j];Uc[c1]++;} 
               for(j=1;j<=Cols[r];j++){c1=Col[r][j]; 
                 for(k=1;k<=Rows[c1];k++){r1=Row[c1][k];Ur[r1]++;if(Ur[r1]==1) 
                   for(l=1;l<=Cols[r1];l++){c2=Col[r1][l];V[c2]--; 
                     if(Uc[c2]+V[c2]<1)m0=c2;if(Uc[c2]==0 && V[c2]<2){m1++;M1[m1]=c2;}}}} 

               nodes++;Node[i]++;goto m2; 
            m4:i--;c=C[i];r=Row[c][I[i]];if(i==clues){if(p==0)printf("%i\n",Node[N4]);goto m6;} 
               for(j=1;j<=Cols[r];j++){c1=Col[r][j];Uc[c1]--; 
                 for(k=1;k<=Rows[c1];k++){r1=Row[c1][k];Ur[r1]--; 
                   if(Ur[r1]==0)for(l=1;l<=Cols[r1];l++){c2=Col[r1][l];V[c2]++;}}} 
               goto m3; 

            m6:{}
    }
} 
