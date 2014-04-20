#include <stdio.h>

int g[2000][2000];
int marc[2000];

int bfs(int c) {
    int fila[2000];
    int fim = 1;
    int inic = 0;

    fila[0] = 0;
    marc[0] = 1;

    while (inic != fim) {
        int curr = fila[inic];

        for (int i = 0; i < c; i++) {
            if (!marc[i] && g[curr][i]) {
                marc[i] = 1;
                fila[fim++] = i;
            }
        }

        inic++;
    }
}

int bfsTransp(int c) {
    int fila[2000];
    int fim = 1;
    int inic = 0;

    fila[0] = 0;
    marc[0] = 1;

    while (inic != fim) {
        int curr = fila[inic];

        for (int i = 0; i < c; i++) {
            if (!marc[i] && g[i][curr]) {
                marc[i] = 1;
                fila[fim++] = i;
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

      for (int i = 0; i < n; i++) {
          marc[i] = 0;
          for (int j = 0; j < n; j++) {
              g[i][j] = 0;
          }
      }

      for (int i = 0; i < e; i++) {
          int from, to, dupla;
          scanf("%d %d %d", &from, &to, &dupla);
          g[from-1][to-1] = 1;
          if (dupla == 2) g[to-1][from-1] = 1;
      }

      bfs(n);

      int is_conn = 1;
      for (int i = 0; i < n; i++) {
          if (!marc[i]) {
              is_conn = 0;
              printf("0\n", i);
              break;
          }
      }
      if (!is_conn) continue;

      for (int i = 0; i < n; i++) marc[i] = 0;
      bfsTransp(n);

      for (int i = 0; i < n; i++) {
          if (!marc[i]) {
              is_conn = 0;
              printf("0\n", i);
              break;
          }
      }

      if (is_conn) printf("1\n");
  }
  return 0;
}