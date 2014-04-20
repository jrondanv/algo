#include <stdio.h>
#include <string.h>

int cnt[10];
int hand[10][60];

int ntv[1000];
int bar[300];

int bar_top, desc;

int draw(int p) {
    hand[p][bar[bar_top++]]++;
    cnt[p]++;
    return bar[bar_top-1];
}

int descarta(int p, int cart) {
    hand[p][cart]--;
    cnt[p]--;
    
    desc = cart;
}

int main() {
    ntv['C']=0;
    ntv['D']=1;
    ntv['H']=2;
    ntv['S']=3;
    
    int P, M, N;
    
    
    while (scanf("%d %d %d", &P, &M, &N) && P) {
        
        memset(hand,0,sizeof(hand));
        
        for (int p = 0; p < P; p++) {
            cnt[p] = M;
            
            for (int m = 0; m < M; m++) {
                int a;
                char b;
                scanf(" %d %c", &a, &b);
                
                hand[p][4*a + ntv[b]]++; 
            }
        }
        
        for (int i = 0; i < N - P*M; i++) {
            int a;
            char b;
            scanf(" %d %c", &a, &b);
                
            bar[i] = 4*a + ntv[b]; 
        }
        
        int control = 1;
        int turn = 0;
        desc = bar[0];
        bar_top = 1;
        
        if (desc/4 == 12) control *= -1;
        else if (desc/4 == 7) {
            draw(0);
            draw(0);
            turn=1;
        }
        else if (desc/4 == 1) {
            draw(0);
            turn=1;
        }
        else if (desc/4 == 11) turn = 1;
        
        while (1) {
            int found = 0;
            for (int i = 55; i > 3; i--) {
                if (hand[turn][i] && (i/4 == desc/4 || i%4 == desc%4)) {
                    found=1;
                    descarta(turn, i);
                    
                    break;
                }
            }
            
            if (cnt[turn] == 0) {
                printf("%d\n", turn+1);
                break;
            }
            
            if (!found) {
                int cart = draw(turn);
                if (cart/4 == desc/4 || cart%4 == desc%4) {
                    descarta(turn,cart);
                    found = 1;
                }
            }
                
            if (found) {  
                int np = (turn + control + P) % P;
                if (desc/4 == 12) control *= -1;
                else if (desc/4 == 7) {
                    draw(np);
                    draw(np);
                    turn=np;
                }
                else if (desc/4 == 1) {
                    draw(np);
                    turn=np;
                }
                else if (desc/4 == 11) turn = np;
            }
        
            turn = (turn + control + P) % P;
        }
    }
    
    return 0;
} 
