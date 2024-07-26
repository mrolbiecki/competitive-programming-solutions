//2023-01-16
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+2;

long long n, k;
long long A[maxN];
int blokL [maxN], blokR [maxN];

long long pref [maxN];

long long sum (int a, int b, int h) {
	
	if (a > b) swap (a, b);
	
	long long ile = b-a+1;
	
	long long res = h - ile + 1 + h;
	res *= (b - a + 1);
	res /= 2;
	
	return res;
}

bool check (int h) {
	
	for (int i = 1; i <= n; i++)
		if (A[i] >= h) 
			return true;
			
	for (int i = 1; i <= n; i++) {
		blokL[i] =  0;
		blokR[i] = n+1;
	}
	
	for (int i = 1; i <= n; i++)
		if (i + h - A[i] <= n)
			blokL[ i + h - A[i] ] = i;
			
	for (int i = 2; i <= n; i++)
		blokL[i] = max(blokL[i-1], blokL[i]);
			
	for (int i = n; i >= 1; i--)
		if (i - (h - A[i]) >= 1)
			blokR[ i - (h - A[i]) ] = i;
			
	for (int i = n-1; i >= 1; i--)
		blokR[i] = min(blokR[i], blokR[i+1]);
	
	for (int i = 1; i <= n; i++) {
		
		int a = min(blokL[i]+1, i), b = max(blokR[i]-1, i);
		if (sum(a, i, h) + sum(i, b, h) - h <= pref[b] - pref[a-1] + k) {
			
			return true;
		}
	}
	return false;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> A[i];
		
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i-1] + A[i];
		
	long long lo = 0, hi = 2e9, mid;
	
	while (lo < hi) {
		
		mid = (lo + hi) / 2;
		
		if (!check(mid))
			hi = mid;
		else
			lo = mid+1;
	}
		
	cout << hi-1;
	
	return 0;
}
