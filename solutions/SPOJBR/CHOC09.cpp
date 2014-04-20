#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

int n, m;

int ganha[1000010]; // numero de movimentos que podem ser feitos pra ganhar em n
                    // se 0, definitivamente perde, se 2, def ganha
                    // se 1, depende se ele esta proibido ou nao.

int mov[1000010]; // qual o movimento pra ganhar em n

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        if (ganha[i] == 0) {
            for (int j = 1; j <= m && i+j <= n; j++) {
                ganha[i+j]++;
                mov[i+j] = j;
            }
        }

        else if (ganha[i] == 1 && i + mov[i] <= n) {
            ganha[i+mov[i]]++;
            mov[i+mov[i]] = mov[i];
        }
    }

    printf("%s\n", ganha[n] ? "Paula" : "Carlos");
    return 0;
}
