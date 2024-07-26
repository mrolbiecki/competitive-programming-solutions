//https://szkopul.edu.pl/problemset/problem/TYf8i2qvrGI0l8QHEYJXO5dG/site/?key=statement
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 15002, base = 1<<17;
const int D = 30001;

int s, w, n, ans;
int stree [base*2], lazy [base*2];

struct point {
	
	int x, y;
	int t; //1- otwarcie, 2-zamknięcie
};

vector <point> P;

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

bool comp (point A, point B) {

	if (A.x == B.x) 
		return A.t < B.t;
	return A.x < B.x;
}

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> w >> n;
	
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		P.push_back({x-1, y, 1});
		P.push_back({x+s-1, y, 2});
	}
	
	sort (P.begin(), P.end(), comp);
	
	int i = 0;
	while (i < 2*n) {
	
		while (i < 2*n && P[i].t == 1)
			update(D+P[i].y-w,D+P[i].y, 1), i++;
		
		ans = max(ans, querry(1, 2*D));
		
		while (i < 2*n && P[i].t == 2)
			update(D+P[i].y-w,D+P[i].y, -1), i++;
	}

	cout << ans;
}
