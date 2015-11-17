void dfsInit(int v, int p) {
  for (int l = 1; l <= logn; l++) {
    parent[v][l] = parent[parent[v][l-1]][l-1];
  }

  for (int i = 0; i < (int)G[v].size(); i++) {
    int v2 = G[v][i];
    if (v2 == p) continue;
    height[v2] = height[v] + 1;
    parent[v2][0] = v;
    dfsInit(v2, v);
  }
}

int goup(int a, int dist) {
  for (int l = 0; dist; l++)
    if (dist & (1<<l)) {
      a = parent[a][l];
      dist -= (1<<l);
    }
  return a;
}

int lca(int a, int b) {
  if (height[a] < height[b]) swap(a, b);
  a = goup(a, height[a] - height[b]);
  if (a == b) return a;
  for (int l = logn; l >= 0; l--) {
    if (parent[a][l] != parent[b][l])
      a = parent[a][l], b = parent[b][l];
  }
  return parent[a][0];
}

void initLCA(int root) {
  while ((1 << (logn+1)) <= n) logn++;
  height[root] = 0;
  parent[root][0] = root;
  dfsInit(root, -1);
}