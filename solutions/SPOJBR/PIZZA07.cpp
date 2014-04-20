#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int v[200000], soma[200000];
deque<int> inter;
int n;

int get(int st, int end) {
    return soma[end] - (st==0?0:soma[st-1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        v[n+i]=v[i];
    }

    soma[0] = v[0];
    for (int i = 1; i < 2*n; i++) soma[i] = soma[i-1] + v[i];
    
    int best = 0;
    for (int i = 0; i < 2*n; i++) {
        while (!inter.empty() && get(inter.back(), i) <= v[i] ) inter.pop_back();
        while (!inter.empty() && i - inter.front() + 1 > n) inter.pop_front();

        inter.push_back(i);
        best = max(best, get(inter.front(), i));
    }

    printf("%d\n", best);
}