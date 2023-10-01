//author: Marcin Rolbiecki (swm4r)
//https://szkopul.edu.pl/problemset/problem/a3IarwgOdubufXQ89OsQz3v_/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+2;

int n, w;
int P[maxN];
string S;

int zakres[maxN], szablon[maxN];

void KMP (string X) {
    
    P[0] = P[1] = 0;
    
    int sz = X.size();

    for (int i = 1; i < sz; i++) {
        
        int pr = P[i];
        while (pr && X[pr] != X[i])
            pr = P[pr];
        if (X[pr] == X[i])
            pr++;

        P[i+1] = pr;
    }
}

int main () {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
    n = S.size();

	for (int i = 0; i <= n; i++)
		zakres[i] = szablon[i] = i;

    KMP (S);
    
    for (int i = 2; i <= n; i++) {
		
		int s = szablon[ P[i] ];
		
		if (P[i] && zakres[s] >= i-s) {
			szablon[i] = s;
			zakres[s] = i;
		}
	}

	cout << szablon[n];

	return 0;
}

