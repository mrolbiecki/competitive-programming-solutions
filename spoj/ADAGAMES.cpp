//2022-10-06
//author: Marcin Rolbiecki
//https://www.spoj.com/problems/ADAGAME5/
#include <bits/stdc++.h>
using namespace std;
 
int grid [6][6] = {
	{0, 1, 2, 3, 4, 5},
	{1, 2, 0, 4, 5, 3},
	{2, 0, 1, 5, 3, 4},
	{3, 4, 5, 0, 1, 2},
	{4, 5, 3, 1, 2, 0},
	{5, 3, 4, 2, 0, 1}};
	
int grid_add [2][2] = {
	{0, 1},
	{1, 0}};
	
int add (int x, int y) {
	
	if (x == y)
		return 0;
	if (x < 2 && y < 2)
		return grid_add[x][y];
		
	return grid_add[x%2][y%2] + 2*add(x/2, y/2);
}
	
int n;
 
int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while (tt--) {
		
		int res = 0;
		
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			res ^= grid[x%6][y%6] + 6*add(x/6, y/6);
		}
		
		cout << (res ? "Ada" : "Vinit") << '\n';	
	}
	
	return 0;
}
