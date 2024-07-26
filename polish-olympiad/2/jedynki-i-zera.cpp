//2022-12-31
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while (tt--) {
		
		int n;
		cin >> n;
		
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		
		int G [2][n];
		bool vis [n] {0};
		
		for (int i = 0; i < n; i++) {
			G[0][i] = (i*10)%n;
			G[1][i] = (i*10+1)%n;
		}
		
		queue <int> Q;
		pair<int, int> path [n];
		vis[1] = 1;
		Q.push(1);
		
		while (!Q.empty()) {
			
			int t = Q.front(); Q.pop();
			
			if (t == 0) break;
			
			for (int i = 0; i < 2; i++)
				if (!vis[ G[i][t] ]) {
					vis[ G[i][t] ] = 1;
					Q.push( G[i][t] );
					path[ G[i][t] ] = {t, i};
				}
		}
		
		vector <int> ans;
		int u = 0;
		
		while (u != 1) {
			
			ans.push_back(path[u].second);
			u = path[u].first;
		}
		
		reverse(ans.begin(), ans.end());
		
		cout << 1;
		for (int a : ans)
			cout << a;
		cout << '\n';
			
	}
	
	return 0;
}
