//2023-01-19
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point {
	
	ll x, y;
};

ll cross (point A, point B, point C) {
	
	return A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y;
}

struct segment {
	
	point a, b;
};

int sgn (ll x) {
	
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

bool colinear (ll a, ll b, ll c, ll d) {
	
	if (a > b) swap (a, b);
	if (c > d) swap (c, d);
	
	return max(a, c) <= min(b, d);
}

bool intersect (segment A, segment B) {
	
	if (cross(A.a, A.b, B.a) == 0 && cross(A.a, A.b, B.b) == 0)
		return (colinear(A.a.x, A.b.x, B.a.x, B.b.x) &&
				colinear(A.a.y, A.b.y, B.a.y, B.b.y));
				
	return  sgn(cross(A.a, A.b, B.a)) != sgn(cross(A.a, A.b, B.b)) &&
			sgn(cross(B.a, B.b, A.a)) != sgn(cross(B.a, B.b, A.b));
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	segment A, B;
	
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	A = {{ax, ay}, {bx, by}};
	cin >> ax >> ay >> bx >> by;
	B = {{ax, ay}, {bx, by}};
	
	cout << (intersect(A, B) ? "TAK" : "NIE");
	
	return 0;
}
