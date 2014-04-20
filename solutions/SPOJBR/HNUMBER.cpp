#include <stdio.h>
 
int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};

int Y, X2;
int pfactors[9], nfactors;
int comb[9], ans;
 
void find_pfactors()
{
    int i = 0, flag = 0;
    nfactors = 0;
    while((Y-1) && (i < 65))
    {
        while( !(Y%primes[i]) )
        {
            flag = 1;
            Y /= primes[i];
        }
        if(flag)
        {
            flag = 0;
            pfactors[nfactors++] = primes[i];
        }
        i++;
    }
    if((Y-1) && (i == 65)) pfactors[nfactors++] = Y;
}
 
int next_comb(int comb[], int k, int n)
{
    int i = k - 1;
    ++comb[i];
    while ((i >= 0) && (comb[i] >= n - k + 1 + i)) 
    {
        --i;
        ++comb[i];
    }
 
    if (comb[0] > n - k)
        return 0;
    
    for (i = i + 1; i < k; ++i)
        comb[i] = comb[i - 1] + 1;
 
    return 1;
}
 
void find_ans()
{
    int i, j, t1, sum, cur_no;
    for(i = 0; i < nfactors; i++)
    {
        for (j = 0; j < nfactors; j++)
            comb[j] = j;
        
        sum = 0;
        do
        {
            cur_no = 1;
            for(t1 = 0; t1 <= i; t1++)
                cur_no *= pfactors[comb[t1]];
            sum += X2/cur_no;
        }while (next_comb(comb, i+1, nfactors));

        if((i%2)==0) ans += sum;
        else ans -= sum;
    }
}
 
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        ans = 0;
        scanf("%d%d", &Y, &X2);
        find_pfactors();
        
        find_ans();
        printf("%d\n", X2-ans);
    }
    return 0;
}
