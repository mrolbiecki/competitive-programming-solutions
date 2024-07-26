//author: Marcin Rolbiecki
#include <bits/stdc++.h> 
#define ll long long
using namespace std;

ll n;
vector <pair <ll, int>> c;
int P [] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

void gen (ll l, ll d, int p, int a) { 
    
    if (p >= 9) return;

    c.push_back({l, d});
    for (int i = 1; i <= a; i++)
        if (l * P[p] <= n) {
            l *= P[p];
            gen(l, d * (i+1), p+1, i);
        } 
}

int main () {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    gen (1, 1, 0, 31);
    
    sort (c.begin(), c.end());

    int maxid = 0;
    for (int i = 0; i < c.size(); i++) 
       if (c[i].second > c[maxid].second)
          maxid = i; 
        
    cout << c[maxid].first;
    return 0;
}



