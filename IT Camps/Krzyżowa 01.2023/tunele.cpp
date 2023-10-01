//2023-01-19
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int n, r;
set <pair <int, int>> V;

void solve (int l, int r, int B) {
	
	if (l != 0)
		for (int i = l+1; i < r; i++)
			V.insert({l, i});
	if (r != n+1)
		for (int i = l+1; i < r; i++)
			V.insert({i, r});
	
	if (r-l-1 <= 3) {
				
		for (int i = l+1; i < r-1; i++)
			V.insert({i, i+1});
		return;
	}
			
	vector <int> spec;
	int dl = sqrt(B);
	
	int prev = l;
	for (int i = l+1; i < r; i++)
		if (i % B == 0) {
			solve (prev, i, dl);
			prev = i;
			spec.push_back(i);
		}
	solve (prev, r, dl);
	
	for (int i = 0; i < (int)spec.size(); i++)
		for (int j = i+1; j < (int)spec.size(); j++)
			V.insert({spec[i], spec[j]});
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r;
	int dl = sqrt(n);
	solve(0, n+1, dl);
	
	cout << V.size() << '\n';
	for (auto p : V)
		cout << p.first << ' ' << p.second << '\n';
	
	return 0;
}
