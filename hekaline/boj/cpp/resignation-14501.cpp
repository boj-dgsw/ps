// DP
// Brute force

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false);\
				cin.tie(nullptr);\
				cout.tie(nullptr);

using namespace std;

struct tp
{
	int time;
	int price;
	
	tp(int _time, int _price) : time(_time), price(_price) {}
	tp() : time(0), price(0) {}
};

int n;
vector<tp> counsels;
vector<int> memo;

void input();
void fillMemo();

int main()
{
	FAST_IO;
	input();
	fillMemo();
	cout << memo[n + 1];
}

void fillMemo()
{
	for (int i = 1; i <= n; i++)
	{
		// memo[j]: j일까지 상담했을 때 수익 최댓값
		for (int j = 1; j <= n + 1; j++)
		{
			// 퇴사 전까지 상담을 할 수 있다면
			if (i + counsels[i].time <= j)
			{
				// i일에 상담을 할 지 안 할지를 정한다:
				// 이 상담으로 인해 현재까지 기록된 j일까지의 최대 수익보다 더 벌 수 있는지 따져야 한다.
				memo[j] = max(memo[j], memo[i] + counsels[i].price);
			}
		}
	}
}

void input()
{
	cin >> n;
	
	counsels.resize(n + 2);
	memo.resize(n + 2);
	
	for (int i = 1; i <= n; i++)
	{
		// i일 상담에 걸리는 시간 및 상담 비용
		cin >> counsels[i].time >> counsels[i].price;
	}
}
