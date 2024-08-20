// Data Structures
// Priority Queue
// Silver III

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);\
		cin.tie(nullptr);                        \
		cout.tie(nullptr);

using namespace std;


int main()
{
	FAST_IO;
	int n;
	cin >> n;
	
	priority_queue<int> pq;
	
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		
		if (a == 0)
		{
			if (pq.empty())
				cout << -1 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		} else
		{
			for (int j = 0; j < a; j++)
			{
				int val; cin >> val;
				pq.emplace(val);
			}
		}
	}
}
