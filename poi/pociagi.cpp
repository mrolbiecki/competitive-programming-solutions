//author: Marcin Rolbiecki (swm4r)
//https://szkopul.edu.pl/problemset/problem/_aNlLfqZBTY6FRf2_IGScTLn/site/?key=statement
#include <bits/stdc++.h>

const int N = 1e3+10;
int n, l, m;

std::map <std::string, int> ile;
std::map <std::string, std::vector <std::pair <int, int>> *> data;
int maxP [N], wej[N];
std::string P [N];

void init (int i) {

     if (data.count(P[i]) == 0) data[P[i]] = new std::vector <std::pair <int, int>>;
}

bool comp (std::pair <int, int> p, int val) {
    
    return p.first < val;
}

int check (int i) { 

    auto V = data[P[i]];

    int maxim = 0;

    for (auto p = std::lower_bound(V->begin(), V->end(), wej[i], comp); p != V->end(); p++)
        maxim = std::max(maxim, p->second);
    
    return maxim;
}

int main () {
	
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> l >> m;

    for (int i = 1; i <= n; i++)
        std::cin >> P[i];

    for (int i = 1; i <= n; i++)
        ile[ P[i] ]++;

    for (int i = 1; i <= n; i++) {

        init(i);
        data[ P[i] ]->push_back({0, ile [ P[i] ]});
    }

    for (int i = 1; i <= m; i++) {
        
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        maxP[a] = std::max( maxP[a], check(a) );
        ile[ P[a] ]--; 
        data[ P[a] ]->push_back({i, ile[P[a] ]});        

        if (a != c) {
            maxP[c] = std::max( maxP[c], check(c) );
            ile[ P[c] ]--;
            data[ P[c] ]->push_back({i, ile[ P[c] ]});
        }

        std::swap ( P[a][b-1], P[c][d-1] );

        ile[ P[a] ]++;
        wej[a] = i;
        init(a);
        data[ P[a] ]->push_back({i, ile[ P[a] ]});

        if (a != c) {
            ile[ P[c] ]++;
            init (c);
            wej[c] = i;
            data[ P[c] ]->push_back({i, ile[ P[c] ]});
        }
    }

    for (int i = 1; i <= n; i++)
        std::cout << std::max(maxP[i], check(i)) << std::endl;

	return 0;
}

