#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

char emote[2000];

struct node {
    node* prox[26];
};

node arr[200010];
int beg;
int end;

int cnt[26];
int final[26];

node* my_malloc() {
    memset(arr[beg].prox, 0, sizeof(arr[beg].prox));
    
    return &arr[beg++];
}

void my_free() {
    beg = 0;
}

void adiciona(char* emote, node* tree) {
    int len = strlen(emote);
    
    for (int i = 0; i < len; i++) {
        if (tree->prox[emote[i]-'a'] == NULL) {
            tree->prox[emote[i]-'a'] = my_malloc();
        }
        
        tree = tree->prox[emote[i]-'a'];
    }
}

void adiciona_reverse(char* emote, node* tree) {
    int len = strlen(emote);
    
    final[emote[len-1]-'a']=1;
    
    for (int i = len-1; i >= 0; i--) {
        if (tree->prox[emote[i]-'a'] == NULL) {
            tree->prox[emote[i]-'a'] = my_malloc();
            cnt[emote[i]-'a']++;
        }
        
        tree = tree->prox[emote[i]-'a'];
    }
}

node* tree_port;
node* tree_esp;
int total;

ull traverse(node* tree) {
    ull curr = total;
    ull tot = 0;
    
    for (int i = 0; i < 26; i++) {
        if (tree->prox[i] != NULL) { 
            curr -= cnt[i];
            if (final[i]) curr++;
            
            tot += traverse(tree->prox[i]);
        }
    }

    return (tree == tree_port) ? tot : tot+curr;
}



int main()
{
    int P, E;
    while (scanf("%d %d", &P, &E) && E) {
        tree_port = my_malloc();
        tree_esp = my_malloc();
        
        for (int i = 0; i < P; i++) {
            scanf("%s", emote);
            adiciona(emote, tree_port);
        }
        
        memset(cnt,0,sizeof(cnt));
        memset(final,0,sizeof(final));
        for (int i = 0; i < E; i++) {
            scanf("%s", emote);
            adiciona_reverse(emote, tree_esp);
        }
        
        total = 0;
        for (int i = 0; i < 26; i++) total += cnt[i];
        
        printf("%llu\n", traverse(tree_port));
        my_free();
    }
}
        



    
    
