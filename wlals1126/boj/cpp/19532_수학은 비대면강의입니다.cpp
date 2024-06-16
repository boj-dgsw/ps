#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int y = (d * c - a * f) / (b * d - a * e);
    int x = (c * e - b * f) / (a * e - b * d);

    cout << x << " " << y << endl;

    return 0;
}
