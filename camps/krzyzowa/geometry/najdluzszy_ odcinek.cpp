//2023-01-27
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int maxN = 5e5+2;

struct point {
	
	ll x, y;
};

int n;
point points[maxN];
vector <point> hull;
point p0;
ld ans;

int sgn (ll x) {
	
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

ll cross (point A, point B, point C) {
	
	return A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y;
}

bool cw (point A, point B, point C) {
	
	return sgn(cross(A, B, C)) <= 0;
}

ll dist (point A, point B) {
	
	return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

bool comp (point A, point B) {
	
	int o = sgn(cross(p0, A, B));
	
	if (o == 0) 
		return dist(p0, A) < dist(p0, B);
		
	return o < 0;
}

void calc_hull () {
	
	p0 = points[0];
	for (int i = 1; i < n; i++)
		if (points[i].y < p0.y || (points[i].y == p0.y && points[i].x < p0.x))
			p0 = points[i];
			
	sort(points, points + n, comp);

	int i = n-1;
	while (i >= 0 && cross(p0, points[i], points[n-1]) == 0) i--;
	reverse(points+i+1, points+n);
	
	for (int i = 0; i < n; i++) {
		
		while ((int)hull.size() >= 2 && !cw(hull[hull.size()-2], hull.back(), points[i]))
			hull.pop_back();
		hull.push_back(points[i]);
	}
}


int it = 0;

void far (int i) {
	
	int l = (it == 0 ? hull.size()-1 : it-1);
	int r = (it == (int)hull.size() ? 0 : it+1);
	
	if (dist(hull[i], hull[it]) < dist(hull[i], hull[r]))
		it = r;
	else if (dist(hull[i], hull[it]) < dist(hull[i], hull[l]))
		it = l;
	else return;
	
	far(i);
}


int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		points[i] = {x, y};
	}
	
	calc_hull();
	
	for (int i = 0; i < (int)hull.size(); i++) {
		
		far (i);
		ans = max(ans, (ld)(sqrt((ld)dist(hull[i], hull[it]))));
	}
	
	cout << fixed << ans;
	
	return 0;
}
