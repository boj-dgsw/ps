// Implementation
// Ad hoc
// Silver III

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector visited(n + 1, false);
	visited[0] = true;
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		
		if (!visited[temp - 1])
		{
			ans++;
		}
		
		visited[temp] = true;
	}
	
	cout << ans;
}
