#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, E;

struct indio {
    int loc;
    int sent;
};

indio locs[1000];
int n_locs[1000];
int state[1000000];

int comp(indio a, indio b) {
    return a.loc<b.loc;
}

int move(int delta) {
    for (int i = 0; i < E; i++) {
        n_locs[i] = (locs[i].loc + locs[i].sent*delta + N) % N;
        state[n_locs[i]]++;
    }
    sort(n_locs, n_locs+E);
    
    int ig = 1;
    for (int j = 0; j < E; j++) {
        if (!state[locs[j].loc]) {
            ig = 0;
            break;
        }
    }
    
    for (int j = 0; j < E; j++) {
        state[n_locs[j]]--;
    }
    
    return ig;
}

int main() {
    scanf("%d %d", &N, &E);
    memset(state,0,sizeof(state));
    
    for (int i = 0; i < E; i++) {
        int loc, sent;
        scanf("%d %d", &loc, &sent);
        
        locs[i].loc = loc-1;
        locs[i].sent = sent;
    }
    
    sort(locs, locs+E, comp);
    
    if (locs[0].sent == 1) {
        for (int i = 1; i < E; i++) {
            if (move(locs[i].loc - locs[0].loc)) {
                printf("%d\n", locs[i].loc - locs[0].loc);
                return 0;
            }
        }
    }
    
    else {
        for (int i = E-1; i > 0; i--) {
            if (move(locs[0].loc + N - locs[i].loc)) {
                printf("%d\n", locs[0].loc + N - locs[i].loc);
                return 0;
            }
        }
    }
    
    printf("%d\n", N);
    return 0;
}

