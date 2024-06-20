#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int total_length = 0;
    int current_length = L;
    int branches = 1;

    while (true) {
        current_length = (current_length * R) / 100;
        if (current_length <= 5) break;
        branches *= 2;
        total_length += branches * current_length;
    }

    cout << total_length << '\n';

    return 0;
}
