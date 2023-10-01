//2022-10-03
//author: Marcin Rolbiecki
//https://www.spoj.com/problems/ADAGAME/
#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 1e4, maxM = 110;
 
int ada[maxN+10][maxM];
int vinit[maxN+10][maxM];
 
int N, M;
 
int turn (int x, int m, bool a) {
	
	int digs[4], t = x, res, base = 1;
	res = (a ? INT_MIN : INT_MAX);
	
	for (int i = 3; i >= 0; i--) {
		digs[i] = t % 10;
		t /= 10;
	}
	
	for (int i = 3; i >= 0; i--) {
		
		if (a)
			res = max(res, (digs[i] == 9 ? vinit[x - 9*base][m-1] : vinit[x + base][m-1]));
		else
			res = min(res, (digs[i] == 9 ? ada[x - 9*base][m-1] : ada[x + base][m-1]));
			
		base *= 10;
	}
	
	return res;
}
 
void prec () {
	
	for (int i = 0; i < maxN; i++) {
		ada[i][0] = i;
		vinit[i][0] = i;
	}
	
	for (int j = 1; j < maxM; j++)
		for (int i = 0; i < maxN; i++) {
			ada[i][j] = turn(i, j, 1);
			vinit[i][j] = turn(i, j, 0);
		}
}
 
int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	prec ();
	
	int tt;
	cin >> tt;
	
	while (tt--) {
		
		cin >> N >> M;
		cout << (ada[N][M] > N ? "Ada\n" : "Vinit\n");
	}
	
	return 0;
}
