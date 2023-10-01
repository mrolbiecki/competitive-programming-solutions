#include "cgdzlib.h"
#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int check (int x, int d) {
	
	for (int i = 1; i <= n; i++) {
		if (i == x) continue; 
		
		if ( f(x, i, d) ) return i;
	}
	return 0;
}

int main() {
	
    n = inicjuj();
    
    if (n == 1) {
		odpowiedz (1);
		return 0;
	}
    
    int lo = 1, hi = n, mid;
    
    while (lo < hi) {
		
		mid = (lo + hi) / 2;
		
		if (!check(1, mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	a = check(1, hi-1);
	b = check(a, n-1);
		
	if ( g(a, b) ) odpowiedz (b);
	else odpowiedz (a);
    
    return 0;
}
