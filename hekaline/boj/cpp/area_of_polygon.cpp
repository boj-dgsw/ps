#include <cstdio>
#include <vector>

#define OUT

using namespace std;
using ld = long double;

struct Coord
{
	ld x;
	ld y;
};

void input(OUT int &n, OUT vector<Coord>& coords);
ld getProduct(Coord stand, Coord coordA, Coord coordB);
ld getArea(vector<Coord>& coords);

int main()
{
	int n;
	vector<Coord> coords;
	input(n, coords);
	
	ld ans = getArea(coords);
	printf("%.1Lf", ans);
	return 0;
}

// 입력
void input(OUT int &n, OUT vector<Coord>& coords)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ld x, y;
		scanf("%Lf%Lf", &x, &y);
		coords.push_back({x, y});
	}
}

// 외적
ld getProduct(Coord stand, Coord coordA, Coord coordB)
{
  // A와 B 좌표 사이의 직각이 되는 높이(외적) 구하고 (A-B) * 높이, 곧 사각형 넓이 반환
	return (coordA.x - stand.x) * (coordB.y - stand.y) - (coordB.x - stand.x) * (coordA.y - stand.y);
}

// 넓이 구하기
ld getArea(vector<Coord>& coords)
{
	ld result = 0;
	int coordLength = coords.size();
	
	for (int i = 1; i < coordLength - 1; i++)
	{
		result += getProduct(coords[0], coords[i], coords[i + 1]);
	}
	result /= (long double)2; // triangle, divide by 2
	return result < 0 ? -result : result;
}
