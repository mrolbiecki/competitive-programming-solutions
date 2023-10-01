//https://www.spoj.com/problems/GSS3/
#include <bits/stdc++.h>
using namespace std;
 
#define INF INT_MAX
 
struct vertice {
 
    int maxPref;
    int maxSuf;
    int maxSub;
    int sum;
};
 
vector <vertice> T;
int n, x, m;
 
vertice makeVertice (int a) {
 
    vertice A;
    A.maxPref = a;
    A.maxSuf = a;
    A.maxSub = a;
    A.sum = a;
 
    return A;
}
 
vertice mergeV (const vertice &A, const vertice &B) {
 
    vertice C;
 
    if (A.sum == -INF)
        return B;
    if (B.sum == -INF)
        return A;
 
    C.sum = A.sum + B.sum;
    C.maxPref = max (A.maxPref, A.sum + B.maxPref);
    C.maxSuf = max (B.maxSuf, B.sum + A.maxSuf);
 
    C.maxSub = max(A.maxSuf + B.maxPref, max(A.maxSub, B.maxSub));
 
    return C;
}
 
vertice q (int id, int lq, int rq, int l, int r) {
 
    if (r < lq || l > rq || r < l)
        return makeVertice(-INF);
 
    if (l >= lq && r <= rq)
        return T[id];
 
    int mid = (l + r) / 2;
 
    return mergeV ( q(id*2, lq, rq, l, mid), q(id*2+1, lq, rq, mid+1, r) );
}
 
void change (int id, int val) {
 
    id--;
 
    T[x+id] = makeVertice(val);
 
    for (int i = (x+id)/2; i > 0; i/=2)
        T[i] = mergeV(T[i*2], T[i*2+1]);
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    cin >> n;
    x = ceil(log(n)/log(2));
    x = pow(2, x);
 
    T.resize(2*x);
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        T[x + i] = makeVertice(a);
    }
    for (int i = x + n; i < 2*x; i++)
        T[i] = makeVertice(0);
 
    for (int i = x - 1; i > 0; i--)
        T[i] = mergeV(T[2*i], T[2*i+1]);
 
    cin >> m;
 
    for (int i = 0; i < m; i++) {
 
        int c, a, b;
        cin >> c >> a >> b;
 
        if (c)
            cout << q(1, a, b, 1, x).maxSub << endl;
        else
            change(a, b);
    }
 
    return 0;
} 
