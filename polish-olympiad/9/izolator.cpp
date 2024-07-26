#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+2;

int n;
int x[maxN];
int y[maxN];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int l = 0, r = n-1;

    for (int i = 0; i < n; i++) {
        y[i] = x[l++];
        i++;
        if (i < n) {
            y[i] = x[r--];
        }
    }

    long long score = y[n-1];
    for (int i = 0; i < n-1; i++) {
        score += y[i];
        score += max(0, y[i+1] - y[i]);
    }

    cout << score;
 }