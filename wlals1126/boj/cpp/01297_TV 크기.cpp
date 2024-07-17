#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int d, w, h;
    cin >> d >> w >> h;

    double x = sqrt(static_cast<double>(d) * d / (h * h + w * w));

    cout << static_cast<int>(floor(x * w)) << " " << static_cast<int>(floor(x * h)) << endl;

    return 0;
}
