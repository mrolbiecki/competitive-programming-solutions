#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 5e5+2, mod = 1e9+7, maxA = 1e6+2;

int n;
int A[maxN];

ll dp[maxN];
ll x[maxA];

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
		
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		(dp[i] = dp[i-1]*2 - x[A[i]] + mod) %= mod;
		x[A[i]] = dp[i-1];
	}
	
	cout << dp[n];
}
