#include <stdio.h>
#include <string.h>

#define MAXN 3000

int adj[MAXN][MAXN];
int cadj[MAXN][MAXN];
int cnt[MAXN];
int ccnt[MAXN];
int marc[MAXN];

int bfs() {
    int fila[MAXN];
    int fim = 1;
    int inic = 0;

    fila[0] = 0;
    marc[0] = 1;

    while (inic != fim) {
        int curr = fila[inic];

        for (int i = 0; i < cnt[curr]; i++) {
            int v = adj[curr][i];
            if (!marc[v]) {
                marc[v] = 1;
                fila[fim++] = v;
            }
        }

        inic++;
    }
}

int bfsTransp() {
    int fila[MAXN];
    int fim = 1;
    int inic = 0;

    fila[0] = 0;
    marc[0] = 1;

    while (inic != fim) {
        int curr = fila[inic];

        for (int i = 0; i < ccnt[curr]; i++) {
            int v = cadj[curr][i];
            if (!marc[v]) {
                marc[v] = 1;
                fila[fim++] = v;
            }
        }

        inic++;
    }
}

int main()
{
  int n,e;
  int teste = 1;

  while (scanf("%d %d", &n, &e) && n) {
      printf("Teste %d\n", teste++);
      
      memset(marc,0,sizeof(marc));
      memset(cnt,0,sizeof(cnt));
      memset(ccnt,0,sizeof(ccnt));

      for (int i = 0; i < e; i++) {
          int from, to;
          scanf("%d %d", &from, &to);
          adj[from-1][cnt[from-1]++] = to-1;
          cadj[to-1][ccnt[to-1]++] = from-1;
      }

      bfs();

      int is_conn = 1;
      for (int i = 0; i < n; i++) {
          if (!marc[i]) {
              is_conn = 0;
              printf("N\n\n", i);
              break;
          }
      }
      if (!is_conn) continue;

      memset(marc,0,sizeof(marc));
      bfsTransp();

      for (int i = 0; i < n; i++) {
          if (!marc[i]) {
              is_conn = 0;
              printf("N\n\n", i);
              break;
          }
      }

      if (is_conn) printf("S\n\n");
  }
  return 0;
}
    
