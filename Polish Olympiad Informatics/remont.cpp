//2023-03-15
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/xNjwUvwdHQoQTFBrmyG8vD1O/site/?key=statement
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxN = 15e4+2;
int neg = maxN, s = 2*maxN;

int n, k;
int A[maxN];

vector <int> G [4*maxN], Gp [4*maxN];
vector <int> order;
bool vis[4*maxN];
int id = 1;
int scc[4*maxN];

void dfs (int v) {
		
	vis[v] = 1;
	for (int u : G[v])
		if (!vis[u])
			dfs(u);
	order.push_back(v);
}

void dfs2 (int v) {
	
	scc[v] = id;
	for (int u : Gp[v])
		if (!scc[u])
			dfs2(u);
}


bool sat () {
	
	for (int i = 1; i < 4*maxN; i++)
		if (!vis[i])
			dfs(i);
	
	reverse (order.begin(), order.end());
	
	for (auto o : order)
		if (!scc[o]) {
			++id;
			dfs2(o);
		}
		
	for (int i = 1; i <= n; i++)
		if (scc[i] == scc[neg + i])
			return false;
	
	return true;
}

void add (int a, int b) {
	
	G[neg + a].pb(b);
	G[neg + b].pb(a);
	
	Gp[b].pb(neg + a);
	Gp[a].pb(neg + b);
}

void extra () {
	
	map <pair<int, int>, int> M;
	
	for (int i = n-1; i >= 0; i--) {
		
		G[s + i].pb(neg + i);
		Gp[neg + i].pb(s + i);
		
		G[i].pb(neg + s + i);
		Gp[neg + s + i].pb(i);
		
		if(M.count({A[i], A[i+1]})) {
			
			int j = M[{A[i], A[i+1]}];
			
			G[s + i].pb(s + j);
			Gp[s + j].pb(s + i);
			
			G[neg + s + j].pb(neg + s + i);
			Gp[neg + s + i].pb(neg + s + j);
			
			G[i].pb(s + j);
			Gp[s + j].pb(i);
			
			G[neg + s + j].pb(neg + i);
			Gp[neg + i].pb(neg + s + j);
		}
		
		M[{A[i], A[i+1]}] = i;
	}
}

void clean () {
	
	fill(vis, vis+4*maxN, 0);
	fill(scc, scc+4*maxN, 0);
	order.clear();
	
	for (int i = 1; i < 4*maxN; i++)
		G[i].clear(), Gp[i].clear();
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt; cin >> tt;
	
	while (tt--) {
		
		cin >> n >> k;
		
		for (int i = 1; i <= n; i++)
			cin >> A[i];
			
		add(1, 1); add(n-1, n-1);
			
		for (int i = 1; i < n-1; i++)
			add(i, i+1);
			
		extra();
		
		cout << (sat() ? "TAK" : "NIE") << '\n';
		
		clean();
	}
	
	return 0;
}
