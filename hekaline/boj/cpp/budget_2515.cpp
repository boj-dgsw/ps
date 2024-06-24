#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int n, m;
vector<int> arr;

void input();
int getMaxUpperLimit();

int sum(const vector<int>& arr)
{ return accumulate(arr.begin(), arr.end(), 0); }


int main()
{
	FAST_IO;
	input();
	
	cout << getMaxUpperLimit();
}

int getMaxUpperLimit()
{
	int maxUpperLimit = -1;
	
	// 예산 요청의 총합이 국가 예산보다 작거나 같다면
	if (sum(arr) <= m) return arr[n - 1];
	
	// else
	int left = 0;
	int right = arr[n - 1];
	
	while (left <= right)
	{
		int sum = 0;
		
		// 예산 상한선
		int upperLimit = (left + right) / 2;
		
		// 상한선을 넘지 않는 예산들의 값 + 상한선 초과 예산 개수 * 상한선
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= upperLimit)
			{
				sum += upperLimit * (n - i);
				
				break;
			}
			
			sum += arr[i];
		}
		
		// 예산 초과
		if (sum > m)
		{
			right = upperLimit - 1;
		} else
		{
			left = upperLimit + 1;
			maxUpperLimit = max(maxUpperLimit, upperLimit);
		}
		
	} // end of while
	
	return maxUpperLimit;
}

void input()
{
	cin >> n;
	arr.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	} sort(arr.begin(), arr.end());
	
	cin >> m;
}
