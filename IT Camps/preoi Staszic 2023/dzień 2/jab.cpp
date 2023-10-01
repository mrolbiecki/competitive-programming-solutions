#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+2, base = 1<<19;

int n, m;
int L[maxN];

struct node {

	int maxi, sz;
	int lazy;
	
	node (int a=0, int b=0) : maxi(a), sz(b), lazy(0) {};
};

node stree[2*base+2];

node merge (node A, node B) {

	node res (max(A.maxi, B.maxi), A.sz + B.sz);
	return res;
}

void init () {
	
	for (int i = 0; i <= n+1; i++) {
		
		node t (L[i], 1);
		stree[base+i] = t;
	}
	
	for (int i = base-1; i >= 1; i--)
		stree[i] = merge(stree[i*2], stree[i*2+1]);
}

void push (int id) {
	
	stree[id].maxi += stree[id].lazy;
	
	if (id < base) {
		stree[2*id].lazy += stree[id].lazy;
		stree[2*id+1].lazy += stree[id].lazy;
	}
	stree[id].lazy = 0;
}

void add (int lq, int rq, int val, int id=1, int l=0, int r=base-1) {

	if (r < l || r < lq || l > rq) return;
	
	if (lq <= l && rq >= r) {
		stree[id].lazy += val;
		return;
	}
	
	push(id);
	int mid = (l+r)/2;
	
	add (lq, rq, val, id*2, l, mid);
	add(lq, rq, val, id*2+1, mid+1, r);
	
	push(id*2); push(id*2+1);
	stree[id] = merge(stree[id*2], stree[id*2+1]);
}

int lbpos (int val, int id=1) {

	if (id >= base) return id-base;
	
	push(id); push(id*2);
	
	if (stree[id*2].maxi >= val)	
		return lbpos(val, id*2);
		
	return lbpos(val, id*2+1);
}

int kthval (int k, int id=1) {

	push(id);
	
	if (id >= base) return stree[id].maxi;
	
	if (stree[id*2].sz >= k)
		return kthval (k, id*2);
	
	return kthval(k-stree[id*2].sz, id*2+1);
}

int zbieraj (int a, int b) {
	return lbpos(b+1) - lbpos(a);
}

void podlej (int k) {
	
	if (k == 0) return;

	int x = kthval(k+1);
	int c = lbpos(x)-1;
	if (c) add (1, c, 1);
	
	int f = lbpos(x+1)-1;
	add (f-(k-c)+1, f, 1);
}

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> L[i];
	L[n+1] = 1e9+2e6;
	L[0] = -1;
		
	sort(L, L+n+1);
		
	init();
	
	for (int i = 1; i <= m; i++)  {
	
		string s; cin >> s;
		
		if (s[0] == 'z') {
		
			int a, b; cin >> a >> b;
			cout << zbieraj(a, b) << '\n';
		}
		if (s[0] == 'p') {
		
			int k; cin >> k;
			podlej(k);
		}
	}
}
