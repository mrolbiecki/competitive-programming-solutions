//2022-12-30
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int R = 1e4+10;

int k, L;
int len[30];
int id[2*R], idSize[2*R];

int FIND (int x) {
	
	if (x != id[x])
		id[x] = FIND(id[x]);
	return id[x];
}

void UNION (int a, int b) {
	
	a = FIND(a);
	b = FIND(b);
	
	if (idSize[a] < idSize[b]) swap(a, b);
	
	idSize[a] += idSize[b];
	id[b] = id[a];
}

vector <int> powtwo (int n) {
	
	vector <int> a (5000);
	a.push_back(1);
	
	while (n--) {
		
		vector <int> t = a;
		
		for (int i = (int)a.size(); i > 0; i--) {
			t[i] += a[i];
			if (t[i] >= 10) {
				t[i-1]++;
				t[i] -= 10;
			}
		}
		
		a = t;
	}
	
	return a;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while (tt--) {
		
		vector <vector <int>> G (2*R);
		vector <vector <int>> start (30);
		vector <int> zero, one;
		
		for (int i = 0; i < 2*R; i++)
			id[i] = i, idSize[i] = 1;
		
		cin >> k;
		for (int i = 0; i < k; i++)
			cin >> len[i];
			
		int l, suml = 0; cin >> l;
		for (int i = 0; i < l; i++) {
			
			char ch; cin >> ch;
			
			if (ch == '0') {
				zero.push_back(suml);
				suml++;
			}
			if (ch == '1') {
				one.push_back(suml);
				suml++;
			}
			
			if (ch > '1') {
				
				start[ch-'a'].push_back(suml);
				suml += len[ch-'a'];
			}
		}
		L = suml;
		
		int r, sumr = R; cin >> r;
		for (int i = 0; i < r; i++) {
			
			char ch; cin >> ch;
			
			if (ch == '0') {
				zero.push_back(sumr);
				sumr++;
			}
			if (ch == '1') {
				one.push_back(sumr);
				sumr++;
			}
			
			if (ch > '1') {
				
				start[ch-'a'].push_back(sumr);
				sumr += len[ch-'a'];
			}
		}
		
		if (suml != sumr - R) {
			cout << 0 << '\n';
			continue;
		}
		
		for (int i = 0; i < L; i++)
			UNION(i, R+i);
		
		for (int ch = 0; ch < k; ch++)
			if (start[ch].size() >= 2)
				for (int i = 1; i < (int)start[ch].size(); i++)
					for (int j = 0; j < len[ch]; j++)
						UNION(start[ch][0] + j, start[ch][i] + j);
					
		if (one.size() >= 2)
			for (int i = 1; i < (int)one.size(); i++)
				UNION(one[i], one[0]);
		
		if (zero.size() >= 2)
			for (int i = 1; i < (int)zero.size(); i++)
				UNION(zero[i], zero[0]);
		
		set <int> cnt;
		int z = (zero.empty() ? -1 : FIND(zero[0]));
		int on = (one.empty() ? -1 : FIND(one[0]));
		
		if (z != -1 && z == on) {
			cout << 0 << '\n';
			continue;
		}
		
		for (int i = 0; i < L; i++) {
			int f = FIND(i);
			if (f != z && f != on)
				cnt.insert(f);
		}
		for (int i = R; i < R + L; i++) {
			int f = FIND(i);
			if (f != z && f != on)
				cnt.insert(f);
		}
		
		vector <int> ans = powtwo(cnt.size());
		
		int i = 0;
		while (ans[i] == 0) i++;
		for (; i < (int)ans.size(); i++)
			cout << ans[i];
		cout << '\n';
	}
	
	
	return 0;
}

/*
1
1
4
1
a
4
1001
*/
