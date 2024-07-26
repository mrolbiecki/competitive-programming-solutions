#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+2;
const int maxM = 4e5+2;

int n, m;
int M[maxN][2];
pair<int, int> T[maxM];
vector <int> G [maxN];
int ans[maxN];
bool vis[maxN];

void dfs (int v, int t) {
    vis[v] = 1;
    ans[v] = t;

    for (int u : G[v]) {
        if (!vis[u]) {
            dfs(u, t);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> M[i][0] >> M[i][1];
        if (M[i][0] != -1) {
            G[i].push_back( M[i][0] );
            G[ M[i][0] ].push_back(i);
        }
        if (M[i][1] != -1) {
            G[i].push_back( M[i][1] );
            G[ M[i][1] ].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        int a, j;
        cin >> a >> j;
        int b = M[a][j - 1];
        T[i] = {a, j - 1};
        G[a].erase(find(G[a].begin(), G[a].end(), b));
        G[b].erase(find(G[b].begin(), G[b].end(), a));
    }

    reverse(T+1, T+1+m);
    dfs(1, -1);

    for (int i = 1; i <= m; i++) {
        int a = T[i].first;
        int b = M[a][ T[i].second ];
        G[a].push_back(b);
        G[b].push_back(a);

        if (vis[a] && !vis[b]) {
            dfs(b, m-i);
        }
        if (vis[b] && !vis[a]) {
            dfs(a, m-i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}