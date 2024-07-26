#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2, mod = 1e9+7;

int n, k;
string sz;

int pref[maxN], dp[maxN];
vector <int> words;

void kmp () {

	int p = 0;
	for (int i = 2; i <= n; i++) {
	
		while (p && sz[p+1] != sz[i])
			p = pref[p];
			
		if (sz[p+1] == sz[i]) p++;
		pref[i] = p;
	}
}

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> sz;
	sz = "#" + sz;
	
	kmp();
	
	int p = n;
	while (p) {
		p = pref[p];
		words.push_back(n-p);
	}

	for (int w : words)
		dp[w] = 1;
	dp[0] = 1;
	
	for (int i = n+1; i <= k-n; i++)
		for (int w : words)
			(dp[i] += dp[i-w]) %= mod;

	cout << dp[k-n];
}
