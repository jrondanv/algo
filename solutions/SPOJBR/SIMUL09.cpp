#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
 
struct PA {
    int ind;
    int st;
    int len;
    bool rev;
    
    bool operator< (PA ot) const {
        return ind < ot.ind;
    }
    
    void print() const {
        printf("%d %d %d %d\n",ind,st,len,rev);
    }
};

set<PA> p;
int N, M;
PA dummy;

PA new_pa[10000];
PA rem[10000];
int tam_rem, tam_new;

long long soma(int a, int b) {
    set<PA>::iterator it;
    dummy.ind=a;
    it = p.upper_bound(dummy);
    it--;
    
    long long resp = 0;
    
    while (it != p.end() && it->ind <= b) {
        int intst = max(a, it->ind);
        int intend = min(b, it->ind + it->len - 1);
        
        long long st,end;
        if (it->rev) st = it->st - (intst-it->ind);
        else st = it->st + (intst-it->ind);
        
        if (it->rev) end = it->st - (intend-it->ind);
        else end = it->st + (intend-it->ind);
        int len = intend - intst + 1;
        
        //printf("st: %d end: %d\n",st,len,end);
        resp += (st + end) * len / 2;
        it++;
    }
    
    return resp;
}

void inverte(int a, int b) {
    set<PA>::iterator it;
    dummy.ind=a;
    it = p.upper_bound(dummy);
    it--;
    
    PA temp, th;
    
    tam_rem = tam_new = 0;
    
    int cur = b;
    while (it != p.end() && it->ind <= b) {
        th = *it;
        p.erase(it++);
        
        if (th.ind < a) {
            temp.ind = th.ind;
            temp.st = th.st;
            temp.len = a - th.ind;
            temp.rev = th.rev;
            //printf("ONE ");
            //temp.print();
            new_pa[tam_new++]=temp;
        }
        if (th.ind + th.len - 1 > b) {
            temp.ind = b+1;
            if (!th.rev) temp.st = (b+1-th.ind) + th.st;
            else temp.st = -(b+1-th.ind) + th.st;
            temp.len = th.len - (b - th.ind) - 1;
            temp.rev = th.rev;
            //printf("TWO ");
            //temp.print();
            new_pa[tam_new++]=temp;
        }
        
        int intst = max(a, th.ind);
        int intend = min(b, th.ind + th.len - 1);
        int st;
        if (th.rev) st = th.st - (intend-th.ind);
        else st = th.st + (intend-th.ind);
        int len = intend - intst + 1;
        
        temp.ind = cur - len + 1;
        temp.rev = !th.rev;
        temp.st = st;
        temp.len = len; 
        new_pa[tam_new++]=temp;
        //temp.print();
        
        cur -= len;
    }
    
    for (int i = 0; i < tam_new; i++) p.insert(new_pa[i]);
    
    /*for (it = p.begin(); it != p.end(); it++) {
        it->print();
    }*/
}

char op;
int a,b;

int main() {
    scanf("%d %d", &N, &M);
    
    PA inic;
    inic.ind = 1;
    inic.st = 1;
    inic.len = 1000000000;
    inic.rev = false;
    p.insert(inic);
    
    char lc;
    int la, lb;
    long long lr;
    
    for (int i = 0; i < M; i++) {
        int ret = scanf(" %c %d %d", &op, &a, &b);
        
        if (ret<=0) {
            if (lc == 'S') {
                for (int j = i; j < M; j++) printf("%lld\n", lr);
            }
            break;
        }
        
        lc = op;
        la = a;
        lb = b;
        if (ret>0) {
            if (op == 'S') {
                lr = soma(a,b);
                printf("%lld\n", lr);
            }
            else inverte(a,b);
        }
    }
}

