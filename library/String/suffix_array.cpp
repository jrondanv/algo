// Entrada: text[]: string, N: tamanho da string
// Saída: sa[], lcp[]
// O(n log² n)

char text[MAX]; long long key[MAX]; int N, sa[MAX], rank[MAX], *lcp=(int*)key;
struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };

void build() {
    for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
    sort(sa, sa+N, Cmp());
    for (int K = 1; ; K *= 2) {
        for (int i = 0; i < N; i++)
            rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
        if (K >= N) break;

        for (int i = 0; i < N; i++)
            key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
        sort(sa, sa+N, Cmp());
    }

    for (int i = 0, k = 0; i < N; i++) {
        if (k > 0) k--;
        if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
        int j = sa[rank[i]+1];
        while (text[i+k] == text[j+k]) k++;
        lcp[rank[i]] = k;
    }
}

