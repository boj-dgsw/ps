// 위상 정렬 + 방향 비순환 그래프
// 그래프 이론
// start가 to보다 우선으로 출력되어야 함


#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n + 1);
	vector<int> inDegree(n + 1);
	queue<int> q;
	
	for (int i = 0; i < m; i++)
	{
		int start, to;
		cin >> start >> to;
		
		arr[start].emplace_back(to);
		inDegree[to] += 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.emplace(i);
		}
	}
	
	while (!q.empty())
	{
		int currI = q.front(); q.pop();
		
		cout << currI << ' ';
		
		for (int nextI : arr[currI])
		{
			inDegree[nextI] -= 1;
			if (inDegree[nextI] == 0)
			{
				q.emplace(nextI);
			}
		}
	}
}
