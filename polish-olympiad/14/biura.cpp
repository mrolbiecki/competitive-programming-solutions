//2024-01-09
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+2;
const int maxM = 2e6+2;

int id[maxN];
int idSize[maxN];
set <int> biura;

int n, m;
vector <int> G[maxN];

int Find(int x) {
	
	if (id[x] != x)
		id[x] = Find(id[x]);
	return id[x];
}

vector <int> deleted;
void clear_biura () {
	
	for (int d : deleted) biura.erase(d);
	deleted.clear();
}

void Union (int x, int y) {
	
	x = Find(x);
	y = Find(y);
	
	if (x == y) return;
	
	if (idSize[x] <= idSize[y]) {
	
		idSize[y] += idSize[x];
		id[x] = y;
		deleted.push_back(x);
	}
	else {
		
		idSize[x] += idSize[y];
		id[y] = x;
		deleted.push_back(y);
	}
}

void dsu_prec () {
	
	for (int i = 1; i <= n; i++)
		id[i] = i, idSize[i] = 1, biura.insert(i);
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	dsu_prec();
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		
		map <int, int> cnt;
		
		for (int tel : G[i])
			cnt[ Find(tel) ]++;
		
		for (int b : biura) {
			
			if (cnt[b] == idSize[b]) continue;
			Union(i, b);
		}
		clear_biura();
	}
	
	vector <int> ans;
	for (int b : biura)
		ans.push_back(idSize[b]);
	sort(ans.begin(), ans.end());
	
	cout << ans.size() << '\n';
	for (int a : ans)
		cout << a << ' ';
		
	return 0;
}
