#include <stdio.h>
#include <map>

using namespace std;

int main() {
	int K;
	map<int,int> exec;
	
	while (scanf("%d", &K) && K) {
        exec.clear();
        int cnt = 0;
        
		for (int i = 0; i < K; i++) {
            int M;
		    scanf("%d", &M);
		    
		    map<int,int>::iterator it = exec.find(M);
		    if (it != exec.end()) {
                cnt += i - it->second;
                it->second = i;
            }
            else {
                cnt += M + i;
                exec.insert(pair<int,int>(M,i));
            }
            
        }
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
