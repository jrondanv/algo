//Treap para arvore binária de busca

struct node{
    int x, y, cnt;
    node *l, *r;    
};

node data[MAXN];
int data_cnt; //zerar no main
node* tree; //raiz
node* null; //referência de nulo

//cria uma treap de 1 elemento igual a 'x'
node* new_node( int x ){
    data[data_cnt].x=x;
    data[data_cnt].y=rand();
    data[data_cnt].cnt=1;
    data[data_cnt].l=null;
    data[data_cnt].r=null;
    return &data[data_cnt++];
}

//atualiza calculo do nó 't'
void refresh(node* t){
    if( t!=null ){
        t->cnt = t->l->cnt + t->r->cnt + 1;
    }
}

//quebra treap 't' nas treaps 'a' e 'b'
//'a' contem todos os elementos menores que 'k'
void split( node* &t, int k, node* &a, node* &b ){
    if( t==null ){
        a=b=null;   
    }   
    else if( t->x < k ){
        node *aux1;
        split(t->r,k,aux1,b);
        t->r=aux1;
        refresh(t);
        a=t;
    }
    else{
        node *aux1;
        split(t->l,k,a,aux1);
        t->l=aux1;
        refresh(t);
        b=t;
    }
}

//merge nas treaps 'a' e 'b'
//elementos de 'a' são menores que 'b'
node* merge( node* &a, node* &b ){
    if( a==null ){
        return b;   
    }
    else if( b==null ){
        return a;   
    }
    if( a->y < b->y ){
        node* aux=merge(a->r,b);
        a->r=aux;
        refresh(a);
        return a;
    }
    else{
        node* aux=merge(a,b->l);
        b->l=aux;
        refresh(b);
        return b;
    }
}

//verifica se existe 'k' na treap 't'
bool find( node* t, int k ){
    if( t==null ){
        return false;   
    }   
    else if( k < t->x ){
        return find(t->l,k);    
    }
    else if( k == t->x ){
        return true;    
    }
    else{
        return find(t->r,k);    
    }
}

//insere 'k' na treap 't'
bool insert( node* &t, int k ){
    if( find(t,k) ){
        return false;   
    }
    node *a, *b, *c, *d;
    split(t,k,a,b);
    c=new_node(k);
    d=merge(a,c);
    t=merge(d,b);
    return true;
}

//deleta 'k' da treap 't'
bool erase( node* &t, int k ){
    if( !find(t,k) ){
        return false;   
    }
    node *a, *b, *c, *d;
    split(t,k,a,b);
    split(b,k+1,c,d);
    t=merge(a,d);
    return true;    
}

//retorna 'k'-ésimo elemento de 't'
int k_element( node* t, int k ){
    if( k <= t->l->cnt ){
        return k_element(t->l,k);
    }   
    else if( k == t->l->cnt+1 ){
        return t->x;    
    }
    else{
        return k_element(t->r,k-t->l->cnt-1);
    }
}

//retorna o número de valores em 't' menores que 'k'
int count( node* t, int k ){
    if( t==null ){
        return 0;   
    }
    else if( k <= t->x ){
        return count(t->l,k);
    }   
    else{
        return 1+t->l->cnt+count(t->r,k);
    }
}


//Treap com corte e swap de vetor

struct node{
    int c, y, val, swap;
    long long sum;
    node *l, *r; 
    node(){}
    node( int v ){
        val=sum=v;
        y=rand();
        c=1;
        swap=0;
    }
};

FILE *in, *out;
int n, m;
node null, data[MAXD];
node *tree;
int d_cnt;

node* new_node( int val ){
    node *ret = &(data[d_cnt++]=node(val));
    ret->r=ret->l=&null;
    return ret;
}

void relax( node* t ){
    if( t!=&null ){
        t->c = t->l->c + t->r->c + 1;
        t->sum = t->l->sum + t->r->sum + t->val;
        if( t->swap==1 ){
            node* aux=t->l;
            t->l=t->r;
            t->r=aux;
            t->l->swap^=1;
            t->r->swap^=1;
            t->swap=0;
        }
    }
}

void relax_child( node* &t ){
    if( t!=&null ){
        relax(t);
        relax(t->l);
        relax(t->r);
    }
}

void split( node* &t, int x, node* &lt, node* &rt){
    relax_child(t);
    if( t==&null ){
        lt=rt=&null;
    }
    else{
        node *a, *b;
        if( x <= t->l->c ){
            split(t->l,x,a,b);
            t->l=b;
            lt=a;
            rt=t;
            relax(t);
        } 
        else{
            split(t->r,x-t->l->c-1,a,b);
            t->r=a;
            lt=t;
            rt=b;
            relax(t);
        }
    }
}

void merge( node* &t1, node* &t2, node* &t ){
    relax_child(t1);
    relax_child(t2);
    if( t1==&null ){
        t = t2;
    }
    else if( t2==&null ){
        t = t1;
    }
    else{
        node* a;
        if( t1->y < t2->y ){
            merge(t1->r,t2,a);
            t1->r = a;
            relax(t1);
            t = t1;
        }
        else{
            merge(t1,t2->l,a);
            t2->l = a;
            relax(t2);
            t = t2;
        }
    }
}

void insert( node* &t, int pos, int val ){
    node *lt, *rt, *a, *b;
    split(t,pos-1,lt,rt);
    a = new_node(val);
    merge(lt,a,b);
    merge(b,rt,t);
}

void create(){
    int k;
    d_cnt=0;
    tree = &null;
    null.c = 0;
    null.sum = 0;
    for( int i=1 ; i<=n ; i++ ){
        fscanf(in,"%d",&k);
        insert(tree,i,k);
    }
}

int r[MAXD], cnt;

void put_print( node* t ){
    relax_child(t);
    if( t!=&null ){
        put_print(t->l);
        r[++cnt]=t->val;
        put_print(t->r);
    }
}

long long soma( node* &t, int a, int b ){
    long long ret=0;
    if( t!=&null ){
        relax_child(t);
        if( a<=1 && t->c<=b ){
            return t->sum;
        }
        if( t->l->c >= a ){
            ret+=soma(t->l,a,b);
        }
        if( t->l->c+1 >= a && t->l->c+1 <= b ){
            ret+=t->val;
        }
        if( b > t->l->c+1 ){
            ret+=soma(t->r,a-t->l->c-1,b-t->l->c-1);
        }       
    }
    return ret;
}



void reverse( node* &t, int a, int b ){
    node *t1, *t2, *t3, *aux;
    split(t,a-1,t1,aux);
    split(aux,b-a+1,t2,t3);
    t2->swap^=1;
    merge(t1,t2,aux);
    merge(aux,t3,t);    
}

/////

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
