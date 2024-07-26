//2024-05-20
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int main () {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int n, ans = 0; cin >> n;
	stack <int> S;
	for (int i = 0; i < n; i++) {
		int d; cin >> d >> d;
		while (!S.empty() && S.top() > d) S.pop();
		if (S.empty() || S.top() != d) {
			S.push(d);
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}
