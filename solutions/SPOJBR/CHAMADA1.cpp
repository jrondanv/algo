#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string nomes[200];

int main() {
    int N,K;
    scanf("%d %d", &N, &K);
    
    for (int i = 0; i < N; i++) {
        cin >> nomes[i];
    }
    
    sort(nomes, nomes+N);
    
    cout << nomes[K-1] << endl;
    return 0;
}
