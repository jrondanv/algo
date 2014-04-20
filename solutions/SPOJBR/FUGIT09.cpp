#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

int n, m;
char dir;
 int d;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    long long lim = ((long long) m) * m;

    long long x = 0, y = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &dir, &d);
        switch (dir) {
            case 'N': y += d; break;
            case 'S': y -= d; break;
            case 'L': x += d; break;
            case 'O': x -= d; break;
        }

        if (x*x+y*y > lim) {
            printf("1\n");
            return 0;
        }
    }

    printf("0\n");
}
