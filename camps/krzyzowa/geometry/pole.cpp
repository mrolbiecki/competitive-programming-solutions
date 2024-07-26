//2023-01-18
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e5+2;

int n;
ll ans;
pair <ll, ll> points [maxN];

ll cross (pair <ll, ll> a, pair <ll, ll> b) {return a.first*b.second - b.first*a.second;}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> points[i].first >> points[i].second;
	
	for (int i = 1; i < n; i++)
		ans += cross(points[i], points[i+1]);
		
	ans += cross(points[n], points[1]);
		
	ans = abs(ans);
	
	cout << setprecision(1) << fixed << (long double)ans/2ll;
	
	return 0;
}
