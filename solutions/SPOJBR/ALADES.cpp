#include <stdio.h>

int main () {
	int H1, M1, H2, M2;
	
	while (scanf("%d %d %d %d", &H1, &M1, &H2, &M2)) {
		if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) break;
		
		int hour_delta = (H2 - H1 + 24) % 24;
		
		int minute_delta = M2 - M1;
		
		if (minute_delta < 0) {
			hour_delta = (hour_delta + 23) % 24;
			minute_delta = (minute_delta + 60) % 60;
		}
		
		printf("%d\n", hour_delta*60 + minute_delta);
	}
	
	return 0;
}