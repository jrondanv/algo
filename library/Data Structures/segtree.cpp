#include <stdio.h>
#include <string.h>

#define MAXN 100000
int N; // numero de elementos da arvore

unsigned long long tree[4*MAXN+10];
unsigned long long update[4*MAXN+10];

// junta informações de dois nós

unsigned long long join(unsigned long long a, unsigned long long b) {
    return a+b;
}

// atualiza o nó, depende do problema
// nesse exemplo, tree[i] eh a soma dos numeros do intervalo [st, end]

void atualiza(int i, unsigned long long v, int st, int end) {
    tree[i] += v*(end - st + 1);
    
    if (st != end) {
        update[2*i] += v;
        update[2*i+1] += v;
    }
}

// mudar o caso-base de acordo com o estado inicial da árvore

void create_tree (int i=1, int e=1, int d=N) {
	if (e == d) {
        tree[i] = 0;
	}
	
	else {
		create_tree(2*i, e, (e+d)/2);
		create_tree(2*i+1, (e+d)/2 + 1, d);
		
		tree[i] = join(tree[2*i],tree[2*i+1]);
	}
}

unsigned long long sum(int p, int q, int v, int i=1, int st=1, int end=N) {    
    atualiza(i,update[i],st,end);
    update[i]=0;
    
    if (p <= st && end <= q) 
        atualiza(i,v,st,end);
    
    else if (q >= st && p <= end) 
        tree[i] = join(sum(p, q, v, 2*i, st, st+(end-st)/2),
                       sum(p, q, v, 2*i+1, st+(end-st)/2+1, end));

    return tree[i];
}

unsigned long long query(int p, int q, int i=1, int st=1, int end=N) {
    atualiza(i,update[i],st,end);
    update[i]=0;
    
    if (q < st || p > end) return 0;
    
    if (p <= st && end <= q) 
        return tree[i];
    
    return join(query(p,q,2*i,st,st+(end-st)/2), query(p,q,2*i+1,st+(end-st)/2+1,end));
}



int main() {
    int T;
    scanf("%d", &T);
    
    int tcnt;
    for (tcnt=0; tcnt<T; tcnt++) {
        int C;
        scanf("%d %d", &N, &C);
        
        int i;
        create_tree();
        memset(update,0,sizeof(update));
        
        for (i=0; i<C; i++) {
            int t, p, q, v;
            scanf("%d %d %d", &t, &p, &q);
            
            if (t == 0) {
                scanf("%d", &v);
                sum(p,q,v);
            }
            
            else {
                printf("%llu\n", query(p,q));
            }
        }
        
    }
    
    return 0;
}
        


