#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXM = 250 * 250  + 5;
const int MAXN = 255;
const int inf = 1e9;
int n, m;
int poz_a, poz_b;
vector<int> adj[MAXM];
vector<vector<int>> adj_agt[MAXM]; // vector przejść agentów

int dist[MAXN][MAXN][2];

bool vis[MAXN][MAXN][2];

int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> poz_a >> poz_b;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j][0] = inf, dist[i][j][1] = inf;
			
	dist[poz_a][poz_b][0] = 0;

    queue<vector<int>> q;
    q.push({poz_a, poz_b, 0});
    while (!q.empty()) {
		
		vector<int> cur = q.front(); q.pop();
        if (cur[2] == 0) {
            int ag_a = cur[0], ag_b = cur[1];
           //cout << ag_a << " " << ag_b << " " << cur[2] << endl;
            vis[ag_a][ag_b][0] = true;
            for (int u : adj[ag_a]) {
                if(!vis[u][ag_b][1]) {
					vis[u][ag_b][1] = true;
                    q.push({u, ag_b, 1});
                    dist[u][ag_b][1] = dist[ag_a][ag_b][0] + 1;
                    //cout << "   A: "<< u << " " << ag_b << " dist: " << dist[u][ag_b]  << endl;
                }
            }
        } else {
            int ag_a = cur[0], ag_b = cur[1];
             //cout << ag_a << " " << ag_b << " " << cur[2] << endl;
            vis[ag_a][ag_b][1] = true;
            for (int u : adj[ag_b]) {
                if(!vis[ag_a][u][0]) {
					vis[ag_a][u][0] = true;
                    q.push({ag_a, u, 0});
                    dist[ag_a][u][0] = dist[ag_a][ag_b][1] + 1;
                    //cout << "   B: " << ag_a << " " << u << " dist: " << dist[ag_a][u] << endl;
                }
            }
        } 
    }
 /*  
    for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k <= 1; k++)
				cout << "dist " << i << ' ' << j << ' '<< k << ": " << dist[i][j][k] << endl;
*/
    int mind = inf;
    
    for (int i = 1; i <= n; i++)
		mind = min(mind, dist[i][i][0]/2);
    
    if (mind == inf/2)
		cout << "NIE";
	else
		cout << mind;
		
    return 0;
}
