#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

#define inf 1000000000

////////////////////////////////////////////////////////////////////////////////
// Suffix Tree
////////////////////////////////////////////////////////////////////////////////
const int maxn = 100100; //10^5
char str[maxn];

struct node
{
    int st, ed;
    map<char,int> pt;
    int link;
};

node vet[2*maxn];
int total;
inline void canonize (int &s, int &k, int p)
{
    if (k<=p)
    {
        int ss=vet[s].pt.find(str[k])->second,
        kk=vet[ss].st, pp=vet[ss].ed;
        while(pp-kk<=p-k)
        {
            k+=pp-kk+1;
            s=ss;
            if (k<=p)
            ss=vet[s].pt.find(str[k])->second,
            kk=vet[ss].st, pp=vet[ss].ed;
        }
    }
}

inline void init(node &x, int st, int ed) {x.st=st; x.ed=ed; x.pt.clear();}
void make_tree()
{
    int s=0, oldr, rr, r, ss, k=0, kk;
    map<char,int>::iterator mi;
    for(int i=0; (!i)||str[i-1]; ++i)
    {
        oldr=0;
        while(1)
        {
            if (k<i)
            {
                ss=(mi=vet[s].pt.find(str[k]))->second;
                kk=vet[ss].st;
                if (str[i]==str[kk+i-k])
                    break;
                else
                {
                    init(vet[r=total++], kk, kk+i-k-1);
                    vet[r].pt.insert(make_pair(str[kk+i-k],ss));
                    mi->second=r;
                    vet[ss].st+=i-k;
                }
            }
            else if (vet[s].pt.find(str[i])==vet[s].pt.end())
                r=s;
            else
                break;
            init(vet[rr=total++], i,inf);
            vet[r].pt.insert(make_pair(str[i],rr));
            if (oldr)
                vet[oldr].link=r;
            oldr=r;
            if (!s)
                ++k;
            s=vet[s].link;
            canonize(s, k, i-1);
        }
        if (oldr)
            vet[oldr].link=s;
        canonize(s,k,i);
    }
}

int traverse_tree(int k) {
    int resp = 0;
    
    if (k != 0 && vet[k].pt.size() >= 2) {
        int ed = (vet[k].ed==inf) ? total-1 : vet[k].ed;
        resp += ed-vet[k].st+1;
    }
    
    map<char,int>::iterator it;
    for (it = vet[k].pt.begin(); it != vet[k].pt.end(); it++) resp += traverse_tree(it->second);
    
    return resp;
}

int main(void)
{
    while (gets(str) && str[0] != '*') {
        total = strlen(str);
        vet[0].pt.clear(); 
        
        make_tree();
        printf("%d\n", traverse_tree(0));
    }
}
