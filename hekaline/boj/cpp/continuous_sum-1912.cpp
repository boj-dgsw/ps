// dp
// 수열 중 한 개 이상의 "연속된" 수를 골라 가장 큰 합을 구해야 함

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> dp(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	
	int res = vec[0];
	dp[0] = vec[0];
	for (int i = 1; i < n; i++)
	{
    // 전에 구했던 연속된 합이랑 현재 수를 더한 값 혹은
    // 현재 수가 더 크면 현재 수를 넣는다
		dp[i] = max(dp[i - 1] + vec[i], vec[i]);

    // 정답은 dp[i]들 중 최댓값
		res = max(res, dp[i]);
	}
	
	cout << res;
}
