#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int N, M;

int depscnt[300];

int dpofcnt[300];
int dpof[300][100];
string narr[300];

priority_queue< int, std::vector<int>, std::greater<int> > no_deps;

map<string,int> m;
int nomes;

int numb[300];
string out[300][10];

int get_ind(string& nome) {
    if (m.find(nome) != m.end()) return m[nome];
    else {
        narr[nomes]=nome;
        return (m[nome] = nomes++);
    }
}

int main() {
    while (scanf("%d %d", &N, &M) && N) {
        memset(depscnt,0,sizeof(depscnt));
        memset(dpofcnt,0,sizeof(dpofcnt));
        
        m.clear();
        string nome;
        nomes = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> nome;
            int avan = get_ind(nome);
            
            int K;
            scanf("%d", &K);
            depscnt[avan]=K;
            for (int k = 0; k < K; k++) {
                cin >> nome;
                int dep = get_ind(nome);
                
                dpof[dep][dpofcnt[dep]++]=avan;
            }
        }
        
        for (int i = 0; i < nomes; i++) {
            if (!depscnt[i]) 
                no_deps.push(i);
        }
        
        int sem = 0;
        while (!no_deps.empty()) {
            int i;
            for (i = 0; i < M && !no_deps.empty(); i++) {
                int disc = no_deps.top();
                no_deps.pop();
                
                out[sem][i] = narr[disc];
            }
            
            for (int p = 0; p < i; p++) {
                int disc = m[out[sem][p]];
                for (int j = 0; j < dpofcnt[disc]; j++) {
                    int ot = dpof[disc][j];
                    depscnt[ot]--;
                    if (!depscnt[ot]) no_deps.push(ot);
                }
            }
            numb[sem]=i;
            sem++;
        }
        
        printf("Formatura em %d semestres\n", sem);
        for (int i = 0; i < sem; i++) {
            printf("Semestre %d :", i+1);
        
            sort(out[i], out[i]+numb[i]);
            for (int j = 0; j < numb[i]; j++) {
                cout << " " << out[i][j];
            }
            cout << endl;
        }
    }
}
