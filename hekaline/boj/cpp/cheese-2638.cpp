#include <iostream>
#include <vector>
#include <queue>
#define OUT
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

constexpr short AIR_INSIDE = 0;
constexpr short CHEESE = 1;
constexpr short AIR_OUTSIDE = 2;
constexpr short WILL_MELTED = 3;

using namespace std;
struct Coord { int i; int j; };

/// <returns> 치즈가 다 녹는 최소 시간을 반환한다. </>
int getMeltingTime(OUT vector<vector<short>>& cheeses);

int main()
{
	FAST_IO;
	
	int v, h;
	cin >> v >> h;
	
	vector<vector<short>> cheeses;
	cheeses.resize(v);
	for (int i = 0; i < v; i++)
	{
		cheeses[i].resize(h);
		for (int j = 0; j < h; j++)
		{
			cin >> cheeses[i][j];
		}
	}
	
	cout << getMeltingTime(cheeses);
	return 0;
}

// 인덱스 유효한지 검사
bool isIndexValid(const int currI, const int currJ, const int maxI, const int maxJ)
{
	return currI >= 0 && currJ >= 0 && currI <= maxI && currJ <= maxJ;
}


// 바깥 공기를 전부 찾는 함수.
void findAirOutside(OUT queue<Coord>& q, OUT vector<vector<short>>& cheeses)
{
	int v = cheeses.size();
	int h = cheeses[0].size();

	while(q.empty() == false)
	{
		Coord currCoord = q.front(); q.pop();
		int i = currCoord.i;
		int j = currCoord.j;
		
		cheeses[i][j] = AIR_OUTSIDE;
		
		vector<Coord> coords = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (Coord coordToAdd : coords)
		{
			int newI = i + coordToAdd.i;
			int newJ = j + coordToAdd.j;
			
			if (isIndexValid(newI, newJ, v - 1, h - 1) && cheeses[newI][newJ] == AIR_INSIDE)
			{
				cheeses[newI][newJ] = AIR_OUTSIDE;
				q.push({newI, newJ});
			}
		}
	}
}

/// <returns> 치즈가 완전 녹았으면 true를 반환, 그렇지 않으면 false를 반환한다. </>
bool simulateMelt(OUT vector<vector<short>>& cheeses)
{
	int v = cheeses.size();
	int h = cheeses[0].size();
	
	queue<Coord> q;
	
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (cheeses[i][j] == CHEESE)
			{
				q.push({i, j});
			}
		}
	}
	
	if (q.empty())
	{
		// 치즈 완전 녹음
		return true;
	}
	
	queue<Coord> willMeltQ;
	vector<Coord> willMeltArr;
	
	// 무한 push를 막기 위한 배열
	vector<vector<bool>> checked;
	checked.resize(v);
	for (int i = 0; i < v; i++)
	{
		checked[i].resize(h);
	}
	// 치즈를 하나씩 둘러본다.
	while (q.empty() == false)
	{
		Coord currCoord = q.front(); q.pop();
		
		int i = currCoord.i;
		int j = currCoord.j;
		
		if (checked[i][j] == true)
			continue;
		
		checked[i][j] = true;
		
		// 치즈 상하좌우 살펴보기
		vector<Coord> coords = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		int contactAirCnt = 0;
		for (Coord coordToAdd : coords)
		{
			int newI = i + coordToAdd.i;
			int newJ = j + coordToAdd.j;
			
			if (isIndexValid(newI, newJ, v - 1, h - 1))
			{
				// 치즈 상하좌우의 공기가 바깥 공기라면
				// 녹을 수 있는 가능성 상승
				if (cheeses[newI][newJ] == AIR_OUTSIDE)
				{
					contactAirCnt += 1;
				}
				// 주변에 다른 치즈가 있으면 그것도 살펴본다.
				else if (cheeses[newI][newJ] == CHEESE)
				{
					q.push({newI, newJ});
				}
			}
		}
		
		// 치즈의 두 면 이상이 노출되면 녹을 것이다.
		if (contactAirCnt >= 2)
		{
			willMeltQ.push({i, j});
			willMeltArr.push_back({i, j});
		}
	}
	
	// 녹을 것으로 예상되는 치즈 모두 녹이기(바깥 공기에 노출되어 있으므로 녹으면 덩달아 바깥 공기가 된다.)
	for (Coord willMeltCoord : willMeltArr)
	{
		cheeses[willMeltCoord.i][willMeltCoord.j] = AIR_OUTSIDE;
	}
	// willMeltQ는 이 함수가 종료되면 사라지지만 상관 없음.
	// cheeses만 멀쩡하면 된다.
	findAirOutside(willMeltQ, cheeses);
	
	return false;
}

int getMeltingTime(OUT vector<vector<short>>& cheeses)
{
	int result = 0;
	int v = cheeses.size();
	int h = cheeses[0].size();
	
	vector<vector<bool>> visited;
	visited.resize(v);
	for (int i = 0; i < v; i++)
	{
		visited[i].resize(h);
	}
	
	// "모눈종이의 맨 가장자리에는 치즈가 놓이지 않는 것으로 가정한다."
	// 플러드 필을 우선적으로 진행한다. 공기가 내부 공기가 아니라면(바깥 공기라면) AIR_OUTSIDE로 간주한다.
	
	queue<Coord> findingAirQ;
	findingAirQ.push({0, 0});
	findingAirQ.push({v - 1, 0});
	findingAirQ.push({0, h - 1});
	findingAirQ.push({v - 1, h - 1});
	
	findAirOutside(findingAirQ, cheeses);
	
	while (true)
	{
		if (simulateMelt(cheeses) == false)
		{
			result += 1;
		} else
		{
			break;
		}
	}
	
	return result;
}
