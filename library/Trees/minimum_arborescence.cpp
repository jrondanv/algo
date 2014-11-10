int V, E;
struct Edge {int a, b, c;} edge[40000];
int d[1000], p[1000], v[1000], n[1000], m[1000];
// 每個點最小入邊的權重，每個點最小入邊的來源，
// 拜訪過，水母環，已收縮。
 
int MST(int r)
{
    memset(m, 0, sizeof(m));
 
    // 目前生成樹的權重，累計收縮水母環而失去的權重。
    int w1 = 0, w2 = 0;
    while (true)    // 一旦形成生成樹就停止。最多執行V-1次。
    {
        /* O(E) graph traversal.
           find minimum in-edge for each vertice.
 
           --->o
        */
        memset(d, 1, sizeof(d));
        memset(p, -1, sizeof(p));
 
        for (int i=0; i<E; ++i)
        {
            int& a = edge[i].a;
            int& b = edge[i].b;
            int& c = edge[i].c;
            if (a != b && b != r && c < d[b])
                d[b] = c, p[b] = a;
        }
 
        /* O(V) jellyfish detection
             ___
            /   \
            \___/
           _/|||\_
            //1\\
        */
        memset(v, -1, sizeof(v));
        memset(n, -1, sizeof(n));
 
        w1 = 0;
        bool jf = false;
        for (int i=0; i<V; ++i)
        {
            if (m[i]) continue;
            if (p[i] == -1 && i != r) return 1e9;
            if (p[i] >= 0) w1 += d[i];
 
            // 找水母環
            int s;
            for (s = i; s != -1 && v[s] == -1; s = p[s])
                v[s] = i;
 
            // 標記水母環上的點，以及將會被收縮掉的點。
            if (s != -1 && v[s] == i)
            {
                jf = true;
                int j = s;
                do
                {
                    n[j] = s; m[j] = 1;
                    w2 += d[j]; j = p[j];
 
                } while (j != s);
                m[s] = 0;
            }
        }
        if (!jf) break;
 
        /* O(E) edge reweighting and cycle contraction
             ___
            /   \ <-
            \___/
        */
        for (int i=0; i<E; ++i)
        {
            int& a = edge[i].a;
            int& b = edge[i].b;
            int& c = edge[i].c;
            if (n[b] >= 0) c -= d[b];
            if (n[a] >= 0) a = n[a];
            if (n[b] >= 0) b = n[b];
            if (a == b) edge[i--] = edge[--E];
        }
    }
    return w1 + w2;
}


// imp2

void backward_traverse (int v, int s, int r, matrix & g,
   vector <int> & no, vector <vector <int>> & comp,
   vector <int> & prev, vector <weight> & mcost,
   vector <int> & mark, weight & cost, bool & found) {
   const int n = g.size ();
   if (mark [v]) {
     vector <int> temp = no;
     found = true;
     do {
       cost + = mcost [v];
       v = prev [v];
       if (v! = s) {
         while (comp [v] .size ()> 0) {
           no [comp [v] .back ()] = s;
           comp [s] .push_back (comp [v] .back ());
           comp [v] .pop_back ();
         }
       }
     } While (! V = s);
     for (int j = 0; j <n; ++ j)
       if (j! = r && no [j] == s)
         for (int i = 0; i <n; ++ i)
           if (no [i]! = s && g [i] [j] <inf)
             g [i] [j] - = mcost [temp [j]];
   }
   mark [v] = true;
   for (int i = 0; i <n; ++ i)
     if (no [i]! = no [v] && prev [no [i]] == v)
       if (! mark [no [i]] || i == s)
         backward_traverse (i, s, r, g,
             no, comp, prev, mcost, mark, cost, found);
 }

 weight minimum_spanning_arborescence (int r, matrix & g) {
   const int n = g.size ();

   vector <int> no (n);
   vector <vector <int>> comp (n);
   for (int i = 0; i <n; ++ i) {
     no [i] = i;
     comp [i] .push_back (i);
   }
   weight cost = 0;
   while (1) {
     vector <int> prev (n, - 1);
     vector <weight> mcost (n, inf);
     for (int i = 0; i <n; ++ i) {
       for (int j = 0; j <n; ++ j) {
         if (j == r) continue;
         if (no [i]! = no [j] && g [i] [j] <inf) {
           if (g [i] [j] <mcost [no [j]]) {
             mcost [no [j]] = g [i] [j];
             prev [no [j]] = no [i];
           }
         }
       }
     }
     bool stop = true;
     vector <int> mark (n);
     for (int i = 0; i <n; ++ i) {
       if (i == r || mark [i] || comp [i] .size () == 0) continue;
       bool found = false;
       backward_traverse (i, i, r, g,
           no, comp, prev, mcost, mark, cost, found);
       if (found) stop = false;
     }
     if (stop) {
       for (int i = 0; i <n; ++ i)
         if (prev [i]> = 0)
           cost + = mcost [i];
       return cost;
     }
   }
 }