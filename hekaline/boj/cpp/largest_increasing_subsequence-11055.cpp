#include <iostream>
#include <vector>
#define OUT

// 빠른 입출력 (C 입출력과의 동기화 해제)
#define FAST_IO std::ios_base::sync_with_stdio(false);\
				std::cin.tie(nullptr);\
				std::cout.tie(nullptr);
using std::cin;
using std::cout;
using std::vector;
using std::max;

// n과 수열을 구성하는 n개의 수를 받는다.
void input(OUT int&, OUT vector<int>&);

// dp 배열을 점화식을 이용해 채운다.
void fillDp(OUT vector<int>& dp, OUT vector<int>& arr);

// vector 요소 중 가장 큰 것을 찾는다.
int findMax(const vector<int>&);

int main()
{
	FAST_IO;
	
	int n;
	vector<int> arr;
	input(OUT n, OUT arr);
	
    // dp 배열의 크기는 n이다.
	vector<int> dp(n);
	fillDp(OUT dp, OUT arr);
    
    // dp 배열 중 가장 큰 수 출력
	cout << findMax(dp);
}

int findMax(const vector<int>& vec)
{
    // -2147483648
	int maxElement = -0x3fffffff - 1;
    // 벡터 크기
	size_t vecLen = vec.size();
	
	for (size_t i = 0; i < vecLen; i++)
	{
		maxElement = max(maxElement, vec[i]);
	}
	
	return maxElement;
}

void fillDp(OUT vector<int>& dp, OUT vector<int>& arr)
{
	// dp[i] = i번째 인덱스까지의 가장 큰 증가하는 부분 수열의 합
	
	size_t vecLen = dp.size();
	for (size_t i = 0; i < vecLen; i++)
	{
		dp[i] = arr[i];
		
		// 첫번째 ~ i번째까지의 가장 큰 증가하는 부분 수열의 합을 구한다.
		// dp[i]를 구성하는 수열 중 arr[i]가 가장 커야 한다.
		for (size_t j = 0; j < i; j++)
		{
			// 수가 증가하면서 (arr[i] 이전의 수가 크면 안 됨) &&
            // 기록된 가장 큰 증가하는 부분 수열보다 더 큰 게 있다면
            // (j까지 기록된 가장 큰 증가하는 부분 수열에 더 큰 수인 i를 더했을 때 
            // 그것이 dp[i]보다 더 크다면 더 큰 증가하는 부분 수열의 합이 나온 것)
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
	}
}


void input(OUT int& n, OUT vector<int>& vec)
{
	cin >> n;
	vec.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
}
