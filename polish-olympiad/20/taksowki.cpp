#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+2;

int n;
long long m, d;
vector <long long> x;
long long s;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> d >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        if (x[i] >= m-d) {
            s = x[i];
            swap(x[i], x[n-1]);
            x.pop_back();
            break;
        }
    }

    if (s < m - d) {
        cout << 0;
        return 0;
    }
    if (s - d >= m) {
        cout << 1;
        return 0;
    }

    long long ds = (d + m - s + 1) / 2;

    sort(x.begin(), x.end(), greater<long long>());

    long long pos = 0;
    int i = 0;
    for (; i < n && pos < ds; i++) {
        if (x[i] <= d - pos) {
            cout << 0;
            return 0;
        }
        pos += x[i] - (d - pos);
    }

    if (pos >= m) {
        cout << i;
        return 0;
    }
    if (pos >= ds) {
        cout << i + 1;
        return 0;
    }

    cout << 0;
    return 0;
}