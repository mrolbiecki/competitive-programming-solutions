//2023-01-07
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+2, T = 1<<19;

int n, m;
int p[maxN];
pair <int, int> D[2*T];
map <pair<int, int>, int> cnt;
set <pair<int, int>> s;
//pozycja, element
pair <int, int> qs [maxN];
int cand[maxN];
int occ[maxN];

pair <int, int> merge (pair <int, int> a, pair<int, int> b) {
	
	pair <int, int> res;
	
	if (a.first == b.first)
		res = {a.first, a.second + b.second};
	else if (a.second > b.second)
		res = {a.first, a.second - b.second};
	else if (b.second > a.second)
		res = {b.first, b.second - a.second};
		
	return res;
}

void init () {
	
	for (int i = T + 1; i <= T + n; i++)
		D[i] = {p[i-T], 1};
		
	for (int i = T-1; i >= 1; i--)
		D[i] = merge(D[2*i], D[2*i+1]);
}

int querry (int l, int r) {
	
	int L = l+T-1;
	int R = r+T+1;
	pair <int, int> res;
	
	while (L/2 != R/2) {
		
		if (L % 2 == 0)
			res = merge(res, D[L+1]);
		if (R % 2 == 1)
			res = merge(res, D[R-1]);
			
		L /= 2, R /= 2;
	}
	
	return res.first;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
		
	init ();
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		qs[i] = {a, b};
		
		cand[i] = querry (a, b);
		
		if (cand[i]) {
			s.insert({a-1, cand[i]});
			s.insert({b, cand[i]});
		}
	}
	
	for (int i = 0; i <= n; i++) {
		
		if (p[i])
			occ[p[i]]++;
			
		while (!s.empty() && (*s.begin()).first == i) {
			
			//cout << (*s.begin()).first << ' ' << (*s.begin()).second << ' ' << occ[ (*s.begin()).second ] << endl;
			
			cnt[ *s.begin() ] = occ[ (*s.begin()).second ];
			s.erase( s.begin() );
		}
	}
	
	for (int i = 0; i < m; i++)
		if (cand[i] && cnt[{qs[i].second, cand[i]}] - cnt[{qs[i].first-1, cand[i]}] >= (qs[i].second - qs[i].first + 1)/2 + 1)
			cout << cand[i] << '\n';
		else
			cout << 0 << '\n';
	
	return 0;
}
