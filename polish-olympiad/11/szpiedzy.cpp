// author: Marcin Rolbiecki
// date: 2024-08-13
// problem: https://szkopul.edu.pl/problemset/problem/RiTxbbjmgXZ84FuD9qo15Aq8/site/?key=statement

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2;

bool is_deleted[maxN];
int n, ans;

int a[maxN];
int deg[maxN];

vector <int> deg_zero;

int cycle_len(int v) {
	is_deleted[v] = 1;
	if (is_deleted[ a[v] ]) {
		return 1;
	} else {	
		return 1 + cycle_len(a[v]);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		deg[ a[i] ]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			deg_zero.push_back(i);
		}
	}
	
	while (!deg_zero.empty()) {
		int v = deg_zero.back();
		deg_zero.pop_back();
		
		if (is_deleted[v]) {
			continue;
		}
		if(is_deleted[ a[v] ]) {
			is_deleted[v] = 1;
			continue;
		}
		ans++;
		is_deleted[v] = is_deleted[ a[v] ] = 1;
		deg[ a[ a[v] ] ]--;
		if (deg[ a[ a[v] ] ] == 0) {
			deg_zero.push_back(a[ a[v] ]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!is_deleted[i]) {
			ans += cycle_len(i) / 2;
		}
	}
	
	cout << ans;

    return 0;
}
