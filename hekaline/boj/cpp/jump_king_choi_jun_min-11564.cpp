#include <iostream>

using namespace std;

int main()
{
	long long k, a, b;
	cin >> k >> a >> b;
	
	long long ans = 0;
	
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		a = abs(a);
		b = abs(b);
		
		if (a > b)
			swap(a, b);
		
		ans = b / k - a / k;
		
		if (a % k == 0)
		{
			ans += 1;
		}
	}
	else
	{
		ans = abs(a) / k + abs(b) / k + (a <= 0 && 0 <= b);
	}
	cout << ans;
}
