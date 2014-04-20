#include <stdio.h>
#include <deque>
#include <vector>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> P;

void mkprimes(int lim) {
   P.push_back(2);
   for ( int i = 3; i <= lim; i += 2 ) {
      for ( int j = 0; P[j]*P[j] <= i; j++ )
         if ( i % P[j] == 0 )
            goto NOPRIME;
            
      P.push_back(i);
NOPRIME:
      ;
   }
}


class poly {
    public:
        deque<int> coefs;
    
    void clean() {
        while (coefs.size() > 1 && coefs.back() == 0) coefs.pop_back();
    }
    
    poly sum(poly &b, int mul) {
        poly n;
        
        int s = coefs.size();
        int bs = b.coefs.size();
        
        int ns = max(s, bs);
        
        for (int i = 0; i < ns; i++) {
            n.coefs.push_back((i<s ? coefs[i] : 0) + mul*(i<bs ? b.coefs[i] : 0));
        }
        
        n.clean();
        
        return n;
    }
    
    poly operator+(poly &b) {
        return sum(b,1);
    }
    
    poly operator- (poly &b) {
        return sum(b,-1);
    }
    
    poly operator* (poly &b) {
        poly n;
        
        int s = coefs.size();
        int bs= b.coefs.size();
        int ns = s+bs-1;
        
        for (int i = 0; i < ns; i++) {
            n.coefs.push_back(0);
        }
        
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < bs; j++) {
                n.coefs[i+j] += coefs[i]*b.coefs[j];
            }
        }
        
        n.clean();
        return n;
    } 
    
    void print(char* str="") {
        int s = coefs.size();
        printf("%s:", str);
        for (int i = s-1; i >=0;i--) {
            printf("%d ",coefs[i]);
        }
        printf("\n");
    }
    
    int evaluate(int x) {
       int sz = coefs.size();
       int sum = 0;
       const int imax = INT_MAX;
       for ( int i = sz-1; i >= 0; i-- ) {
          if ( imax/x < sum ) return 1;
          sum *= x;
          if ( coefs[i] > 0 && imax-coefs[i] < sum ) return 1;
          sum += coefs[i];
       }
       return sum;
    }
};

char line[100];
int ind, lower;


poly parse(char* line, char delim) {
    int op = -1;
    vector<poly> expr1_parts;
    poly cur_num;
    
    while (line[ind] != delim) {
        cur_num.coefs.clear();
        while (isdigit(line[ind])) {
            lower=max(line[ind]-'0'+1, lower);
            cur_num.coefs.push_front(line[ind]-'0');
            ind++;
        }
        
        if (line[op] == '*') {
            poly temp = cur_num * expr1_parts.back();
            expr1_parts.pop_back();
            expr1_parts.push_back(temp);
        }
        else {
            expr1_parts.push_back(cur_num);
        }
        
        if (line[ind] != delim) {
            op = ind;
            ind++;
        }
    }  
    
    poly expr1;
    for (int j = 0; j < expr1_parts.size(); j++) {
        expr1 = expr1 + expr1_parts[j];
    }
    
    ind++;
    return expr1;
}

    
void factorize(const vector< pair<int,int> > &f, int i, vector<int> &s, int val) {
   if ( i == (int)f.size() ) {
      s.push_back(val);
      return;
   }
   int px = 1;
   for ( int j = 0; j <= f[i].second; j++ ) {
      factorize(f, i+1, s, val*px);
      px *= f[i].first;
   }
}

vector<int> submultiples(int x) {
   vector< pair<int, int> > f;
   for ( int i = 0; P[i]*P[i] <= x; i++ )
      if ( x % P[i] == 0 ) {
         f.push_back(make_pair(P[i], 0));
         while ( x % P[i] == 0 ) {
            x /= P[i];
            f.back().second++;
         }
      }
   if ( x != 1 )
      f.push_back(make_pair(x, 1));
   vector<int> s;
   factorize(f, 0, s, 1);
   sort(s.begin(), s.end());
   return s;
}
    
    
    
int main() {
    mkprimes(19683);
    
    while (gets(line) != NULL && line[0] != '=') {
        poly expr1, expr2;
        
        ind = 0;
        lower = 2;
    
        expr1 = parse(line, '=');

        expr2 = parse(line, '\0');
        
        expr1 = expr1 - expr2;
        
        while (expr1.coefs.size() > 1 && expr1.coefs.front() == 0) {
            expr1.coefs.pop_front();
        }
        
        //expr1.print("poly_final");
        if (expr1.coefs.size() == 1) {
            if (expr1.coefs[0] == 0) printf("%d+\n", lower);
            else printf("*\n");
        }    
        
        else {
            vector<int> sb = submultiples(abs(expr1.coefs[0]));
            int s = sb.size();
            int first = 1;
            
            
            for (int i = 0; i < s; i++) {
                //printf("Testando %d\n", sb[i]);
                if (sb[i] < lower) continue;
                
                int valid = 0;
                
                if (!expr1.evaluate(sb[i])) valid = 1;
                
                if (valid) {
                    if (!first) printf(" ");
                    else first = 0;
                    printf("%d",sb[i]);
                }
            }
            
            if (first) printf("*");
            printf("\n");
        }  
    } 
    
    return 0;
}
