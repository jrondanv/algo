#include <stdio.h>
#include <string.h>

char seq1[2000010];
char seq2[2000010];

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int n;
        scanf(" %s %d", seq1, &n);
        
        char* curseq = seq1;
        char* res_seq = seq2;
        
        printf("%s\n", seq1);
        
        for (int i = 0; i < n; i++) {
            int len = strlen(curseq);
            char cur_char = '0';
            
            int cnt = 0;
            int k = 0;
            
            for (int j = 0; j < len; j++) {
                if (curseq[j] == cur_char) cnt++;
                else {
                    if (cnt > 0) {
                        k += sprintf(res_seq+k, "%d", cnt);
                        res_seq[k++] = cur_char;
                    } 
                    cur_char = curseq[j];
                    cnt = 1;
                }
            }
            
            k += sprintf(res_seq+k, "%d", cnt);
            res_seq[k++] = cur_char;
            res_seq[k] = '\0';
            
            printf("%s\n", res_seq);
            
            char* temp = curseq;
            curseq = res_seq;
            res_seq = temp;
        }
        
        printf("\n");
    }
    
    return 0;
}
        
