// Greedy
// 현재 주유소보다 가격이 더 낮은 주유소가 나올 때까지의 거리만큼
// 현 주유소에서 그곳까지 갈 수 있는 만큼의 기름을 산다.

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> dist;
vector<int> price;
int n;

void input();
long long getMinPrice();

int main()
{
	FAST_IO;
	
	input();
	cout << getMinPrice();
}

long long getMinPrice()
{
	long long ans = 0;
	int lowestPrice = price[0];
	long long currDist = 0;
	
	for (int i = 0; i < n - 1; i++)
	{
		if (lowestPrice > price[i])
		{
			ans += lowestPrice * currDist;
			currDist = 0;
			lowestPrice = price[i];
		}
		currDist += dist[i];
	}
	if (currDist != 0)
	{
		ans += lowestPrice * currDist;
	}
	
	return ans;
}

void input()
{
	cin >> n;
	dist.resize(n - 1);
	price.resize(n);
	
	for (int i = 0; i < n - 1; i++)
	{
		cin >> dist[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	price[n - 1] = 0x7f'fff'fff;
}
