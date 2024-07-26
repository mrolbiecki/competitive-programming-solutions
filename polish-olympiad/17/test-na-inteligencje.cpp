//2023-01-13
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxW = 1e6+2;;

int m, n;
set <int> pos [maxW];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		pos[a].insert(i);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		int l, p = 0; cin >> l;
		bool ok = 1;
		
		for (int j = 0; j < l; j++) {
			
			int b; cin >> b;
			
			auto it = pos[b].upper_bound(p);
			
			if (it == pos[b].end())
				ok = 0;
			else
				p = *it;
		}
		
		cout << (ok ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}
