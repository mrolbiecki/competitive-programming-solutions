//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

int main () {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, S;
    cin >> n >> S;
    
    int W[n];
    for (int i = 0; i < n; i++)
        W[i] = i * (-1);

    int k = 1, add = 0, s = (0-n+1)*n/2;

    while (k < n && s + (n-k)*2 < S) {
       s += (n-k)*2;
       add += 2;
       W[k] += add;
       k++;
    }

    if (k == n && S) {
       cout << "NIE";
       return 0; 
    }

    for (int i = k; i <= n; i++) 
        W[i] += add;
    for (int i = n-1; i >= 0; i--)
       if (s+2 <= S) {
           W[i] += 2;
           s += 2;
       }

    if (s != S) {
        cout << "NIE";
        return 0;
    }


    for (int i = 0; i < n; i++)
        cout << W[i] << '\n';





}
