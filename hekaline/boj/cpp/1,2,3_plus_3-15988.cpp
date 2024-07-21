#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> memo(4);
constexpr int DIV = 1'000'000'009;

int getNumber(int n)
{
	if (memo.size() > n)
	{
		return memo[n];
	}
	
	for (int i = memo.size(); i <= n; i++)
	{
		int iVal = ((memo[i - 1] + memo[i - 2]) % DIV + memo[i - 3]) % DIV;
		memo.push_back(iVal);
	}
	
	return memo[n];
}

int main()
{
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		
		cout << getNumber(n) << '\n';
	}
}
