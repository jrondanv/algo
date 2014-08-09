//Problem Name : 229C - Triangles
//Execution Time : 765 ms
//Memory : 3900 KB
#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
int m;

int incident[1000000];

int main() {
    cin >> n >> m;

    long long tria = n*(n-1)*(n-2)/6;
    long long rem = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        incident[a]++; incident[b]++;
    }

    for (int i = 0; i < n; i++) {
        rem += ((long long)incident[i]) * (n-incident[i]-1);
    } 

    cout << tria - rem/2 << endl;
}