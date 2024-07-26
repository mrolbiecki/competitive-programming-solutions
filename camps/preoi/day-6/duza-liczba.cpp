#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 6e5+10;

string n;
ll ans[maxN], sum;

int main () {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int dl = n.size();
	
	for (int i = 0; i < dl; i++)
		sum += (n[i]-'0');
	
	for (int i = maxN-1; i >= 1; i--) {
		if (i >= maxN-dl) ans[i] += sum;
		if (ans[i] >= 10) {
			ans[i-1] += ans[i]/10;
			ans[i] %= 10;	
		}
	}

	int i = 0;
	while (ans[i] == 0) i++;
	for (; i < maxN; i++)
		cout << ans[i];
}
	
