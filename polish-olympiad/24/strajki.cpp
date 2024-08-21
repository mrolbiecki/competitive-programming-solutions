// author: Marcin Rolbiecki
// date: 2024-08-21
// problem: https://szkopul.edu.pl/problemset/problem/lR_LabSUC2n7EMmDHpw-wk_b/site/?key=statement

#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+2;


bool is_big [maxN], is_del[maxN];
int del_neigh_cnt[maxN];
vector <int> G [maxN], Gb [maxN];

int sq, n, m, ans;

void update (int v, int val) {
	for (int u : Gb[v]) {
		del_neigh_cnt[u] += val;
	}
}

int cnt (int v) {
	if (is_big[v]) {
		return del_neigh_cnt[v];
	}
	
	int res = 0;
	for (int u : G[v]) {
		if (is_del[u]) {
			res++;
		}
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	sq = sqrt(n);
	
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		if ((int)G[i].size() >= sq) {
			is_big[i] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int u : G[i]) {
			if (is_big[u]) {
				Gb[i].push_back(u);
			}
		}
	}
	
	ans = 1;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int z; cin >> z;
		if (z > 0) {
			ans += G[z].size() - cnt(z) - 1;
			update(z, 1);
			is_del[z] = 1;
		} else {
			z = -z;
			ans -= G[z].size() - cnt(z) - 1;
			update(z, -1);
			is_del[z] = 0;
		}
		cout << ans << '\n';
	}

  return 0;
}
