// Geometry
// Math

#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

struct coord
{
	int x;
	int y;
	
	coord() : x(0), y(0) {}
	coord(int _x, int _y) : x(_x), y(_y) {}
};

class rectangle
{
public:
	coord upperL;
	coord lowerR;
	
	rectangle() : upperL(0, 0), lowerR(0, 0) {}
	rectangle(int x1, int y1, int x2, int y2) : upperL(x1, y1), lowerR(x2, y2) {}
	
	// 직사각형 입력
	void input()
	{
		cin >> upperL.x >> upperL.y;
		cin >> lowerR.x >> lowerR.y;
	}
	
	// 직사각형 범위 출력
	[[nodiscard]]
	int get_area() const
	{
		return (lowerR.x - upperL.x) * (lowerR.y - upperL.y);
	}
};

int main()
{
	FAST_IO;
	
	// test case number
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		rectangle origin, overlap;
		origin.input();
		overlap.input();
		
		// 겹쳐진 곳 구하는 식
		int overlapX = min(origin.lowerR.x, overlap.lowerR.x) - max(origin.upperL.x, overlap.upperL.x);
		int overlapY = min(origin.lowerR.y, overlap.lowerR.y) - max(origin.upperL.y, overlap.upperL.y);
				
		// overlapX나 overlapY가 0 이하이면 겹치지 않는다
		if (overlapX <= 0 || overlapY <= 0)
		{
			// 음수가 곱해질 수도 있으므로 0 처리
			overlapX = 0;
			overlapY = 0;
		}
		// 원본 포스터에서 overlap 범위 뺀 값 출력
		cout << origin.get_area() - (overlapX * overlapY) << '\n';
	}
}
