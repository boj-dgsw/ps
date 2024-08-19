// Dynamic Programming
// Graph
// Silver I

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

constexpr int DIV = 1'000'000'007;

int main()
{
	int n;
	cin >> n;
	
	vector<vector<int>> neighbors
	{
		{1, 2},
		{0, 2, 3},
		{0, 1, 3, 4},
		{1, 2, 4, 5},
		{2, 3, 5, 7},
		{3, 4, 6},
		{5, 7},
		{4, 6}
	};
	
	vector<vector<int>> memo(8, vector<int>(n + 1));
	memo[0][0] = 1;
	
	for (int time = 1; time <= n; time++)
	{
		for (int loc = 0; loc < 8; loc++)
		{
			for (const int& neighbor : neighbors[loc])
			{
				memo[neighbor][time] += memo[loc][time - 1];
				memo[neighbor][time] %= DIV;
			}
		}
	}
	
	
	cout << memo[0][n];
}
