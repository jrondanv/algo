#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
typedef long long ll;

#define INF 1000000000

struct node {
    node *L, *R;
    int c, y;
    int n; ll v;
};

void relax(node* T) {
    if (T==NULL) return;
    
    T->v = T->n;
    T->c = 1;
    if (T->L != NULL) {
        T->v += T->L->v;
        T->c += T->L->c;
    }
    if (T->R != NULL) {
        T->v += T->R->v;
        T->c += T->R->c;
    }
} 

node* pilha[100000];
int fim;

node* build(int N, int* arr) {
    fim = 0;
    node* dummy = new node;
    dummy->y = -INF;
    dummy->L=dummy->R=NULL;
    pilha[fim++]=dummy;
    
    for (int i = 0; i < N; i++) {
        node* N = new node;
        N->n = arr[i];
        N->y = rand();
        N->L = N->R = NULL;
        N->v = N->n;
        
        while (pilha[fim-1]->y > N->y) {
            fim--;
            relax(pilha[fim]);
        }
        
        N->L = pilha[fim-1]->R;
        pilha[fim-1]->R = N;
        
        pilha[fim++]=N;
    }
    
    for (int i = fim-1; i >=0; i--) relax(pilha[i]);
    return dummy->R;
}

int cnt(node* T) {
    return T ? T->c : 0;
}

int lc(node* T) {
    return T->L ? T->L->c : 0;
}

void split(node* T, int x, node* &L, node* &R) {
    if (T == NULL) {L=R=NULL; return; }
    
    if (x <= lc(T)) {
        split(T->L, x, L, T->L);
        R=T;
    }
    else {
        split(T->R, x - lc(T) - 1, T->R, R);
        L=T;
    }
    
    relax(T);
}

node* merge(node* L, node* R) {
    if (L==NULL) return R;
    if (R==NULL) return L;
    
    if (L->y < R->y) {
        L->R = merge(L->R, R);
        relax(L);
        return L;
    }
    
    else {
        R->L = merge(L, R->L);
        relax(R);
        return R;
    }
}

void pt(node* T, int d = 0) {
    if(T==NULL) return;
    pt(T->L); 
    printf("%d ", T->n);
    pt(T->R);
}

ll s(node* N) {
    if (N == NULL) return 0;
    return N->v;
}

int odds[100000];

int main() {
    freopen("movetofront.in","r",stdin);
    freopen("movetofront.out","w",stdout);
    srand(time(NULL));
    
    int n,m;
    scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            odds[i]=i+1;
        }
        
        node* T = build(n, odds);
        
        int fO, lO;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &fO, &lO);
            node *oL, *oR, *oL2, *oR2;
            
            split(T, fO-1, oL, oR);
            
            lO -= cnt(oL);
            
            split(oR, lO, oL2, oR2);
            
            T = merge(oL2, oL);
            T = merge(T, oR2);
            
        }
    
    
    pt(T);
}
