// Geometry
// Bruteforce

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
constexpr char BOMB = 'o';
constexpr char SAFE = 'x';

vector<vector<char>> map(10, vector<char>(10));
vector<vector<bool>> isSafe(10, vector<bool>(10, true));

// 폭탄 십자상에 있는 칸의 isSafe를 false로 만든다.
void MakeUnsafe(int targetR, int targetC);

// 입력
void Input();

// isSafe가 true인 곳을 전부 다 살펴 {fromR, fromC}와 그 곳 사이의 거리를 재서 가장 짧은 거리를 반환한다.
int FindShortestDist(int fromR, int fromC);

// {currR, currC}에서 {targetR, targetC}까지의 거리 반환
int GetDist(int currR, int currC, int targetR, int targetC)
{
	return abs(currR - targetR) + abs(currC - targetC);
}

int main()
{
	FAST_IO;
	
	int r, c;
	cin >> r >> c;
	r--; c--;
	
	
	Input();
	cout << FindShortestDist(r, c);
}

int FindShortestDist(int fromR, int fromC)
{
	pair<int, int> closestCoord = {1000, 1000};
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			// is safe zone?
			if (!isSafe[r][c]) continue;

      // 안전한 좌표와 원래 좌표를 비교한다.
			int newDist = GetDist(fromR, fromC, r, c);
			int currClosestDist = GetDist(fromR, fromC, closestCoord.first, closestCoord.second);
			if (currClosestDist < newDist)
				continue;
			
			closestCoord = { r, c };
		}
	}

  // 가장 가까운 좌표에서 {fromR, fromC} 사이의 거리 반환
	return GetDist(closestCoord.first, closestCoord.second, fromR, fromC);
}

void Input()
{
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			cin >> map[r][c];
		}
	}
	
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			// is bomb?
			if (map[r][c] == BOMB)
			{
				MakeUnsafe(r, c);
			}
		}
	}
}

void MakeUnsafe(int targetR, int targetC)
{
	for (int r = 0; r < 10; r++)
		isSafe[r][targetC] = false;
	
	for (int c = 0; c < 10; c++)
		isSafe[targetR][c] = false;
}
