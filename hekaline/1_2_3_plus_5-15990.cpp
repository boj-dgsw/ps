#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using ll = long long;

constexpr int DIV = 1'000'000'009;
vector<vector<int>> memo(4, vector<int>(4));

ll getNumber(int n)
{
	if (memo.size() > n)
		return ((memo[n][1] + memo[n][2]) % DIV + memo[n][3]) % DIV;
	
	int oldSize = memo.size();
	memo.resize(n + 1);
	for (int i = oldSize; i <= n; i++)
	{
		memo[i].resize(4);
		memo[i][1] = (memo[i - 1][2] + memo[i - 1][3]) % DIV;
		memo[i][2] = (memo[i - 2][1] + memo[i - 2][3]) % DIV;
		memo[i][3] = (memo[i - 3][1] + memo[i - 3][2]) % DIV;
	}
	
	return ((memo[n][1] + memo[n][2]) % DIV + memo[n][3]) % DIV;
}

int main()
{
	FAST_IO;
	
	int t;
	cin >> t;
	
	memo[1][1] = 1;
	memo[2][2] = 1;
	memo[3][1] = 1;
	memo[3][2] = 1;
	memo[3][3] = 1;
	
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		cout << getNumber(n) << '\n';
	}
}
