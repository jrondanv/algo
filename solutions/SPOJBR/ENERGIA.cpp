#include <stdio.h>
#include <vector>
#define MAX_ALUNOS 1000

using namespace std;

int main()
{
  int e, l;
  int teste = 1;
  while (scanf("%d %d", &e, &l) && e) {
      int network[e+1];
      vector<int> networks[e+1];
      
      for (int i = 0; i < e+1; i++) {
          network[i] = i;
          networks[i].push_back(i);
      }

      for (int i = 0; i < l; i++) {
          int f, t;
          scanf("%d %d", &f, &t);

          if (network[f] == network[t]) continue;
          if (networks[network[f]].size() == e) continue;

          if (networks[network[t]].size() > networks[network[f]].size()) {
              int temp = t;
              t = f;
              f = temp;
          }

          vector<int>::iterator end = networks[network[t]].end();

          for (vector<int>::iterator j = networks[network[t]].begin(); j < end; j++) {
                  network[*j] = network[f];
                  networks[network[f]].push_back(*j);
          }



      }

      printf("Teste %d\n", teste++);
      if (networks[network[1]].size() == e) printf("normal");
      else printf("falha");
      printf("\n\n");


    }
  return 0;
}
