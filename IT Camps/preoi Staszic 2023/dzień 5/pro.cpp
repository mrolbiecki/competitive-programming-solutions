#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2002;

int n, ans;
pair <int, int> p[maxN];

map <pair<pair<int, int>, ll>, int> mid;

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].first >> p[i].second;

	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++) {
			
			int xm = (p[i].first + p[j].first)/2;
			int ym = (p[i].second + p[j].second)/2;
			ll odl = 1ll*(p[i].first-p[j].first)*(p[i].first-p[j].first);
			odl += 1ll*(p[i].second-p[j].second)*(p[i].second-p[j].second);
			mid[{{xm, ym}, odl}]++;
		}
	
	for (auto m : mid)
		ans += m.second*(m.second-1)/2;
		
	cout << ans;
}
