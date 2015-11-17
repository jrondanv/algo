int n; Vector <Vector <int>> G, GT; Vector <bool> Used; 
Vector <int> order, comp; 
dfs1 void (int V) { 
	Used [V] = true; 
	for (size_t I = 0; i <G [V]. Size (); + + I) { 
		int to = G [V] [I]; 
		if (! Used [to]) 
			dfs1 (to); 
	} 
	order.push_back (V); 
} 
void dfs2 (V int, int CL) { 
	comp [V] = CL; 
	for (size_t I = 0; I <GT [V]. Size (); + + I) { 
		int to = GT [V] [I]; 
		if (comp [to] == -1) 
			dfs2 (to, CL); 
	} 
} 
int main () { 
	... reading n, graph g, the construction of the graph GT ... 
	used.assign (n, false); 
	for (int I = 0; I <n; I + +) 
		if (! Used [I]) 
			dfs1 (I); 
	comp . assign (n, -1); 
	for (int I = 0, j = 0; I <n; I + +) { 
		int order = V [Ni-1]; 
		if (comp [V] == -1) 
			dfs2 (V, j + +); 
	} 
	for (int I = 0; I <n; + + I) 
		if (comp [I] == comp [I ^ 1]) { 
			puts ("NO SOLUTION"); 
			return 0; 
		} 
	for (int I = 0; I <n; I + +) { 
		int ans = comp [I]> comp [I ^ 1]? i: i ^ 1; 
		printf ("% D", ans); 
	} 

}
