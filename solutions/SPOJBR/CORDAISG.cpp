#include <stdio.h>
#include <string.h>
struct Fila{
    int v[1010];
    int i,f;
}F;
void init(){
    F.i=F.f=0;
}
void pop(){
    F.i++;
}
void push(int i){
    F.v[F.f++]=i;
}
int front(){
    return F.v[F.i];
}
bool empty(){
    return F.i==F.f;
}

bool vai;
int m,n,o,d;
int M[1010][1010];
int max[1010];
int cor[1010];
bool pais[1010][1010];
int pred[1010];

void cordal(int i){
    init();
    push(i);
    while(!empty()){
        i=front();
        cor[i]=2;
        pop();
        for(int j=0;j<max[i];j++){
            if(M[i][j]==pred[i] || M[i][j]==i)continue;
            if(cor[M[i][j]]<=1){
                if(cor[M[i][j]]==0){
                    pred[M[i][j]]=i;
                    push(M[i][j]);
                }
                cor[M[i][j]]=1;
                pais[M[i][j]][i]=true;
                
            }
            else{
               // printf("voltou no %d de %d com pai %d\n",M[i][j],i,pred[i]);
                if(!pais[M[i][j]][pred[i]]){
                    printf("0");
                    vai=false;
                    return;
                }
                else{
                    pais[M[i][j]][i]=true;
                }
            }
        }
    
    }
    
    
    
}

int main(){
    while(scanf("%d %d",&n,&m)!=EOF && (m!=0 || n!=0)){
        for(int i=1;i<=n;i++){
            memset(pais[i],0,4*(n+1));
            max[i]=0;
            cor[i]=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d %d",&o,&d);
            M[o][max[o]++]=d;
            M[d][max[d]++]=o;
        }
        vai = true;
        for(int i=0;i<n;i++){
            memset(cor,0,4*(n+1));
            if(vai)cordal(i);
        }
        if(vai)printf("1");
        
        
    }
    
}