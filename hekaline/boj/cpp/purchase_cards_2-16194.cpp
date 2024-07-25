#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> memo(n);
	for (int i = 0; i < n; i++)
	{
		cin >> memo[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			memo[i] = min(memo[i], memo[j] + memo[i - j - 1]);
		}
	}
	
	cout << memo[n - 1];
}
