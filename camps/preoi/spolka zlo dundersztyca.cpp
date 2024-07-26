//2023-01-30
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maX = 125;

int X, Y, Z, m;
bool grid[maX][maX][maX];
pair <int, int> W [maX][maX];
bool visW [maX][maX];

int odl [maX][maX][maX];

struct point {
	
	int x, y, z;
};

point S, K;

void BFS () {
	
	deque <point> Q;
	Q.push_back({S.x, S.y, S.z});
	odl[S.z][S.y][S.x] = 0;
	
	while (!Q.empty()) {
		
		point p = Q.front(); Q.pop_front();
		
		if (p.x != 1 && grid[p.z][p.y][p.x-1] && odl[p.z][p.y][p.x-1] == -1) {
			odl[p.z][p.y][p.x-1] = odl[p.z][p.y][p.x] + 1;
			Q.push_back({p.x-1, p.y, p.z});
		}
		if (p.x != X && grid[p.z][p.y][p.x+1] && odl[p.z][p.y][p.x+1] == -1) {
			odl[p.z][p.y][p.x+1] = odl[p.z][p.y][p.x] + 1;
			Q.push_back({p.x+1, p.y, p.z});
		}
		if (p.y != 1 && grid[p.z][p.y-1][p.x] && odl[p.z][p.y-1][p.x] == -1) {
			odl[p.z][p.y-1][p.x] = odl[p.z][p.y][p.x] + 1;
			Q.push_back({p.x, p.y-1, p.z});
		}
		if (p.y != Y && grid[p.z][p.y+1][p.x] && odl[p.z][p.y+1][p.x] == -1) {
			odl[p.z][p.y+1][p.x] = odl[p.z][p.y][p.x] + 1;
			Q.push_back({p.x, p.y+1, p.z});
		}
		
		if (!visW[p.y][p.x] && W[p.y][p.x].first <= p.z && W[p.y][p.x].second >= p.z) {
			
			visW[p.y][p.x] = 1;
			
			for (int i = W[p.y][p.x].first; i <= W[p.y][p.x].second; i++)
				if (i != p.z && grid[i][p.y][p.x] && odl[i][p.y][p.x] == -1) {
					odl[i][p.y][p.x] = odl[p.z][p.y][p.x];
					Q.push_front({p.x, p.y, i});
				}
		}
	}
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> X >> Y >> Z;
	
	for (int z = 1; z <= Z; z++)
		for (int y = 1; y <= Y; y++)
			for (int x = 1; x <= X; x++) {
				
				char ch; cin >> ch;
				grid[z][y][x] = ch == 'O';
				
				odl[z][y][x] = -1;
			}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		W[Y-b+1][a] = {c, d};
	}
	
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	S = {a, Y-b+1, c}; K = {d, Y-e+1, f};
	
	BFS();
	
	cout << odl[K.z][K.y][K.x];
	
	return 0;
}
