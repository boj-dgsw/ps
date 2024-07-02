// 볼록 껍질
// 기하학
// Platinum V

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

class Point
{
public:
	Point() = default;
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	
	friend istream& operator>>(istream& is, Point& p)
	{
		is >> p.x >> p.y;
		return is;
	}
	
	bool operator <(const Point& p) const
	{
		return y == p.y ? x < p.x : y < p.y;
	}
	
	static bool cmp(const Point& p1, const Point& p2)
	{
		ll _ccw = ccw({stdX, stdY}, p1, p2);
		
		if (_ccw == 0)
		{
			return dist({stdX, stdY}, p1) < dist({stdX, stdY}, p2);
		}
		return _ccw > 0;
	}
	
	[[nodiscard]]
	static ll ccw(const Point& p1, const Point& p2, const Point& p3)
	{
		return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	}
	
	[[nodiscard]]
	ll ccw(Point& p2, Point& p3) const
	{
		return (p2.x - x) * (p3.y - y) - (p3.x - x) * (p2.y - y);
	}
	
	[[nodiscard]]
	static ll dist(const Point& p1, const Point& p2)
	{
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}
	
	[[nodiscard]]
	ll dist(const Point& p) const
	{
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
	
	[[nodiscard]]
	ll getX() const { return x; }
	[[nodiscard]]
	ll getY() const { return y; }
	
	static ll stdX;
	static ll stdY;

private:
	ll x = 0;
	ll y = 0;
};

ll Point::stdX = 0;
ll Point::stdY = 0;

void input();

vector<Point> vec;
vector<int> pntStack;
int n;

int main()
{
	input();
	
	sort(vec.begin(), vec.end());
	Point::stdX = vec[0].getX();
	Point::stdY = vec[0].getY();
	sort(next(vec.begin()), vec.end(), Point::cmp);
	
	pntStack.push_back(0);
	pntStack.push_back(1);
	
	for (int i = 2; i < n; i++)
	{
		while (pntStack.size() >= 2)
		{
			Point prevPnt = vec[pntStack[pntStack.size() - 2]];
			Point currPnt = vec[pntStack.back()];
			if (vec[i].ccw(prevPnt, currPnt) <= 0)
				pntStack.pop_back();
			else
				break;
		}
		pntStack.push_back(i);
	}
	
	cout << pntStack.size() << endl;
	return 0;
}

void input()
{
	cin >> n;
	vec.resize(n);
	
	for (auto& element : vec)
		cin >> element;
}
