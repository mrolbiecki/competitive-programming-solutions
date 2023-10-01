//2023-01-18
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxA = 20;
const int maxS = 1<<maxA;

int n, m, A;
string s;

ll seg [maxA+1][maxS+2];
int on [maxA+1];

int give_ans () {
	
	for (int i = 1; i < maxA; i++)
		if (on[i] != (1<<i))
			return i;
	return maxA;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s;
	s = '#' + s;
	A = min(maxA, n);
	
	for (int l = 1; l <= A; l++) {
		for (int i = n; i >= l; i--) {
			
			ll h = 0;
			for (int b = 0; b < l; b++)
				if (s[i-b] == '1')
					h += (1<<b);
			
			if (!seg[l][h]) on[l]++;
			seg [l][h]++;
		}
	}
	
	cout << give_ans() << '\n';
	
	for (int q = 0; q < m; q++) {
		
		int z; cin >> z;
		
		for (int l = 1; l <= A; l++) {
			for (int i = min(z+l-1, n); i >= max(z, l); i--) {
				
				ll h = 0;
				for (int b = 0; b < l; b++)
					if (s[i-b] == '1')
						h += (1<<b);

				if (seg[l][h] == 1) on[l]--;
				seg [l][h]--;
			}
		}
		
		if (s[z] == '0') s[z] = '1';
		else s[z] = '0';
		
		for (int l = 1; l <= A; l++) {
			for (int i = min(z+l-1, n); i >= max(z, l); i--) {
				
				ll h = 0;
				for (int b = 0; b < l; b++)
					if (s[i-b] == '1')
						h += (1<<b);

				if (!seg[l][h]) on[l]++;
				seg [l][h]++;
			}
		}
		
		cout << give_ans() << '\n';
	}
	
	return 0;
}
