// author: Marcin Rolbiecki
// date: 2024-09-11
// problem: https://szkopul.edu.pl/problemset/problem/OuZMUi4nBcPXMIOr10Z-JGsG/site/?key=statement

#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+2, inf = 1e6+2;

int n, m, k;
int dist[maxN];
vector <int> G[maxN];
vector <int> ans;

void dfs (int v, int d) {
	dist[v] = d;
	if (d == 2) {
		return;
	}
	for (int u : G[v]) {
		if (dist[u] >= d + 1) {
			dfs(u, d + 1);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	fill(dist+1, dist+1+n, inf);
	
	for (int i = 1; i <= n; i++) {
		if (dist[i] > 2) {
			ans.push_back(i);
			dfs(i, 0);
		}
	}
	
	cout << ans.size() << '\n';
	for (int a : ans) {
		cout << a << ' ';
	}

    return 0;
}
