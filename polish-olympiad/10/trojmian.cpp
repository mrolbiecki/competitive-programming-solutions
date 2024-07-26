//2023-01-24
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN = 1003, mod = 3;
const int maxT = 34;

int q;
int dp[maxN][2*maxN];
ll t[maxT], s[maxT];

int x (int d, ll n, ll k);

int y (int d, ll n, ll k) {
	
	if (n < maxN) return dp[n][k];
	
	if (n < 2*t[d]) return y(d-1, n-t[d], k);
	if (n <= 2*t[d]+s[d-1]) {
		
		if (k < (n-2*t[d])*2+1) return x(d-1, n-2*t[d], k);
		if (k < t[d]) return 0;
		return 2*x(d-1, n-2*t[d], k-t[d]) % mod;
	}
	if (k < (n-2*t[d]-s[d-1])*2) return y(d-1, n-2*t[d], k);
	if (k < t[d]) return 0;
	if (k < (n-2*t[d])*2+1) return y(d-1, n-2*t[d], k-t[d]);
	if (k < 2*t[d]) return 0;
	return y(d-1, n-2*t[d], k-2*t[d]);
}

int x (int d, ll n, ll k) {
	
	if (d < 0) return 0;
	
	if (n < maxN) return dp[n][k];
	
	if (n <= s[d-1]) return x(d-1, n, k);
	if (n < t[d]) {
		
		if (k < (n-s[d-1])*2) return y(d-1, n, k);
		if (k < t[d]) return 0;
		return y(d-1, n, 2*n-k);
	}
	if (k < (n-t[d])*2+1) return x(d-1, n-t[d], k);
	if (k < t[d]) return 0;
	if (k < (n-s[d-1])*2) return x(d-1, n-t[d], k-t[d]);
	if (k < 2*t[d]) return 0;
	return x(d-1, n-t[d], k-2*t[d]);
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	t[0] = 1; s[0] = 1;
	for (int i = 1; i < maxT; i++)
		t[i] = t[i-1] * 3;
	
	for (int i = 1; i < maxT; i++)
		s[i] = s[i-1] + t[i];
	
	for (int i = 0; i < maxN; i++)
		dp[i][0] = 1;
	dp[0][0] = 1;
	
	for (int i = 1; i < maxN; i++) {
		
		(dp[i][1] = dp[i-1][1] + dp[i-1][0]) %= mod;
		
		for (int j = 2; j < 2*maxN; j++)		
			(dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2]) %= mod;
	}
	
	cin >> q;
	for (int i = 1; i <= q; i++) {
		
		ll n, k; cin >> n >> k;
		if (n < maxN) cout << dp[n][k] << '\n';
		else cout << x(maxT, n, k) << '\n';
	}
	
	return 0;
}

/*
1
1000000000000000 2000000000000000
*/
