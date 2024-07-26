//https://szkopul.edu.pl/problemset/problem/bS_effBgQtuS7NXJA_dn7Ogm/site/?key=statement
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 252;
const int l = 17;

int n, m, k, ans;
int s[maxN];
int two[l];

struct matrix {

	bool M[maxN][maxN];
	
	matrix (bool x=0) {
	
		for (int i = 1; i < maxN; i++)
			for (int j = 1; j < maxN; j++)
				M[i][j] = (x && i == j ? 1 : 0);
	}
	
	matrix operator * (matrix B) {
	
		matrix res;
	
		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= n; y++)
				for (int i = 1; i <= n; i++) {
					res.M[x][y] |= M[x][i] & B.M[i][y];
					if (res.M[x][y]) break;
				}
		return res;
	}
/*
	void wypisz () {
	
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cout << M[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
	}
*/
};

matrix G;
vector <matrix> p (l);

bool check (matrix &a) {
	
	bool res = 0;
	
	for (int i = 1; i <= n; i++) {
		
		bool w = 1;
		for (int j = 1; j <= k; j++)
			if(!a.M[s[j]][i]) w = 0;

		res |= w;
	}
		
	return res;
}

int main () {

       ios_base::sync_with_stdio(0);
       cin.tie(0);

	cin >> n >> m >> k;
	
	for (int i = 1; i <= k; i++)
		cin >> s[i];
		
	for (int i = 1; i <= m; i++) {
	
		int a, b; cin >> a >> b;
		G.M[a][b] = 1;
	}
	
	p[0] = G;
	for (int i = 1; i < l; i++)
		p[i] = p[i-1] * p[i-1];
		
	two[0] = 1;
	for (int i = 1; i < l; i++)
		two[i] = two[i-1] * 2;
	
	matrix M (1);
	
	if (check(M)) {
		cout << "TAK\n" << 0;
		return 0;
	}
	
	for (int i = l-1; i >= 0; i--) {
	
		matrix res = M * p[i];

		if (!check(res)) {
			
			M = M * p[i];
			ans += two[i];
		}
	}
	
	M = M * G;

	if (!check(M))
		cout << "NIE";
	else
		cout << "TAK\n" << ans+1;
}
