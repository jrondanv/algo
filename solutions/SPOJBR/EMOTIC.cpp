#include <stdio.h>
#include <string.h>

char linha[100];
char emote[20];

struct node {
    node* prox[130];
    bool end;
};

node arr[1000];
int beg;
int end;

node* my_malloc() {
    memset(arr[beg].prox, 0, sizeof(arr[beg].prox));
    arr[beg].end = false;
    
    return &arr[beg++];
}

void my_free() {
    beg = 0;
}

void adiciona(char* emote, node* tree) {
    int len = strlen(emote);
    
    for (int i = 0; i < len; i++) {
        if (tree->prox[emote[i]] == NULL) {
            tree->prox[emote[i]] = my_malloc();
        }
        
        tree = tree->prox[emote[i]];
    }
    
    tree->end = true;
}

int verifica (char* str, int i, node* tree) {
    for (; str[i] != '\0'; i++) {
        //printf("%d\n", i);
        if (tree->prox[str[i]] == NULL) return -1;
        else if (tree->prox[str[i]]->end) return i;
        
        tree = tree->prox[str[i]];
    } 
    
    return -1;
}

int main()
{
    int E, L;
    while (scanf("%d %d", &E, &L) && E) {
        node* tree = my_malloc();
        
        for (int i = 0; i < E; i++) {
            scanf("%s", emote);
            adiciona(emote, tree);
        }
        
        int cnt = 0;
        while (getchar() != '\n');
        for (int i = 0; i < L; i++) {
            gets(linha);
            
            int len = strlen(linha);
            int fim = len;
            
            for(int j = 0; j < len; j++) {
                if (j > fim) {
                    cnt++;
                    fim = len;
                }
                
                int k = verifica(linha, j, tree);
                if (k == -1) continue;
                else if (k < fim) fim = k;
            }
            
            if (fim != len) cnt++;
        }
        
        printf("%d\n", cnt);
        my_free();
    }
    
    
}

