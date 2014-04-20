#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

long long pd[10001][2];
int A;
long long S, E;
int nextegg;

#define INF 1000000000000000LL
#define MAXN 10010
pair<long long, int> tree[MAXN][2];

void add(int egg, int targ, long long delta)  {
    int orig = targ;
    while (targ <= A) {
        if (tree[targ][egg-1].first == 0 || tree[targ][egg-1].first > delta) {
            tree[targ][egg-1].first = delta;
            tree[targ][egg-1].second = orig;
        } 

        targ += targ&-targ;
    }
}

int query(int egg, int tst, int tend) {
    long long bestval = INF;
    int bestid;
    while (tend >= tst) {
        if (tree[tend][egg-1].first < bestval) {
            bestval = tree[tend][egg-1].first;
            bestid = tree[tend][egg-1].second;
        }
        tend -= tend&-tend;
    }
    return bestid;
}


bool brk(int i, int k) {
    long long cst_break = E*(k-i-1);
    cst_break += S*( ( i+k ) * (k-i-1) ) / 2;
    if (nextegg == 1) cst_break -= S*(i+1);

    return cst_break + S*(k-i) + E >= pd[k][nextegg-1] + S*(k-i) + E;
}

long long cost(int i, int k) {
    long long cst_break = E*(k-i-1);
    cst_break += S*( ( i+k ) * (k-i-1) ) / 2;
    if (nextegg == 1) cst_break -= S*(i+1);

    return max(pd[k][nextegg-1] + S*(k-i) + E, cst_break + S*(k-i) + E);
}

int search(int i) {
    int st = i+1, end = A;
    while (st < end) {
        int mid = (st+end)/2;

        if (brk(i, mid)) end = mid;
        else st = mid+1;
    }
    return st;
}

int main() {
    scanf("%d %lld %lld", &A, &S, &E);

    pd[A][0]=pd[A][1]=0;
    add(1,A,S*A);
    add(2,A,S*A);

    for (int i = A-1; i > 0; i--) {
        for (int egg = 1; egg <= 2; egg++) {
            if (egg == 2) nextegg = 1;
            else nextegg = egg+1;

            int cand1 = search(i);
            
            int cand2 = cand1;
            if (cand1 > i+1) cand2 = query(nextegg, i+1, cand1-1);

            if (cost(i,cand1) > cost(i,cand2)) swap(cand1,cand2);
            //int next = search(i, egg);

            pd[i][egg-1] = cost(i, cand1);

            if (egg == 2) pd[i][egg-1] += S*i;
            //printf("de %d (%d) vai pra %d ou %d (custo total: %d)\n", i,egg,cand1,cand2,pd[i][egg]);
        }
        pd[i][0] = min(pd[i][0], pd[i][1]);
        add(1,i,pd[i][0] + S*i);
        add(2,i,pd[i][1] + S*i);
    }

    nextegg = 1;
    int cand1 = search(0);
    int cand2 = cand1;
    if (cand1 > 1) cand2 = query(1,1,cand1-1);
    if (cost(0,cand1) > cost(0,cand2)) swap(cand1,cand2);

    printf("%lld\n", cost(0, cand1));
}