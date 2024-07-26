//2023-01-06
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+2;

pair <int, int> wyk [maxN];
//koniec - poczatek
int dp[maxN];

int best (int i) {
	
	int l = 0, r = i-1, s;
	while (l < r) {
		
		s = (l + r + 1)/2;
		
		if (wyk[s].first <= wyk[i].second)
			l = s;
		else
			r = s-1;
	}
	return r;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wyk[i].second >> wyk[i].first;
		
	sort (wyk, wyk + n + 1);
		
	for (int i = 1; i <= n; i++)
		dp[i] = max(dp[i-1], dp[ best(i) ] + wyk[i].first - wyk[i].second);
		
	cout << dp[n];

	return 0;
}
