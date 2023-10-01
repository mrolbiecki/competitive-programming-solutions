//2023-03-13
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/wrTmzO9-dzEbLtsRUCdMV2_W/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e6+2, L = 21;

int n, m;
int l[maxN], r[maxN];

int f;
int left (int v) {
		
	if (l[v]) return l[v];
	else return l[v] = ++f;
}
int right (int v) {
	
	if (r[v]) return r[v];
	else return r[v] = ++f;
}

int ID[maxN];

void dfs (int v, bool on, int wsk) {
		
	ID[v] = wsk;
	
	if (l[v]) dfs(l[v], on, (on ? left(wsk) : wsk));
	if (r[v]) dfs(r[v], 1, right(wsk));
}

int jump[L][maxN];
int lvl[maxN], in[maxN], out[maxN], timer;

void dfs2 (int v) {
	
	in[v] = ++timer;
	
	if (l[v]) {
		lvl[ l[v] ] = lvl[v]+1;
		jump[0][ l[v] ] = v;
		dfs2(l[v]);
	}
	if (r[v]) {
		lvl[ r[v] ] = lvl[v]+1;
		jump[0][ r[v] ] = v;
		dfs2(r[v]);
	}
	
	out[v] = ++timer;
}

bool isanc (int a, int b) {return in[a] <= in[b] && out[a] >= out[b];}

int lca (int a, int b) {
	
	if (a == b) return a;
	if (lvl[a] < lvl[b]) swap(a, b);
	
	for (int i = L-1; i >= 0; i--)
		if (!isanc(jump[i][a], b))
			a = jump[i][a];
			
	return jump[0][a];
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n; f = n;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
		
	for (int i = 1; i <= n; i++)
		ID[i] = i;
		
	dfs(1, 0, 1);
	dfs2(1);
/*
	for (int i = 1; i <= n; i++)
		cout << ID[i] << ' ';
	cout << endl;
*/
	jump[0][1] = 1;
	for (int i = 1; i <= f; i++) {
		if (l[i]) jump[0][l[i]] = i;
		if (r[i]) jump[0][r[i]] = i;
	}
	
	for (int lg = 1; lg < L; lg++)
		for (int i = 1; i <= f; i++)
			jump[lg][i] = jump[lg-1][ jump[lg-1][i] ];

	cin >> m;
	for (int i = 1; i <= m; i++) {
		
		int a, b; cin >> a >> b; 
		if (ID[a] == ID[b]) {
			cout << "TAK\n";
			continue;
		}
		int c = lca(ID[a], ID[b]);
		
		if (lvl[ID[a]] != lvl[ID[b]]) cout << (lvl[ID[a]] > lvl[ID[b]] ? "TAK\n" : "NIE\n");
		else cout << (isanc(l[c], ID[b]) ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}
