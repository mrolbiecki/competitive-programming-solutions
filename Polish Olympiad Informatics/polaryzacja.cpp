//2022-09-30
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/vG3DC9--8cjl4sPNwjBj9ag6/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 25e4+10;

vector <vector <int>> T (maxN);
long long SUB[maxN];
long long PAIRS[maxN];
int ile[maxN];
bool DP[maxN];

int n, cent;
long long ans;

void DFS (int x) {
	
	SUB[x] = 1;
	
	for (int child : T[x]) 
		if (SUB[child] == 0) {
			
			DFS(child);
			SUB[x] += SUB[child];
		}
}

int find_centroid (int x) {
	
	for (int child : T[x])
		if (SUB[child]*2 > n) {
			
			SUB[x] -= SUB[child];
			SUB[child] = n;
			
			return find_centroid (child);
		}
	return x;
}

long long backpack () {
	
	DP[0] = 1;
	
	for (int i : T[cent])
		ile[ SUB[i] ]++;
		
	for (int i = 1; i*2 <= n; i++)
		while (ile[i] >= 3) {
			ile[i] -= 2;
			ile[i*2]++;
		}
		
	for (int i = 0; i <= n; i++)
		for (int l = 0; l < ile[i]; l++)
			for (int j = n-i; j >= 0; j--)
				if (DP[j])
					DP[j + i] = 1;
	
	for (int i = (n-1)/2; i >= 0; i--)
		if (DP[i])
			return (long long)(i) * (n-i-1);
			
	return 0;
} 

void DFS2 (int x, int p) {
	
	for (int child : T[x])
		if (child != p) {
			
			DFS2(child, x);
			PAIRS[x] += PAIRS[child] + SUB[child];
		}
}


int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		
		int u, v;
		cin >> u >> v;
		
		T[u].push_back(v);
		T[v].push_back(u);
	}
	
	DFS(1);
	cent = find_centroid (1);
	ans = backpack ();
	
	DFS2(cent, cent);
	for (int child : T[cent])
		ans += PAIRS[child];
		
	ans += (n-1);
	
	cout << n-1 << " " << ans;	
	
	return 0;
}
