#include <stdio.h>
#include <string.h>

int num[20];

char data[3] = {'-', '0', '+'};

void print(int val, int neg) {
    if (neg) val = -val;
    printf("%c", data[val+1]);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            printf("0\n");
            continue;
        }
        memset(num,0,sizeof(num));
        
        int neg = n < 0;
        if (neg) n = -n;
        
        int i = 0;
        while (n) {
            num[i] = n % 3;
            n /= 3;
            
            i++;
        }
        
        int lim = i;
        for (i = 0; i < lim; i++) {
            num[i+1] += num[i]/3;
            num[i] = num[i]%3;
            
            if (num[i] == 2) {
                num[i] = -1;
                num[i+1] += 1;
            } 
        }
        
        if (num[lim] != 0) print(num[lim],neg);
        for (int i = lim-1; i >= 0; i--) {
            print(num[i],neg);
        }
        printf("\n");
    }

    return 0;
}
