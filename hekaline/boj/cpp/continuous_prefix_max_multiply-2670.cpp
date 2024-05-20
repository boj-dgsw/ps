// DP
// 연속 부분 최대 곱 구하기

#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	
	int n;
	cin >> n;
	
	vector<double> nums(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	nums[0] = 1.0;
	
	vector<double> dp(n + 1);
	double largest = -1.0;
	for (int i = 1; i <= n; i++)
	{
    // 점화식: 이전에 dp했던 수에 i번째 수 곱하기 혹은 i번째 수로 새로 시작
		dp[i] = max(dp[i-1] * nums[i], nums[i]);
		largest = max(largest, dp[i]);
	}

  // 자릿수 고정
	cout << fixed;

  // 소수점 최대 셋째 자리까지
	cout.precision(3);
	
	cout << largest;
}
