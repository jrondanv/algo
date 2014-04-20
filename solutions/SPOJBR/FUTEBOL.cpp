#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

int T,G;

struct times {
    string nome;
    string upper;
    int jogos;
    int ganhou;
    int pts;
    int gols;
    int saldo;

    bool operator< (times ot) const {
        if (pts>ot.pts) return true;
        else if (pts==ot.pts && saldo>ot.saldo) return true; 
        else if (pts==ot.pts && saldo==ot.saldo && gols>ot.gols) return true;
        else if (pts==ot.pts && saldo==ot.saldo && gols==ot.gols) return upper<ot.upper;
        return false;
    }
    
    bool operator== (times ot) const {
        return (pts==ot.pts && saldo==ot.saldo && gols==ot.gols);
    }
};

void atualiza(times& t, int sc, int ot_sc) {
    t.jogos++;
    
    if (sc > ot_sc) t.pts += 3;
    else if (sc == ot_sc) t.pts++;
    
    t.gols+=sc;
    t.saldo+=sc-ot_sc;
}

times t[100];
map<string, int> m;

int hack(int c) {
    return toupper(c);
}

int main(){
    bool first = false;
	while (scanf("%d %d", &T, &G) > 0 && T) {
        if (!first) printf("\n");
        else first = true;
        
        m.clear();
        for (int i = 0; i < T; i++) {
            cin >> t[i].nome;
            t[i].upper.resize(t[i].nome.size());
            transform(t[i].nome.begin(), t[i].nome.end(), t[i].upper.begin(), hack);
            t[i].jogos=t[i].pts=t[i].ganhou=t[i].saldo=t[i].gols=0;
            m[t[i].nome]=i;
        }
        
        for (int i = 0; i < G; i++) {
            string t1, t2;
            int s1, s2;
            char tr;
            cin >> t1 >> s1 >> tr >> s2 >> t2;
            
            int pt = m[t1], st = m[t2];
            
            atualiza(t[pt],s1,s2);
            atualiza(t[st],s2,s1);
        }
        
        sort(t,t+T);
        
        for (int i = 0; i < T; i++) {
            if (i==0 || !(t[i-1] == t[i])) printf("%2d.", i+1);
            else printf("   ");
            
            cout << setw(16) << t[i].nome;
            printf("%4d %4d %4d %4d %4d", t[i].pts, t[i].jogos, t[i].gols, t[i].gols-t[i].saldo, t[i].saldo);
            
            if (t[i].jogos == 0) printf("    N/A");
            else printf("%7.2lf", t[i].pts*100 / ((double)t[i].jogos*3));
            printf("\n");
        }
    }
	return 0;
}



