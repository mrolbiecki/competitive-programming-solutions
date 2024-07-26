#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2003, maxM = 3003;

int n, m;
int a[maxM], b[maxM];
ll dp[maxN][maxN], c1[maxM], c2[maxM];
int order[maxN];

vector <int> topo;
vector <pair<int, int>> G[maxN];

bool vis[maxN];

void dfs (int v) {

	vis[v] = 1;
	sort(G[v].begin(), G[v].end());
	
	for (auto e : G[v])
		if (!vis[e.first])
			dfs(e.first);
	topo.push_back(v);
}

void toposort () {

	dfs(1);
	reverse(topo.begin(), topo.end());
	
	for (int i = 0; i < (int)topo.size(); i++)
		order[topo[i]] = i+1;
}

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c1[i] >> c2[i];
		G[a[i]].push_back({b[i], i});
	}
	
	toposort();
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = 1e13;
	
	dp[1][1] = 0;
	
	for (int i = 0; i < (int)topo.size(); i++) {
	
		for (int j = 0; j <= i; j++) {
			//x <= y
			int y = topo[i], x = topo[j];
			
			if (x == y)
				for (auto e : G[x])
					dp[e.first][e.first] =
					min(dp[e.first][e.first], dp[x][y] + 
					c1[e.second] + c2[e.second]);
			else {
				int i1 = 0, i2 = 0;
				while (i1 < (int)G[x].size() && i2 < (int)G[y].size()) {
				
					if (G[x][i1].first < G[y][i2].first) i1++;
					else if (G[x][i1].first > G[y][i2].first) i2++;
					else {
						int c = G[x][i1].first;
						dp[c][c] = 
						min(dp[c][c], dp[x][y] + 
						c1[G[x][i1].second] + c1[G[y][i2].second]);
						i1++; i2++;
					}
				}
			}
				
			for (auto e : G[y])
				dp[x][e.first] = 
				min(dp[x][e.first], dp[x][y] + c1[e.second]);
				
			for (auto e : G[x])
				if (order[e.first] > order[y])
					dp[y][e.first] = 
					min(dp[y][e.first], dp[x][y] + c1[e.second]);
		}
	}	
/*	
	for (int i = 1; i <= n; i++) {
	
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}	
*/	
	cout << dp[n][n];
}
