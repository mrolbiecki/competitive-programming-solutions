//author: Marcin Rolbiecki (swm4r)
//https://www.spoj.com/problems/ADASTRNG/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5+10, L = 20;
 
int n;
int KMR[N][L], SA[N], RANK[N], LCP[N];
string S;
 
long long W[27];
 
int main () {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
    n = S.size();
 
    for (int i = 0; i < n; i++)
        KMR[i][0] = S[i] - 'a' + 1;
 
    int pot = 1;
 
    for (int x = 1; x < L; x++) {
        
        pair <pair <int, int>, int> P [N];
 
        for (int i = 0; i < n; i++)
            if (i + pot >= n)
                P[i] = {{KMR[i][x-1], -1}, i};
            else
                P[i] = {{KMR[i][x-1], KMR[i+pot][x-1]}, i};
        
        sort (P, P + n);
        pair <int, int> prev = {-1, -1};
        int ile = -1;
 
        for (int i = 0; i < n; i++) {
            
            if (P[i].first != prev)
                ile++;
            KMR[P[i].second][x] = ile;
            prev = P[i].first;
        }
 
        pot *= 2;
    }
 
    for (int i = 0; i < n; i++) {
        RANK[i] = KMR[i][L-1];
        SA[ RANK[i] ] = i;
    }
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        
        if (RANK[i] == 0) {
            k = 0;
            continue;
        }
        int j = SA[ RANK[i]-1 ];
 
        while (i+k<n && j+k<n && S[i+k] == S[j+k])
            k++;
        LCP[RANK[i]] = k;
 
        if (k) k--;
    }
 
    for (int i = 0; i < n; i++) 
        W[ S[i] - 'a' ] += (long long)(n-i-LCP[RANK[i]]);
    
    for (int i = 0; i < 26; i++)
        cout << W[i] << ' ';
        
	return 0;
}
