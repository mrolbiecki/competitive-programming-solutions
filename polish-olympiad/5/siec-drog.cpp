//2023-01-15
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 202;

int n;
int odl[maxN][maxN];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> odl[i][j];
			
	for (int a = 1; a <= n; a++)
		for (int b = a+1; b <= n; b++) {
			
			bool ok = 1;
			
			for (int c = 1; c <= n; c++) {
				
				if (c == a || c == b) continue;
				if (odl[a][c] + odl[c][b] == odl[a][b]) ok = 0;
			}
			
			if (ok) cout << a << ' ' << b << '\n';
		}
	
	return 0;
}
