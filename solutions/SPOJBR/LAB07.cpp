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

int n, m;
int board[100][100];
int dist[100][100][11];
struct loc {
	int x, y, t;
	loc(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int t = 0; t < 10; t++) {
				dist[i][j][t]=-1;
			}
		}
	}

	queue<loc> q;
	dist[0][0][0] = 0;
	q.push(loc(0,0,0));
	int ans = -1;

	while (!q.empty()) {
		loc cur = q.front();

		if (cur.x == n-1 && cur.y == m-1) {
			ans = dist[cur.x][cur.y][cur.t];
			break;
		}

		q.pop();

		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				if (dx*dy != 0 || dx+dy==0) continue;
				int nx = cur.x + dx;
				int ny = cur.y + dy;
				int t = cur.t;

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (dist[nx][ny][(t+1)%10] != -1) continue;

				int h = (board[cur.x][cur.y] + t) % 10;
				int oh = (board[nx][ny] + t) % 10;

				if (oh > h+1) continue;

				dist[nx][ny][(t+1)%10] = dist[cur.x][cur.y][cur.t] + 1;
				q.push( loc(nx,ny, (t+1)%10) );
			}
		}

		if (dist[cur.x][cur.y][(cur.t+1)%10] == -1) {
			dist[cur.x][cur.y][(cur.t+1)%10] = dist[cur.x][cur.y][cur.t] + 1;
			q.push( loc(cur.x, cur.y, (cur.t+1)%10 ) );
		}
	}

	printf("%d\n", ans); 			
}