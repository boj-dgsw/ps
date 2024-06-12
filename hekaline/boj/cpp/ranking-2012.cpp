// Greedy
// Silver III

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

bool isInRange(int i, int n)
{ return i >= 0 && i <= n; }

int main()
{
	FAST_IO;
	int n;
	cin >> n;
	
	vector<bool> checked(n + 1, false);
	vector<int> arr(n);
	long long ans = 0;
	
	for (auto& e : arr) cin >> e;
	sort(arr.begin(), arr.end());
	
	for (int i = 1; i <= arr.size(); i++)
	{
		ans += abs(arr[i - 1] - i);
	}
	
	cout << ans;
}
