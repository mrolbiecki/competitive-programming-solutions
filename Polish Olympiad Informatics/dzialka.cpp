//2023-01-13
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/VZifqMhw2OhTWnQqv7mC5Cge/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2010;

int n, ans;
bool grid[maxN][maxN];
int h[maxN][maxN];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> grid[y][x];
			
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			h[y][x] = (grid[y][x] ? 0 : h[y-1][x] + 1);
			
	for (int y = 1; y <= n; y++) {
		
		stack <pair <int, int>> S;
		
		for (int x = 1; x <= n; x++) {
			
			int pos = x;
			while (!S.empty() && S.top().second > h[y][x]) {
				
				auto p = S.top(); S.pop();
				pos = p.first;
				ans = max(ans, p.second * (x-p.first));
			}
			
			S.push({pos, h[y][x]});
		}
		
		while (!S.empty()) {
				
			auto p = S.top(); S.pop();
			ans = max(ans, p.second * (n-p.first+1));
		}
	}

	cout << ans;
	
	return 0;
}
