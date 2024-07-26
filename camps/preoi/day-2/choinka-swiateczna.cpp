#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+2, maxL = 31;

vector <pair <int, int>> T [maxN];
int a[maxN], b[maxN];

int n;

int x[maxN], y[maxN];
int cntx [maxL], cnty [maxL];

void dfs (int v, int p) {

	for (auto e : T[v])
		if (e.first != p) {
			x[e.first] = x[v]^a[e.second];
			y[e.first] = y[v]^b[e.second];
			dfs(e.first, v);
		}
}

int main () {

	cin >> n;
	for (int i = 1; i < n; i++) {
	
		int v, u; cin >> v >> u;
		T[v].push_back({u, i});
		T[u].push_back({v, i});
		cin >> a[i] >> b[i];
	}
	
	dfs(1, -1);
	
	for (int b = 0; b < maxL; b++)
		for (int i = 1; i <= n; i++) {
			if (x[i] & (1<<b)) cntx[b]++;
			if (y[i] & (1<<b)) cnty[b]++;
		}
	
	int mask=0;
	for (int b = 0; b < maxL; b++)
		if (cntx[b] != cnty[b] && cntx[b] != n-cnty[b]) {
			cout << "NIE";
			return 0;
		}
		else if (cntx[b] == n-cnty[b])
			mask |= (1<<b);
	
	multiset <int> X, Y;
	for (int i = 1; i <= n; i++)
		X.insert(x[i]^mask), Y.insert(y[i]);
		
	cout << (X == Y ? "TAK" : "NIE");
}
