// DP

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); \
				cin.tie(nullptr);                 \
				cout.tie(nullptr);

using namespace std;

int n;
int main()
{
	FAST_IO;
	cin >> n;
	
	// 돌 가져가는 횟수가 홀수면 상근 승
	// 짝수 2(1, 1), 7(3, 4 / 1, 4, 1, 1),
	// 짝수가 보장되는 점화식: memo[i-1] && memo[i-3] && memo[i-4]
	vector<bool> memo {1, 1, 0, 1, 1};
	memo.resize(n);
	
	for (int i = 5; i <= n; i++)
	{
		memo[i] = !(memo[i - 1] && memo[i - 3] && memo[i - 4]);
	}
	
	cout << (memo[n] ? "SK" : "CY");
}
