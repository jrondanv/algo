#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX 10010
int p[MAX], rank[MAX];
int c[MAX], size[MAX];

// Inicializa um set x
void make_set(int x) {
    p[x] = x;
    rank[x] = 0;
}

void link(int x,int y) {
    if (rank[x] > rank[y])
        p[y] = x;
    else {
        p[x] = y;
        if (rank[x] == rank[y])
            rank[y] = rank[y] + 1;
    }
}

// Find the set ID of item x
int find_set(int x) {
    if (x != p[x])
        p[x] = find_set(p[x]);
    return p[x];
}

// Union two set containing item x and item y
void union_set(int x,int y) {
    link (find_set(x), find_set(y));
}

int L, B, a, b;

int main() {
    if (scanf("%d %d", &L, &B)<2) printf("%d\n", 1/0);
    for (int i = 0; i < L; i++) {
        make_set(i);
        if (scanf("%d", &c[i])<1) printf("%d\n", 1/0);
    }
    for (int i = 0; i < L; i++) {
        if (scanf("%d", &a)<1) printf("%d\n", 1/0);
        c[i] ^= a;
    }
    for (int i = 0; i < B; i++) {
        if (scanf("%d %d", &a, &b)<2) printf("%d\n", 1/0);
        union_set(a-1,b-1);
    }

    for (int i = 0; i < L; i++) {
        if (c[i]) size[find_set(i)]++;
    }

    bool found = false;
    for (int i = 0; i < L && !found; i++) {
        if (size[i]&1) found = true;
    }

    if (found) printf("N\n");
    else printf("S\n");
}

