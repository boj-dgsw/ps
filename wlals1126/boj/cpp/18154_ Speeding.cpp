#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> photos(N);

    for (int i = 0; i < N; ++i) {
        cin >> photos[i].first >> photos[i].second;
    }

    int max_speed = 0;

    for (int i = 1; i < N; ++i) {
        int dt = photos[i].first - photos[i - 1].first;
        int dd = photos[i].second - photos[i - 1].second;
        int speed = dd / dt;
        max_speed = max(max_speed, speed);
    }

    cout << max_speed << '\n';

    return 0;
}
