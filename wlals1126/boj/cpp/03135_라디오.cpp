#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b;

    cin >> n;

    int minDiff = abs(b - a);
    int value = a;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (minDiff > abs(b - num)) {
            minDiff = abs(b - num);
            value = num;
        }
    }

    if (value != a) {
        result += 1;
    }
    result += minDiff;
    cout << result << endl;

    return 0;
}
