#include <bits/stdc++.h>
using namespace std;

const int maxN = 15e4+2;

int n;
int X[maxN], Y[maxN], Z[maxN], del[maxN];

bool compx (int a, int b) {
	return X[a] > X[b];
}
bool compy (int a, int b) {
	return Y[a] > Y[b];
}
bool compz (int a, int b) {
	return Z[a] > Z[b];
}

int main () {

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> X[i] >> Y[i] >> Z[i];
		
	vector <int> xv, yv, zv;
	for (int i = 1; i <= n; i++) {
		xv.push_back(i);
		yv.push_back(i);
		zv.push_back(i);
	}
	
	sort (xv.begin(), xv.end(), compx);
	sort (yv.begin(), yv.end(), compy);
	sort (zv.begin(), zv.end(), compz);
	
	int xi = 0, yi = 0, zi = 0;
	while (xi < n && yi < n && zi < n) {
	
		while (xi < n && del[xv[xi]]) xi++;
		while (yi < n && del[yv[yi]]) yi++;
		while (zi < n && del[zv[zi]]) zi++;
		
		if (xi >= n || yi >= n || zi >= n) break;
		
		int x = xv[xi], y = yv[yi], z = zv[zi];

		
		if (Y[x] >= Y[y] || Z[x] >= Z[z]) {
			del[x] = 1; continue;
		}
		if (X[y] >= X[x] || Z[y] >= Z[z]) {
			del[y] = 1; continue;
		}
		if (X[z] >= X[x] || Y[z] >= Y[y]) {
			del[z] = 1; continue;
		}
		
		cout << X[x] + Y[y] + Z[z];
		return 0;
	}
	
	cout << -1;
}
