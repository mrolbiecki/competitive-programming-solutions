//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, C[N], m;
long long s;

int main () {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        C[a]++; C[b]++;
    }

    for (int i = 1; i <= n; i++)
       s += (long long)C[i] * (n - C[i] - 1);

   cout << (long long)(n * (n-1) * (n-2)) / 6 - s/2;
   return 0;
} 

