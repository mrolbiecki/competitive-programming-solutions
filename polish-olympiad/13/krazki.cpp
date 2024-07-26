//2022-10-08
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5+10;

int n, m;
int otwory[maxN], minn[maxN];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> otwory[i];
		
	minn[0] = otwory[0];
	
	for (int i = 1; i < n; i++)
		minn[i] = min(minn[i-1], otwory[i]);
		
	minn[n] = minn[n-1];
		
	int stop = n;
	
	for (int i = 0; i < m; i++) {
		
		int d;
		cin >> d;
		
		if (stop > -1) stop--;
		while (stop >= 0 && minn[stop] < d) stop--;
	}
	
	cout << stop+1;
	
	return 0;
}
