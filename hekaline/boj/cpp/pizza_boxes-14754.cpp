// Greedy
// 옆에서 볼 때랑 앞에서 볼 때 영향이 없도록 피자 박스 제거
// Silver II

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	
	vector<vector<int>> arr(n, vector<int>(m));
	for (auto& line : arr)
		for (auto& element : line)
		{
			cin >> element;
			ans += element;
		}
	
	vector<int> checkSide(n);
	vector<int> checkFront(m);
	map<int, bool> checkNum;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (checkFront[j] < arr[i][j])
				checkFront[j] = arr[i][j];
			
			if (checkSide[i] < arr[i][j])
				checkSide[i] = arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (!checkNum[checkSide[i]])
		{
			checkNum[checkSide[i]] = true;
			ans -= checkSide[i];
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		if (!checkNum[checkFront[i]])
		{
			checkNum[checkFront[i]] = true;
			ans -= checkFront[i];
		}
	}
	
	cout << ans;
}
