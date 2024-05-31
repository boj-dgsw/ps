// Geometry
// Bruteforcing

#include <iostream>
#include <vector>
#include <cmath>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

struct coord { int x; int y; };
vector<coord> riceCoords;
int n, r;

// n, r 및 밥알 좌표 입력
void input();

// 웍을 {-100, -100} ~ {100, 100} 좌표로 옮기면서 최대 밥알을 지켜내는 위치를 반환한다.
coord getAns();

// {i, j}에 웍을 두었을 때 지켜지는 밥알의 개수를 구한다.
int getRiceCountInRange(int i, int j);

int main()
{
	FAST_IO;
	input();
	
	coord ans = getAns();
	cout << ans.x << ' ' << ans.y;
}

coord getAns()
{
	coord ans = {1000, 1000};
	int maxRice = -1;
	
	// 브루트포스
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			int riceCount = getRiceCountInRange(i, j);
			if (maxRice < riceCount)
			{
				maxRice = riceCount;
				ans = {i, j};
			}
		}
	}
	
	return ans;
}

int getRiceCountInRange(int i, int j)
{
	int res = 0;
	for (auto rice : riceCoords)
	{
		// 웍 안에 들었을 때
		if (sqrt(pow(i - rice.x, 2) + pow(j - rice.y, 2)) <= r)
		{
			res += 1;
		}
	}
	
	return res;
}

void input()
{
	cin >> n >> r;
	riceCoords.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> riceCoords[i].x >> riceCoords[i].y;
	}
}
