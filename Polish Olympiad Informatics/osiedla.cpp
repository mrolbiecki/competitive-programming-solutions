//2022-12-10
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/nldsb4EW1YuZykBlf4lcZL1Y/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+10;

int n, m;
vector <set <int>> Gp (maxN);
vector <vector <int>> G (maxN), Grev (maxN);
vector <pair <int, int>> edges (maxN);
bool skierowanie [maxN], odw[maxN];

vector <int> order;
int ss;

void dfs_skierowanie (int x) {
	
	odw[x] = 1;
	
	for (auto e : Gp[x]) {
		
		int u;
		if (edges[e].first == x) {
			skierowanie[e] = 1;
			u = edges[e].second;
		}
		else {
			skierowanie[e] = 0;
			u = edges[e].first;
		}
		
		Gp[u].erase(e);
		G[x].push_back(u);
		Grev[u].push_back(x);
		
		if (!odw[u])
			dfs_skierowanie(u);
	}
}

void dfs_order (int x) {
	
	odw[x] = 1;
	
	for (int u : G[x])
		if (!odw[u])
			dfs_order(u);
	
	order.push_back(x);
}

void dfs_spojne (int x) {
	
	odw[x] = 1;
	
	for (int u : Grev[x])
		if (!odw[u])
			dfs_spojne(u);
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1, a, b; i <= m; i++) {
		cin >> a >> b;
		edges[i] = {a, b};
		Gp[a].insert(i);
		Gp[b].insert(i);
	}
	
	for (int i = 1; i <= n; i++)
		if (!odw[i])
			dfs_skierowanie(i);
	
	fill(odw, odw + n + 1, 0);
	
	for (int i = 1; i <= n; i++)
		if (!odw[i])
			dfs_order(i);
	
	reverse(order.begin(), order.end());
	fill(odw, odw + n + 1, 0);
	
	for (int i = 0; i < n; i++)
		if (!odw[ order[i] ]) {
			dfs_spojne( order[i] );
			ss++;
		}
	
	cout << ss << '\n';
			
	for (int i = 1; i <= m; i++)
		cout << (skierowanie[i] ? '>' : '<');
		
	return 0;
}
