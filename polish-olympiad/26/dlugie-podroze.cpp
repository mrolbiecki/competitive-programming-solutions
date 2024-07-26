//2023-03-14
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/QHh99tBu4p9FMsFohv4da7S7/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int k = 200, maxN = 1e5+2, inf = 1e6;

int n, m, p;
int dist [k+2][maxN];
int vis[maxN];

vector <int> G[maxN];

int R (int a, int b) {return a + rand() % (b-a+1);}

void bfs (int x) {
	
	int st = R(1, n);
	
	queue <int> Q;
	Q.push(st);
	vis[st] = x;
	
	while (!Q.empty()) {
		
		int v = Q.front(); Q.pop();
		
		for (int u : G[v])
			if (vis[u] != x) {
				
				vis[u] = x;
				dist[x][u] = dist[x][v] + 1;
				Q.push(u);
			}
	}
}

int querry (int a, int b) {
	
	int res = inf;
	
	for (int i = 1; i <= k; i++)
		res = min(res, dist[i][a] + dist[i][b]);
		
	return res;
}

int main () {
	
	srand(69420);
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> p;
	for (int i = 1; i <= m; i++) {
		
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 1; i <= k; i++) bfs(i);

	for (int i = 1; i <= p; i++) {
	
		int a, b; cin >> a >> b;
		cout << querry(a, b) << '\n';
	}
	
	return 0;
}
