#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int simulate(vector<int>& pos, int start) {
    unordered_set<int> exploded;
    queue<pair<int, int>> q;
    q.push({start, 1});
    exploded.insert(start);

    int count = 0;

    while (!q.empty()) {
        auto [p, r] = q.front();
        q.pop();
        count++;

        for (int x : pos) {
            if (exploded.find(x) == exploded.end() && abs(x - p) <= r) {
                q.push({x, r + 1});
                exploded.insert(x);
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }

    int max_exploded = 0;
    for (int i = 0; i < n; ++i) {
        max_exploded = max(max_exploded, simulate(pos, pos[i]));
    }

    cout << max_exploded << endl;
    return 0;
}
