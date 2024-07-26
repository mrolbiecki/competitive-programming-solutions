//2023-01-25
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e5+2;

struct point {
	
	ll x, y;
};

int n, q;
point polygon[maxN];

int sgn (ll x) {
	
	if (x < 0ll) return -1;
	if (x > 0ll) return 1;
	return 0;
}

ll cross (point A, point B, point C) {
	
	return A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y;
}

bool isInTriangle (point p, point A, point B, point C) {
	
	return abs(cross(A, B, C)) == 
			abs(cross(A, B, p)) + abs(cross(B, C, p)) + abs(cross(C, A, p));
}

bool check (int x, point p) { //największy taki punkt, że ma p po tej samej stronie co większego sąsiada
	
	return (sgn(cross(polygon[0], polygon[x], p)) == sgn(cross(polygon[0], polygon[x], polygon[x+1])));
}

bool isInPolygon (point p){
	
	if (isInTriangle(p, polygon[0], polygon[1], polygon[2]) ||
		isInTriangle(p, polygon[0], polygon[n-1], polygon[n-2]))
		return true;
	
	if (sgn(cross(polygon[0], polygon[1], p)) != sgn(cross(polygon[0], polygon[1], polygon[n-1])) ||
		sgn(cross(polygon[0], polygon[n-1], p)) != sgn(cross(polygon[0], polygon[n-1], polygon[1])))
		return false;
	
	int lo = 1, hi = n-1, mid;
	
	while (lo < hi) {
		
		mid = (lo + hi)/2;
		
		if (!check(mid, p))
			hi = mid;
		else
			lo = mid+1;
	}
	
	return isInTriangle(p, polygon[0], polygon[hi-1], polygon[hi]);
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> polygon[i].x >> polygon[i].y;
		
	polygon[n] = polygon[0];
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		
		point p;
		cin >> p.x >> p.y;
		cout << ( isInPolygon(p) ? "TAK" : "NIE") << '\n';
	}
	
	return 0;
}
