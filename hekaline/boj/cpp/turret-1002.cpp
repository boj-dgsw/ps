// x, y, r로 그린 두 원이 얼마나 많이 겹치는지
// 무한, 0, 1, 또는 2만 나온다.

#include <iostream>
#include <bits/stdc++.h>
#define PII pair<int, int>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		long double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		
		// 같은 원(두 원의 모든 점이 겹침)
		if (dist == 0. && r1 == r2)
		{
			cout << -1 << '\n';
		}
		// 원의 일부 면이 겹쳐 교점이 2개인 상태
		// 전자만 만족하면 한 원이 다른 원을 포함하는 상태도 포함됨.
		else if (r1 + r2 > dist && abs(r1 - r2) < dist)
		{
			cout << 2 << '\n';
		}
		// 1. 서로 한 점에서 만나지만 한 원이 다른 원을 포함하고 있지 않음
		// 2 / 3. 한 원이 다른 원을 포함하고 있고 두 원의 점이 한 점에서 만남
		else if (dist == r1 + r2 || dist + r2 == r1 || dist + r1 == r2)
		{
			cout << 1 << '\n';
		}
        // 아무런 상태도 만족하지 못함.
		else
			cout << 0 << '\n';
	}
}
