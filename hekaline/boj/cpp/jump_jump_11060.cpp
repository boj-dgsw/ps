#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

constexpr int MAX = 100001;
vector<int> arr;
vector<int> memo;

int main()
{
	FAST_IO;
	
	int n;
	cin >> n;
	
	memo.resize(n + 1, MAX);
	memo[0] = memo[1] = 0;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= arr[i] && i + j <= n; j++)
		{
			memo[i + j] = min(memo[i + j], memo[i] + 1);
		}
	}
	
//	for (int i = 1; i <= n; i++)
//	{
//		cout << memo[i] << ' ';
//	} cout << '\n';
	
	cout << (memo[n] == MAX ? -1 : memo[n]);
}
