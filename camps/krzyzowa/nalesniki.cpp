//2023-01-20
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;

bool checkCase2 (ll a) {
	
	int two = 0;
	
	while (a && a % 2 == 0)
		a /= 2, two++;
	while (a && a % 3 == 0)
		a /= 3;
		
	return (two <= 1 && a == 1);
}

int q (int n, int k) {
	
	if (n == 0 && k == 0) return 1;
	
	if ((n % 3 == 0 && k % 3) || k < 0) return 0;
		
	if (n % 3 == 1 || (n % 3 == 0 && k % 3 == 0))
		return q(n/3, k/3);
		
	return (q(n-1, k) + q(n-1, k-1) + q(n-1, k-2)) % 3;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int Q; cin >> Q;
	for (int i = 1; i <= Q; i++) {
		
		ll a, b;
		cin >> a >> b;
		
		if (checkCase2(a)) {
			
			if (a % 2 == 1) {
				if (b == 0 || b == a || b == 2*a)
					cout << 1;
				else cout << 0;
			}
			if (a % 2 == 0) {
				
				if (b == 0 || b == 2*a) cout << 1;
				else if (b == a/2 || b == a/2+a) cout << 2;
				else cout << 0;
			}
			cout << '\n';
		}
		else
			cout << q(a, b) << '\n';
	}
	
	return 0;
}
