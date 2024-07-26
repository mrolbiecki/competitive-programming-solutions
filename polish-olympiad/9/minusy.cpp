//2022-10-08
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int n;
char c, p;

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> p;
	cout << p;
	
	for (int i = 1; i < n-1; i++) {
		
		cin >> c;
		if (c == '-' && p == '+')
			cout << ')';
		if (c == '+' && p == '-')
			cout << '(';
		cout << '-';
		p = c;
	}
	
	if (c == '+')
		cout << ')';
	
	return 0;
}
