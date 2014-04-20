#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define pop(x) __builtin_popcount(x)
#define ind(x) __builtin_ctz(x)
#ifndef ONLINE_JUDGE
#define getchar_unlocked() getchar()
#endif

typedef unsigned long long ull;
ull B = 3409;

char p[10201], *b;
//char p[101];
//char b[10001];

int main(){
    int t;
    for (scanf("%d", &t), gets(p); t; t--) {
        gets(p);
        //scanf("%s %s", p, b);
        
        int lp = 0;
        ull search = 0;
        for (; p[lp]!=' '; lp++) {
            search = search*B + p[lp]-'a';
        }
        
        b=p+lp;
        while (*b == ' ') b++;
        
        //printf("search = %lld\n",search);
        
        int lb = 0;
        for (; b[lb] != '\0'; lb++) {
            b[lb]-='a';
        }
        
        ull cur = 0;
        int prev = 0, next = lp%lb;
        int ind = 0;
        for (int i = 0; i < lp; i++) {
            cur = cur*B + b[ind];
            ind++;
            if (ind == lb) ind=0;
        } 
        
        ull pot = 1;
        for (int i = 0; i < lp-1; i++) pot *= B; //ull pot = B**lp;
        
        bool found = false;
        for (int i = 0; i < lb && !found; i++) {
            //printf("cur = %lld\n",cur);
            if (cur == search) found = true;
            else {
                //printf("%c %c\n",b[prev],b[next]);
                cur -= pot*(b[prev]);
                cur = (cur * B) + b[next];
                prev++; 
                next++;
                if (prev == lb) prev = 0;
                if (next == lb) next = 0;
            }
        }
        
        //printf("back:\n");
        if (!found) {
            cur = 0;
            prev = 0; next = lp%lb;
            ind = lb-1;
            for (int i = 0; i < lp; i++) {
                cur = cur*B + b[ind];
                if (ind == 0) ind = lb-1;
                else ind--;
            } 
            
            for (int i = 0; i < lb && !found; i++) {
                if (cur == search) found = true;
                else {
                    cur -= pot*(b[lb-1-prev]);
                    cur = (cur * B) + b[lb-1-next];
                    prev++; 
                    next++;
                    if (prev == lb) prev = 0;
                    if (next == lb) next = 0;
                }
                //printf("cur = %lld\n",cur);
            }
        }
        
        if (found) printf("S\n");
        else printf("N\n");
    }
}

