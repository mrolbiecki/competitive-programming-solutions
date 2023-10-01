//https://szkopul.edu.pl/problemset/problem/oNnWY6ZuzzhvG-jCmijiXkIk/site/?key=statement
#include <bits/stdc++.h>
using namespace std;

int n, k;
unordered_map < int, unordered_map <int, vector  <pair <int, bool> > > > M;
vector <int> V;
// d / a % d / l

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    V.resize(n + 2);

    for (int i = 0; i < k; i++) {

        int a, l, d;
        cin >> a >> l >> d;
        M[d][a % d].push_back({a, 0});
        M[d][a % d].push_back({a + (l-1)*d, 1});
    }

    for (auto m : M) {

        int d = m.first;

        for (auto mm : m.second) {

            int sum = 0;
            int j = 0;

            auto & S = mm.second;
            sort (S.begin(), S.end());

            for (int pos = mm.first; pos <= n; pos += d) {

                while (j < S.size() && S[j].first == pos && !S[j].second) {

                    sum++;
                    j++;
                }

                V[pos] += sum;

                while (j < S.size() && S[j].first == pos) {

                    sum--;
                    j++;
                }
            }
        }
    }


    for (int i = 1; i <= n; i++)
        cout << V[i] << " ";

    return 0;
}
