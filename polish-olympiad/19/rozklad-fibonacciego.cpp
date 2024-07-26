//2023-01-06
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while (tt--) {
		
		vector <long long> F {0, 1};
		
		int r = 0, s = 1;
		long long k;
		cin >> k;
		
		while (F[s] <= k) {
			F.push_back(F[s] + F[s-1]);
			s++;
		}
		
		while (k) {
			
			while (F[s-1] > k) s--;
			
			if (k - F[s-1] < F[s] - k)
				k -= F[s-1];
			else
				k = F[s] - k;
			
			r++;
		}
		
		cout << r << '\n';
	}
	
	return 0;
}
