#include <iostream>
using namespace std;

int pisano(int m) {
    int previous = 0;
    int current = 1;
    int temp = 0;

    for (int i = 0; i < m * m; ++i) {
        temp = (previous + current) % m;
        previous = current;
        current = temp;

        if (previous == 0 && current == 1) {
            return i + 1;
        }
    }

    return 0;
}

int main() {
    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int n, m;
        cin >> n >> m;

        cout << n << " " << pisano(m) << endl;
    }

    return 0;
}
