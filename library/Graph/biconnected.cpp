/* Componentes Biconectadas e pontes
 * Entrada:
 * - G: Lista de adjacencia do grafo nao-direcionado
 * - g: grau dos vertices
 * - N: Quantidade de vértices
 * Saída:
 * A gosto do freguês.
 * Obs: vértices de 0 a N-1
 * Componentes biconexas não têm pontes, mas podem
 * ter pontos de articulação!
 */

int vis[NMAX];
void reset(){
    for (int i=0; i<N_vertices; i++)
        vis[i] = 0;
}
int biponte(int v, int pai){
    if(vis[v]) return vis[v];
    int R = vis[v] = intime++;
    for(int i=0; i<g[v]; i++){
        if(G[v][i] == pai)
            continue;
        int r = biponte(G[v][i], v);
        if(r < R){
            // v está na mesma componente biconexa de G[v][i]
            // union_set(v, G[v][i]);
            R = r;
        }
    }
    if(R >= vis[v] && pai != -1)
        printf("ponte -> (%d, %d)\n", v+1, pai+1);
        // Se o grafo permitir multiplas arestas, verificar
        // se a aresta (v+1, pai+1) ocorre mais de uma vez.
    return R;
}

void biconexo(){
    intime = 1;
    for (int i=0; i<N; i++)
        biponte(i, -1);
}
