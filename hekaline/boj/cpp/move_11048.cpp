// DP
// Silver II

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i < m; i++)
	{
		arr[0][i] += arr[0][i - 1];
	}
	
	for (int i = 1; i < n; i++)
	{
		arr[i][0] += arr[i - 1][0];
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int maxVal = max(arr[i - 1][j], arr[i][j - 1]);
			maxVal = max(maxVal, arr[i - 1][j - 1]);
			
			arr[i][j] += maxVal;
		}
	}
	
	cout << arr[n - 1][m - 1];
}
