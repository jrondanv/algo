#include <stdio.h>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

#define INF 1000000000

int T;
int N, M;

char inp[10000];
int pos;

long long number() {
    long long res = 0;
    while (isdigit(inp[pos])) {
        res = res*10 + inp[pos++]-'0';
    }
    return res;
}

long long factor() {
    long long res = number();
    while (inp[pos] == '*') {
        pos++;
        res *= number();
    }
    return res;
}


long long parse1() {
    long long res = factor();
    while (inp[pos] == '+') {
        pos++;
        res += factor();
    }
    return res;
}

long long factor2() {
    long long res = number();
    while (inp[pos] == '+') {
        pos++;
        res += number();
    }
    return res;
}


long long parse2() {
    long long res = factor2();
    while (inp[pos] == '*') {
        pos++;
        res *= factor2();
    }
    return res;
}

int main() {
    for (scanf("%d\n", &T); T; T--) {
        gets(inp);
        
        pos=0;
        long long min = parse1();
        pos=0;
        long long max = parse2();
        
        printf("The maximum and minimum are %lld and %lld.\n",max,min);
    }
}


