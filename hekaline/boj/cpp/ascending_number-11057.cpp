#include <iostream>
#include <bits/stdc++.h>

using namespace std;

constexpr int DIV = 10'007;

int main()
{
	int n;
	cin >> n;
	
	vector<vector<int>> memo(n + 1, vector<int>(10));
	for (int i = 0; i <= 9; i++)
	{
		memo[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k <= 9; k++)
			{
				memo[i][k] = (memo[i][k] + memo[i - 1][j]) % DIV;
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = (ans + memo[n][i]) % DIV;
	}
	
	cout << ans;
}
