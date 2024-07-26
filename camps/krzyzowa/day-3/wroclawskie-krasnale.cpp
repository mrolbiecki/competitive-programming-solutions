//2023-01-19
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int n;

struct seg {
	
	int A, B, a, b;
};

struct op {
	
	bool operator () (seg a, seg b) const {
		
		if (a.A == b.A)
			return a.B < b.B;
		return a.A < b.A;
	}
};

set <seg, op> S;

bool intersect (int a1, int a2, int b1, int b2) {
	
	if (a2 <= b1 || b2 <= a1) return false;
	return true;
}

seg merge (seg a, seg b) {
	
	seg res;
	res.A = min(a.A, b.A);
	res.B = max(a.B, b.B);
	
	res.a = max(a.a, b.a);
	res.b = min(a.b, b.b);
	
	return res;
}

bool check (seg & t) {

	if (S.empty()) {
		S.insert(t);
		return true;
	}
	
	auto m = S.upper_bound(t);
	if (m != S.begin() && (*m).A > t.B) --m;
	auto l = m;
	auto r = m;
	if (m != S.begin()) --l;
	if (m != --S.end()) ++r;
	
	if ((intersect((*l).A, (*l).B, t.A, t.B) && (l != m) && intersect((*m).A, (*m).B, t.A, t.B)) ||
		(intersect((*m).A, (*m).B, t.A, t.B) && (m != r) && intersect((*r).A, (*r).B, t.A, t.B))) {
			return false;
	}
		
	if ((!intersect((*l).A, (*l).B, t.A, t.B) && !intersect(t.A, t.B, (*m).A, (*m).B)) &&
		(!intersect(t.A, t.B, (*r).A, (*r).B))) {
		S.insert(t);
		return true;
	}

	if (intersect((*l).a, (*l).b, t.A, t.B) && (l == m || !intersect(t.A, t.B, (*m).A, (*m).B))) {
		
		seg x = (*l); S.erase(l);
		S.insert(merge(x, t));
		return true;
	}
	
	if (intersect((*m).a, (*m).b, t.A, t.B) && (l == m || !intersect(t.A, t.B, (*l).A, (*l).B)) && 
	   (r == m || !intersect(t.A, t.B, (*r).A, (*r).B))) {
		
		seg x = (*m); S.erase(m);
		S.insert(merge(x, t));
		return true;
	}
	
	if (intersect((*r).a, (*r).b, t.A, t.B) && (m == r || !intersect(t.A, t.B, (*m).A, (*m).B))) {
		
		seg x = (*r); S.erase(r);
		S.insert(merge(x, t));
		return true;
	}
	
	return false;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		
		int A, B; cin >> A >> B;
		seg t;
		t.A = t.a = A, t.B = t.b = B;
		
		cout << (check(t) ? "TAK" : "NIE") << '\n';
	}

	return 0;
}
