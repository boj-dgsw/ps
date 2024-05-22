// dp
// 부분 수열의 최대 합 구하기

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void input(int& n, vector<int>& arr);
int GetMaximumSubarray(int n, const vector<int>& arr);

int main()
{
	FAST_IO;
	
	int t;
	cin >> t;
	
	vector<int> arr;
	int n;
	
	while (t--)
	{
		input(n, arr);
		cout << GetMaximumSubarray(n, arr) << '\n';
	}
}

void input(int& n, vector<int>& arr)
{
	cin >> n;
	arr.resize(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}

int GetMaximumSubarray(int n, const vector<int>& arr)
{
	vector<long long> memo(n + 1);
	long long maxVal = -2147483648;
	
	for (int i = 1; i <= n; i++)
	{
		memo[i] = max(memo[i - 1] + arr[i], (long long)arr[i]);
		maxVal = max(maxVal, memo[i]);
	}
	
	return maxVal;
}
