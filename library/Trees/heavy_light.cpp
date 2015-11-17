struct heavy{
    int v;
    vector<int> b; 
    heavy(){} 
    heavy( int a ){
        v=a;
        b.clear();
        b.push_back(0);   
    }

    void add( int pos, int k ){
        while( pos<b.size() ){
            b[pos]+=k;
            pos+=pos&-pos;   
        }
    }
    int sum( int pos ){
        int ret=0;
        while( pos>0 ){
            ret+=b[pos];
            pos-=pos&-pos;
        }
        return ret;   
    }
};

int n, m;
int st[MAXN], pai[MAXN], size[MAXN];
vector<int> l[MAXN];
heavy d[MAXN];
int d_cnt, h[MAXN], pos[MAXN];

int calc_size( int x ){
    size[x]=0;
    for( int i=0 ; i<l[x].size() ; i++ ){
        size[x]+=1+calc_size(l[x][i]);
    }
    return size[x];
}

void inicia(int);

void continua( int x, int cnt, int p ){
    //printf("continua %d %d %d\n",x,cnt,p);
    h[x]=cnt;
    pos[x]=p;
    d[cnt].b.push_back(0);
    for( int i=0 ; i<l[x].size() ; i++ ){
        if( 2*(size[l[x][i]]+1) > size[x] ){
            continua(l[x][i],cnt,p+1);   
        }
        else{
            inicia(l[x][i]);
        }
    }
}

void inicia( int x ){
    //printf("inicia %d\n",x);
    d[++d_cnt] = heavy(x);
    continua(x,d_cnt,1);
}

void add( int x, int k ){
    st[x]-=k;
    d[h[x]].add(pos[x],k);
}

int sum( int x ){
    int ret=0;
    while( x!=0 ){
        ret+=d[h[x]].sum(pos[x]);
        x=pai[d[h[x]].v];   
    }
    return ret;
}
