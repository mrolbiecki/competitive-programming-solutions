//2023-01-17
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e6+2;
const ll mod = 1e9+7;

int n, m;

vector <vector <int>> T(maxN), G (maxN);
bool vis[maxN];
char col [maxN];
int dl [maxN];
set <int> sum [maxN];
vector <int> v [maxN];

ll ansA, ansB;

ll pot (ll a, ll b, ll res=1) {
	
	while (b) {
		
		if (b&1) (res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

void edges_ver (int a, int b) {
	
	if (col[a] == '0' || col[b] == '0') return;
	if (col[a] == '1' && col[b] == '1') {
		G[a].push_back(b);
		G[b].push_back(a);
		return;
	}
	if (col[a] == '4' && col[b] == '4') {
		
		edges_ver(T[a][2], T[b][0]);
		edges_ver(T[a][3], T[b][1]);
		return;
	}
	if (col[a] == '4') {
		
		edges_ver(T[a][2], b);
		edges_ver(T[a][3], b);
		return;
	}
	if (col[b] == '4') {
		
		edges_ver(a, T[b][0]);
		edges_ver(a, T[b][1]);
		return;
	}
}

void edges_hor (int a, int b) {
	
	if (col[a] == '0' || col[b] == '0') return;
	if (col[a] == '1' && col[b] == '1') {
		G[a].push_back(b);
		G[b].push_back(a);
		return;
	}
	if (col[a] == '4' && col[b] == '4') {
		
		edges_hor(T[a][1], T[b][0]);
		edges_hor(T[a][3], T[b][2]);
		return;
	}
	if (col[a] == '4') {
		
		edges_hor(T[a][1], b);
		edges_hor(T[a][3], b);
		return;
	}
	if (col[b] == '4') {
		
		edges_hor(a, T[b][0]);
		edges_hor(a, T[b][2]);
		return;
	}
}

void edges_in (int x) {
	
	if (col[x] != '4') return;
	
	for (int i = 0; i < 4; i++)
		edges_in(T[x][i]);
	
	edges_hor(T[x][0], T[x][1]);
	edges_hor(T[x][2], T[x][3]);
	edges_ver(T[x][0], T[x][2]);
	edges_ver(T[x][1], T[x][3]);
}

int wczytaj (int p) {
	
	char ch; cin >> ch;
	
	int id = ++n;
	col[id] = ch;
	dl[id] = p;
	
	if (ch == '4')
		for (int i = 1; i <= 4; i++)
			T[id].push_back(wczytaj(p-1));
			
	return id;
}

void add (int x, int i) {
	
	if (sum[i].count(x)) {
		sum[i].erase(x);
		add(x+1, i);
	} else
		sum[i].insert(x);
}

void dfs (int rep, int x) {
	
	vis [x] = 1;
	
	add(2*dl[x], rep);
	
	for (int u : G[x])
		if (!vis[u])
			dfs(rep, u);
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m;
	
	wczytaj(m);
	edges_in(1);

	for (int i = 1; i <= n; i++)
		if (col[i] == '1' && !vis[i]) {
			
			ansA++;
			dfs(i, i);
			
			for (int s : sum[i])
				v[i].push_back(s);
				
			if (!v[i].empty())
				reverse(v[i].begin(), v[i].end());
		}
		
	int maxID = 1;
	for (int i = 1; i <= n; i++)
		if (v[maxID] < v[i])
			maxID = i;
			
	for (int p : v[maxID])
		(ansB += pot(2, p)) %= mod;

	
	cout << ansA << '\n' << ansB;
	
	return 0;
}
