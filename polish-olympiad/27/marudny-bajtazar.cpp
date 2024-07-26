//2023-01-10
//author: Marcin Rolbiecki
//https://szkopul.edu.pl/problemset/problem/kvwWom2nxVBqipEfeiMtidn5/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

const int B = 1<<20;

int n, m;
string s;
int p[22][B];
int cnt[22];

int check () {
	
	for (int i = 1; i <= n; i++)
		if (cnt[i] != 1<<i)
			return i;
	return 20;
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s;
	
	for (int k = 1; k <= 20; k++) {
		for (int i = 0; i < n-k+1; i++) {
			
			int num = 0;
			
			for (int j = 0; j < k; j++)
				if (s[i+j] == '1')
					num |= 1<<(k-1-j);
					
			if (p[k][num] == 0)
				cnt[k]++;
					
			p[k][num]++;
		}
	}
	
	cout << check() << '\n';
	
	for (int i = 0; i < m; i++) {
		
		int a; cin >> a; --a;
		
		for (int k = 1; k <= 20; k++) {
			int l = max(0, a-k+1), r = min(n-k+1, a+1);
			for (int i = l; i < r; i++) {
				
				int num = 0;
				
				for (int j = 0; j < k; j++)
					if (s[i+j] == '1')
						num |= 1<<(k-1-j);
						
				if (p[k][num] == 1)
					cnt[k]--;
						
				p[k][num]--;
			}
		}
		
		if (s[a] == '1') s[a] = '0';
		else s[a] = '1';
		
		for (int k = 1; k <= 20; k++) {
			int l = max(0, a-k+1), r = min(n-k+1, a+1);
			for (int i = l; i < r; i++) {
				
				int num = 0;
				
				for (int j = 0; j < k; j++)
					if (s[i+j] == '1')
						num |= 1<<(k-1-j);
						
				if (p[k][num] == 0)
					cnt[k]++;
						
				p[k][num]++;
			}
		}
		
		cout << check() << '\n';
	}
	
	
	return 0;
}
