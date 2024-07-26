//2023-01-19
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5+2, maxL = 31, base = 1<<19;

int n, q;
int A[maxN];

struct node {
	
	int t[maxL] {0};
	int lazy=0;
};

node T[base*2];
node neut;

bool ison (int x, int b) {return (x>>(b-1)&1);}

int lb (int x) {
	
	int res = 0;
	for (int b = 1; 1<<(b-1) <= x; b++)
		if (ison(x, b))
			res = b;
	return res;
}

void add (node & N, int x) {
	
	int l = lb(x);
	
	while (x && N.t[l]) {
		x ^= N.t[l];
		l = lb(x);
	}
	if (x) N.t[l] = x;
}

node merge (node A, node B) {
	
	node res;
	
	for (int i = 1; i <= 30; i++)
		add(res, B.t[i]);
	for (int i = 1; i <= 30; i++)
		add(res, A.t[i]);	
	
	return res;
}

void init () {
	
	for (int i = 1; i <= n; i++) {
		
		node nd;
		add(nd, A[i]);
		T[base+i] = nd;
	}
	
	for (int i = base; i >= 1; i--)
		T[i] = merge(T[2*i], T[2*i+1]);
}

void resetG (int id) {
	
	for (int i = 1; i <= 30; i++)
			T[id].t[i] = 0;
			
	add(T[id], T[id].lazy);
}

void push (int id) {
	
	if (T[id].lazy) {
		T[id*2].lazy = T[id].lazy;
		T[id*2+1].lazy = T[id].lazy;
		
		resetG(id*2);
		resetG(id*2+1);
	}
	T[id].lazy = 0;
}

int lq, rq, val;
void update (int id, int l, int r) {
	
	if (rq < l || lq > r) return;
		
	if (lq <= l && rq >= r) {
		T[id].lazy = val;
		resetG(id);
		return;
	}
	
	push(id);
	
	int mid = (l + r)/2;
	update (id*2, l, mid); update(id*2+1, mid+1, r);
	
	T[id] = merge(T[id*2], T[id*2+1]);
}

node seg (int id, int l, int r) {

	if (rq < l || lq > r) return neut;
	if (lq <= l && rq >= r) return T[id];
	
	push(id);
	
	int mid = (l + r)/2;
	return merge (seg (id*2, l, mid), seg (id*2+1, mid+1, r));
}

int maks () {
	
	node N = seg(1, 0, base-1);
	
	int res = 0;
	for (int b = 30; b >= 1; b--)
		if (N.t[b] && !ison(res, b))
			res ^= N.t[b];

	return res;
}

bool check () {
	
	node N = seg(1, 0, base-1);
	
	int res = 0;
	for (int b = 30; b >= 1; b--)
		if (N.t[b] && (ison(val, b) != ison(res, b)))
			res ^= N.t[b];
			
	return res == val;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> A[i];
		
	init();
		
	for (int i = 1; i <= q; i++) {
		
		string typ; cin >> typ;
		
		if (typ[0] == 'a') {
			cin >> lq >> rq >> val;
			update(1, 0, base-1);
		}
		if (typ[0] == 'm') {
			cin >> lq >> rq;
			cout << maks() << '\n';
		}
		if (typ[0] == 'l') {
			cin >> lq >> rq >> val;
			cout << (check() ? "TAK" : "NIE") << '\n';
		}
	}
	
	
	return 0;
}
