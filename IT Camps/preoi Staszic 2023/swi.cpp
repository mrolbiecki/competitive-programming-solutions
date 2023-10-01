#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll ten[17];
vector <ll> nums;

bool isprime (ll x) {

	for (ll i = 2; i*i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int dl (ll x) {return log(x)/log(10)+1;}

priority_queue <ll> Q;

void gen () {

	while (!Q.empty()) {
	
		ll f = -1*Q.top(); Q.pop();
		int d = dl(f);
		
		for (ll i = 1; i <= 9; i++) {
		
			ll num = i*ten[d]+f;
			if (num <= ten[13] && isprime(num)) {
				Q.push(-1*num);
				nums.push_back(num);
			}	
		}
	}
}

void prec() {
	
	ten[0]=1;
	for (int i = 1; i <= 16; i++)
		ten[i] = ten[i-1]*10;
}

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	prec();
	
	nums = {2, 3, 5, 7};
	Q.push(-3); Q.push(-7);

	gen();
	sort (nums.begin(), nums.end());
	
	for (auto num : nums)
		cout << num << ", ";
	cout << '\n';
}
