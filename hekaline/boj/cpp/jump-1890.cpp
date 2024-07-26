// Silver I
// DP

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	
	// 게임 판
	vector<vector<ll>> arr(n + 1, vector<ll>(n + 1));
	
	// [i][j]로 가는 경로의 개수
	vector<vector<ll>> memo(n + 1, vector<ll>(n + 1));
	memo[1][1] = 1; // 시작 칸의 경로 개수는 1개
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == n && j == n) break;
			if (i + arr[i][j] <= n)
			{
				// 아래쪽 방향
				memo[i + arr[i][j]][j] += memo[i][j];
			}
			if (j + arr[i][j] <= n)
			{
				// 오른쪽 방향
				memo[i][j + arr[i][j]] += memo[i][j];
			}
		}
	}
	
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++ )
//		{
//			cout << memo[i][j] << ' ';
//		} cout << '\n';
//	}
	cout << memo[n][n];
}
