// 설명 맨 아래에
// BFS / DFS

#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void input();
void bfs(int i, int j);

int n, m;
int groupN = 0;

vector<vector<bool>> map;
vector<vector<int>> groupMap;
vector<int> groupArr;
vector<pair<int, int>> wallCoords;
vector<pair<int, int>> airCoords;
vector<vector<bool>> visited;


bool isIndexValid(int currI, int currJ)
{
	return currI >= 0 && currJ >= 0 && currI < n && currJ < m;
}

int main()
{
	input();

	for (pair<int, int> coord : airCoords)
	{
		if (visited[coord.first][coord.second] == false)
			bfs(coord.first, coord.second);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				printf("0");
			else // if map[i][j] == '1'
			{
				vector<pair<int, int>> coordToAdd = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
				int sum = 1;
				set<int> groupSet;

				for (auto add : coordToAdd)
				{
					int nextI = i + add.first;
					int nextJ = j + add.second;

					if (!isIndexValid(nextI, nextJ)) continue;
					if (map[nextI][nextJ] == 1) continue;

					if (groupSet.find(groupMap[nextI][nextJ]) == groupSet.end())
					{
						sum += groupArr[groupMap[nextI][nextJ]];
						groupSet.insert(groupMap[nextI][nextJ]);
					}
				
				}

				printf("%d", sum % 10);
			}
		} printf("\n");
	}	

}



void bfs(int i, int j)
{
	queue<pair<int, int>> coordQ;
	vector<pair<int, int>> affectedAir;

	coordQ.emplace(i, j);

	while (!coordQ.empty())
	{
		auto currCoord = coordQ.front(); coordQ.pop();
		int currI = currCoord.first;
		int currJ = currCoord.second;

		if (visited[currI][currJ]) continue;

		visited[currI][currJ] = true;
		affectedAir.emplace_back(currI, currJ);

		vector<pair<int, int>> coordToAdd = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

		for (auto add : coordToAdd)
		{
			int nextI = currI + add.first;
			int nextJ = currJ + add.second;

			if (!isIndexValid(nextI, nextJ)) continue;

			if (visited[nextI][nextJ] || map[nextI][nextJ] == 1) continue;

			coordQ.emplace(nextI, nextJ);
		}
	}

	for (auto coord : affectedAir)
	{
		groupMap[coord.first][coord.second] = groupN;
	}

	int size = affectedAir.size();
	groupArr.push_back(size);
	groupN += 1;
}

void input()
{
	scanf("%d%d", &n, &m);

	map.resize(n);
	groupMap.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		groupMap[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			int temp;
			scanf("%1d", &temp);

			map[i][j] = (bool)temp;

			if (map[i][j] == 1)
			{
				wallCoords.emplace_back(i, j);
			}
			else
			{
				airCoords.emplace_back(i, j);
			}
		}
	}
}

// 그래프 탐색인데 벽을 탐색하는 게 아니라 빈 공간을 탐색해 그 공간의 크기를 탐색한 후 그룹 배열[탐색한 좌표의 i][탐색한 좌표의 j]에 넣어야 한다. (시간 때문)
// 그 후 1(벽)들에서부터 상하좌우를 탐색해야 하는데, 이는 0의 group 크기를 그려놓은 배열을 이용하는 것이다.
// 추가적으로 0의 group들을 매길 번호를 각 그룹마다 다르게 부여해야 한다. 그렇지 않으면 
/// 0 0 0
/// 0 1 0
/// 0 0 0 처럼 상하좌우 탐색할 때 같은 그룹을 탐색해버리는 경우가 있으니 그룹 숫자를 매기는 것이다.
