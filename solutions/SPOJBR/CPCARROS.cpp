#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int plate_number(char* plate) {
    int old;
    int num = 0;
    
    if (isdigit(plate[3]) && isdigit(plate[4])) old = 1;
    else if (!isdigit(plate[3]) && !isdigit(plate[4])) old = 0;
    else return -1;
    
    for (int i=0; i<3; i++) {
        if (old) num*=26;
        else num*=21;
        
        num += plate[i]-'A';
        
        if (!old) {
            num -= plate[i] > 'A';
            num -= plate[i] > 'C';
            num -= plate[i] > 'M';
            num -= plate[i] > 'I';
            num -= plate[i] > 'P';
        }
    }

    for (int i = 3; i < 5; i++) {
        if (old) {
            num *= 10;
            num += plate[i]-'0';
        }
        else {
            num *= 21;
            num += plate[i] - 'A';
            num -= plate[i] > 'A';
            num -= plate[i] > 'C';
            num -= plate[i] > 'M';
            num -= plate[i] > 'I';
            num -= plate[i] > 'P';
        }
    }
    
    num *= 10;
    num += plate[5]-'0';
    num *= 10;
    num += plate[6]-'0';
    
    if (!old) {
        for (int i = 0; i < 5; i++) {
            if (plate[i] == 'A' || plate[i] == 'C' || plate[i] == 'M' || plate[i] == 'I' || plate[i] == 'P') return -1;
        }
    }
    
    if (!old) return num + (26*26*26*10*10*10*10);
    return num;
}

int main() {
    char n1[10], n2[10];
	int C;
	
	while (scanf(" %s %s %d", n1, n2, &C) && C) {
		int M = plate_number(n1);
		int I = plate_number(n2);
		
		if (I > M && I-M <= C) printf("Y\n", M, I);
		else printf("N\n", M, I);
	}
	return 0;
}
