// binary search
// bruteforce
// implementation
// Silver I

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll binary_search();
vector<ll> times;
ll n, s, m;

int main()
{
	cin >> n >> s;
	cin >> m;
	
	n = n - s;
	times.resize(m + 1);
	
	for (int i = 1; i <= m; i++)
	{
		cin >> times[i];
	}
	
	cout << binary_search();
}

ll binary_search()
{
	ll left = 0, right = 100'000'001;
	ll time(0);
	
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		// cout << left << ' ' << mid << ' ' << right << '\n';
		
		ll taken = 0;
		
		for (int i = 1; i <= m; i++)
		{
			taken += (mid / times[i]) + 1;
		}
		
		if (taken < n)
		{
			left = mid + 1;
		}
		else if (taken >= n)
		{
			time = mid;
			right = mid - 1;
		}
	}
	
	if (time == 0)
	{
		return n;
	}
	
	ll taken = 0;
	for (int i = 1; i <= m; i++)
	{
		taken += (time - 1) / times[i] + 1;
	}
	
	for (int i = 1; i <= m; i++)
	{
		taken += time % times[i] == 0;
		
		if (taken == n)
			return i;
	}
	
	return -1;
}
