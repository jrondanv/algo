#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cards[2];
int trinca[2];

int pot3[16];
int memo[1600000];

void pre() {
    int pot = 1;
    for (int i = 0; i < 16; i++) {
        pot3[i] = pot;
        pot *= 3;
    }
    
    memset(memo,-1,sizeof(memo));
    memo[0] = 0;
}

int get(int state, int k) {
    return (state % pot3[k+1])/pot3[k];
}



int trincas(int state) {
    if (memo[state] != -1) return memo[state];
    
    int ret = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = i+1; j <= 13; j++) {
      
            if (get(state,i-1)==2 && get(state,j-1) && i+i>j) {
                ret = max(ret, trincas(state-pot3[i-1]-pot3[i-1]-pot3[j-1])+1);
            }
            
            if (get(state,i-1) && get(state,j-1)==2) {
                ret = max(ret, trincas(state-pot3[i-1]-pot3[j-1]-pot3[j-1])+1);
            }
                
            for (int k = j+1; k < min(14,i+j); k++) {
                if (get(state,i-1) && get(state,j-1) && get(state,k-1)) {
                    ret = max(ret, trincas(state-pot3[i-1]-pot3[j-1]-pot3[k-1])+1);                            
                }
            }
            
        }
    }
    
    memo[state] = ret;
    return ret;
}

int main() {
    int N;
    
    pre();
    
    while (scanf("%d", &N) && N) {
        int pl = 0;
        
        cards[0]=cards[1]=0;
        trinca[0]=trinca[1]=0;
        
        for (int i = 0; i < N; i++) {
            int c;
            scanf("%d", &c);
            c--;
            
            if (get(cards[pl], c) == 2) {
                trinca[pl]++;
                cards[pl] -= 2*pot3[c];
            }
            else cards[pl] += pot3[c];
            
            pl = 1-pl;
        }
        
        //printf("Round 1: %d x %d\n", trinca[0],trinca[1]);
        if (trinca[0] > trinca[1]) printf("1\n");
        else if (trinca[1] > trinca[0]) printf("2\n");
        else {
            trinca[0] = trincas(cards[0]);
            trinca[1] = trincas(cards[1]);
            
            //printf("Round 2: %d x %d\n", trinca[0],trinca[1]);
            if (trinca[0] > trinca[1]) printf("1\n");
            else if (trinca[1] > trinca[0]) printf("2\n");
            else printf("0\n");
        } 
    }

    return 0;    
}
