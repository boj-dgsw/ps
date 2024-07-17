#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n;
vector<int> l;

void input();
int findMaxDiff();

int main()
{
	FAST_IO;
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		input();
		cout << findMaxDiff() << '\n';
	}
}

int findMaxDiff()
{
	int diff = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int left = l[i];
		int right = l[i + 1];
		
		diff = max(diff, abs(right - left));
	}
	diff = max(diff, abs(l[0] - l[n - 1]));
	
	return diff;
}

void input()
{
	cin >> n;
	l.resize(n);
	
	for (auto& element : l)
	{
		cin >> element;
	} sort(l.begin(), l.end());
	
	// 통나무들이 ㅅ자 형태로 이루어져야 높이 차가 최소이다.
	vector<int> temp(n);
	for (int i = 0; i < n / 2; i++)
	{
		int left = l[i * 2];
		int right = l[i * 2 + 1];
		
		temp[i] = left;
		temp[n - i - 1] = right;
	}
	if (n % 2)
	{
		temp[n / 2] = l[n - 1];
	}
	
	l = temp;
}

// counterexample
// 1
// 9
// 37 43 2 16 40 10 32 29 41
//
// expected: 19
