#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

bool win (int* girl, int* boy) {
	int boy_s[3];
	
	int i;
	for (i=0; i<3; i++) boy_s[i] = boy[i];
	sort(boy_s, boy_s+3);
	
	i = 0;
	int j = 0, c = 0, bc = 0;
	while (i != 3 && j != 3) {
		if (girl[i] < boy_s[j]) {
			if (bc == 0) c++;
			else bc--;
			i++;
		}
		
		else if (girl[i] == boy_s[j]) {
			return false;
		}
		
		else {
			bc++;
			j++;
		}
	}
	
	return c > 1;
}			

int main() {
	int girl[3];
	int boy[3];
	std::set<int> used;
	
	while (1) {
		scanf("%d %d %d %d %d", girl,girl+1,girl+2,boy,boy+1);
		
		if (girl[0] == 0) break;
		
		sort(girl, girl+3);
		
		int i;
		used.clear();
		for (i=0; i<2; i++) {
			used.insert(girl[i]);
			used.insert(boy[i]);
		}
		used.insert(girl[2]);
		
		for (i=1; i<53; i++) {
			if (used.find(i) != used.end()) continue;
			boy[2] = i;
			if (win(girl, boy)) {
				printf("%d\n", i); 
				break;
			}
		}
		
		if (i == 53) printf("-1\n");
	}
	
	return 0;
}