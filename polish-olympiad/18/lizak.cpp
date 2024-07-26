//author: Marcin Rolbiecki (swm4r)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, m, sum;

string liz;
int val [N];
pair <int, int> P [2 * N];

void solve (int l, int r, int k) {
    
    P[k] = {l+1, r+1}; 

    if (k < 3) return;

    if (val[l] == 2)
        return solve (l+1, r, k-2);
    if (val[r] == 2)
        return solve (l, r-1, k-2);
    return solve (l+1, r-1, k-2);
}

int main () {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    for (int i = 0; i < 2*N; i++)
        P[i] = {-1, -1};

	cin >> n >> m >> liz;
    
    for (int i = 0; i < n; i++) {
        if (liz[i] == 'T')
            val[i] = 2;
        else
            val[i] = 1;
        sum += val[i];
    }

    solve (0, n-1, sum);

    int l = -1, r = -1;
    int sumL = 0;

    for (int i = 0; i < n; i++)
        if (val[i] == 1) {
            if (l == -1)
                l = i;
            r = i;
        }

    if (r != -1 && r > n-l-1)
        solve (0, r-1, sum - (n-r-1)*2 - 1);
    else if (l != -1)
        solve (l+1, n-1, sum - (l)*2 - 1);

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;

        if (P[a].first == -1)
            cout << "NIE\n";
        else
            cout << P[a].first << ' ' << P[a].second << '\n';
    }

	return 0;
}

