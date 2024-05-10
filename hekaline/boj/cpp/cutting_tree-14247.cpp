// Greedy
// n개의 나무를 n일에 걸쳐 자르는데, 최대한 많은 나무를 얻어야 한다.
// 2번째 줄에는 현재 n개의 나무 각각의 길이를 받고
// 3번째 줄에는 각각의 나무가 하루에 자라는 길이를 받는다.

#include <iostream>
#include <vector>
#include <algorithm>
#define LEN first
#define GROW second
#define FAST_IO ios_base::sync_with_stdio(false); \
				cin.tie(nullptr);                 \
				cout.tie(nullptr);

using namespace std;

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.GROW < b.GROW;
	}
};

void input();
long long getMaxAmount();

int n;
vector<pair<int, int>> v;

int main()
{
	FAST_IO;
	
	input();
	cout << getMaxAmount();
}

long long getMaxAmount()
{
	long long ans = 0l;
	
	for (int i = 0; i < n; i++)
	{
    // 하루에 가장 많이 자라는 나무를 가장 늦게 자른다.
		ans += v[i].LEN + v[i].GROW * i;
	}
	
	return ans;
}

void input()
{
	cin >> n;
	v.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].LEN;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].GROW;
	}

  // 핵심은 하루 당 가장 많이 자라는 나무를 가장 늦게 자르는 것이다.
	sort(v.begin(), v.end(), cmp());
}
