#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO
	
	int n, m;
	cin >> n >> m;
	
	int minSetPrice = 0x7'fff'fff;
	int minSinglePrice = 0x7'fff'fff;
	
	for (int i = 0; i < m; i++)
	{
		int set, single;
		cin >> set >> single;
		
		minSetPrice = min(minSetPrice, set);
		minSinglePrice = min(minSinglePrice, single);
	}
	
	int minPrice = min(minSetPrice * (n / 6) + minSinglePrice * (n % 6), minSetPrice * (n / 6 + (bool)(n % 6)));
	minPrice = min(minPrice, minSinglePrice * n);
	
	cout << minPrice;
}
