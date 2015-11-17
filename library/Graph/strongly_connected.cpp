/* Determina as CFC em O(V+E)
 * Entrada:
 * - G: Matriz de adjacência do grafo direcionado
 * - n: Quantidade de vértices
 * Saída:
 * A gosto do freguês, modifique a função CFC().
 * Obs: vértices de 0 a n-1
 */

#include <stack>
#include <vector>

using namespace std;

int n;
int G[NMAX][NMAX];
bool foi[NMAX];
stack<int> P;
vector<int> V;

void dfs(int i){
    foi[i] = true;
    for (int j=0;j<n;j++)
        if (G[i][j] && !foi[j])
            dfs(j);
    P.push(i);
}

void dfsT(int i){
    foi[i] = true;
    V.push_back(i);
    for(int j=0;j<n;j++)
        if (G[j][i] && !foi[j]){
            // j está na mesma componente conexa que i
            dfsT(j);
        }
}

void CFC(){
    memset(foi,0,sizeof(foi));
    for(int i=0;i<n;i++)
        if (!foi[i])
            dfs(i);
    memset(foi,0,sizeof(foi));
    while(!P.empty()){
        int u = P.top(); P.pop();
        if (!foi[u]){
            V.clear();
            dfsT(u);
            // V contém os vértices de um CFC
        }
    }
