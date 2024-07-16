#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<>> pq;

ll getSum();

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		pq.push(temp);
	}
	
	for (int i = 0; i < m; i++)
	{
		ll first = pq.top(); pq.pop();
		ll second = pq.top(); pq.pop();
		
		ll val = first + second;
		pq.push(val);
		pq.push(val);
	}
	
	cout << getSum();
}

ll getSum()
{
	ll sum = 0;
	
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	
	return sum;
}
