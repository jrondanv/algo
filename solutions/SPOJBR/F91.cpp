#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cctype>

namespace IO
{
const int SIZE = 1 << 19;
char buff[SIZE], *p = buff + SIZE;
char saida[1 << 24], *sp = saida, cnt=0;

char read_char()
{
    if( p == buff + SIZE )
    {
        fread_unlocked( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
}

inline int read_int()
{
    char c;

    while( !isdigit( c = read_char() ) );

    int r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}

void write_chars(char* a, int sz) {
    memcpy(sp,a,sz);
    sp+=sz;
    cnt+=sz;
}

void write_beg() {
    *(sp++) = 'f';
    *(sp++) = '9';
    *(sp++) = '1';
    *(sp++) = '(';
    cnt+=4;
}

void write_mid() {
    *(sp++) = ')';
    *(sp++) = ' ';
    *(sp++) = '=';
    *(sp++) = ' ';
    cnt+=4;
}

void write_no() {
    *(sp++) = '9';
    *(sp++) = '1';
    cnt+=2;
}

void write_num(int n)
{
    int off = sprintf(sp, "%d", n);
    cnt += off;
    sp += off;
}

void write_nl() {
    *(sp++) = '\n';
    cnt++;
}

void output() {
    fwrite_unlocked(saida, 1, cnt, stdout);
} 

}

using namespace IO;
using namespace std;

char beg[5] = "f91(";
char mid[5] = ") = ";
char no[3] = "91";

int main() {
  int num;
  while (1) {
    num=read_int();
    if (num == 0) break;
    
    write_beg();
    write_num(num);
    write_mid();
    if (num > 101) write_num(num-10);
    else write_no();
    write_nl();
  }
  
  output();
  return 0;
}





