// dp
// 새로운 점화식

#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

vector<ull> memo { 1, 1, 2, 5 };

ull t(int n);

int main()
{
	int n;
	cin >> n;
	
	memo.resize(n + 1, 0);
	cout << t(n);
}

ull t(int n)
{
	if (n <= 1) return 1;
	if (memo[n] != 0) return memo[n];
	
	ull temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += t(i) * t(n - i - 1);
	}
	
	return memo[n] = temp;
}
