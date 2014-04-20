#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;

const int tmax = (int)1e3 + 100;

#define pb push_back
#define mp make_pair

struct pt{
    int x,y;
    pt( int a = 0, int b = 0 ) : x(a), y(b){
    }
    pt operator-(pt q){ 
        return pt(x - q.x, y - q.y); 
    }
    int operator%(pt q){ 
        return x * q.y - y * q.x;
    }
};

pt c_hull[tmax];
int dp[tmax][tmax];
int top;

void add( int x, int y){
    pt p(x,y);
    while( top >= 2 && (p - c_hull[top-1])%(p - c_hull[top-2]) <= 0 ) top--;
    c_hull[top++] = p; 
}

int get_val( int idx, int x_val ){
    return c_hull[idx].x - c_hull[idx].y*x_val;
}

int main()
{
    int N,lim;
    scanf("%d %d", &N, &lim);
    vector < pair < int, int > > save;
    for( int i = 0; i < N; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        save.pb(mp(a,b));
    }
    sort(save.begin(), save.end());
    int iter;
    top = iter = 0;
    for( int i = 1; i <= N; i++){
        dp[i][1] = save[i-1].second*i;
        add(dp[i][1],i);    
    }
    for( int L = 2; L <= lim; L++){
        iter = 0;
        for( int i = L; i <= N; i++){
            int Ci = save[i-1].second;
            int v_now = get_val(iter, Ci);
            while(  iter+1 < top && c_hull[iter+1].y < i && get_val(iter+1,Ci) < v_now )
                v_now = get_val(++iter,Ci);            
            dp[i][L] = v_now + Ci*i;
        }
        top = 0;
        for( int i = L; i <= N; i++)
            add(dp[i][L],i);        
    }
    printf("%d\n", dp[N][lim]);
    return 0;
}