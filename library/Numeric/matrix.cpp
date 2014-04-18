void copia(int c[4][4], int a[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) c[i][j] = a[i][j];
    }
}

void mult(int c[4][4], int a[4][4], int b[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
            c[i][j] %= mod;
        }
    }

}

void pow(int c[4][4], int a[4][4], int b) {
    if (b == 1) {
        copia(c, a);
        return;
    }

    int temp[4][4];

    pow(c, a, b/2);
    mult(temp, c, c);

    if (b&1) mult(c, temp, a);
    else copia(c, temp);
}