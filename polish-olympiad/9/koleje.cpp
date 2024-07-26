#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int base = 1<<17;

int n, m, z;

ll stree [base*2], lazy [base*2];

void push (int id) {

	lazy[id*2] += lazy[id];
	lazy[id*2+1] += lazy[id];
	
	stree[id*2] += lazy[id];
	stree[id*2+1] += lazy[id];

	lazy[id] = 0;
}

int querry (int lq, int rq, int id=1, int l=0, int r=base-1) {
	
	if (rq < l || lq > r) return 0;
	if (lq <= l && rq >= r) return stree[id];
	
	push(id);
	
	int mid = (l+r)/2;
	return  max(querry(lq, rq, id*2, l, mid),
				querry(lq, rq, id*2+1, mid+1, r));
}

void update (int lq, int rq, int val, int id=1, int l=0, int r=base-1) {
	
	if (rq < l || lq > r) return;
	if (lq <= l && rq >= r) {
		
		stree[id] += val;
		lazy[id] += val;
		return;
	}
	push(id);
	
	int mid = (l+r)/2;
	update(lq, rq, val, id*2, l, mid);
	update(lq, rq, val, id*2+1, mid+1, r);
	
	stree[id] = max(stree[id*2], stree[id*2+1]);
}


int main () {

	cin >> n >> m >> z;
	while (z--) {
	
		int p, k, l; 
		cin >> p >> k >> l;
	
		if (querry(p, k-1) <= m-l) {
			update(p, k-1, l);
			cout << 'T' << '\n';
		}
		else cout << 'N' << '\n';
	}
}
