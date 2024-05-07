// Geometry
// 성규와 교수의 거리가 5 이상이고
// 성규와 교수를 꼭짓점으로 하는 직사각형 내 학생이 3명 이상 있으면 1 출력
// 없으면 0 출력

#include <iostream>
#include <vector>
#include <cmath>

#define FAST_IO ios_base::sync_with_stdio(false);\
                cin.tie(nullptr);\
                cout.tie(nullptr);

using namespace std;
using ld = long double;

constexpr int STUDENT = 1;
constexpr int SUNGGYU = 2;
constexpr int PROFESSOR = 5;


struct coord
{
	int x;
	int y;
	
	coord (int _x, int _y) : x(_x), y(_y) {}
	coord() : x(0), y(0) {}
};

int n;
coord startCoord;
coord endCoord;
coord upperLeft;
coord lowerRight;

vector<vector<int>> vec;
vector<coord> stuCoords;

void input();
bool isInSquare(coord& currLoc)
{
	
	
	return (currLoc.x >= upperLeft.x && currLoc.x <= lowerRight.x &&
			currLoc.y >= upperLeft.y && currLoc.y <= lowerRight.y);
}

int main()
{
	FAST_IO;
	input();
	
	upperLeft = {min(startCoord.x, endCoord.x), min(startCoord.y, endCoord.y)};
	lowerRight = {max(startCoord.x, endCoord.x), max(startCoord.y, endCoord.y)};
	
	ld distBetweenTwo = sqrt(pow(startCoord.x - endCoord.x, 2) +
	                         pow(startCoord.y - endCoord.y, 2));
	
	// 거리가 가까움
	if (distBetweenTwo < 5)
	{
		cout << 0;
		return 0;
	}
	
	int cnt = 0;
	
	// 학생 좌표 살펴보기
	for (auto& coord : stuCoords)
	{
		if (!isInSquare(coord)) continue;
		
		cnt += 1;
		if (cnt >= 3)
		{
			cout << 1;
			return 0;
		}
	}
	
	cout << 0;
	return 0;
}

void input()
{
	cin >> n;
	vec.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		vec[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
			
			switch(vec[i][j])
			{
				case STUDENT:
					stuCoords.emplace_back(i, j);
					break;
				case SUNGGYU:
					startCoord = {i, j};
					break;
				case PROFESSOR:
					endCoord = {i, j};
					break;
			}
		}
	}
}
