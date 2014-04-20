#include <stdio.h>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <set>

using namespace std;

struct edge {
    int cost;
    int dest_ling;
};

vector<edge> adj[4100][26];
map<string, int> lingua;
char linha[400];
char *pal1, *pal2, *pal3;

int L;

#define INF 1000000000

int dist[4100][26];
int seen[4100];
char let[4100];

int best1[4100];
int best2[4100];

struct compara {
    bool operator() (int lang1, int lang2) {
        if (dist[lang1][best1[lang1]] != dist[lang2][best1[lang2]]) {
            return dist[lang1][best1[lang1]] < dist[lang2][best1[lang2]];
        }

        return lang1 < lang2;
    }
};

set<int, compara> heap;
int n;

void update_lang(int lang, int let, int new_cost) {
    if (new_cost >= dist[lang][let]) return;

    if (let == best1[lang]) {
        heap.erase(lang);
        dist[lang][let]=new_cost;
        heap.insert(lang);
    }

    else if (best1[lang] == -1 || new_cost < dist[lang][best1[lang]]) {
        heap.erase(lang);

        dist[lang][let] = new_cost;
        best2[lang] = best1[lang];
        best1[lang] = let;

        heap.insert(lang);
    }

    else if (new_cost < dist[lang][best2[lang]]) {
        dist[lang][let] = new_cost;
        best2[lang] = let;
    }
}

int get_lang(char* str) {
    if (lingua.find(str) == lingua.end()) lingua[str] = L++;
    return lingua[str];
}

int main() {
    while (scanf("%d", &n) && n) {
        gets(linha);
        lingua.clear();
        for (int i = 0; i <= 2*n+10; i++) {
            for (int j = 0; j < 26; j++) adj[i][j].clear();
        }

        heap.clear();
        L = 0;

        memset(seen,0,sizeof(seen));
        memset(best1,-1,sizeof(best1));
        memset(best2,-1,sizeof(best2));

        gets(linha);
        int off;
        for (off = 0; linha[off] != ' '; off++);
        linha[off]='\0';
            
        int orig = get_lang(linha);
        int targ = get_lang(linha+off+1);

        for (int i = 0; i < n; i++) {
            gets(linha);
            pal1 = linha;
            
            for (off = 0; linha[off] != ' '; off++);
            pal2 = linha+off+1;
            linha[off]='\0';
            for (; linha[off] != ' '; off++);
            linha[off]='\0';
            pal3 = linha+off+1;

            int ling1 = get_lang(pal1);
            int ling2 = get_lang(pal2);

            edge e = {strlen(pal3), ling2};
            adj[ling1][pal3[0]-'a'].push_back(e);

            e.dest_ling = ling1;
            adj[ling2][pal3[0]-'a'].push_back(e);
        }

        int found = INF;

        if (orig == targ) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < adj[orig][i].size(); j++) {
                    found = min(found, adj[orig][i][j].cost);
                }
            }
        }

        else {

        for (int i = 1; i < L; i++) {
            for (int j = 0; j < 26; j++) {
                dist[i][j] = INF;
            }
        }

        dist[orig][0] = 0;
        dist[orig][1] = 0;
        best1[orig] = 0;
        best2[orig] = 1;
        heap.insert(0);

        while (!heap.empty()) {
            int curr = *heap.begin();
            heap.erase(heap.begin());
            
            int currlet = best1[curr];

            best1[curr] = best2[curr];
            best2[curr] = -1;

            seen[curr]++;

            if (seen[curr] == 1 && best1[curr] != -1) heap.insert(curr);

            if (curr == targ) {
                found = dist[curr][currlet];
                break;
            }

            if (seen[curr] == 1) {
                let[curr] = currlet;
                for (int i = 0; i < 26; i++) {
                    if (i == currlet) continue;

                    for (int j = 0; j < adj[curr][i].size(); j++) {
                        edge e = adj[curr][i][j];
                        if (seen[e.dest_ling] < 2) update_lang(e.dest_ling, i, e.cost + dist[curr][currlet]);
                    }
                }
            }

            else {
                int i = let[curr];
                for (int j = 0; j < adj[curr][i].size(); j++) {
                    edge e = adj[curr][i][j];
                    if (seen[e.dest_ling] < 2) update_lang(e.dest_ling, i, e.cost + dist[curr][currlet]);
                }
            }
        }

        }

        if (found == INF) printf("impossivel\n");
        else printf("%d\n", found);
    }
}
