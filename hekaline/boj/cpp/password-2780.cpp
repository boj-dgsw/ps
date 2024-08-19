// Dynamic Programming
// Graph
// Silver I

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);\
		cin.tie(nullptr);\
		cout.tie(nullptr);

using namespace std;

constexpr int DIV = 1'234'567;

int maxN(0);
vector<vector<int>> memo(10, vector<int>(1001));
int getMethodCount(int n);

int main()
{
	FAST_IO;
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;
		
		cout << getMethodCount(n) << '\n';
	}
}

int getMethodCount(int n)
{
	if (maxN == 0)
	{
		// "memo" not initialized
		for (int i = 0; i < 10; i++)
		{
			memo[i][1] = 1;
		}
		
		maxN = 1;
	}
	
	vector<vector<int>> neighbors
	{
		{7},
		{2, 4},
		{1, 5, 3},
		{2, 6},
		{1, 5, 7},
		{2, 4, 6, 8},
		{3, 5, 9},
		{4, 8, 0},
		{5, 7, 9},
		{6, 8}
	};
	
	if (maxN < n)
	{
		for (int nextLen = maxN + 1; nextLen <= n; nextLen++)
		{
			for (int pw = 0; pw <= 9; pw++)
			{
				for (const int& neighbor : neighbors[pw])
				{
					memo[neighbor][nextLen] += memo[pw][nextLen - 1];
					memo[neighbor][nextLen] %= DIV;
				}
			}
		}
		maxN = n;
	}
	
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += memo[i][n];
	}
	
	return ans % DIV;
}
