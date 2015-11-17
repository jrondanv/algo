/*
•	An undirected graph has a closed Euler tour iff it is connected and each vertex has an even degree.
•	An undirected graph has an open Euler tour iff it is connected, and each vertex, except for exactly two vertices, has an even degree. The two vertices of odd degree have to be the endpoints of the tour.
•	A directed graph has a closed Euler tour iff it is strongly connected and the in-degree of each vertex is equal to its out-degree.
•	Similarly, a directed graph has an open Euler tour iff it is strongly connected and for each vertex the difference between its in-degree and out-degree is 0, except for two vertices. In one of them the difference has to be +1 (this will be the beginning of the tour) and in the other one the difference has to be -1 (this will be its end).
*/

// Entrada: mtx[][], matriz de adjacência
//                 n, tamanho do grafo

list<int> euleriantour(int start) //para multigrafos não direcionados.
{
    int v;
    bool viz;
    list<int> res;
    stack<int> dfs;
    dfs.push(start);
    while(!dfs.empty())
    {
        v=dfs.top();
        viz=0;
        for(int i=0; !viz&&i<n; ++i)
        if (mtx[v][i])
        {
            dfs.push(i);
            mtx[v][i]--;
            mtx[i][v]--;
            viz=1;
        }
        if(!viz)
        {
            dfs.pop();
            res.push_front(v);
        }
    }
    return res;
}
