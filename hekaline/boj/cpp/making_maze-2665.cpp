// Dijkstra
// 0-1 BFS
// Gold IV
// 0을 1, 1을 0으로 치환해서 왼쪽 위에서 오른쪽 아래까지의 거리 구하기

#include <iostream>
#include <bits/stdc++.h>
#define PQ_TYPE pair<short, pair<short, short>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

struct cmp
{
	bool operator()(const PQ_TYPE& a, const PQ_TYPE& b)
	{
		return a.first > b.first;
	}
};

int n;
vector<vector<bool>> arr;

bool canVisit(const int& i, const int& j)
{ return i >= 0 && j >= 0 && i < n && j < n; }

int dijkstra();

void input();

int main()
{
	FAST_IO;
	input();
	
	cout << dijkstra();
}

int dijkstra()
{
	vector<pair<short, short>> offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	vector<vector<short>> minDist(n, vector<short>(n, 51 * 51));
	
	priority_queue<PQ_TYPE, vector<PQ_TYPE>, cmp> pq;
	pq.push({0, {0, 0}});
	
	while (!pq.empty())
	{
		auto currVal = pq.top(); pq.pop();
		auto& currDist = currVal.first;
		auto& currCoord = currVal.second;
		
		if (minDist[currCoord.first][currCoord.second] < currDist)
			continue;
		
		minDist[currCoord.first][currCoord.second] = currDist;
		
		for (const auto& offset : offsets)
		{
			short newI = currCoord.first + offset.first;
			short newJ = currCoord.second + offset.second;
			
			if (!canVisit(newI, newJ)) continue;
			
			if (currDist + arr[newI][newJ] < minDist[newI][newJ])
			{
				minDist[newI][newJ] = currDist + arr[newI][newJ];
				pq.push({minDist[newI][newJ], {newI, newJ}});
			}
		}
	}
	
	return minDist[n - 1][n - 1];
}

void input()
{
	cin >> n;
	arr.resize(n, vector<bool>(n));
	
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = abs(temp[j] - '1');
		}
	}
}
