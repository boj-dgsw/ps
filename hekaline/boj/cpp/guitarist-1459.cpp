// Silver I
// DP

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
constexpr int OUT_OF_RANGE = -1;

bool isInRange(int val, int m)
{
	return val >= 0 && val <= m;
}

int main()
{
	FAST_IO;
	int n, s, m;
	cin >> n >> s >> m;
	
	vector<short> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	vector<vector<bool>> memo(n + 1, vector<bool>(1001));
	memo[0][s] = true;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (!memo[i - 1][j]) continue;
			if (isInRange(j + arr[i], m))
			{
				memo[i][j + arr[i]] = true;
			}
			if (isInRange(j - arr[i], m))
			{
				memo[i][j - arr[i]] = true;
			}
		}
		
	}
	
	for (int i = 1000; i >= 0; i--)
	{
		if (memo[n][i])
		{
			cout << i;
			return 0;
		}
	}
	
	cout << -1;
}
