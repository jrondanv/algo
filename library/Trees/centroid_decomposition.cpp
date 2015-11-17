int nn;
void dfs1(int u,int p)
{
    sub[u]=1;
    nn++;
    for(auto it=g[u].begin();it!=g[u].end();it++)
        if(*it!=p)
        {
            dfs1(*it,u);
            sub[u]+=sub[*it];
        }
}

int dfs2(int u,int p)
{
    for(auto it=g[u].begin();it!=g[u].end();it++)
        if(*it!=p && sub[*it]>nn/2)
            return dfs2(*it,u);
    return u;
}
void dfs4(int u, int p, vector<int> v, int d) {
    mergev(v, all[u]);
    smallest[u][d] = v;
    for (int k : g[u]) if (k != p) {
        dfs4(k, u, v, d);
    }
}
void decompose(int root,int p, int d)
{
    nn=0;
    dfs1(root,root);
    int centroid = dfs2(root,root);
    if(p==-1)p=centroid;
    par[centroid]=p;
    dt[centroid]=d;
    dfs4(centroid,centroid, vector<int>(), d);
    for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
    {
        g[*it].erase(centroid);
        decompose(*it,centroid,d+1);
    }
    g[centroid].clear();
}

void query(int u, int v, int k)
{
    int x = u, y = v;
    while(x != y)
    {
        if (dt[x] < dt[y]) y = par[y];
        else x = par[x];
    }
    vector<int> ans;
    mergev(ans, smallest[u][dt[x]]);
    mergev(ans, smallest[v][dt[x]]);
    int count = min(k, (int)ans.size());
    printf("%d ", count);
    for (int i = 0; i < count; i++) printf("%d ", ans[i]+1);
    printf("\n");
}
