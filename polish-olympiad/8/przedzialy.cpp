//2023-01-14
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2;

int n;
int p[2*maxN];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[2*a]++;
		p[2*b+1]--;
	}
	
	for (int i = 1; i <= 2*maxN; i++)
		p[i] += p[i-1];
	
	for (int i = 1; i < 2*maxN; i++) {
		if (p[i-1] == 0 && p[i] != 0)
			cout << i/2 << ' ';
		if (p[i-1] != 0 && p[i] == 0)
			cout << (i-1)/2 << '\n';
	}
		
	
	
	
	return 0;
}
