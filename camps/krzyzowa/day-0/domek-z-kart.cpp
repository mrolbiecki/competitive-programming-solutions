//2023-01-16
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = (1<<17)+10, maxK = 22;

int n, k, N;
long long val[maxN];
long long dp[maxK][maxN];
long long ans;

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	N = 1<<n;
	k /= 2;
	
	for (int i = 1; i < N; i++) {
		
		int a, b; cin >> a >> b;
		val[i] = a+b;
	}
	
	for (int x = N-1; x >= 1; x--) {
		
		dp[1][x] = val[x];
		
		for (int i = 2; i <= k; i++)
			dp[i][x] = -1e15;
		
		for (int i = 0; i <= k-1; i++)
			for (int j = 0; j <= k-i-1; j++)
				dp[i+j+1][x] = max(dp[i+j+1][x], dp[i][x*2] + dp[j][x*2+1] + val[x]);
	}	

	for (int i = 0; i <= k; i++)
		ans = max(ans, dp[i][1]);
		
	cout << ans;
	
	return 0;
}
