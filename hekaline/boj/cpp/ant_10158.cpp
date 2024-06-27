// Ad-Hoc

#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	int w, h, p, q, t;
	
	cin >> w >> h >> p >> q >> t;
	int x = p + t;
	int y = q + t;
	
	bool isHeadingLeft = ((x - 1) / w) % 2;
	bool isHeadingDown = ((y - 1) / h) % 2;
	
	x = (p + t) % w;
	if (x == 0) x = w;
	y = (q + t) % h;
	if (y == 0) y = h;
	
	// cout << isHeadingLeft << ' ' << isHeadingDown << '\n';
	// cout << x << ' ' << y << '\n';
	cout << (isHeadingLeft ? (w - x) : x) << ' '
		<< (isHeadingDown ? (h - y) : y) << '\n';
}
