#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAX 100000
using namespace std;
int gcd(int a, int b);
int main()
{
    while(true)
    {
        int T, Q, VT[MAX];
        cin >> T >> Q;
        if (!T && !Q)
            break;
        int ii, d = -1;
        for (ii = 0; ii < T; ii++)
        {
            cin >> VT[ii];
            if (ii == 0) d = 2*VT[ii];
            else d = gcd(2*VT[ii],d);
        }
        d = abs(d);

        for (ii = 1; ii <= Q; ii++)
        {

            int S, D;
            bool band = false;
            cin >> S >> D;
            if ((S+D) % d == 0 || (D-S) % d == 0) band = true;
            
            if (band)
                cout << "Y";
            else
                cout << "N";
            if (ii < Q)
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
 
int gcd(int a, int b)
{
    int temp;
    
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


