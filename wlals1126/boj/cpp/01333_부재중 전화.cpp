#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L, D;
    cin >> N >> L >> D;

    vector<int> time(10000, 0);
    int sec = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            time[sec++] = 1;
        }
        sec += 5;
    }
    sec = 0;

    while (true) {
        if (time[sec] == 0) {
            cout << sec;
            break;
        }
        sec += D;
    }

    return 0;
}
