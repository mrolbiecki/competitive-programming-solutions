//2023-01-17
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+2, alfa = 26, maxS = 2e6+2;

int n, ans;
string S[maxN];

int trie [alfa][maxS];
int father[maxS];
int on [maxS], leaves[maxS];

int endID [maxN];

int nxt = 2;

int go (int x, char c) {
	
	if (trie[c-'a'][x])
		return trie[c-'a'][x];
	
	leaves[x]++;
	father[nxt] = x;
	return trie[c-'a'][x] = nxt++;
}

void ins (int i, int id=1, int f=1) {
	
	for (char c : S[i]) id = go(id, c);
	
	endID[i] = id;
	leaves[id]++;
}

void check (int x) {
	
	if (x == 1) return;
	
	if (leaves[x] == on[x]) {
		
		ans = ans - on[x] + 1;
		on[ father[x] ]++;
		check( father[x] );
		return;
	}
}

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
		ins (i);
	}
	
	for (int i = 1; i <= n; i++) {
		
		int id = endID[i];
		
		ans++; on[id]++;
		check(id);
		cout << ans << '\n';
	}
	
	return 0;
}
