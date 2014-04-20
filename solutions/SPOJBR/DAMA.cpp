#include <stdio.h>
#include <vector>
#define MAX_ALUNOS 1000

using namespace std;

int main()
{
  int x1, y1, x2, y2;
  int teste = 1;
  while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && x1) {
      if (x1 == x2 && y1 == y2) {
          printf("0\n");
          continue;
      }
      
      if (x1 == x2 || y1 == y2) {
          printf("1\n");
          continue;
      }

      if (x1-x2 == y1-y2 || x2-x1 == y1-y2) {
          printf("1\n");
          continue;
      }
      
      printf("2\n");

    }
  return 0;
}
