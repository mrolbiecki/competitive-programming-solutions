//2023-01-20
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/ElDZtvfzCl9Sj2lC1sAKG0dU/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int alfa = 27, inf = 1e9;

int n, ans = -inf;
string s;

int sum [alfa][alfa], mi [alfa][alfa], mini[alfa][alfa];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	s = '#' + s;
	
	for (int i = 0; i < alfa; i++)
		for (int j = 0; j < alfa; j++)
			mini[i][j] = inf;
	
	for (int i = 1; i <= n; i++) {
		
		int x = s[i] - 'a';
		
		for (int j = 0; j < alfa; j++)
			sum[j][x]++;
		for (int j = 0; j < alfa; j++)
			sum[x][j]--;
			
		for (int j = 0; j < alfa; j++) {
			mini[x][j] = mi[x][j];
			mi[x][j] = min(mi[x][j], sum[x][j]);
		}
			
		for (int j = 0; j < alfa; j++) {			
			ans = max(ans, sum[x][j] - mini[x][j]);
			ans = max(ans, sum[j][x] - mini[j][x]);
		}
	}
	
	cout << ans;
	
	return 0;
}
