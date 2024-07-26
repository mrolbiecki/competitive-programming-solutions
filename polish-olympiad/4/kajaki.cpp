#include <bits/stdc++.h>

using namespace std;
int w, n, k = 0;
vector <int> T;

int l, r;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> w >> n;

    T.resize(n);

    for (int i = 0; i < n; i++)
        cin >> T[i];

    sort (T.begin(), T.end());

    l = 0; r = n - 1;

    while (l <= r) {

        if (T[r] + T[l] <= w) {
            l++;
            r--;
        }
        else
            r--;

        k++;
    }

    cout << k << endl;

    return 0;
}