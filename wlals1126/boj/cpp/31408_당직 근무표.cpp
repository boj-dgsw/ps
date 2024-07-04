#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> schedule(N);
    unordered_map<int, int> count;

    for (int i = 0; i < N; ++i) {
        cin >> schedule[i];
        count[schedule[i]]++;
    }

    int max_count = 0;
    for (const auto& pair : count) {
        max_count = max(max_count, pair.second);
    }

    if (max_count <= (N + 1) / 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
