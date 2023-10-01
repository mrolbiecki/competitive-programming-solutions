//2022-11-24
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/GmAagCBetbskP0qiKlgVd-6A/site/?key=statement
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll Tsize = 1<<19;

struct node {
	
	ll val;
	ll add;
	ll r;
};

int n, m;
node D[2*Tsize];
pair <ll, ll> M[Tsize];

ll f (ll l, ll r, ll c=0) {return (l-1)*r*l/2 + c*l;}

//suma na przedziale
ll querry (ll id, ll lq, ll rq, ll L=0, ll R=Tsize-1) {
	
	if (lq > R || rq < L)
		return 0ll;
		
	if (lq <= L && rq >= R)
		return D[id].val + D[id].add;
	
	D[id].val += D[id].add;
	
	D[id*2].r += D[id].r;
	D[id*2+1].r += D[id].r;
	
	ll mid = (L + R)/2;
	
	ll x = R-L+1, l = mid-L+1, a;
	a = (D[id].add - f(x, D[id].r, 0))/x;
	
	ll add1 = 0;
	if (l > 0)
		add1 = f(l, D[id].r, a);
		
	D[2*id].add += add1;
	D[2*id+1].add += D[id].add - add1;
		
	D[id].add = D[id].r = 0;
	
	return querry (id*2, lq, rq, L, mid) + querry (id*2+1, lq, rq, mid+1, R);
}

//dodawanie na przedziale
void update (ll id, ll val, ll r, ll a, ll lq, ll rq, ll L=0, ll R=Tsize-1) {
	
	if (lq > R || rq < L)
		return;
		
	if (lq <= L && rq >= R) {
		D[id].add += val;
		D[id].r += r;
		return;
	}
	
	D[id].val += val;
		
	ll mid = (L + R)/2;
	
	ll l = max(min(mid, rq)-max(L, lq)+1, 0ll);
	
	ll val1 = 0;
	if (l > 0ll)
		val1 = f(l, r, a);
	
	update (id*2, val1, r, a, lq, rq, L, mid);
	update (id*2+1, val-val1, r, a+l*r, lq, rq, mid+1, R);
}


int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		
		char c;
		cin >> c;
		
		if (c == 'P') {
			
			ll x, s, a;
			cin >> x >> s >> a;
			M[x] = {s, a};
			
			ll l = min(s/a, x-1);
			ll r = min(s/a, n-x);
			ll a0 = s-l*a;
			
			update (1, f(r+1, -a, s), -a, s, x, x+r, 0, Tsize-1);
			update (1, f(l, a, a0), a, a0, x-l, x-1, 0, Tsize-1);
		}
		if (c == 'U') {
			
			ll x, s, a;
			cin >> x;
			s = M[x].first; a = M[x].second;
			
			ll l = min(s/a, x-1);
			ll r = min(s/a, n-x);
			ll a0 = s-l*a;
			
			update (1, -f(r+1, -a, s), a, -s, x, x+r, 0, Tsize-1);
			update (1, -f(l, a, a0), -a, -a0, x-l, x-1, 0, Tsize-1);
		}
		if (c == 'Z') {
			
			ll x1, x2;
			cin >> x1 >> x2;
			
			cout << querry (1, x1, x2, 0, Tsize-1)/(x2-x1+1) << '\n';
		}

	}
	
	return 0;
}
