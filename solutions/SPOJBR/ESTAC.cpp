#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
  
int c, t;
int esta[1000];
 
int op,id,tam;
 
int main() {
    while (scanf("%d %d", &c, &t) > 0) {
        int cnt = 0;
        memset(esta,0,sizeof(esta));
 
        for (; t; t--) {
            scanf(" %c %d", &op, &id);
            if (op == 'C') {
                scanf("%d", &tam);
 
                bool found = false;
                for (int i = 0; i < c && !found; i++) {
                    if (!esta[i]) {
                        found = true;
 
                        for (int j = i; j < i+tam && found; j++) {
                            if (j >= c || esta[j]) {
                                i = j; 
                                found = false;
                            }
                        }
 
                        if (found) {
                            cnt++;
                            for (int j = i; j < i+tam; j++) esta[j] = id;
                        }
                    }
                }
            }
 
            else if (op == 'S') {
                for (int i = 0; i < c; i++) if (esta[i] == id) esta[i] = 0;
            }
        }
 
        printf("%d\n", cnt*10);
    }
}