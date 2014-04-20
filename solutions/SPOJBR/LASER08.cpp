#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 110000

#define getchar_unlocked getchar

int comeco[MAXN];
int fim[MAXN];
int pos;

#define BUFSIZE 1024*1024
char ans[BUFSIZE+1];

void print_num(int n) {
    if (n != 0) {
        int dig[10];
        int i = 0;
        while (n) {
            dig[i++] = n%10;
            n /= 10;
        }

        for (i--; i >= 0; i--) {
            ans[pos++] = dig[i]+'0';
        }
    }
    else {
        ans[pos++]='0';
    }
    
    ans[pos++]='\n';
}

int n,c;

inline int read_int() {
    char c;
    while (((c=getchar_unlocked()) < 48 || c > 57) && c !='-');
    int p = 0, sign = 1;
    if (c == '-') sign = -1;
    else p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p*sign;
}

int main() {
    n = read_int();
    c = read_int();

    for (int i = 0; i < n; i++) {
        comeco[i] = read_int();
        read_int();
        fim[i] = read_int();
        read_int();

        if (fim[i] < comeco[i]) swap(comeco[i], fim[i]);
    }

    sort(comeco, comeco+n);
    sort(fim, fim+n);

    for (int i = 0; i < c; i++) {
        int a = read_int();
        int b = read_int();

        int com1 = 0, com2 = n;
        while (com1 < com2) {
            int mid = (com1+com2+1)/2;
            if (comeco[mid-1] < a) com1 = mid;
            else com2 = mid-1; 
        }

        int fim1 = 0, fim2 = n;
        while (fim1 < fim2) {
            int mid = (fim1+fim2+1)/2;
            if (fim[mid-1] <= b) fim1 = mid;
            else fim2 = mid-1; 
        }
    
        print_num(n+com1-fim1);
    }

    fwrite(ans, 1, pos, stdout);
    return 0;
}
