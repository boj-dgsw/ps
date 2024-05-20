// DP
// 피보나치와 유사함

#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ull = unsigned long long;
using namespace std;

// 새 피보나치 함수
ull koong(int n);

// 피보나치 결과 기록 (메모이제이션)
ull memo[68] = {1,1,2,4,8,};

int main()
{
	FAST_IO;
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << koong(n) << '\n';
	}
}

ull koong(int n)
{
	if (memo[n] != 0) return memo[n];

  // 새로운 점화식
	return memo[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}
