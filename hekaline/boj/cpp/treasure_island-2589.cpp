// Gold V
// BFS

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

constexpr char LAND = 'L';
constexpr char WATER = 'W';

vector<vector<char>> arr;
int n, m;

int getDistance(pair<int, int> startsAt);
bool canVisit(int i, int j)
{
	bool isInRange = i >= 0 && j >= 0 && i < n && j < m;
	return isInRange && arr[i][j] == LAND;
}

int main()
{
	cin >> n >> m;
	arr.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == LAND)
			{
				ans = max(ans, getDistance({i, j}));
			}
		}
	}
	
	cout << ans;
}

int getDistance(pair<int, int> startsAt)
{
	int maxDist = -1;
	queue<pair<int, int>> q;
	q.emplace(startsAt);
	
	vector<vector<int>> visited(n, vector<int>(m));
	visited[startsAt.first][startsAt.second] = 1;
	
	while (!q.empty())
	{
		pair<int, int> currCoord = q.front(); q.pop();
		
		pair<int, int> offsets[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (const auto& offset : offsets)
		{
			int newI = currCoord.first + offset.first;
			int newJ = currCoord.second + offset.second;
			
			if (canVisit(newI, newJ) && !visited[newI][newJ])
			{
				visited[newI][newJ] = visited[currCoord.first][currCoord.second] + 1;
				maxDist = max(maxDist, visited[newI][newJ]);
				q.emplace(newI, newJ);
			}
		}
	}
	
	return maxDist - 1;
}
