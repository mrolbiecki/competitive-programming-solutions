#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2;

int n, ans;
int where[maxN];
int vis[maxN];

void dfs (int v, int x) {
    vis[v] = x;

    if (!vis[ where[v] ]) {
        dfs(where[v], x);
    } else if (vis[ where[v] ] != x) {
        ans--;
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> where[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i, i);
        }
    }

    cout << ans;
}