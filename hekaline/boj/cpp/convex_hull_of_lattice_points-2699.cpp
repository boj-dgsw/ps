// 볼록 껍질
// 기하학
// Platinum V

#include <iostream>
#include <bits/stdc++.h>
#define OUT
#define NAMEOF(a) #a
#define FAST_IO \
	ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);                \


using namespace std;
using ll = long long;

class Point
{
public:
	Point() = default;
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	
	[[nodiscard]] ll getX() const { return x; }
	[[nodiscard]] ll getY() const { return y; }
	
	[[nodiscard]] ll dist(const Point& p) const
	{ return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y); }
	
	[[nodiscard]]
	static ll dist(const Point& p1, const Point& p2)
	{ return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y); }
	
	friend istream& operator>>(istream& is, Point& p)
	{
		is >> p.x >> p.y;
		
		return is;
	}
	
	friend ostream& operator<<(ostream& os, const Point& p)
	{
		os << p.x << ' ' << p.y;
		
		return os;
	}
	
	bool operator<(const Point& p) const
	{
		return y == p.y ? x < p.x : y > p.y;
	}
	
	static bool cmp(const Point& p1, const Point& p2)
	{
		ll _ccw = ccw({stdX, stdY}, p1, p2);
		
		if (_ccw == 0)
		{
			return dist({stdX, stdY}, p1) < dist({stdX, stdY}, p2);
		}
		
		return _ccw < 0;
	}
	
	[[nodiscard]]
	ll ccw(const Point& p2, const Point& p3) const
	{ return (p2.x - x) * (p3.y - y) - (p3.x - x) * (p2.y - y); }
	
	[[nodiscard]]
	static ll ccw(const Point& p1, const Point& p2, const Point& p3)
	{ return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y); }
	
	static ll stdX; // 원점 X
	static ll stdY; // 원점 Y
	
private:
	ll x;
	ll y;
};

ll Point::stdX = 0;
ll Point::stdY = 0;

void Input(OUT int& n, OUT vector<Point>& vec);
void PrintConvexHull(const int& n, const vector<Point>& vec);

int main()
{
	FAST_IO;
	
	int t;
	cin >> t;
	
	int n;
	vector<Point> vec;
	
	while (t--)
	{
		Input(n, vec);
		PrintConvexHull(n, vec);
	}
}

void PrintConvexHull(const int& n, const vector<Point>& vec)
{
	vector<int> pntStack;
	pntStack.push_back(0);
	pntStack.push_back(1);
	
	for (int i = 2; i < n; i++)
	{
		while (pntStack.size() >= 2)
		{
			int stackSize = pntStack.size();
			const Point& prevPnt = vec[pntStack[stackSize - 2]];
			const Point& currPnt = vec[pntStack[stackSize - 1]];
			
			if (vec[i].ccw(prevPnt, currPnt) >= 0)
				pntStack.pop_back();
			else
				break;
		}
		pntStack.push_back(i);
	}
	
	cout << pntStack.size() << '\n';
	for (const auto& element : pntStack)
		cout << vec[element] << '\n';
}

void Input(OUT int& n, OUT vector<Point>& vec)
{
	cin >> n;
	
	vec.resize(n);
	for (auto& element : vec)
	{
		cin >> element;
	}
	sort(vec.begin(), vec.end());
	
	Point::stdX = vec[0].getX();
	Point::stdY = vec[0].getY();
	
	sort(next(vec.begin()), vec.end(), Point::cmp);
}
