//2023-01-08
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/jgCcEjQu3kdpM4BmxA6GujfX/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5+2;

vector <vector<int>> T (maxN);
int dp [maxN];
int n, k;

void dfs (int x, int p) {
	
	dp[x] = 0;
	
	for (int u : T[x])
		if (u != p) 
			dfs(u, x);
			
	for (int u : T[x])
		if (u != p)
			dp[x] += dp[u] + 1;
			
	dp[x] = max(0, dp[x] - k);
}


bool check (int x) {
	
	k = x;
	dfs(1, -1);
	return dp[1] == 0;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	
	int l = 0, r = n-1, s;
	
	while (l < r) {
		
		s = (l + r)/2;
		
		if (check(s))
			r = s;
		else
			l = s+1;
	}
	
	cout << r;
	
	return 0;
}
