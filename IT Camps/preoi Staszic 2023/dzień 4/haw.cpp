#include <bits/stdc++.h>
#define int long long
using namespace std;

auto main () -> int32_t {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while (tt--) {
	
		int A, B, n;
		cin >> A >> B >> n;
		
		int minx = A, miny = B, maxx = 0, maxy = 0;
		
		for (int i = 1; i <= n; i++) {
			int x, y; cin >> x >> y;
			
			minx = min(minx, x);
			miny = min(miny, y);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		}
		
		int a = minx-1, b = miny-1, c = A-maxx, d = B-maxy;
		cout << (a^b^c^d ? "Bajtek" : "Bitek") << '\n';
	}
}
