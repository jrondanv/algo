char t[MAXN]; //string onde se quer achar o padrão
char p[MAXM]; //padrão
int pos[MAXM]; //função de transição
int n, m; //tamanhos do texto e padrão

//calcula função de transição
void func(){
     int i, j=-1;
     pos[0]=-1;
     for( i=1 ; i<m ; i++ ){
          while( j>=0 && p[j+1]!=p[i] )
                 j=pos[j];
          if( p[j+1]==p[i] )
              j++;
          pos[i]=j;
     }     
}

//acha posições
void kmp(){
     int i, j=-1;
     for( i=0 ; i<n ; i++ ){
          while( j>=0 && t[i]!=p[j+1] )
                 j=pos[j];
          if( t[i]==p[j+1] )
              j++;
          if( j==m-1 ){
              //ocorrencia em i-m+1
              j=pos[j];    
          }
     }
}
