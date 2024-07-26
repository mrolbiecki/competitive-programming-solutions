#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e4+2;

int n;
int a[maxN];
int l, r;
long long lSum, rSum, ans;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lSum += a[i];
    }

    lSum -= a[0];
    rSum += a[0];

    for (int l = 0; l < n; l++) {
        lSum += a[l];
        rSum -= a[l];
        while (lSum > rSum) {
            r = (r + 1) % n;
            rSum += a[r];
            lSum -= a[r];
            ans = max(ans, min(rSum, lSum));
        }
    }

    cout << ans;
}