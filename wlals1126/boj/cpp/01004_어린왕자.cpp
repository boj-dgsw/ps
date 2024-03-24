#include <iostream>
using namespace std;

bool isinner(int x, int y, int r, int x1, int y1) {
	int distance = (x - x1) * (x - x1) + (y - y1) * (y - y1);
	if (distance > r * r)
		return false;
	return true;
}

int main() {
	int t, cases;
	cin >> t;
	int x1, y1, x2, y2;

	int x, y, r;
	int count;
	for (int i = 0; i < t; i++) {
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		cin >> cases;
		count = 0;
		for (int j = 0; j < cases; j++) {
			cin >> x;
			cin >> y;
			cin >> r;
			if (isinner(x, y, r, x1, y1) != isinner(x, y, r, x2, y2)) {
				count += 1;
			}

		}
		cout << count << endl;

	}
}
