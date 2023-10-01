//2023-01-18
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2e5+2, base = 1<<19;

int n, m, k, q;
vector <vector <int>> TA (maxN), TB (maxN);

int inA[maxN], inB[maxN], outA[maxN], outB[maxN];
int timeA, timeB;
ll ans[maxN];

ll tree [2*base];

struct point {
	
	int x, y;
	int h=0; //w gore
	int typ; //1 otwarcie, 2 zapytanie 3 zamknięcie
	ll val; //wartosc prostokata
};

vector <point> V;

void update (int l, int r, ll val) {
	
	int L = base + l - 1, R = base + r + 1;
	
	while (L/2 != R/2) {
		
		if (L % 2 == 0) tree[L+1] += val;
		if (R % 2 == 1) tree[R-1] += val;
		
		L /= 2; R /= 2;
	}
}

ll querry (int x) {

	ll res = 0;
	x += base;
	
	while (x) {
		
		res += tree[x];
		x /= 2;
	}
	return res;
}

bool comp (point a, point b) {
	
	if (a.x == b.x) {
		if (a.y == b.y)
			return a.typ < b.typ;
		return a.y < b.y;
	}
	return a.x < b.x;
}

void dfsA (int x) {
	
	inA[x] = ++timeA;
	for (int u : TA[x]) dfsA(u);
	outA[x] = ++timeA;
}

void dfsB (int x) {
	
	inB[x] = ++timeB;
	for (int u : TB[x]) dfsB(u);
	outB[x] = ++timeB;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		TA[a].push_back(i);
	}
	cin >> m;
	for (int i = 2; i <= m; i++) {
		int b; cin >> b;
		TB[b].push_back(i);
	}
	
	dfsA(1); dfsB(1);
	
	cin >> k;
	for (int i = 1; i <= k; i++) {
		
		int c, d, e; cin >> c >> d >> e;
		point op, cl;
		
		op.x = inA[c]; op.y = inB[d]; op.h = outB[d]-inB[d]+1; op.val = e; op.typ = 1;
		cl.x = outA[c]; cl.y = inB[d]; cl.h = outB[d]-inB[d]+1; cl.val = e; cl.typ = 3;
		
		V.push_back(op); V.push_back(cl);
	}
	
	cin >> q;
	for (int i = 1; i <= q; i++) {
		
		int x, y; cin >> x >> y;
		point qu;
		
		qu.x = inA[x]; qu.y = inB[y]; qu.val = i; qu.typ = 2;
		V.push_back(qu);
	}
	
	sort (V.begin(), V.end(), comp);
	
	for (point p : V) {
		
		if (p.typ == 1)
			update(p.y, p.y+p.h-1, p.val);
			
		if (p.typ == 2)
			ans[ p.val ] = querry (p.y);
			
		if (p.typ == 3)
			update(p.y, p.y+p.h-1, -p.val);
	}
	
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';

	return 0;
}
