#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

#define MAX 33000000000LL

int moebius[200000];
int moebius_sum[200000];

int prime[200000];

map<long long, long long> cache;

long long maxMoebius = (long long)sqrt(MAX);

const double factor =  1.644934066848;

#define min(a, b) a<b ? a : b
#define max(a, b) a>b ? a : b

void pre() {
  long long int i, j;

  for (i=0; i<maxMoebius; i++){
     moebius[i] = -1; 
     prime[i] = 1;
 }

 long long n_sq_i = 3;
 long long n_sq = 4;

 for (i=2; i<maxMoebius; i++){
     if (prime[i]) for (j=i*i; j<maxMoebius; j+=i) prime[j] = 0;

     if ( i == n_sq){
        n_sq = n_sq_i*n_sq_i;
        n_sq_i++;
        if (moebius[i] != 0)     
          for (j=i; j<maxMoebius; j+=i)
            moebius[j] = 0;
    }
    else if (prime[i] == 1){
      for (j=i; j<maxMoebius; j+=i)
         moebius[j] = -moebius[j];
 }

 moebius_sum[i] = moebius_sum[i-1]+moebius[i];
}
}

long long int getNumber(long long n){
  long long est = (long long) (factor*n);

  long long lb = max(0,est-512);
  long long ub = est+512;
  while (lb < ub){
     long long m = (lb+ub)/2;
     long long thisN;
            if ((thisN = cache[m]) == 0) {
              thisN = m;
              long long c_sq = 2;
              long long val = m/4;
              while (val) {
                long long lim;

                lim = sqrt(m/val);
                while ((val)*(lim*lim) > m) lim--; 

                thisN -= (moebius_sum[lim] - moebius_sum[c_sq-1]) * val;
                c_sq = lim+1;
                val = m/(c_sq*c_sq); 
            }      
            cache[m] = thisN;
        }      
        if (thisN < n)
          lb = m+1;
      else
          ub = m;
  }

  return lb;
}

int main() {
  int N;
  scanf("%d", &N);
  pre();

  for (int i = 0; i < N; i++) {
    long long n;
    scanf("%lld", &n);

    printf("%lld\n", getNumber(n));
}
return 0;
}



