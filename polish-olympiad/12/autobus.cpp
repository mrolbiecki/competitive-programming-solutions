// author: Marcin Rolbiecki
// date: 2024-10-07
// problem: https://szkopul.edu.pl/problemset/problem/YBrY12KT6hTbgYrqwXhH3soW/site/?key=statement

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2;
const int T = 1<<20;

int n, m, k;

map <pair<int, int>, int> P;
map <pair<int, int>, int> M;
int stree[2 * T];

void update (int pos, int val) {
	pos += T;
	stree[pos] = max(stree[pos], val);
	pos /= 2;
	while (pos) {
		stree[pos] = max(stree[pos * 2], stree[pos * 2 + 1]);
		pos /= 2;
	}
}

int query (int l, int r, int id, int lo, int hi) {
	if (id == 0) return 0;
	if (r < lo || hi < l) {
		return 0;
	}
	if (l <= lo && hi <= r) {
		return stree[id];
	}
	int mid = (lo + hi) / 2;
	return max(
		query(l, r, id * 2, lo, mid),
		query(l, r, id * 2 + 1, mid + 1, hi)
	);
}



int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= k; i++) {
		int x, y, p;
		cin >> x >> y >> p;
		M[{y, x}] = p;
	}
	
	int y_before = 0, y_after = 0;
	for (auto m : M) {
		auto p = m.first;
		if (p.first > y_before) {
			y_after++;
		}
		y_before = p.first;
		P[{p.second, y_after}] = m.second;
	}
	
	for (auto it = P.rbegin(); it != P.rend(); it++) {
		auto p = it->first;
		update(p.second, query(p.second, m, 1, 0, T - 1) + it->second);
	}
	
	cout << stree[1];

	return 0;
}
