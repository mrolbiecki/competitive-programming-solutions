// author: Marcin Rolbiecki
// problem: https://szkopul.edu.pl/problemset/problem/8AKFvYX1GKjeakIidXGH5_h7/site/?key=statement
// date: 2024-08-13
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1002;

int n, m;
int x[maxN], y[maxN];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i < m; i++) {
        cin >> x[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> y[i];
    }

    sort(x+1, x+m, greater<int>());
    sort(y+1, y+n, greater<int>());

    int i = 1, j = 1;
    long long sum = 0;

    while (i <= m || j <= n) {
        if (i > m || (j <= n && y[j] >= x[i])) {
            sum += y[j++] * i;
        } else {
            sum += x[i++] * j;
        }
    }

    cout << sum;
}