// Prefix sum
// Gold V

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); \
		cin.tie(nullptr);\
		cout.tie(nullptr);

using namespace std;
using ld = long double;

int n, q;
vector<int> xArr, yArr;
vector<ld> rightHp, leftHp;

void input();
ld pythagorean(int x, int y);
int getWeight(int fromY, int toY);

int main()
{
	FAST_IO;
	input();
	cout << fixed;
	
	while (q--)
	{
		int i, j;
		cin >> i >> j;

		if (i < j)
		{
			// to right
			cout << rightHp[j] - rightHp[i] << '\n';
		} else
		{
			cout << leftHp[j] - leftHp[i] << '\n';
		}
	}
}

ld pythagorean(int x, int y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

int getWeight(int fromY, int toY)
{
	return fromY < toY ? 3 : fromY == toY ? 2 : 1;
}

void input()
{
	cin >> n >> q;
	xArr.resize(n + 1);
	yArr.resize(n + 1);
	rightHp.resize(n + 1);
	leftHp.resize(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> xArr[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> yArr[i];
	}
	
	for (int i = 2; i <= n; i++)
	{
		rightHp[i] = pythagorean(xArr[i - 1] - xArr[i], yArr[i - 1] - yArr[i]) *
				getWeight(yArr[i - 1], yArr[i]);
		
		rightHp[i] += rightHp[i - 1];
	}
	
	for (int i = n - 1; i >= 1; i--)
	{
		leftHp[i] = pythagorean(xArr[i + 1] - xArr[i], yArr[i + 1] - yArr[i]) *
				getWeight(yArr[i + 1], yArr[i]);
		leftHp[i] += leftHp[i + 1];
	}
}
