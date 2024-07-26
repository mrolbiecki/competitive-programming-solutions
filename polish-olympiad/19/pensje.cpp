//2024-05-20
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2;

vector <int> G[maxN];
int kto[maxN], ile[maxN], pensja[maxN];
int czyWolny[maxN], nextWolny[maxN];
int n, dyrektor;

void dfs (int v, int maxi) {
	kto[maxi] = v;
	ile[maxi]++;
	
	for (int u : G[v]) {
		if (pensja[u]) dfs(u, pensja[u]);
		else dfs(u, nextWolny[maxi-1]);
	}
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		czyWolny[i] = 1;
	
	for (int i = 1; i <= n; i++) {
		int parent;
		cin >> parent >> pensja[i];
		if (parent == i)
			dyrektor = parent;
		else
			G[parent].push_back(i);
			
		if (pensja[i])
			czyWolny[ pensja[i]  ] = 0;
	}
	
	
	for (int i = 1; i <= n; i++)
		if (czyWolny[i])
			nextWolny[i] = i;
		else
			nextWolny[i] = nextWolny[i-1];
			
	pensja[dyrektor] = n;
	dfs(dyrektor, pensja[dyrektor]);
	
	int suma = 0;
	for (int i = 1; i <= n; i++) {
		suma += ile[i];
		if (ile[i] == 1 && suma == i)
			pensja[ kto[i] ] = i;
	}
	
	for (int i = 1; i <= n; i++)
		cout << pensja[i] << '\n';

	
	return 0;
}