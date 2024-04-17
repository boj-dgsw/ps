#include <iostream>
#include <vector>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define OUT

using namespace std;

constexpr char EMPTY = '.';
constexpr char TREE = '+';
constexpr char WOLF = 'V';
constexpr char HUT = 'J';
constexpr int INF = 0x3f3f3f3f;

struct Coord
{
	int i;
	int j;
	
	Coord() : i(0), j(0) {}
	Coord(int n) = delete;
	Coord(int _i, int _j) : i(_i), j(_j){}
};

#define WOLF_ELEMENT pair<Coord, int>
#define PQ_WE priority_queue<WOLF_ELEMENT, vector<WOLF_ELEMENT>, Cmp>

struct Cmp
{
	bool operator()(const WOLF_ELEMENT& a, const WOLF_ELEMENT& b)
	{
		return a.second < b.second;
	}
};

int n;
int m;
vector<vector<char>> map;
vector<vector<int>> minDistToTree;
queue<Coord> treeQ;
Coord wolfCoord;
Coord hutCoord;

void input();
void getMinDistToTree();
int solve();
bool isIndexInRange(int currI, int currJ)
{
	return currI >= 0 && currJ >= 0 && currI < n && currJ < m;
}


int main()
{
	FAST_IO
	
	input();
	getMinDistToTree();
	cout << solve();
}

int solve()
{
	priority_queue<WOLF_ELEMENT, vector<WOLF_ELEMENT>, Cmp> pq;
	//priority_queue<int> answerQ;
	vector<vector<bool>> visited;
	
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		visited[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
	visited[wolfCoord.i][wolfCoord.j] = true;
	
	pq.push({wolfCoord, minDistToTree[wolfCoord.i][wolfCoord.j]});
	
	while (!pq.empty())
	{
		WOLF_ELEMENT current = pq.top(); pq.pop();
		
		Coord currCoord = current.first;
		int currDist = current.second;
		
		visited[currCoord.i][currCoord.j] = true;
		
		if (currCoord.i == hutCoord.i && currCoord.j == hutCoord.j)
		{
			//answerQ.push(currDist);
			return currDist;
			continue;
		}
		
		vector<Coord> coordsToAdd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		int maxDistNearby = -1;
		for (Coord add : coordsToAdd)
		{
			int nextI = currCoord.i + add.i;
			int nextJ = currCoord.j + add.j;
			if (!isIndexInRange(nextI, nextJ) || visited[nextI][nextJ])
			{
				continue;
			}
			
			maxDistNearby = max(maxDistNearby, minDistToTree[nextI][nextJ]);
		}
		
		for (Coord add : coordsToAdd)
		{
			int nextI = currCoord.i + add.i;
			int nextJ = currCoord.j + add.j;
			if (isIndexInRange(nextI, nextJ) && !visited[nextI][nextJ] &&
				(minDistToTree[nextI][nextJ] == maxDistNearby || minDistToTree[nextI][nextJ] >= currDist))
			{
				pq.push({{nextI, nextJ}, min(currDist, maxDistNearby)});
				visited[nextI][nextJ] = true;
			}
		}
	}
	
	return 0;
}

void getMinDistToTree()
{
	minDistToTree.resize(n);
	for (int i = 0; i < n; i++)
	{
		minDistToTree[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			minDistToTree[i][j] = INF;
		}
	}
	
	int qSize = treeQ.size();
	for (int i = 0; i < qSize; i++)
	{
		Coord treeCoord = treeQ.front(); treeQ.pop();
		minDistToTree[treeCoord.i][treeCoord.j] = 0;
		treeQ.push(treeCoord);
	}
	
	while (!treeQ.empty())
	{
		Coord currCoord = treeQ.front(); treeQ.pop();
		
		vector<Coord> coordsToAdd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (Coord add : coordsToAdd)
		{
			int newI = currCoord.i + add.i;
			int newJ = currCoord.j + add.j;
			
			if (!isIndexInRange(newI, newJ)) continue;
			
			if (minDistToTree[newI][newJ] > minDistToTree[currCoord.i][currCoord.j] + 1)
			{
				minDistToTree[newI][newJ] = minDistToTree[currCoord.i][currCoord.j] + 1;
				treeQ.emplace(newI, newJ);
			}
		}
	}
	
	//// DEBUG BEGINS ////
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << minDistToTree[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	//// DEBUG ENDS ////
}

void input()
{
	cin >> n >> m;
	map.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			
			if (map[i][j] == TREE)
			{
				treeQ.emplace(i, j);
			} else if (map[i][j] == HUT)
			{
				hutCoord = {i, j};
				
			} else if (map[i][j] == WOLF)
			{
				wolfCoord = {i, j};
			}
		}
	}
}
