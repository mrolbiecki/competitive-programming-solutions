//https://www.spoj.com/problems/KQUERY/
#include <bits/stdc++.h>
using namespace std;
 
vector <vector <int> > V;
int n, x, nq;
 
vector <int> vMerge (const vector <int> &v1, const vector <int> &v2) {
 
    vector <int> v3;
    int a = 0, b = 0;
 
    while (a != v1.size() || b != v2.size()) {
 
        if (a == v1.size())
            v3.push_back(v2[b++]);
        else if (b == v2.size())
            v3.push_back(v1[a++]);
        else if (v1[a] < v2[b])
            v3.push_back(v1[a++]);
        else
            v3.push_back(v2[b++]);
    }
 
    return v3;
}
 
void build () {
 
    for (int i = x - 1; i > 0; i--)
        V[i] = vMerge(V[2*i], V[2 * i + 1]);
}
 
int q (int x, int id, int lq, int rq, int l, int r) {
 
 
    if (r < lq || l > rq)
        return 0;
    if (l >= lq && r <= rq) {
 
        auto it = upper_bound(V[id].begin(), V[id].end(), x);
        return (V[id].end() - it);
    }
 
    int mid = (l + r) / 2;
 
    return q(x, id*2, lq, rq, l, mid) + q(x, id*2+1, lq, rq, mid + 1, r);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    cin >> n;
    x = ceil(log(n) / log(2));
    x = pow (2, x);
 
    V.resize(2 * x);
 
    for (int i = 0; i < n; i++) {
 
        vector <int> v (1);
        cin >> v[0];
 
        V[x + i] = v;
    }
    for (int i = x + n; i < 2*x; i++)
        V[i] = {0};
 
    build();

    cin >> nq;
 
    for (int i = 0; i < nq; i++) {
 
        int a, b, c;
        cin >> a >> b >> c;
 
        cout << q(c, 1, a, b, 1, x) << endl;
    }
 
 
    return 0;
}
