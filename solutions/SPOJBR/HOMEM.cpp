    #include <stdio.h>
    #include <algorithm>
    #define left(node) (node*2+1)
    #define right(node) (node*2+2)
    #define MAXN 100010
     
    using namespace std;
     
    struct seg
    {
        int h,e,r;
    };
     
    seg segtree[MAXN*4];
    int flag[MAXN*4];
    int n;
     
    void make( int node = 0, int ini = 0, int fim = n-1)
    {
        if ( ini == fim )
        {
            flag[node] = 0;
            segtree[node].h = 1;
            segtree[node].e = segtree[node].r = 0;
        }
        else
        {
            flag[node] = 0;
            int meio = (ini+fim)/2;
            make(left(node), ini, meio);
            make(right(node),meio+1,fim);
            segtree[node].h = segtree[left(node)].h + segtree[right(node)].h;
            segtree[node].e = segtree[node].r = 0;
        }
    }
     
    void modify(int node, int amount)
    {
        if (amount%3 == 0)
            return;
        if (amount%3 == 1)
        {
            swap(segtree[node].h,segtree[node].e);
            swap(segtree[node].h,segtree[node].r);
            return;
        }
        swap(segtree[node].h,segtree[node].r);
        swap(segtree[node].h,segtree[node].e);
    }
     
    void lazy(int node, int ini, int fim)
    {
        if ( flag[node] )
        {
            modify(node, flag[node]);
            if ( ini != fim )
            {
                flag[left(node)] += flag[node];
                flag[right(node)] += flag[node];
            }
            flag[node] = 0;
        }
    }
     
     
    void update(int node, int ini, int fim, int i, int j)
    {
        lazy(node,ini,fim);
        if ( ini > fim || j < ini || i > fim )
            return;
        if ( i <= ini && j >= fim )
        {
            flag[node]++;
            lazy(node,ini,fim);
            return;
        }
     
        int meio = (ini+fim)/2;
        update(left(node), ini, meio, i,j);
        update(right(node), meio+1, fim, i,j);
        segtree[node].h = segtree[left(node)].h + segtree[right(node)].h;
        segtree[node].r = segtree[left(node)].r + segtree[right(node)].r;
        segtree[node].e = segtree[left(node)].e + segtree[right(node)].e;
    }
     
    pair < int, pair < int, int > > get(int node, int ini, int fim, int i, int j)
    {
        lazy(node,ini,fim);
        if ( ini > fim || j < ini || i > fim )
            return make_pair(0,make_pair(0,0));
        if ( i <= ini && j >= fim )
        {
            lazy(node,ini,fim);
            return make_pair(segtree[node].h,make_pair(segtree[node].e,segtree[node].r));
        }
        int meio = (ini+fim)/2;
        pair < int, pair < int, int > > K1, K2;
        K1 = get(left(node),ini,meio,i,j);
        K2 = get(right(node), meio+1, fim, i,j);
        return make_pair(K1.first+K2.first,make_pair(K1.second.first+K2.second.first,K1.second.second+K2.second.second));
    }
     
    int main()
    {
        int q;
        while (scanf("%d %d", &n, &q)!= EOF)
        {
            make();
            for (int i = 0; i < q; i++)
            {
                char c;
                int a,b;
                scanf(" %c %d %d", &c, &a, &b);
                a--,b--;
                if ( c == 'C')
                {
                    pair < int, pair < int, int > > Resp;
                    Resp = get(0,0,n-1,a,b);
                    printf("%d %d %d\n", Resp.first, Resp.second.first, Resp.second.second);
                }
                else
                    update(0,0,n-1,a,b);
            }
            printf("\n");
        }
        return 0;
    }

