#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+2;
int n, m;
vector <int> G[maxN];
int vis[maxN];

void dfs (int v, int x) {
    vis[v] = x;
    for (int u : G[v]) {
        if (!vis[u])
            dfs(u, x % 2 + 1);
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 0) {
            cout << "NIE";
            return 0;
        }
        if (!vis[i]) {
            dfs(i, 1);
        }
    }

    cout << "TAK\n";
    for (int i = 1; i <= n; i++) {
        cout << (vis[i] == 1 ? 'K' : 'S') << '\n';
    }
}