//https://szkopul.edu.pl/problemset/problem/Orc2Z7ti1xLaUUQDT1a6RGR5/site/?key=statement
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 15002;
const int inf = 1e6;

int n, m;
int a[maxN], b[maxN];

vector <vector <int>> dp (2, vector <int> (maxN));
int p [maxN], pre[maxN];

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
		
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= m; i++)
		cin >> b[i];
		
	map <int, int> pos;
	for (int i = 1; i <= m; i++) {
	
		p[i] = -inf;
	
		if (!pos.count(b[i]))
			pre[i] = 0;
		else
			pre[i] = pos[ b[i] ];
			
		pos[ b[i] ] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
		
			if (a[i] == b[j] && pre[j])
				dp[1][j] = p[ pre[j] ] + 2;

			dp[1][j] = max({dp[1][j], dp[1][j-1], dp[0][j]});
		}
		
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j])
				p[j] = dp[0][j-1];

		dp[0] = dp[1];
	}
	
	cout << dp[1][m];
}
