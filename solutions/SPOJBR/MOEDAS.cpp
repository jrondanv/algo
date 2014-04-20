#include <stdio.h>
#include <queue>

using namespace std;

int quantmoeda[50001];
int moeda[100];
int calc;

#ifdef FFAO
#define getchar_unlocked getchar
#endif

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}


int seen[50000];

int main() {
    int m;

    while (m=read_int()) {
        calc++;
        
        int n;
        n=read_int();

        for (int i = 0; i < n; i++) {
            moeda[i]=read_int();
        }

        queue<int> states;
        states.push(0);
        bool found = false;

        while (!states.empty()) {
            int curr = states.front();
            states.pop();

            for (int i = n-1; i >= 0; i--) {
                int th = curr + moeda[i];
                if (th > m) continue;
                if (th == m) {
                    quantmoeda[m] = quantmoeda[curr]+1;
                    found = true;
                    break;
                }
                if (seen[th] != calc) {
                    quantmoeda[th] = quantmoeda[curr]+1;
                    states.push(th);
                    seen[th] = calc;
                }
            }

            if (found) break;
        }

        if (found) printf("%d\n", quantmoeda[m]);
        else printf("Impossivel\n");
    }

    return 0;
}
