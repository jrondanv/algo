#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000000

int p[MAXN];
char str[MAXN], s[MAXN];
int map[128];
int M, T;
bool KMP(char *str,char *s){    //find s in str
        p[0]=-1;
        for(int i=1,j=-1;i<T-1;i++){
                while(j>=0 && s[j+1]!=s[i])
                        j=p[j];
                if(s[j+1]==s[i])
                        j++;
                p[i]=j;
        }
        for(int i=0,j=-1;i<M-1;i++){
                while(j>=0 && s[j+1]!=str[i])
                        j=p[j];
                if(s[j+1]==str[i]){
                        j++;
                        if(j+1==T-1){
                                return true;
                                j=p[j];
                        }
                }
        }
        return false;
}


int main(){
    map['A']=0;
    map['B']=2;
    map['C']=3;
    map['D']=5;
    map['E']=7;
    map['F']=8;
    map['G']=10;
    
    while (scanf("%d %d", &M, &T) && M) {
        int prev;
        char nota[10];
        for (int i = 0; i < M; i++) {
            scanf(" %s", nota);
            int val = map[nota[0]];
            
            if (nota[1] == '#') val++;
            else if (nota[1] == 'b') val--;
            
            if (i != 0) {
                str[i-1] = (val - prev + 12) % 12;
            }
            prev = val;
        }
        for (int i = 0; i < T; i++) {
            scanf(" %s", nota);
            int val = map[nota[0]];
            
            if (nota[1] == '#') val++;
            else if (nota[1] == 'b') val--;
            
            if (i != 0) {
                s[i-1] = (val - prev + 12) % 12;
            }
            prev = val;
        }
        
        if (KMP(str,s)) printf("S\n");
        else printf("N\n");
    }
    return 0;
}
