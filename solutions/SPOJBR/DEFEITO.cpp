#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n;
double side[100];
double ang[100];
const double pi = 2*acos(0);

int main() {
	while (scanf("%d", &n) > 0) {
		int miss = -1;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &side[i]);
			if (side[i] < -0.5) miss = i;
		}

		for (int i = 0; i < n; i++) {
			scanf("%lf", &ang[i]);
		}

		double dx = 1, dy = 0;
		double x = 0, y = 0;

		for (int i = (miss+1)%n; i != miss; i = (i+1)%n) {
			x += side[i]*dx;
			y += side[i]*dy;

			if (ang[i] > -0.5) {
				double rad = ang[i] * pi / 180;
				
				double ndx = -dx*cos(rad) - dy*sin(rad);
				dy = -dy*cos(rad) + dx*sin(rad);
				dx = ndx;
			}

			//printf("%lf %lf %lf %lf\n", x,y,dx,dy);
		}

		double l = hypot(x,y);
		double a1 = acos((x*dx + y*dy) / l) * 180 / pi;
		double a2 = acos(x / l) * 180 / pi;
		printf("%.1lf %.1lf %.1lf\n", l, a1, a2);

	}
}