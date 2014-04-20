#include <stdio.h>
#include <vector>
#define MAX_ALUNOS 1000

using namespace std;

int main()
{
  int i, indice_melhor, n;
  int turma=1;
  struct
  {
    int codigo, media;
  } alunos[MAX_ALUNOS];
  /* le numero de alunos da primeira turma */
  scanf("%d", &n);
  vector<int> melhores;
  while (n > 0)
    {
      melhores.clear();
      /* le dados dos alunos */
      for (i = 0; i < n; i++)
         scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
      /* procura alunos de maior media */
      indice_melhor = 0;
      for (i = 0; i < n; i++) {
         if (alunos[i].media > alunos[indice_melhor].media) {
             indice_melhor = i;
             melhores.clear();
         }
         else if (!(alunos[i].media == alunos[indice_melhor].media)) continue;

         melhores.push_back(i);
    }

      /* escreve resposta */
      printf("Turma %d\n", turma++);

      vector<int>::iterator p;
      for (p = melhores.begin(); p < melhores.end(); p++) {
          printf("%d ", alunos[*p].codigo);
      }
      printf("\n\n");
      /* le numero de alunos da proxima turma */
      scanf("%d", &n);
    }
  return 0;
}
