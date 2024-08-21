// author: Marcin Rolbiecki
// date: 2024-08-21
// problem: https://szkopul.edu.pl/problemset/problem/6sGsrkO-SrmtogJ7u3RIOj3f/site/?key=statement

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+2;

int lo[maxN], hi[maxN];

int n, ans;

deque <int> max_que;

int get_lo () {
	return max_que.front();
}

void max_que_add (int el) {
	while (!max_que.empty() && el > max_que.back()) {
		max_que.pop_back();
	}
	max_que.push_back(el);
}

void max_que_del (int el) {
	if (max_que.front() == el) {
		max_que.pop_front();
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lo[i] >> hi[i];
	}
	
	int r = 1, l = 1;
	
	for (; r <= n; r++) {
		while (l < r && get_lo() > hi[r]) {
			max_que_del(lo[l]);
			l++;
		}
		max_que_add(lo[r]);
		ans = max(ans, r - l + 1);
	}
	
	cout << ans;
	
	return 0;
}
