#include <bits/stdc++.h>
//https://www.spoj.com/problems/DISQUERY/
using namespace std;
 
const int N = 100001, L = 18;
int n, q, t = 1;
 
vector <vector <pair <int, int> > > T (N);
vector <vector <int> > S (N), MIN (N), MAX (N);
vector <int> ODL (N), IN (N), OUT (N);
 
void DFS (int r, int par, int minLen, int maxLen) {
 
    IN[r] = t++;
 
    S[r][0] = par;
    MIN[r][0] = minLen;
    MAX[r][0] = maxLen;
 
    for (int i = 1; i < L; i++) {
 
        S[r][i] = S[ S[r][i - 1] ][i - 1];
        MIN[r][i] = min (MIN[r][i - 1], MIN[S[r][i - 1]][i - 1]);
        MAX[r][i] = max (MAX[r][i - 1], MAX[S[r][i - 1]][i - 1]);
    }
 
    for (auto t : T[r])
        if(t.first != par)
            DFS(t.first, r, t.second, t.second);
 
    OUT[r] = t++;
}
 
bool isAnc (int a, int b) {return (IN[a] <= IN[b] && OUT[a] >= OUT[b]);}
 
int main () {
 
    ios_base::sync_with_stdio(0);
    cin >> n;
 
    for (int i = 1; i < n; i++) {
 
        int a, b, c;
        cin >> a >> b >> c;
 
        T[a].push_back(make_pair(b, c));
        T[b].push_back(make_pair(a, c));
    }
 
    for (int i = 0; i <= n; i++) {
 
        MIN[i].resize(L);
        MAX[i].resize(L);
        S[i].resize(L);
    }
 
    DFS(1, 1, INT_MAX, 0);
 
    cin >> q;
 
    for (int z = 0; z < q; z++) {
 
        int a, b, minLen = INT_MAX, maxLen = INT_MIN;
        cin >> a >> b;
 
        for (int l = L - 1; l >= 0; l--)
            if (!isAnc(S[a][l], b)) {
 
                minLen = min(minLen, MIN[a][l]);
                maxLen = max(maxLen, MAX[a][l]);
                a = S[a][l];
            }
 
        for (int l = L - 1; l >= 0; l--)
            if (!isAnc(S[b][l], a)) {
                minLen = min(minLen, MIN[b][l]);
                maxLen = max(maxLen, MAX[b][l]);
                b = S[b][l];
            }
 
        if (!isAnc(b, a)) {
            minLen = min(minLen, MIN[b][0]);
            maxLen = max(maxLen, MAX[b][0]);
        }
        if (!isAnc(a, b)) {
            minLen = min(minLen, MIN[a][0]);
            maxLen = max(maxLen, MAX[a][0]);
        }
 
        cout << minLen << " " << maxLen << endl;
    }
 
    return 0;
}
