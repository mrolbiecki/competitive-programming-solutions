// author: Marcin Rolbiecki
// problem: https://szkopul.edu.pl/problemset/problem/PCtteC6gKwc2ZikW8nUZzfyh/site/?key=statement
// date: 2024-07-26
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e3 + 1;

int n, m; //n - verticies, m - edges
bool adj [maxN][maxN]; //adjacency matrix
bool is_deleted [maxN]; 

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
	}
	
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!is_deleted[i] && !is_deleted[j] && !adj[i][j]) {
                is_deleted[i] = is_deleted[j] = 1;
            }
        }
    }

    int ans_size = n / 3, ans_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!is_deleted[i]) {
            cout << i << ' ';
            ans_cnt++;
        }
        if (ans_cnt == ans_size) {
            break;
        }
    }
}
