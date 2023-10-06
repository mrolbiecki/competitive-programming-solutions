//2023-01-17
//author: Marcin Rolbiecki
//a segment tree with polynomials in its nodes
//the problem statement is called "blokada_statement.pdf"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN = 3e5+2, mod = 1e9+7, maxT = 1<<19;

int n, q;
int val [maxN];

struct node {
	
	ll l, lx;
	ll m, mx;
};

node T [2*maxT];

node merge (node &a, node &b) {
	
	node res;
	
	(res.l = (a.l * b.l) % mod + (a.lx * b.m) % mod) %= mod;
	(res.lx = (a.l * b.lx) % mod + (a.lx * b.mx) % mod) %= mod;
	(res.m = (a.m * b.l) % mod + (a.mx * b.m) % mod) %= mod;
	(res.mx = (a.m * b.lx) % mod + (a.mx * b.mx) % mod) %= mod;
	
	return res;
}

void init () {
	
	node t = {0, 0, 0, 0};
	
	for (int i = 0; i < maxT; i++)
		T[maxT + i] = t;
		
	for (int i = 1; i <= n; i++)
		T[maxT + i] = {val[i], 1, 1, 0};
		
	for (int i = maxT-1; i >= 1; i--)
		T[i] = merge (T[2*i], T[2*i+1]);
}

pair <ll, ll> querry (int l, int r) {
	
	int L = maxT+l-1, R = maxT+r+1;
	
	deque <node> Lseg;
	deque <node> Rseg;
	
	deque <node> seg;
	
	while (L/2 != R/2) {
		
		if (L % 2 == 0) Lseg.push_back(T[L + 1]);
		if (R % 2 == 1) Rseg.push_front(T[R - 1]);
		
		L/=2; R/=2;
	}
	
	for (auto ls : Lseg)
		seg.push_back(ls);
	for (auto rs : Rseg)
		seg.push_back(rs);
	
	node res = seg.front(); seg.pop_front();
	
	while (!seg.empty()) {
		
		res = merge(res, seg.front());
		seg.pop_front();
	}
	
	pair <ll, ll> ans = {res.l, res.m};
	
	return ans;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> val[i];
		
	init ();
		
	for (int i = 1; i <= q; i++) {
		
		int l, r;
		cin >> l >> r;
		
		pair <ll, ll> Q = querry (l, r);
		
		cout << Q.first << ' ' << Q.second << '\n';
	}

	return 0;
}
