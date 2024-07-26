//2023-01-18
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/unYhfsxoVEsb1O89HLtzjWc5/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 4e4+2;

int n, m;
vector <vector <int>> G(maxN);
bool vis [maxN];
int odl [maxN];
int layer[6];
long long ans;

void bfs (int x) {
	
	for (int i = 1; i <= n; i++) {
		odl[i] = 1e9;
		vis[i] = 0;
	}
	
	queue <int> Q;
	Q.push(x);
	vis[x] = 1; odl[x] = 0;
	
	while (!Q.empty()) {
		
		int t = Q.front(); Q.pop();
		
		for (int u : G[t])
			if (!vis[u]) {
				odl[u] = odl[t] + 1;
				vis[u] = 1;
				Q.push(u);
			}
	}
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	bfs(1);
	
	for (int i = 1; i <= n; i++)
		if (odl[i] <= 2)
			layer[odl[i]]++;
	
	bfs (2);
	
	for (int i = 1; i <= n; i++)
		if (odl[i] <= 2)
			layer [ 5-odl[i] ]++;
			
	layer[0] = layer[5] = 1;
			
	int x = n;
	for (int i = 0; i <= 5; i++)
		x -= layer[i];
	
	if (layer[1] > layer[4]) layer[2] += x;
	else layer[3] += x;
	
	for (int i = 0; i <= 4; i++)
		ans += 1ll*layer[i]*layer[i+1];
		
	for (int i = 0; i <= 5; i++)
		ans += 1ll*layer[i]*(layer[i]-1)/2;
		
	cout << ans-m;
	
	return 0;
}
