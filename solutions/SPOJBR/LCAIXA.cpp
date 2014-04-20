#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 2^27
#define INVALID 0x8000000

typedef unsigned long long ull;

int N, F;

int T[40];

int avalor[40001], ovalor[40001];
int soma[1050000]; // 2^20
int acr[1050000];

char out[2] = {'+','-'};

int main() {
    while (scanf("%d %d", &N, &F) && N) {
        for (int i = 0; i < N; i++) scanf("%d", T+i); 
        
        int mid = N/2;
        
        for (int i = 0; i <= 40000; i++) avalor[i] = ovalor[i] = INVALID;
        
        int lim_mid = 1 << mid;
        
        soma[0] = 0;
        for (int i = 0; i < mid; i++) soma[0] -= T[i];
        
        acr[0]=0;
        for (int i = 1, j = 0; j < mid; i <<= 1, j++) {
            acr[i] = 2*T[j];    
        }
        
        for (int i = 0; i < lim_mid; i++) {
            int bit = i & (i-1);
            soma[i] = soma[bit] + acr[i-bit]; 
            
            if (avalor[soma[i]+20000]!=INVALID) {
                avalor[soma[i]+20000]&=i;
                ovalor[soma[i]+20000]|=i;
            }
            else avalor[soma[i]+20000]=ovalor[soma[i]+20000]=i;
        }
        
        int band_left = INVALID, band_right = INVALID;
        int bor_left = INVALID, bor_right = INVALID;
        
        soma[0] = 0;
        for (int i = mid; i < N; i++) soma[0] -= T[i];
        
        acr[0]=0;
        for (int i = 1, j = mid; j < N; i <<= 1, j++) {
            acr[i] = 2*T[j];    
        }
        
        lim_mid = 1 << (N - mid);
        for (ull i = 0; i < lim_mid; i++) {
            int bit = i & (i-1);
            soma[i] = soma[bit] + acr[i-bit]; 
            
            if (abs(F-soma[i])<=20000) {
                if (avalor[F-soma[i]+20000]!=INVALID) {
                    if (band_left == INVALID) {
                        band_left = bor_left = i;
                        band_right = avalor[F-soma[i]+20000];
                        bor_right = ovalor[F-soma[i]+20000];
                    }
                    else {
                        band_left &= i;
                        bor_left |= i;
                        band_right &= avalor[F-soma[i]+20000];
                        bor_right |= ovalor[F-soma[i]+20000]; 
                    }
                }
            }
        }
        
        if (band_left == INVALID) {
            printf("*\n");
            continue;
        }
        for (int i = 1, j = 0; j < mid; i<<=1, j++) {
            if ((band_right & i) == (bor_right & i)) printf("%c",out[!(band_right&i)]);
            else printf("?");
        } 
        for (int i = 1, j = mid; j < N; i<<=1, j++) {
            if ((band_left & i) == (bor_left & i)) printf("%c",out[!(band_left&i)]);
            else printf("?");
        } 
        printf("\n");
    }
}    
