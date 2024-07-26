//2023-01-15
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 184;

int n, m;
bool odw[maxN][maxN];
int odl[maxN][maxN];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	queue <pair <int, int>> Q;
	
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++) {
			char b;
			cin >> b;
			
			if (b == '1') {
				odw[y][x] = 1;
				Q.push({y, x});
			}
		}
		
	while (!Q.empty()) {
		
		int x = Q.front().second, y = Q.front().first;
		Q.pop();
		
		if (x != 1 && !odw[y][x-1]) {
			odl[y][x-1] = odl[y][x] + 1;
			odw[y][x-1] = 1;
			Q.push({y, x-1});
		}
		if (x != m && !odw[y][x+1]) {
			odl[y][x+1] = odl[y][x] + 1;
			odw[y][x+1] = 1;
			Q.push({y, x+1});
		}
		if (y != 1 && !odw[y-1][x]) {
			odl[y-1][x] = odl[y][x] + 1;
			odw[y-1][x] = 1;
			Q.push({y-1, x});
		}
		if (y != n && !odw[y+1][x]) {
			odl[y+1][x] = odl[y][x] + 1;
			odw[y+1][x] = 1;
			Q.push({y+1, x});
		}
	}
	
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++)
			cout << odl[y][x] << ' ';
		cout << '\n';
	}
	
	return 0;
}
