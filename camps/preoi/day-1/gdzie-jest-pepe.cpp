//2023-01-30
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+2;

int n, m, ans;

struct seg {
	
	int x1, y1, x2, y2;
};

struct point {
	
	int x, y;
	int h;
	int type; //2 - pion, 1 - x open, 3 - x close
};

vector <seg> S;

bool comp (point A, point B) {

	if (A.x == B.x)
		return A.type < B.type;
	return A.x < B.x;
}

bool check (int x) {

	vector <point> V;
	
	for (seg s : S) {
	
		if (s.y2 - s.y1 >= 2*x)
			V.push_back({s.x1, s.y1+x, s.y2-s.y1-2*x,  2});
	
		if (s.x2 - s.x1 >= 2*x) {
			V.push_back({s.x1+x, s.y1, 0, 1});
			V.push_back({s.x2-x, s.y1, 0, 3});	
		}
	}
	
	sort(V.begin(), V.end(), comp);
	
	multiset <int> broom;
	
	for (point p : V) {
	
		if (p.type == 1)
			broom.insert(p.y);
		if (p.type == 3)
			broom.erase(broom.find(p.y));
			
		if (p.type == 2) {
			
			auto it = broom.lower_bound(p.y);
			
			if (it != broom.end() && (*it) <= p.y + p.h)
				return true;
		}
	}
	
	return false;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		S.push_back({x1, y, x2, y});
	}
	for (int i = 1; i <= m; i++) {
		
		int y1, y2, x;
		cin >> y1 >> y2 >> x;
		S.push_back({x, y1, x, y2});
	}
	
	int lo = 0, hi = 1e9+1, mid;
	
	while (lo < hi) {
	
		mid = (lo + hi)/2;
		
		if (!check(mid))
			hi = mid;
		else
			lo = mid+1;
	}
		
	cout << hi-1;
			
	return 0;
}
