//2023-01-20
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5+2;

int n, x, y, ans = 1e9;
int dp[maxN];
vector <vector <int>> T (maxN);
vector <int> path;

int delA, delB;
void dfs (int v, int p) {
	
	vector <int> d;
	dp[v] = 0;
	
	for (int u : T[v])
		if (u != p) {
			if ((v == delA && u == delB) || (u == delA && v == delB))
				continue;
			dfs(u, v);
			d.push_back(dp[u]);
		}

	sort (d.begin(), d.end(), greater<int>());
	
	for (int i = 0; i < (int)d.size(); i++)
		dp[v] = max(dp[v], d[i] + i + 1);
}

bool find_path (int v, int p) {
	
	bool on_path = false;
	for (int u : T[v])
		if (u != p) {
			if (find_path(u, v)) {
				path.push_back(u);
				on_path = true;
			}
		}
		
	return (on_path || v == y);
}

int check (int i) {
	
	if (i < 0) return 1;
	if (i >= (int)path.size()) return 0;
	
	delA = path[i]; delB = path[i+1];
	dfs(x, -1); dfs(y, -1);
	
	return dp[x] < dp[y];
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x >> y;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		
		T[a].push_back(b);
		T[b].push_back(a);
	}
	
	find_path(x, -1);
	path.push_back(x);
	reverse(path.begin(), path.end());

	int lo = 0, hi = path.size()-1, mid;
	
	while (lo < hi) {
		
		mid = (lo + hi)/2;
		
		if (check(mid))
			lo = mid+1;
		else
			hi = mid;
	}
	
	check(hi); ans = min(ans, max(dp[x], dp[y]));
	check(hi-1); ans = min(ans, max(dp[x], dp[y]));
	check(hi+1); ans = min(ans, max(dp[x], dp[y]));
	
	cout << ans;
	
	return 0;
}
