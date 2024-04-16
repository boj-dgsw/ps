// 웰노운 그래프 탐색 문제입니다.
// 'K'에서 '*'까지의 거리를 구합니다. 인접 8칸으로 이동할 수 있으며
// 오른쪽, 오른쪽 위, 오른쪽 아래로 가면 weight이 0이지만 나머지는 weight이 1이므로 무한 탐색은 걱정하지 않아도 됩니다.

#include <iostream>
#include <vector>
#include <queue>
#define OUT
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

constexpr char SEA = '.';
constexpr char TREASURE = '*';
constexpr char ROCK = '#';
constexpr char BOAT = 'K';
constexpr int INF = 0x3f3f3f3f;

struct Coord { int i; int j; };

pair<Coord, Coord> input(OUT int& h, OUT int& w, OUT vector<vector<char>>& map);
int getMinFuel(const vector<vector<char>>& map, Coord boatCoord, Coord treasureCoord);

int main()
{
	FAST_IO
	
	int h, w;
	vector<vector<char>> map;
	
	auto coords = input(h, w, map);
	Coord boatCoord = coords.first;
	Coord treasureCoord = coords.second;
	
	int minFuel = getMinFuel(map, boatCoord, treasureCoord);
	cout << minFuel;
}

/// <returns> 보트와 보물 좌표 반환 </returns>
pair<Coord, Coord> input(OUT int& h, OUT int& w, OUT vector<vector<char>>& map)
{
	cin >> h >> w;
	map.resize(h);
	
	Coord boatCoord = {-1, -1};
	Coord treasureCoord = {-1, -1};
	
	for (int i = 0; i < h; i++)
	{
		map[i].resize(w);
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == BOAT)
			{
				boatCoord = {i, j};
			}
			else if (map[i][j] == TREASURE)
			{
				treasureCoord = {i, j};
			}
		}
	}
	
	return {boatCoord, treasureCoord};
}

bool isIndexValid(const int currI, const int currJ, const int maxI, const int maxJ)
{
	return currI >= 0 && currJ >= 0 && currI <= maxI && currJ <= maxJ;
}
int getMinFuel(const vector<vector<char>>& map, const Coord boatCoord, const Coord treasureCoord)
{
	int h = map.size();
	int w = map[0].size();
	
	queue<Coord> q;
	q.push(boatCoord);
	
	vector<vector<int>> minDistArr;
	minDistArr.resize(h);
	for (int i = 0; i < h; i++)
	{
		minDistArr[i].resize(w);
		for (int j = 0; j < w; j++)
		{
			minDistArr[i][j] = INF;
		}
	}
	minDistArr[boatCoord.i][boatCoord.j] = 0;
	
	while (!q.empty())
	{
		Coord currCoord = q.front(); q.pop();
		
		int currI = currCoord.i;
		int currJ = currCoord.j;
		
		// 인접 8칸 + 자기 자신 칸 살펴보기(어차피 넘어가짐)
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int nextI = currI + i;
				int nextJ = currJ + j;
				
				if (!isIndexValid(nextI, nextJ, h - 1, w - 1) || map[nextI][nextJ] == ROCK)
					continue;
				
				int addedFuel = (int)(j != 1); // j가 1이 아니라면(오른쪽으로 가지 않는다면) 연료를 사용
				if (minDistArr[nextI][nextJ] > minDistArr[currI][currJ] + addedFuel)
				{
					minDistArr[nextI][nextJ] = minDistArr[currI][currJ] + addedFuel;
					q.push({nextI, nextJ});
				}
			}
		}
	}
	
	return minDistArr[treasureCoord.i][treasureCoord.j] == INF ? -1 : minDistArr[treasureCoord.i][treasureCoord.j];
}
