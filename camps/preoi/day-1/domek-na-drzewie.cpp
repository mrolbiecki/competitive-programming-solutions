#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2e4+2, base = 1<<17, maxM = 2e9+1;

ll n, m;
int A[maxN], ans[maxN];
vector <int> qs [maxN];
pair <int, ll> Q [maxN];
vector <int> T [maxN];

int stree [base*2];

void add (int i, int val) {

	i += base;
	stree[i] += val; i /= 2;
	
	while (i)
		stree[i] = stree[i*2] + stree[i*2+1], i /= 2;
}

int sum (int l, int r) {

	int L = l+base-1, R = r+base+1, res=0;
	
	while (L/2 != R/2) {
		
		if (L % 2 == 0) res += stree[L+1];
		if (R % 2 == 1) res += stree[R-1];
		L /= 2; R /= 2;
	}
	
	return res;
}

bool check (ll s, int t, ll k) {

	ll cnt = 2*k+s-1;
	cnt /= s;
	cnt += s;
	cnt /= (s+1);
	
	return sum(cnt, maxN) >= t;
}

int querry (int t, ll k) {

	ll lo = 1, hi = maxM, mid;
	
	while (lo < hi) {
	
		mid = (lo+hi)/2;
		
		if (check(mid, t, k))
			hi = mid;
		else
			lo = mid+1;
	}
	
	return (hi != maxM ? hi : -1);
}

void dfs (int v, int p) {

	int cnt = A[v];
	
	for (int u : T[v])
		cnt += A[u];
		
	add (cnt, 1);
	
	for (int i : qs[v])
		ans[i] = querry (Q[i].first, Q[i].second);
	
	for (int u : T[v])
		if (u != p)
			dfs(u, v);
	
	add (cnt, -1);
}

int main () {

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	for (int i = 2; i <= n; i++) {
	
		int u, v; cin >> u >> v;
		T[v].push_back(u);
		T[u].push_back(v);
	}	
	
	int q; cin >> q;
	
	for (int i = 1; i <= q; i++) {
		int x, t; ll k; cin >> x >> t >> k;
		qs[x].push_back(i);
		Q[i] = {t, k};
	}
	
	dfs(1, -1);
	
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
}
