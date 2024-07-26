//2022-11-17
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/aKKSmtjWTtDOEHDqnmQ3-eAA/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e4+10;

int n, m;

vector <vector<int>> G (maxN), Gc (maxN), T (maxN);
vector <int> ans (maxN, -1);

vector <int> postord;
bool odw[maxN];
int SS[maxN], ss_size[maxN];
int ss = 0;

void topo_sort (int x) {
	
	odw[x] = 1;
	for (int u : G[x])
		if (!odw[u])
			topo_sort(u);
	
	postord.push_back(x);
}

void dfs_ss (int x) {
	
	odw[x] = 1;
	for (int u : Gc[x])	
		if (!odw[u] && !SS[u]) {
			SS[u] = SS[x];
			ss_size[ SS[x] ]++;
			dfs_ss(u);
		}
}

void find_ss () {
	
	fill(odw, odw + maxN, 0);
	
	for (int i = 1; i <= n; i++)
		if (!odw[i])
			topo_sort(i);
	
	reverse(postord.begin(), postord.end());
	
	for (int i = 1; i <= n; i++)
		for (int u : G[i])
			Gc[u].push_back(i);			
	
	fill(odw, odw + maxN, 0);
	
	for (int i = 0; i < n; i++) {
		
		int p = postord[i];
		
		if (!odw[p]) {
			SS[p] = ++ss;
			ss_size[ SS[p] ] = 1;
			dfs_ss(p);
		}
	}
}

void dfs_tree (int x) {
	
	odw[x] = 1;
	for (int u : G[x]) {
		
		if (SS[x] != SS[u])
			T[ SS[x] ].push_back( SS[u] );
		
		if (!odw[u])
			dfs_tree(u);
	}
}

void build_tree () {
	
	fill(odw, odw + maxN, 0);
	
	for (int i = 1; i <= n; i++)
		if (!odw[i])
			dfs_tree(i);
}

int calc_ans (int x) {
	
	if (ans[x] != -1)
		return ans[x];
	
	ans[x] = ss_size[x];
	
	for (int u : T[x])
		ans[x] += calc_ans(u);
	
	return ans[x];
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	
	find_ss();
	build_tree();
	
	for (int i = 1; i <= n; i++) {
		
		if (ans[SS[i]] == -1)
			calc_ans(SS[i]);
			
		cout << ans[SS[i]]-1 << '\n';
	}
	
	return 0;
}
/*
4 5
1 2
2 1
2 3
3 4
4 3
*/ 
