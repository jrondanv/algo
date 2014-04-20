#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

class frac {
    public:
        int x, y, num, den;
        
        frac() {}
        frac(int _num, int _den) : num(_num), den(_den) {normalize();}
        
        int normalize() {
            int mdc = gcd(abs(x),abs(y));
            num=x/mdc;
            den=y/mdc;
        }
        
        bool operator==(frac b) const { return (num==b.num)&&(den==b.den);}
        bool operator!=(frac b) const { return !((*this)==b);}
        bool operator< (frac b) const { return (num<b.num) || (num==b.num && den < b.den); }
    
        bool compxy(frac b) const { return abs(b.x) > abs(x) || (abs(b.x) == abs(x) && abs(b.y) > abs(y)); }
};

struct light {
    frac ang;
    int alt;

    bool operator< (light b) const {
        if (ang != b.ang) return ang < b.ang;
        return ang.compxy(b.ang);
    }
};

light luz[100010];

pair<int, int> invisible[100010];
int invcnt;

int N;
int main() {
    int teste = 1;
    while (scanf("%d", &N) && N) {
        invcnt = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &luz[i].ang.x, &luz[i].ang.y);
            luz[i].ang.normalize();
            scanf("%d", &luz[i].alt);
        }
        
        sort(luz,luz+N);
        
        printf("Data set %d:\n", teste++);

        for (int i = 1; i < N; i++) {
            if (luz[i-1].ang == luz[i].ang) {
                if (luz[i-1].alt >= luz[i].alt) {
                    invisible[invcnt].first = luz[i].ang.x;
                    invisible[invcnt++].second = luz[i].ang.y;
                    luz[i].alt = luz[i-1].alt;
                }
            }
        }
        
        sort(invisible,invisible+invcnt);
        if (invcnt == 0) printf("All the lights are visible.\n");
        else {
            printf("Some lights are not visible:\n");
            for (int i = 1; i <= invcnt; i++) {
                printf("x = %d, y = %d", invisible[i-1].first, invisible[i-1].second);
                if (i!=invcnt) printf(";\n");
                else printf(".\n");
            }
        }
    }
}
        
          
