//2022-12-29
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2*5e4+10;

int n;
int s[maxN];
bool vis[maxN];

stack <int> S, D;
vector <int> ans;

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < 2*n; i++)
		cin >> s[i];
		
	for (int i = 2*n-1; i >= 0; i--)
		S.push(s[i]);
	
	while (!S.empty()) {
		
		int t = S.top(); S.pop();
		
		if (!vis[t]) {
			D.push(t);
			vis[t] = 1;
			continue;
		}
		
		while (D.top() != t) {
			
			ans.push_back(D.size());
			int d = D.top();
			S.push(d);
			vis[d] = 0;
			D.pop();
		}
		
		D.pop();
	}
	
	cout << ans.size() << '\n';
	for (int a : ans)
		cout << a << '\n';
	
	return 0;
}
