//https://szkopul.edu.pl/problemset/problem/zKf5Ua8okcS0jngsrTgKVM9L/site/?key=statement
//hard problem, solution uses matrix exponentaion
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 130, L = 70;
const ll inf = 2e18+2;

int n, m;
ll k, ans;

struct matrix {

	vector <vector<ll>> M;
	
	matrix () {
		M.resize(maxN, vector <ll> (maxN, 0));
	}
	
	inline ll mult (ll a, ll b) {
	
		if (a == 0) return 0;
		if (b > inf/a) return inf;
		return a*b;
	}
	
	matrix operator * (matrix B) {
	
		matrix res;
	
		for (int i = 0; i < 3*n+3; i++)
			for (int j = 0; j < 3*n+3; j++)
					for (int l = 0; l < 3*n+3; l++) {
					
						res.M[i][j] += mult(M[i][l], B.M[l][j]);
						res.M[i][j] = min(res.M[i][j], inf);
					}
		return res;
	}
/*
	void wypisz () {
	
		for (int i = 0; i <= 3*n+2; i++) {
			for (int j = 0; j <= 3*n+2; j++)
				cout << M[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
	}
*/
};

matrix G;
matrix p[L];

ll cnt (matrix a) {

	ll res = 0;
	for (int i = 3; i <= 3*n; i+=3)
		res += a.M[0][i], res = min(res, inf);
		
	return res;
}

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	k += n;
	
	G.M[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		G.M[0][3*i] = 1;
		G.M[3*i+1][3*i] = 1;
		G.M[3*i+2][3*i+1] = 1;
	}
	
	for (int i = 1; i <= m; i++) {
	
		int a, b, c; cin >> a >> b >> c;
		G.M[3*a][3*b+c-1]++;
	}
	
	p[0] = G;
	
	int x = 1;
	
	while (x < 69 && cnt(p[x-1]) < k) {
		p[x] = p[x-1] * p[x-1];
		x++;
	}
		
	if (cnt(p[x-1]) < k) {
	
		cout << -1;
		return 0;
	}
	
	matrix M = G;
	
	for (int i = x-1; i >= 0; i--)
		if (cnt(M*p[i]) < k) {
			M = M * p[i];
			ans += (1ll<<i);
		}
	
	cout << ans+1;
}
